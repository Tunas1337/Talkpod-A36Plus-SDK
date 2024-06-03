# CMSIS Build CMakeLists generated on 2024-06-02T00:58:57

cmake_minimum_required(VERSION 3.22)

# Target options

set(TARGET Project)
set(CPU Cortex-M4)
set(PRJ_DIR "/home/tunas/code/Talkpod-A36Plus-SDK/Projects")
set(OUT_DIR "/home/tunas/code/Talkpod-A36Plus-SDK/Projects/out/Project/Project")
set(INT_DIR "/home/tunas/code/Talkpod-A36Plus-SDK/Projects/tmp/Project/Project")
set(FPU SP_FPU)
set(BYTE_ORDER Little-endian)
set(OPTIMIZE size)
set(DEBUG on)
set(CC_FLAGS_GLOBAL "-std=c99 -fno-rtti -funsigned-char -fshort-enums -fshort-wchar -ffunction-sections -Wno-packed -Wno-missing-variable-declarations -Wno-missing-prototypes -Wno-missing-noreturn -Wno-sign-conversion -Wno-nonportable-include-path -Wno-reserved-id-macro -Wno-unused-macros -Wno-documentation-unknown-command -Wno-documentation -Wno-license-management -Wno-parentheses-equality")
set(CXX_FLAGS_GLOBAL "-xc++ -std=c++11 -fno-rtti -funsigned-char -fshort-enums -fshort-wchar -ffunction-sections -Wno-packed -Wno-missing-variable-declarations -Wno-missing-prototypes -Wno-missing-noreturn -Wno-sign-conversion -Wno-nonportable-include-path -Wno-reserved-id-macro -Wno-unused-macros -Wno-documentation-unknown-command -Wno-documentation -Wno-license-management -Wno-parentheses-equality")
set(LD_FLAGS_GLOBAL "--library_type=microlib --map --load_addr_map_info --xref --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --summary_stderr --info summarysizes")
set(LD_SCRIPT "/home/tunas/code/Talkpod-A36Plus-SDK/Projects/Project_Project.sct")

set(DEFINES
  GD32F330
  USE_STDPERIPH_DRIVER
  GD32F3X0
  __MICROLIB
)

set(INC_PATHS
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/CMSIS/GD/GD32F3x0/Include"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/CMSIS"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Users/Inc"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/CMSIS/GD/GD32F3x0/Source/ARM"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Include"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Projects/.cmsis/include"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Projects/RTE/_GD32F330"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Projects/.eide/deps"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Hardware/Inc"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Drivers/LCD"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Drivers/Flash"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Drivers/BK4819"
  "/home/tunas/.cache/arm/packs/GigaDevice/GD32F3x0_DFP/3.0.2/Device/Include"
)

set(AS_ARM_SRC_FILES
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/CMSIS/GD/GD32F3x0/Source/ARM/startup_gd32f3x0.s"
)

set(CC_SRC_FILES
  "/home/tunas/code/Talkpod-A36Plus-SDK/Drivers/BK4819/bk4819.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Drivers/Flash/w25q16jv.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Drivers/LCD/st7735s.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Hardware/Src/dma.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Hardware/Src/gpio.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Hardware/Src/key.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Hardware/Src/spi.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Hardware/Src/usart.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/CMSIS/GD/GD32F3x0/Source/system_gd32f3x0.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_adc.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_cec.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_cmp.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_crc.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_ctc.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_dac.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_dbg.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_dma.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_exti.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_fmc.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_fwdgt.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_gpio.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_i2c.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_misc.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_pmu.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_rcu.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_rtc.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_spi.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_syscfg.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_timer.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_tsi.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_usart.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/GD32F3x0_standard_peripheral/Source/gd32f3x0_wwdgt.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Users/Src/boot.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Users/Src/gd32f3x0_it.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Users/Src/main.c"
  "/home/tunas/code/Talkpod-A36Plus-SDK/Users/Src/systick.c"
)

set(AS_FLAGS_/home/tunas/code/Talkpod-A36Plus-SDK/Libraries/GD32/CMSIS/GD/GD32F3x0/Source/ARM/startup_gd32f3x0.s "-masm=auto")

# Toolchain config map

set(TOOLCHAIN_VERSION_MIN "6.19.0")
set(TOOLCHAIN_VERSION_MAX "6.19.0")
include ("/home/tunas/code/cmsis-toolbox-linux-amd64/etc/AC6.6.16.2.cmake")
include ("/home/tunas/code/cmsis-toolbox-linux-amd64/etc/CMSIS-Build-Utils.cmake")

# Setup project

project(${TARGET} LANGUAGES AS_ARM C)

cbuild_get_running_toolchain(TOOLCHAIN_ROOT TOOLCHAIN_VERSION C)

# Global Flags

set(CMAKE_AS_ARM_FLAGS "${AS_ARM_CPU} ${AS_ARM_BYTE_ORDER} ${AS_ARM_DEFINES} ${AS_ARM_OPTIONS_FLAGS} ${AS_ARM_FLAGS}")
cbuild_get_system_includes(CC_SYS_INC_PATHS_LIST CC_SYS_INC_PATHS)
set(CMAKE_C_FLAGS "${CC_CPU} ${CC_BYTE_ORDER} ${CC_DEFINES} ${CC_OPTIONS_FLAGS} ${CC_FLAGS} ${CC_FLAGS_GLOBAL} ${CC_SYS_INC_PATHS}")
set(CMAKE_C_LINK_FLAGS "${LD_CPU} ${_LS}\"${LD_SCRIPT}\" ${LD_FLAGS_GLOBAL} ${LD_OPTIONS_FLAGS} ${LD_FLAGS}")

# Local Flags

foreach(SRC ${AS_ARM_SRC_FILES})
  string(REPLACE " " "?" S ${SRC})
  if(DEFINED AS_FLAGS_${S})
    set(AS_FLAGS_LOCAL "${AS_FLAGS_${S}}")
  else()
    set(AS_FLAGS_LOCAL "${AS_FLAGS_GLOBAL}")
  endif()
  set_source_files_properties(${SRC} PROPERTIES COMPILE_FLAGS "${AS_FLAGS_LOCAL}")
  set_source_files_properties(${SRC} PROPERTIES LANGUAGE AS_ARM)
endforeach()

# Compilation Database

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_custom_target(database COMMAND ${CMAKE_COMMAND} -E copy_if_different "${INT_DIR}/compile_commands.json" "${OUT_DIR}")

# Setup Target

add_executable(${TARGET} ${AS_ARM_SRC_FILES} ${CC_SRC_FILES})
set_target_properties(${TARGET} PROPERTIES PREFIX "" SUFFIX ".axf" OUTPUT_NAME "Project")
set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR} LINK_DEPENDS ${LD_SCRIPT})
target_include_directories(${TARGET} PUBLIC ${INC_PATHS})
