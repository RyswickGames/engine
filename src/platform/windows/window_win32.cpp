#include "window_win32.h"

WindowWin32::WindowWin32(const WindowProps& props) : m_props(props), m_shouldClose(false) {
    WNDCLASSEXA wc = {0};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = "RyswickWindowClass";
    RegisterClassExA(&wc);

    m_window = CreateWindowExA(0, "RyswickWindowClass", m_props.title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, m_props.width, m_props.height, NULL, NULL, wc.hInstance, this);

    if (!m_window) {
        return;
    }

    ShowWindow(m_window, SW_SHOW);
}

WindowWin32::~WindowWin32() {
    DestroyWindow(m_window);
    UnregisterClassA("RyswickWindowClass", GetModuleHandle(NULL));
}

void WindowWin32::PollEvents() {
    MSG msg = {0};
    while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}

void* WindowWin32::NativeHandle() {
    return m_window;
}

bool WindowWin32::ShouldClose() const {
    return m_shouldClose;
}

LRESULT WindowWin32::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    WindowWin32* window = nullptr;
    if (msg == WM_NCCREATE) {
        CREATESTRUCT* cs = reinterpret_cast<CREATESTRUCT*>(lparam);
        window = reinterpret_cast<WindowWin32*>(cs->lpCreateParams);
        SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));
    } else {
        window = reinterpret_cast<WindowWin32*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    }

    if (window) {
        if (msg == WM_CLOSE || msg == WM_DESTROY) {
            window->m_shouldClose = true;
            if (msg == WM_DESTROY) PostQuitMessage(0);
            return 0;
        }
    }

    return DefWindowProcA(hwnd, msg, wparam, lparam);
}
