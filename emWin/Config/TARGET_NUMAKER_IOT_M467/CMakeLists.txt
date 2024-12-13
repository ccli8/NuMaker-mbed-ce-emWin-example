# Copyright (c) 2020-2021 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

target_include_directories(emWin
    PUBLIC
        .
)

target_sources(emWin
    PRIVATE
        ILI9341.cpp
        LCDConf2.c
)
