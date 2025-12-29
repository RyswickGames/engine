#include "engine.h"
#include "../platform/windows/window_win32.h"
#include "../graphics/dx12/dx12_renderer.h"

Engine::Engine() : m_isRunning(false) {
    Initialize();
}

Engine::~Engine() {
    Shutdown();
}

void Engine::Initialize() {
    WindowProps props = { 1920, 1080, "Ryswick" };
    m_window = std::make_unique<WindowWin32>(props);
    m_renderer = std::make_unique<DX12Renderer>();
    m_renderer->Initialize(m_window->NativeHandle(), props.width, props.height);
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
        m_renderer->BeginFrame();
        m_renderer->EndFrame();
    }
}

