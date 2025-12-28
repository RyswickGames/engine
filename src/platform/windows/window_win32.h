#pragma once
#include <windows.h>
#include <cstdint>
#include "../window.h"

class WindowWin32 {
public:
    WindowWin32(const WindowProps&);
    ~WindowWin32();

    void PollEvents();
    void* NativeHandle();
    bool ShouldClose() const;

    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

private:
    HWND m_window;
    WindowProps m_props;
};