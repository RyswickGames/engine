#ifndef __APPLE__
#include "opengl_renderer.h"

OpenGLRenderer::OpenGLRenderer()
    : m_hdc(nullptr)
    , m_glrc(nullptr)
    , m_hwnd(nullptr)
    , m_width(0)
    , m_height(0) {}
// ---------------------------------------------------------------------------
OpenGLRenderer::~OpenGLRenderer() {
    Shutdown();
}
// ---------------------------------------------------------------------------
void OpenGLRenderer::Initialize(void* windowHandle, uint32_t width, uint32_t height) {
    m_width = width;
    m_height = height;
    m_hwnd = (HWND)windowHandle;
    CreateContext(m_hwnd);
}
// ---------------------------------------------------------------------------
void OpenGLRenderer::Shutdown() {
    DestroyContext();
}
// ---------------------------------------------------------------------------
void OpenGLRenderer::CreateContext(HWND hwnd) {
    m_hdc = GetDC(hwnd);

    PIXELFORMATDESCRIPTOR pfd = {};
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;
    pfd.cStencilBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int pixelFormat = ChoosePixelFormat(m_hdc, &pfd);
    SetPixelFormat(m_hdc, pixelFormat, &pfd);

    m_glrc = wglCreateContext(m_hdc);
    wglMakeCurrent(m_hdc, m_glrc);
    glViewport(0, 0, (GLsizei)(m_width), (GLsizei)(m_height));
}
// ---------------------------------------------------------------------------
void OpenGLRenderer::DestroyContext() {
    if (m_glrc) {
        wglMakeCurrent(nullptr, nullptr);
        wglDeleteContext(m_glrc);
        m_glrc = nullptr;
    }
    if (m_hdc && m_hwnd) {
        ReleaseDC(m_hwnd, m_hdc);
        m_hdc = nullptr;
    }
    m_hwnd = nullptr;
}
// ---------------------------------------------------------------------------
void OpenGLRenderer::BeginFrame() {
    glViewport(0, 0, (GLsizei)(m_width), (GLsizei)(m_height));
    glClearColor(0.0f, 0.2f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.6f, 0.2f);
    glVertex2f(0.0f, 0.5f);
    glColor3f(0.2f, 0.8f, 1.0f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.9f, 0.2f, 0.4f);
    glVertex2f(-0.5f, -0.5f);
    glEnd();
}
// ---------------------------------------------------------------------------
void OpenGLRenderer::EndFrame() {
    SwapBuffers(m_hdc);
}
// ---------------------------------------------------------------------------
void OpenGLRenderer::Resize(uint32_t width, uint32_t height) {
    if (m_width == width && m_height == height) return;
    m_width = width;
    m_height = height;
    glViewport(0, 0, (GLsizei)(m_width), (GLsizei)(m_height));
}
// ---------------------------------------------------------------------------
#endif
