PROJECT_NAME := Ryswick
BUILD_DIR    := build/vs
CMAKE        := cmake
VCPKG_ROOT := C:/Users/dev/vcpkg
VCPKG_TOOLCHAIN := $(VCPKG_ROOT)/scripts/buildsystems/vcpkg.cmake
VCPKG_TOOLCHAIN := $(subst \,/,$(VCPKG_TOOLCHAIN))
GENERATOR := "Visual Studio 17 2022"

.PHONY: all
all: build-debug

.PHONY: configure
configure:
	$(CMAKE) -S . -B $(BUILD_DIR) \
		-G $(GENERATOR) \
		-DCMAKE_TOOLCHAIN_FILE=C:/Users/dev/vcpkg/scripts/buildsystems/vcpkg.cmake

.PHONY: build-debug
build-debug: configure
	$(CMAKE) --build $(BUILD_DIR) --config Debug

.PHONY: build-release
build-release: configure
	$(CMAKE) --build $(BUILD_DIR) --config Release

run-debug: build-debug
	$(BUILD_DIR)/bin/Debug/$(PROJECT_NAME).exe

run-release: build-release
	$(BUILD_DIR)/bin/Release/$(PROJECT_NAME).exe

.PHONY: clean
clean:
	$(CMAKE) -E rm -rf $(BUILD_DIR)

.PHONY: reconfigure
reconfigure:
	$(CMAKE) -E rm -rf $(BUILD_DIR)
	$(MAKE) configure