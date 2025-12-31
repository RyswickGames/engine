#pragma once
#include <memory>
#include "../platform/window.h"
#include "../graphics/renderer.h"
#include "../core/common/alias.h"

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

    UniquePtr<Window> m_window;
    UniquePtr<Renderer> m_renderer;

    bool m_isRunning;
};
