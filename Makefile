PROJECT_NAME := Ryswick
CMAKE        := cmake
UNAME_S := $(shell uname -s)
GENERATOR    ?=
BUILD_TYPE   ?= Debug

ifeq ($(UNAME_S),Darwin)
    ifeq ($(GENERATOR),)
        GENERATOR := Ninja
    endif
    ifeq ($(GENERATOR),Xcode)
        BUILD_DIR := build/xcode
    else
        BUILD_DIR := build/ninja
    endif
    VCPKG_ROOT := $(HOME)/vcpkg
else
    GENERATOR   := Visual Studio 17 2022
    BUILD_DIR   := build/vs
    VCPKG_ROOT  := C:/Users/dev/vcpkg
endif
VCPKG_TOOLCHAIN := $(VCPKG_ROOT)/scripts/buildsystems/vcpkg.cmake

.PHONY: all configure build-debug build-release clean reconfigure

all: build-debug

configure:
ifeq ($(UNAME_S),Darwin)
	$(CMAKE) -S . -B $(BUILD_DIR) \
		-G "$(GENERATOR)" \
		-DCMAKE_TOOLCHAIN_FILE=$(VCPKG_TOOLCHAIN) \
		$(if $(filter Ninja,$(GENERATOR)),-DCMAKE_BUILD_TYPE=$(BUILD_TYPE),)
else
	$(CMAKE) -S . -B $(BUILD_DIR) \
		-G "$(GENERATOR)" \
		-DCMAKE_TOOLCHAIN_FILE=$(VCPKG_TOOLCHAIN)
endif

build-debug: configure
ifeq ($(UNAME_S),Darwin)
ifeq ($(GENERATOR),Xcode)
	$(CMAKE) --build $(BUILD_DIR) --config Debug
else
	$(CMAKE) --build $(BUILD_DIR)
endif
else
	$(CMAKE) --build $(BUILD_DIR) --config Debug
endif

build-release:
ifeq ($(UNAME_S),Darwin)
ifeq ($(GENERATOR),Xcode)
	$(CMAKE) --build $(BUILD_DIR) --config Release
else
	$(CMAKE) -S . -B $(BUILD_DIR) \
		-G "$(GENERATOR)" \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_TOOLCHAIN_FILE=$(VCPKG_TOOLCHAIN)
	$(CMAKE) --build $(BUILD_DIR)
endif
else
	$(CMAKE) --build $(BUILD_DIR) --config Release
endif

run-debug: build-debug
ifeq ($(UNAME_S),Darwin)
ifeq ($(GENERATOR),Xcode)
	$(BUILD_DIR)/bin/Debug/$(PROJECT_NAME)
else
	$(BUILD_DIR)/bin/Debug/$(PROJECT_NAME)
endif
else
	$(BUILD_DIR)/bin/Debug/$(PROJECT_NAME).exe
endif

run-release: build-release
ifeq ($(UNAME_S),Darwin)
ifeq ($(GENERATOR),Xcode)
	$(BUILD_DIR)/bin/Release/$(PROJECT_NAME)
else
	$(BUILD_DIR)/bin/Release/$(PROJECT_NAME)
endif
else
	$(BUILD_DIR)/bin/Release/$(PROJECT_NAME).exe
endif
