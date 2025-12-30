#pragma once
#include "../renderer.h"
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl/client.h>
#include <vector>
#include <memory>
#include <DirectXTK12/GraphicsMemory.h>
#include "CommonStates.h"
#include "DescriptorHeap.h"
#include "ResourceUploadBatch.h"

using Microsoft::WRL::ComPtr;

class DX12Renderer : public Renderer {
public:
    DX12Renderer();
    ~DX12Renderer() override;

    void Initialize(void* windowHandle, uint32_t width, uint32_t height) override;
    void Shutdown() override;
    void BeginFrame() override;
    void EndFrame() override;
    void Resize(uint32_t width, uint32_t height) override;

private:
    void CreateDevice();
    void CreateSwapChain(HWND hwnd, uint32_t width, uint32_t height);
    void CreateDescriptorHeaps();
    void CreateSyncObjects();
    void CreateRootSignature();
    void CreatePipelineState();

    void FenceSitter();

    static const uint32_t FrameCount = 2;

    ComPtr<ID3D12Device> m_device;
    ComPtr<ID3D12CommandQueue> m_commandQueue;
    ComPtr<IDXGISwapChain3> m_swapChain;
    ComPtr<ID3D12Resource> m_renderTargets[FrameCount];
    ComPtr<ID3D12CommandAllocator> m_commandAllocator;
    ComPtr<ID3D12GraphicsCommandList> m_commandList;

    ComPtr<ID3D12RootSignature> m_rootSignature;
    ComPtr<ID3D12PipelineState> m_pipelineState;

    ComPtr<ID3D12Fence> m_fence;
    UINT64 m_fenceValue;
    HANDLE m_fenceEvent;

    std::unique_ptr<DirectX::GraphicsMemory> m_graphicsMemory;
    std::unique_ptr<DirectX::CommonStates> m_commonStates;
    std::unique_ptr<DirectX::DescriptorHeap> m_rtvHeap;

    uint32_t m_frameIndex;

    uint32_t m_width;
    uint32_t m_height;
};
