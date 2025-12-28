#include "window_win32.h"

WindowWin32::WindowWin32(const WindowProps& props) : m_props(props) {
    WNDCLASSEXA wc = {0};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = "RyswickWindowClass";
    RegisterClassExA(&wc);

    m_window = CreateWindowExA(0, "RyswickWindowClass", m_props.title, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, m_props.width, m_props.height, NULL, NULL, wc.hInstance, NULL);

    if (!m_window) {
        MessageBoxA(NULL, "Failed to create window", "Error", MB_OK | MB_ICONERROR);
        return;
    }


}

WindowWin32::~WindowWin32() {
    DestroyWindow(m_window);
    UnregisterClassA("RyswickWindowClass", GetModuleHandle(NULL));
}

void WindowWin32::PollEvents() {
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    if (msg.message == WM_QUIT) {
        PostQuitMessage(0);
    }
}

void* WindowWin32::NativeHandle() {
    return m_window;
}

bool WindowWin32::ShouldClose() const {
    MSG msg = {0};
    return GetMessage(&msg, NULL, 0, 0) == 0;
}

LRESULT WindowWin32::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_CLOSE:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcA(hwnd, msg, wparam, lparam);
    }
    return 0;
}