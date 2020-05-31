/*====================================================================
BSD 2-Clause License

Copyright (c) 2020, Ruler
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
====================================================================*/
#pragma once

#ifndef __CORE_H__
#define __CORE_H__

// Default allocator
#ifndef DEFAULT_ALLOCATOR
#define DEFAULT_ALLOCATOR(T) core::aligned_allocator<T, 32>
#endif // !DEFAULT_ALLOCATOR

// CPU L2 cache
#ifndef L2_CACHE_SIZE
#define L2_CACHE_SIZE 0x00200000
#endif // !CPU_L2_CACHE

#include "allocator.h"
#include "aligned_allocator.h"
#include "sample_allocator.h"
#include "rb_tree.h"
#include "tree.h"
#include "scalar.h"
#include "vector.h"
#include "matrix.h"
#include "tensor.h"
#include "bytes.h"
#include "endian.h"
#include "string.h"
#include "wstring.h"

#include "openmp.h"
//#include "cpu.h"

#endif
