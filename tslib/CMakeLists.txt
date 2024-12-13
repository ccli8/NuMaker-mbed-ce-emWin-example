# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_library(tslib STATIC EXCLUDE_FROM_ALL)

if("NUMAKER_IOT_M467" IN_LIST MBED_TARGET_LABELS)
    add_subdirectory(TARGET_NUMAKER_IOT_M467)
endif()

if("NUMAKER_PFM_M487" IN_LIST MBED_TARGET_LABELS)
    add_subdirectory(TARGET_NUMAKER_PFM_M487)
endif()

target_include_directories(tslib
    PUBLIC
        .
)

target_sources(tslib
    PRIVATE
        fbutils.c
        M48XTouchPanel.c
        testutils.c
        ts_calibrate.c
)

target_link_libraries(tslib
    PUBLIC
        mbed-core-flags
        emWin
)
