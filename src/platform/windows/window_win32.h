#pragma once

#ifndef __APPLE__

#include <windows.h>
#include <cstdint>
#include "../window.h"

class WindowWin32 : public Window {
public:
    WindowWin32(const WindowProps&);
    ~WindowWin32();

    void PollEvents() override;
    void* NativeHandle() override;
    bool ShouldClose() const override;

    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

private:
    HWND m_window;
    WindowProps m_props;
    bool m_shouldClose;
};

#endif
