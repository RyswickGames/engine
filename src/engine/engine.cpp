#include "engine.h"
#include <fmt/core.h>
#ifndef __APPLE__
    #include "../platform/windows/window_win32.h"
    #include "../graphics/dx12/dx12_renderer.h"
    // (carter): haven't bothered to add opengl to macos cmake config yet
#else
    #include "../platform/macos/window_macos.h"
#endif
#include "../graphics/opengl/opengl_renderer.h"

Engine::Engine() : m_isRunning(false) {
    Initialize();
}

Engine::~Engine() {
    Shutdown();
}

void Engine::Initialize() {
    WindowProps props = { 1920, 1080, "Ryswick" };
#ifndef __APPLE__
    m_window   = MakeUnique<WindowWin32>(props);
#else
    m_window = MakeUnique<WindowMacOS>(props);
#endif
    m_renderer = MakeUnique<OpenGLRenderer>();

    if (m_renderer) {
        m_renderer->Initialize(m_window->NativeHandle(), props.width, props.height);
        fmt::println("Macos opengl init post-call");
    }

    m_isRunning = true;
}

void Engine::Shutdown() {
    if (m_renderer) {
        m_renderer->Shutdown();
    }
}

void Engine::Run() {
    while (m_isRunning && !m_window->ShouldClose()) {
        m_window->PollEvents();
#ifndef __APPLE__
        m_renderer->BeginFrame();
        m_renderer->EndFrame();
#endif
    }
}
