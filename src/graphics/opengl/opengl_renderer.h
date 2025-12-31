#pragma once
#include "../renderer.h"

#ifndef __APPLE__
#include <windows.h>
#include <gl/GL.h>
#else
#include <OpenGL/gl3.h>
#endif

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
    void CreateContext(void* viewPtr);
    void DestroyContext();

#ifndef __APPLE__
    void CreateContext(HWND hwnd);

    HDC   m_hdc;
    HGLRC m_glrc;
    HWND  m_hwnd;
#else
    /* NSOpenGLContext* */void* m_context = nullptr;
    // temp
    GLuint m_shader;
#endif
    uint32_t m_width;
    uint32_t m_height;
};
