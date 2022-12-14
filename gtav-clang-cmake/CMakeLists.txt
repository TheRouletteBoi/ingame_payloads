cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE toolchain/toolchain.cmake)
project("gtav" C CXX ASM)

# detect operating system and host processor
message(STATUS "We are on a ${CMAKE_SYSTEM_NAME} system")
message(STATUS "The host processor is ${CMAKE_HOST_SYSTEM_PROCESSOR}")

add_link_options(
    -T${CMAKE_SOURCE_DIR}/src/linker.x
    -nostartfiles -nostdlib -nodefaultlibs -Wl,--gc-sections,-static,--undefined=PayloadEntry
)

add_compile_options(
    -Os -g -fno-exceptions -fno-builtin -ffunction-sections -ffreestanding -nostdinc -Wno-int-to-pointer-cast
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

add_executable("${PROJECT_NAME}.elf" "src/crt0.s" "src/main.cpp" )

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMENT Create ${PROJECT_NAME}.bin
    COMMAND ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin 
	)
