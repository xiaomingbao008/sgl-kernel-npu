# Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
# MemFabric_Hybrid is licensed under Mulan PSL v2.
# You can use this software according to the terms and conditions of the Mulan PSL v2.
# You may obtain a copy of Mulan PSL v2 at:
#          http://license.coscl.org.cn/MulanPSL2
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
# EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
# MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
# See the Mulan PSL v2 for more details.

include_directories(
        ${ZBCCL_BASE_DIR}/3rdparty/ska
        ${ZBCCL_SRC_DIR}/include
        ${ZBCCL_SRC_DIR}/csrc/common
        ${ZBCCL_SRC_DIR}/csrc/ccl
        ${ZBCCL_SRC_DIR}/csrc/sma
        ${ZBCCL_SRC_DIR}/csrc/sma/observers/tracing
)

## add files into src variables
file(GLOB_RECURSE ZBCCL_SRC_FILES
        ${ZBCCL_SRC_DIR}/csrc/*.cpp
)

set(ZBCCL_PUBLIC_INCLUDE_DIR "${PROJECT_HYBM_SRC_BASE}/include")

## build the static and shared library
add_library(zbccl_objects OBJECT ${ZBCCL_SRC_FILES})
target_compile_options(zbccl_objects PRIVATE -fPIC)
target_include_directories(zbccl_objects INTERFACE ${ZBCCL_PUBLIC_INCLUDE_DIR})

add_library(zbccl_static STATIC $<TARGET_OBJECTS:zbccl_objects>)
set_target_properties(zbccl_static PROPERTIES OUTPUT_NAME "zbccl")
target_link_libraries(zbccl_static PUBLIC pthread dl)
target_include_directories(zbccl_static INTERFACE ${ZBCCL_PUBLIC_INCLUDE_DIR})

add_library(zbccl_shared SHARED $<TARGET_OBJECTS:zbccl_objects>)
set_target_properties(zbccl_shared PROPERTIES OUTPUT_NAME "zbccl")
target_link_libraries(zbccl_shared PUBLIC pthread dl)
target_include_directories(zbccl_shared INTERFACE ${ZBCCL_PUBLIC_INCLUDE_DIR})

## install header files
file(GLOB HEADER_FILES ${ZBCCL_SRC_DIR}/include/*.h)
install(
        FILES ${HEADER_FILES}
        DESTINATION ${PROJECT_HYBM_OUTPUT}/include
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ)

## install library
install(
        TARGETS zbccl_static zbccl_shared
        DESTINATION ${PROJECT_HYBM_OUTPUT}/lib64
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
)
