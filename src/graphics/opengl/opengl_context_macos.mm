#import "opengl_renderer.h"
#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>

void OpenGLRenderer::CreateContext(void* viewPtr)
{
    NSView* view = (__bridge NSView*)viewPtr;

    NSOpenGLPixelFormatAttribute attrs[] =
    {
        NSOpenGLPFAOpenGLProfile,
        NSOpenGLProfileVersion3_2Core,

        NSOpenGLPFAColorSize,   32,
        NSOpenGLPFADepthSize,   24,
        NSOpenGLPFAStencilSize, 8,
        NSOpenGLPFADoubleBuffer,
        NSOpenGLPFAAccelerated,
        0
    };

    NSOpenGLPixelFormat* pixelFormat =
        [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];

    NSOpenGLContext* ctx =
        [[NSOpenGLContext alloc] initWithFormat:pixelFormat
                                   shareContext:nil];

    // dude fuck this
    m_context = (__bridge_retained void*)ctx;

    [ctx setView:view];
    [ctx makeCurrentContext];

    NSRect bounds = [view bounds];
    glViewport(0, 0,
               (GLsizei)bounds.size.width,
               (GLsizei)bounds.size.height);
}
