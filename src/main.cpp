#include <iostream>
#include <Windows.h>
#include "platform/window.h"
#include "platform/windows/window_win32.h"
#include "graphics/renderer.h"

extern "C" {
    __declspec(dllexport) extern const UINT D3D12SDKVersion = 710;
    __declspec(dllexport) extern const char* D3D12SDKPath = ".\\dx12\\";
}

int main() {
    WindowProps wd{1920, 1080, "Ryswick"};
    auto window = new WindowWin32(wd);
    while (!window->ShouldClose()) {
        ShowWindow((HWND)window->NativeHandle(), SW_SHOW);
        window->PollEvents();
        UpdateWindow((HWND)window->NativeHandle());
    }
}
