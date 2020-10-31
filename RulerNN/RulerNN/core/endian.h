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
			char *a = reinterpret_cast<char*>(&x);
			char *b = reinterpret_cast<char*>(&val);
			b[1] = a[0];
			b[0] = a[1];
			return val;
		}

		// reverse byte order for 16-bit unsigned integer
		static unsigned short bswap_ushort(unsigned short x)
		{
			unsigned short val;
			char *a = reinterpret_cast<char*>(&x);
			char *b = reinterpret_cast<char*>(&val);
			b[1] = a[0];
			b[0] = a[1];
			return val;
		}

		// reverse byte order for 32-bit signed integer
		static signed int bswap_int(signed int x)
		{
			signed int val;
			char *a = reinterpret_cast<char*>(&x);
			char *b = reinterpret_cast<char*>(&val);
			b[3] = a[0];
			b[2] = a[1];
			b[1] = a[2];
			b[0] = a[3];
			return val;
		}

		// reverse byte order for 32-bit unsigned integer
		static unsigned int bswap_uint(unsigned int x)
		{
			unsigned int val;
			char *a = reinterpret_cast<char*>(&x);
			char *b = reinterpret_cast<char*>(&val);
			b[3] = a[0];
			b[2] = a[1];
			b[1] = a[2];
			b[0] = a[3];
			return val;
		}

		// reverse byte order for 32-bit signed integer
		static signed long bswap_long(signed long x)
		{
			signed long val;
			char *a = reinterpret_cast<char*>(&x);
			char *b = reinterpret_cast<char*>(&val);
			b[3] = a[0];
			b[2] = a[1];
			b[1] = a[2];
			b[0] = a[3];
			return val;
		}

		// reverse byte order for 32-bit unsigned integer
		static unsigned long bswap_long(unsigned long x)
		{
			unsigned long val;
			char *a = reinterpret_cast<char*>(&x);
			char *b = reinterpret_cast<char*>(&val);
			b[3] = a[0];
			b[2] = a[1];
			b[1] = a[2];
			b[0] = a[3];
			return val;
		}

		// reverse byte order for 64-bit signed integer
		static signed long long bswap_long(signed long long x)
		{
			signed long long val;
			char *a = reinterpret_cast<char*>(&x);
			char *b = reinterpret_cast<char*>(&val);
			b[7] = a[0];
			b[6] = a[1];
			b[5] = a[2];
			b[4] = a[3];
			b[3] = a[4];
			b[2] = a[5];
			b[1] = a[6];
			b[0] = a[7];
			return val;
		}

		// reverse byte order for 64-bit unsigned integer
		static unsigned long long bswap_long(unsigned long long x)
		{
			unsigned long long val;
			char *a = reinterpret_cast<char*>(&x);
			char *b = reinterpret_cast<char*>(&val);
			b[7] = a[0];
			b[6] = a[1];
			b[5] = a[2];
			b[4] = a[3];
			b[3] = a[4];
			b[2] = a[5];
			b[1] = a[6];
			b[0] = a[7];
			return val;
		}

		// reverse byte order for 32-bit floating point value
		static float bswap_float(float x)
		{
			float val;
			char *a = reinterpret_cast<char*>(&x);
			char *b = reinterpret_cast<char*>(&val);
			b[3] = a[0];
			b[2] = a[1];
			b[1] = a[2];
			b[0] = a[3];
			return val;
		}

		// reverse byte order for 64-bit floating point value
		static double bswap_double(double x)
		{
			double val;
			char *a = reinterpret_cast<char*>(&x);
			char *b = reinterpret_cast<char*>(&val);
			b[7] = a[0];
			b[6] = a[1];
			b[5] = a[2];
			b[4] = a[3];
			b[3] = a[4];
			b[2] = a[5];
			b[1] = a[6];
			b[0] = a[7];
			return val;
		}

		// reverse byte order for 128-bit floating point value
		static long double bswap_longdouble(long double x)
		{
			long double val;
			char *a = reinterpret_cast<char*>(&x);
			char *b = reinterpret_cast<char*>(&val);
			b[15] = a[0];
			b[14] = a[1];
			b[13] = a[2];
			b[12] = a[3];
			b[11] = a[4];
			b[10] = a[5];
			b[9]  = a[6];
			b[8]  = a[7];
			b[7]  = a[8];
			b[6]  = a[9];
			b[5]  = a[10];
			b[4]  = a[11];
			b[3]  = a[12];
			b[2]  = a[13];
			b[1]  = a[14];
			b[0]  = a[15];
			return val;
		}
	};

} // namespace core

#endif
