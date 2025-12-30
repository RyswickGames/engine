// (carter): This is all example code. I have no fucking clue what I'm doing in apple's walled garden.
//           what the fuck is objectivec++?????
#import <Cocoa/Cocoa.h>
#import <Metal/Metal.h>

#include "window_macos.h"


@interface AppDelegate : NSObject <NSApplicationDelegate>
@end

@implementation AppDelegate
- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender {
    return YES;
}
@end


WindowMacOS::WindowMacOS(const WindowProps& props)
: m_window(nullptr)
, m_shouldClose(false)
{
    @autoreleasepool {
        [NSApplication sharedApplication];
        [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];

        static AppDelegate* delegate = [[AppDelegate alloc] init];
        [NSApp setDelegate:delegate];

        NSUInteger style =
        NSWindowStyleMaskTitled |
        NSWindowStyleMaskClosable |
        NSWindowStyleMaskResizable |
        NSWindowStyleMaskMiniaturizable;

        NSRect rect = NSMakeRect(
                                 100, 100,
                                 props.width,
                                 props.height
                                 );

        NSWindow* window = [[NSWindow alloc]
                            initWithContentRect:rect
                            styleMask:style
                            backing:NSBackingStoreBuffered
                            defer:NO];

        NSString* title =
        props.title
        ? [NSString stringWithUTF8String:props.title]
        : @"Application";

        [window setTitle:title];
        [window makeKeyAndOrderFront:nil];
        [window center];

        [NSApp activateIgnoringOtherApps:YES];

        m_window = (__bridge_retained void*)window;
    }
}

WindowMacOS::~WindowMacOS()
{
    @autoreleasepool {
        NSWindow* window = (__bridge_transfer NSWindow*)m_window;
        [window close];
    }
}

void WindowMacOS::PollEvents()
{
    @autoreleasepool {
        NSEvent* event;
        while ((event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                           untilDate:[NSDate distantPast]
                                              inMode:NSDefaultRunLoopMode
                                             dequeue:YES])) {
            if ([event type] == NSEventTypeApplicationDefined)
                continue;

            [NSApp sendEvent:event];
        }

        if (m_window) {
            NSWindow* window = (__bridge NSWindow*)m_window;
            if (![window isVisible]) {
                m_shouldClose = true;
            }
        }
    }
}

void* WindowMacOS::NativeHandle()
{
    return m_window;
}

bool WindowMacOS::ShouldClose() const
{
    return m_shouldClose;
}
