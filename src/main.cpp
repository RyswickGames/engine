#include <iostream>
#include <Windows.h>

extern "C" {
    __declspec(dllexport) extern const UINT D3D12SDKVersion = 710;
    __declspec(dllexport) extern const char* D3D12SDKPath = ".\\dx12\\";
}

auto main() -> int {
    std::cout << "Hello, world\n";
    return 0;
}