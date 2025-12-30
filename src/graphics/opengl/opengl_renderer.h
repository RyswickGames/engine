#pragma once
#include "../renderer.h"

#ifndef __APPLE__
#include <windows.h>
#include <gl/GL.h>

class OpenGLRenderer : public Renderer {
public:
    OpenGLRenderer();
    ~OpenGLRenderer() override;

    void Initialize(void* windowHandle, uint32_t width, uint32_t height) override;
    void Shutdown() override;
    void BeginFrame() override;
    void EndFrame() override;
    void Resize(uint32_t width, uint32_t height) override;

private:
    void CreateContext(HWND hwnd);
    void DestroyContext();

    HDC m_hdc;
    HGLRC m_glrc;
    HWND m_hwnd;
    uint32_t m_width;
    uint32_t m_height;
};
#endif
