add_executable(Ryswick
    main.cpp
    platform/windows/window_win32.cpp
    graphics/dx12/dx12_renderer.cpp
)

target_include_directories(Ryswick PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/external/dx12-agility/include
)

target_link_libraries(Ryswick PRIVATE
    d3d12
    dxgi
    dxguid
)