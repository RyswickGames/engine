add_executable(Ryswick
    main.cpp
    engine/engine.cpp
)

target_include_directories(Ryswick PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(Ryswick PRIVATE fmt::fmt)

if(APPLE)
    enable_language(OBJC OBJCXX)

    target_sources(Ryswick PRIVATE
        platform/macos/window_macos.mm
    )

    set_source_files_properties(
        platform/macos/window_macos.mm
        PROPERTIES LANGUAGE OBJCXX
    )

    target_compile_options(Ryswick PRIVATE
        -fobjc-arc
        -fobjc-weak
    )

    target_link_libraries(Ryswick PRIVATE
        "-framework Cocoa"
        "-framework Metal"
        "-framework MetalKit"
        "-framework Foundation"
    )
endif()

if(WIN32)
    target_sources(Ryswick PRIVATE
        platform/windows/window_win32.cpp
        graphics/dx12/dx12_renderer.cpp
    )

    target_include_directories(Ryswick PRIVATE
        ${PROJECT_SOURCE_DIR}/external/dx12-agility/include
    )

    target_link_libraries(Ryswick PRIVATE
        d3d12
        dxgi
        dxguid
        d3dcompiler
    )
endif()
