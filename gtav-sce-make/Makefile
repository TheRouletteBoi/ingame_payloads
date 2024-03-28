TOOLCHAIN_FILES = toolchain/ppu/

CELL_MK_DIR = $(CELL_SDK)/samples/mk
include $(CELL_MK_DIR)/sdk.makedef-ppu-snc.mk

CELL_BUILD_TOOLS = SNC
SNC_PPU_PREFIX = ps3

SNC_PPU_CXXLD := ps3ppuld64
BUILD_TYPE := debug

PRX_DIR			= .
BINARY_DIR = build/$(BUILD_TYPE)/
CELL_SDK_FILE_NAME = gtav
CELL_SDK_FILE_EXT = .elf

PPU_SRCS := $(wildcard src/*.cpp src/*.s)

PPU_LOADLIBS +=

PPU_LD_DEBUG_FLAGS := -s
PPU_CXX_DEBUG_FLAGS := -g -Xinlinedebug=1 -D"_DEBUG" -D"__CELL_ASSERT__"

ifeq ($(BUILD_TYPE), release)
	PPU_LDFLAGS += -T src/linker.x -oformat=elf -no-required-files -no-standard-libraries -strip-unused-data $(PPU_LD_DEBUG_FLAGS) -o $(BINARY_DIR)$(CELL_SDK_FILE_NAME)$(CELL_SDK_FILE_EXT) -L"C:/usr/local/cell/host-win32/lib/prx/ldscripts"
	PPU_CXXFLAGS += -Tp -DNDEBUG -D__PS3__ -DLIBNAME=$(CELL_SDK_FILE_NAME) -DSTUBNAME=$(CELL_SDK_FILE_NAME)_stub -Xdepmode=1 -MD -Xmserrors -I. -I"C:/usr/local/cell/target/ppu/include" -I"C:/usr/local/cell/target/common/include" -I"C:/usr/local/cell/host-win32/sn/ppu/include" -O2 -Xstd=cpp11 -Xc-=rtti -c
else
	PPU_LDFLAGS += -T src/linker.x -oformat=elf -no-required-files -no-standard-libraries -strip-unused-data -o  $(BINARY_DIR)$(CELL_SDK_FILE_NAME)$(CELL_SDK_FILE_EXT) -L"C:/usr/local/cell/host-win32/lib/prx/ldscripts"
	PPU_CXXFLAGS += -Tp -D__PS3__ $(PPU_CXX_DEBUG_FLAGS) -DLIBNAME=$(CELL_SDK_FILE_NAME) -DSTUBNAME=$(CELL_SDK_FILE_NAME)_stub -Xdepmode=1 -MD -Xmserrors -I. -I"C:/usr/local/cell/target/ppu/include" -I"C:/usr/local/cell/target/common/include" -I"C:/usr/local/cell/host-win32/sn/ppu/include" -O2 -Xstd=cpp11 -Xc-=rtti -c
endif

CLEANFILES = $(PRX_DIR)/$(PPU_SPRX_TARGET)

all:
	mkdir -p $(BINARY_DIR)
	$(MAKE) $(PPU_OBJS_DEPENDS)
	$(SNC_PPU_CXXLD) $(PPU_LDFLAGS) $(PPU_LINK_OBJS)
	$(TOOLCHAIN_FILES)ppu-lv2-objcopy -O binary $(BINARY_DIR)$(CELL_SDK_FILE_NAME)$(CELL_SDK_FILE_EXT) $(BINARY_DIR)$(CELL_SDK_FILE_NAME).bin

rebuild:
	$(MAKE) --no-print-directory clean
	$(MAKE) --no-print-directory all

clean:
	@echo "# removing $(BINARY_DIR) if it is empty.";
	@if [ -d $(BINARY_DIR) ]; then \
		rm -r $(BINARY_DIR); \
	fi

release:
	$(MAKE) rebuild BUILD_TYPE=release

debug:
	$(MAKE) rebuild BUILD_TYPE=debug

include $(CELL_MK_DIR)/sdk.target-ppu.mk