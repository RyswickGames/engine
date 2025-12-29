#pragma once
#include <memory>
#include "../platform/window.h"
#include "../graphics/renderer.h"

// (carter): Dates of each version change
//
// 12/28/25 0.1.0
#define MAJOR 0
#define MINOR 1
#define PATCH 0

class Engine {
public:
    Engine();
    ~Engine();

    void Run();

private:
    void Initialize();
    void Shutdown();

    std::unique_ptr<Window> m_window;
    std::unique_ptr<Renderer> m_renderer;
    bool m_isRunning;
};
