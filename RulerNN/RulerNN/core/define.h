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

#ifndef __CORE_DEFINE_H__
#define __CORE_DEFINE_H__

#include "error.h"

// Microsoft Visual Studio
#if defined(_MSC_VER)
#define ALIGN(n)  __declspec(align(n))
// GNU GCC/G++.
#elif defined(__GNUC__) || defined(__GNUG__)
#define ALIGN(n)  __attribute__((aligned(n)))
#endif

#define CONST_ARRAY_4(x)  { (x), (x), (x), (x) }
#define CONST_ARRAY_8(x)  { (x), (x), (x), (x), (x), (x), (x), (x) }

namespace core
{
	// Copy mode
	using copy_mode_type = unsigned char;
	static constexpr copy_mode_type WITHOUT_COPY      = 0x00;                     // no copy or reference to any data
	static constexpr copy_mode_type SHALLOW_COPY      = 0x01;                     // only reference the original data
	static constexpr copy_mode_type DEEP_COPY         = 0x02;                     // copy all the original data

	// Border type
	using border_type = unsigned char;
	static constexpr border_type    BORDER_CONSTANT   = 0x00;                     // iiii|abcdefgh|iiii
	static constexpr border_type    BORDER_REPLICATE  = 0x01;                     // aaaa|abcdefgh|hhhh
	static constexpr border_type    BORDER_REFLECT    = 0x02;                     // dcba|abcdefgh|hgfe
	static constexpr border_type    BORDER_REFLECT101 = 0x03;                     // edcb|abcdefgh|gfed
	static constexpr border_type    BORDER_WRAP       = 0x04;                     // efgh|abcdefgh|abcd

	// Axis type
	using axis_type = unsigned char;
	static constexpr axis_type      AXIS_NONE         = 0x00;
	static constexpr axis_type      AXIS_X            = 0x01;                     // x-axis
	static constexpr axis_type      AXIS_Y            = 0x02;                     // y-axis
	static constexpr axis_type      AXIS_Z            = 0x04;                     // z-axis
	static constexpr axis_type      AXIS_XY           = AXIS_X | AXIS_Y;          // x-axis and y-axis
	static constexpr axis_type      AXIS_YZ           = AXIS_Y | AXIS_Z;          // y-axis and z-axis
	static constexpr axis_type      AXIS_XYZ          = AXIS_X | AXIS_Y | AXIS_Z; // x-axis, y-axis and z-axis

} // namespace core

#endif
