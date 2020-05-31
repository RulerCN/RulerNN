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

#ifndef __CORE_CPU_ERROR_H__
#define __CORE_CPU_ERROR_H__

#include "../error.h"

namespace core
{
	// domain_error
	static constexpr char NO_SUPPORT_AVX2[]  = "Your CPU does not support AVX2 instructions.";
	static constexpr char NO_SUPPORT_AVX[]   = "Your CPU does not support AVX instructions.";
	static constexpr char NO_SUPPORT_SSE42[] = "Your CPU does not support SSE4.2 instructions.";
	static constexpr char NO_SUPPORT_SSE41[] = "Your CPU does not support SSE4.1 instructions.";
	static constexpr char NO_SUPPORT_SSSE3[] = "Your CPU does not support SSSE3 instructions.";
	static constexpr char NO_SUPPORT_SSE3[]  = "Your CPU does not support SSE3 instructions.";
	static constexpr char NO_SUPPORT_SSE2[]  = "Your CPU does not support SSE2 instructions.";
	static constexpr char NO_SUPPORT_SSE[]   = "Your CPU does not support SSE instructions.";

} // namespace core

#endif
