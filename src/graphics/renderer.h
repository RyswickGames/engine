#include <cstdint>

enum class API {
    DX12,
    OPENGL,
    VULKAN
};

class Renderer {
public:
    virtual ~Renderer() = default;
    virtual void Initialize(void* windowHandle) = 0;
    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;
    virtual void Resize(uint32_t w, uint32_t h) = 0;
};
