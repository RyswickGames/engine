#pragma once
#include "../window.h"

class WindowMacOS final : public Window {
public:
    explicit WindowMacOS(const WindowProps& props);
    ~WindowMacOS();

    void  PollEvents() override;
    void* NativeHandle() override;
    bool  ShouldClose() const override;

private:
    /* NSWindow* */void* m_window;
    bool  m_shouldClose;
};
