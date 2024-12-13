# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

if("NUMAKER_IOT_M467" IN_LIST MBED_TARGET_LABELS)
    add_subdirectory(TARGET_NUMAKER_IOT_M467)
endif()

if("NUMAKER_PFM_M487" IN_LIST MBED_TARGET_LABELS)
    add_subdirectory(TARGET_NUMAKER_PFM_M487)
endif()

target_include_directories(emWin
    PUBLIC
        .
)

target_sources(emWin
    PRIVATE
        GUI_X.c
        GUIConf.c
        LCDConf.c
)
