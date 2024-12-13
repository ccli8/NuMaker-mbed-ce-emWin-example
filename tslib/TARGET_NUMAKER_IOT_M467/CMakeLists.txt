# Copyright (c) 2020-2021 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

target_include_directories(tslib
    PUBLIC
        .
)

target_sources(tslib
    PRIVATE
        TouchPanel.cpp
)
