add_executable(Ryswick
    main.cpp
    engine/engine.cpp
    platform/windows/window_win32.cpp
    graphics/dx12/dx12_renderer.cpp
)

target_include_directories(Ryswick PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/external/dx12-agility/include
)
find_package(fmt CONFIG REQUIRED)

target_link_libraries(Ryswick PRIVATE
    d3d12
    dxgi
    dxguid
    d3dcompiler
    fmt::fmt
)
