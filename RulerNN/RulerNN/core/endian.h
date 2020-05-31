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

#ifndef __CORE_ENDIAN_H__
#define __CORE_ENDIAN_H__

namespace core
{
	// Class endian
	class endian
	{
	public:
		// reverse byte order for 16-bit signed integer
		static signed short bswap_short(signed short x)
		{
			signed short val;
			char *src = reinterpret_cast<char*>(&x);
			char *dst = reinterpret_cast<char*>(&val);
			dst[1] = src[0];
			dst[0] = src[1];
			return val;
		}

		// reverse byte order for 16-bit unsigned integer
		static unsigned short bswap_ushort(unsigned short x)
		{
			unsigned short val;
			char *src = reinterpret_cast<char*>(&x);
			char *dst = reinterpret_cast<char*>(&val);
			dst[1] = src[0];
			dst[0] = src[1];
			return val;
		}

		// reverse byte order for 32-bit signed integer
		static signed int bswap_int(signed int x)
		{
			signed int val;
			char *src = reinterpret_cast<char*>(&x);
			char *dst = reinterpret_cast<char*>(&val);
			dst[3] = src[0];
			dst[2] = src[1];
			dst[1] = src[2];
			dst[0] = src[3];
			return val;
		}

		// reverse byte order for 32-bit unsigned integer
		static unsigned int bswap_uint(unsigned int x)
		{
			unsigned int val;
			char *src = reinterpret_cast<char*>(&x);
			char *dst = reinterpret_cast<char*>(&val);
			dst[3] = src[0];
			dst[2] = src[1];
			dst[1] = src[2];
			dst[0] = src[3];
			return val;
		}

		// reverse byte order for 32-bit signed integer
		static signed long bswap_long(signed long x)
		{
			signed long val;
			char *src = reinterpret_cast<char*>(&x);
			char *dst = reinterpret_cast<char*>(&val);
			dst[3] = src[0];
			dst[2] = src[1];
			dst[1] = src[2];
			dst[0] = src[3];
			return val;
		}

		// reverse byte order for 32-bit unsigned integer
		static unsigned long bswap_long(unsigned long x)
		{
			unsigned long val;
			char *src = reinterpret_cast<char*>(&x);
			char *dst = reinterpret_cast<char*>(&val);
			dst[3] = src[0];
			dst[2] = src[1];
			dst[1] = src[2];
			dst[0] = src[3];
			return val;
		}

		// reverse byte order for 64-bit signed integer
		static signed long long bswap_long(signed long long x)
		{
			signed long long val;
			char *src = reinterpret_cast<char*>(&x);
			char *dst = reinterpret_cast<char*>(&val);
			dst[7] = src[0];
			dst[6] = src[1];
			dst[5] = src[2];
			dst[4] = src[3];
			dst[3] = src[4];
			dst[2] = src[5];
			dst[1] = src[6];
			dst[0] = src[7];
			return val;
		}

		// reverse byte order for 64-bit unsigned integer
		static unsigned long long bswap_long(unsigned long long x)
		{
			unsigned long long val;
			char *src = reinterpret_cast<char*>(&x);
			char *dst = reinterpret_cast<char*>(&val);
			dst[7] = src[0];
			dst[6] = src[1];
			dst[5] = src[2];
			dst[4] = src[3];
			dst[3] = src[4];
			dst[2] = src[5];
			dst[1] = src[6];
			dst[0] = src[7];
			return val;
		}

		// reverse byte order for 32-bit floating point value
		static float bswap_float(float x)
		{
			float val;
			char *src = reinterpret_cast<char*>(&x);
			char *dst = reinterpret_cast<char*>(&val);
			dst[3] = src[0];
			dst[2] = src[1];
			dst[1] = src[2];
			dst[0] = src[3];
			return val;
		}

		// reverse byte order for 64-bit floating point value
		static double bswap_double(double x)
		{
			double val;
			char *src = reinterpret_cast<char*>(&x);
			char *dst = reinterpret_cast<char*>(&val);
			dst[7] = src[0];
			dst[6] = src[1];
			dst[5] = src[2];
			dst[4] = src[3];
			dst[3] = src[4];
			dst[2] = src[5];
			dst[1] = src[6];
			dst[0] = src[7];
			return val;
		}

		// reverse byte order for 128-bit floating point value
		static long double bswap_longdouble(long double x)
		{
			long double val;
			char *src = reinterpret_cast<char*>(&x);
			char *dst = reinterpret_cast<char*>(&val);
			dst[15] = src[0];
			dst[14] = src[1];
			dst[13] = src[2];
			dst[12] = src[3];
			dst[11] = src[4];
			dst[10] = src[5];
			dst[9]  = src[6];
			dst[8]  = src[7];
			dst[7]  = src[8];
			dst[6]  = src[9];
			dst[5]  = src[10];
			dst[4]  = src[11];
			dst[3]  = src[12];
			dst[2]  = src[13];
			dst[1]  = src[14];
			dst[0]  = src[15];
			return val;
		}
	};

} // namespace core

#endif
