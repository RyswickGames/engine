#include "../renderer.h"

class DX12Renderer : public Renderer {
public:
    void Initialize(void* windowHandle) override;
    void BeginFrame() override;
    void EndFrame() override;
    void Resize(uint32_t w, uint32_t h) override;
};