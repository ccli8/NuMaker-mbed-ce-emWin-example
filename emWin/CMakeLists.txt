# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_library(emWin STATIC EXCLUDE_FROM_ALL)

add_subdirectory(Config)

target_include_directories(emWin
    PUBLIC
        Include
)

target_link_libraries(emWin
    PUBLIC
        mbed-core-flags
        tslib
    INTERFACE
        NUemWin
)

# Fix cyclic dependency between emWin and NUemWin
add_library(NUemWin STATIC IMPORTED)
if("${MBED_TOOLCHAIN}" STREQUAL "ARM")
    set_property(TARGET NUemWin PROPERTY IMPORTED_LOCATION
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/TOOLCHAIN_ARM/NUemWin_CM4_Keil.ar
    )
elseif("${MBED_TOOLCHAIN}" STREQUAL "GCC_ARM")
    set_property(TARGET NUemWin PROPERTY IMPORTED_LOCATION
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/TOOLCHAIN_GCC/libNUemWin_CM4_GNU.a
    )
endif()
target_link_libraries(NUemWin
    INTERFACE
        emWin
)
