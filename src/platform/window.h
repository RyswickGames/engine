#pragma once
#include <cstdint>

struct WindowProps {
    uint32_t    width, height;
    const char* title;
};

class Window {
public:
    virtual void  PollEvents()        = 0;
    virtual void* NativeHandle()      = 0;
    virtual bool  ShouldClose() const = 0;
};
