#pragma once
#include <cstdint>

enum class API {
    DX12,
    OPENGL,
    VULKAN
};

class Renderer {
public:
    virtual ~Renderer() = default;
    virtual void Initialize(void* windowHandle, uint32_t width, uint32_t height) = 0;
    virtual void Shutdown() = 0;
    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;
    virtual void Resize(uint32_t width, uint32_t height) = 0;
};
