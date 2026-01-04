/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2026-2026. All rights reserved.
 * ZBCCL is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 */
#include "zbccl_common_includes.h"
#include "zbccl_mem_allocator.h"

using namespace zbccl;

ZBCCL_API int32_t zbccl_torch_allocator_init(zbccl_allocator_options *options, int32_t flags)
{
    return Z_OK;
}

ZBCCL_API void zbccl_torch_allocator_uninit(int32_t flags) {}

ZBCCL_API void *zbccl_torch_malloc(ssize_t size, int32_t device, aclrtStream stream)
{
    return nullptr;
}

ZBCCL_API void zbccl_torch_free(void *ptr, ssize_t size, int32_t device, aclrtStream stream) {}
