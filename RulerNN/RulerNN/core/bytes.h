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

#ifndef __CORE_BYTES_H__
#define __CORE_BYTES_H__

#include <cstring>
#include <string>
#include <vector>

namespace core
{
	// Class bytes
	class bytes
	{
	public:
		// converts a 8-bit signed integer to bytes
		static void to_bytes(char **ptr, signed char val)
		{
			signed char *b = reinterpret_cast<signed char*>(*ptr);
			*b = val;
			*ptr += 1;
		}

		// converts a 8-bit unsigned integer to bytes
		static void to_bytes(char **ptr, unsigned char val)
		{
			unsigned char *b = reinterpret_cast<unsigned char*>(*ptr);
			*b = val;
			*ptr += 1;
		}

		// converts a 16-bit little-endian signed integer to bytes
		static void to_little_bytes(char **ptr, signed short val)
		{
			signed short *b = reinterpret_cast<signed short*>(*ptr);
			*b = val;
			*ptr += 2;
		}

		// converts a 16-bit little-endian unsigned integer to bytes
		static void to_little_bytes(char **ptr, unsigned short val)
		{
			unsigned short *b = reinterpret_cast<unsigned short*>(*ptr);
			*b = val;
			*ptr += 2;
		}

		// converts a 32-bit little-endian signed integer to bytes
		static void to_little_bytes(char **ptr, signed int val)
		{
			signed int *b = reinterpret_cast<signed int*>(*ptr);
			*b = val;
			*ptr += 4;
		}

		// converts a 32-bit little-endian unsigned integer to bytes
		static void to_little_bytes(char **ptr, unsigned int val)
		{
			unsigned int *b = reinterpret_cast<unsigned int*>(*ptr);
			*b = val;
			*ptr += 4;
		}

		// converts a 32-bit little-endian signed integer to bytes
		static void to_little_bytes(char **ptr, signed long val)
		{
			signed long *b = reinterpret_cast<signed long*>(*ptr);
			*b = val;
			*ptr += 4;
		}

		// converts a 32-bit little-endian unsigned integer to bytes
		static void to_little_bytes(char **ptr, unsigned long val)
		{
			unsigned long *b = reinterpret_cast<unsigned long*>(*ptr);
			*b = val;
			*ptr += 4;
		}

		// converts a 64-bit little-endian signed integer to bytes
		static void to_little_bytes(char **ptr, signed long long val)
		{
			signed long long *b = reinterpret_cast<signed long long*>(*ptr);
			*b = val;
			*ptr += 8;
		}

		// converts a 64-bit little-endian unsigned integer to bytes
		static void to_little_bytes(char **ptr, unsigned long long val)
		{
			unsigned long long *b = reinterpret_cast<unsigned long long*>(*ptr);
			*b = val;
			*ptr += 8;
		}

		// converts a 32-bit little-endian floating point value to bytes
		static void to_little_bytes(char **ptr, float val)
		{
			float *b = reinterpret_cast<float*>(*ptr);
			*b = val;
			*ptr += 4;
		}

		// converts a 64-bit little-endian floating point value to bytes
		static void to_little_bytes(char **ptr, double val)
		{
			double *b = reinterpret_cast<double*>(*ptr);
			*b = val;
			*ptr += 8;
		}

		// converts a 128-bit little-endian floating point value to bytes
		static void to_little_bytes(char **ptr, long double val)
		{
			long double *b = reinterpret_cast<long double*>(*ptr);
			*b = val;
			*ptr += 16;
		}

		// converts a 16-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, signed short val)
		{
			const char *a = reinterpret_cast<const char*>(&val);
			char *b = *ptr;
			b[1] = a[0];
			b[0] = a[1];
			*ptr += 2;
		}

		// converts a 16-bit big-endian unsigned integer to bytes
		static void to_big_bytes(char **ptr, unsigned short val)
		{
			const char *a = reinterpret_cast<const char*>(&val);
			char *b = *ptr;
			b[1] = a[0];
			b[0] = a[1];
			*ptr += 2;
		}

		// converts a 32-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, signed int val)
		{
			const char *a = reinterpret_cast<const char*>(&val);
			char *b = *ptr;
			b[3] = a[0];
			b[2] = a[1];
			b[1] = a[2];
			b[0] = a[3];
			*ptr += 4;
		}

		// converts a 32-bit big-endian unsigned integer to bytes
		static void to_big_bytes(char **ptr, unsigned int val)
		{
			const char *a = reinterpret_cast<const char*>(&val);
			char *b = *ptr;
			b[3] = a[0];
			b[2] = a[1];
			b[1] = a[2];
			b[0] = a[3];
			*ptr += 4;
		}

		// converts a 32-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, signed long val)
		{
			const char *a = reinterpret_cast<const char*>(&val);
			char *b = *ptr;
			b[3] = a[0];
			b[2] = a[1];
			b[1] = a[2];
			b[0] = a[3];
			*ptr += 4;
		}

		// converts a 32-bit big-endian unsigned integer to bytes
		static void to_big_bytes(char **ptr, unsigned long val)
		{
			const char *a = reinterpret_cast<const char*>(&val);
			char *b = *ptr;
			b[3] = a[0];
			b[2] = a[1];
			b[1] = a[2];
			b[0] = a[3];
			*ptr += 4;
		}

		// converts a 64-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, signed long long val)
		{
			const char *a = reinterpret_cast<const char*>(&val);
			char *b = *ptr;
			b[7] = a[0];
			b[6] = a[1];
			b[5] = a[2];
			b[4] = a[3];
			b[3] = a[4];
			b[2] = a[5];
			b[1] = a[6];
			b[0] = a[7];
			*ptr += 8;
		}

		// converts a 64-bit big-endian unsigned integer to bytes
		static void to_big_bytes(char **ptr, unsigned long long val)
		{
			const char *a = reinterpret_cast<const char*>(&val);
			char *b = *ptr;
			b[7] = a[0];
			b[6] = a[1];
			b[5] = a[2];
			b[4] = a[3];
			b[3] = a[4];
			b[2] = a[5];
			b[1] = a[6];
			b[0] = a[7];
			*ptr += 8;
		}

		// converts a 32-bit big-endian floating point value to bytes
		static void to_big_bytes(char **ptr, float val)
		{
			const char *a = reinterpret_cast<const char*>(&val);
			char *b = *ptr;
			b[3] = a[0];
			b[2] = a[1];
			b[1] = a[2];
			b[0] = a[3];
			*ptr += 4;
		}

		// converts a 64-bit big-endian floating point value to bytes
		static void to_big_bytes(char **ptr, double val)
		{
			const char *a = reinterpret_cast<const char*>(&val);
			char *b = *ptr;
			b[7] = a[0];
			b[6] = a[1];
			b[5] = a[2];
			b[4] = a[3];
			b[3] = a[4];
			b[2] = a[5];
			b[1] = a[6];
			b[0] = a[7];
			*ptr += 8;
		}

		// converts a 128-bit big-endian floating point value to bytes
		static void to_big_bytes(char **ptr, long double val)
		{
			const char *a = reinterpret_cast<const char*>(&val);
			char *b = *ptr;
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
			*ptr += 16;
		}

		// converts a string to bytes
		static void to_bytes(char **ptr, const std::string &str)
		{
			size_t count = str.size();
			std::memcpy(*ptr, str.data(), count);
			*ptr += count;
		}

		// converts a vector of 8-bit signed integer to bytes
		static void to_bytes(char **ptr, const std::vector<signed char> &vct)
		{
			size_t count = vct.size();
			std::memcpy(*ptr, vct.data(), count);
			*ptr += count;
		}

		// converts a vector of 8-bit unsigned integer to bytes
		static void to_bytes(char **ptr, const std::vector<unsigned char> &vct)
		{
			size_t count = vct.size();
			std::memcpy(*ptr, vct.data(), count);
			*ptr += count;
		}

		// converts a little-endian wide string to bytes
		static void to_little_bytes(char **ptr, const std::wstring &str)
		{
			size_t count = str.size() << 1;
			std::memcpy(*ptr, str.data(), count);
			*ptr += count;
		}

		// converts a vector of 16-bit little-endian signed integer to bytes
		static void to_little_bytes(char **ptr, const std::vector<signed short> &vct)
		{
			size_t count = vct.size() << 1;
			std::memcpy(*ptr, vct.data(), count);
			*ptr += count;
		}

		// converts a vector of 16-bit little-endian unsigned integer to bytes
		static void to_little_bytes(char **ptr, const std::vector<unsigned short> &vct)
		{
			size_t count = vct.size() << 1;
			std::memcpy(*ptr, vct.data(), count);
			*ptr += count;
		}

		// converts a vector of 32-bit little-endian signed integer to bytes
		static void to_little_bytes(char **ptr, const std::vector<signed int> &vct)
		{
			size_t count = vct.size() << 2;
			std::memcpy(*ptr, vct.data(), count);
			*ptr += count;
		}

		// converts a vector of 32-bit little-endian unsigned integer to bytes
		static void to_little_bytes(char **ptr, const std::vector<unsigned int> &vct)
		{
			size_t count = vct.size() << 2;
			std::memcpy(*ptr, vct.data(), count);
			*ptr += count;
		}

		// converts a vector of 32-bit little-endian signed integer to bytes
		static void to_little_bytes(char **ptr, const std::vector<signed long> &vct)
		{
			size_t count = vct.size() << 2;
			std::memcpy(*ptr, vct.data(), count);
			*ptr += count;
		}

		// converts a vector of 32-bit little-endian unsigned integer to bytes
		static void to_little_bytes(char **ptr, const std::vector<unsigned long> &vct)
		{
			size_t count = vct.size() << 2;
			std::memcpy(*ptr, vct.data(), count);
			*ptr += count;
		}

		// converts a vector of 64-bit little-endian signed integer to bytes
		static void to_little_bytes(char **ptr, const std::vector<signed long long> &vct)
		{
			size_t count = vct.size() << 3;
			std::memcpy(*ptr, vct.data(), count);
			*ptr += count;
		}

		// converts a vector of 64-bit little-endian unsigned integer to bytes
		static void to_little_bytes(char **ptr, const std::vector<unsigned long long> &vct)
		{
			size_t count = vct.size() << 3;
			std::memcpy(*ptr, vct.data(), count);
			*ptr += count;
		}

		// converts a vector of 32-bit little-endian floating point value to bytes
		static void to_little_bytes(char **ptr, const std::vector<float> &vct)
		{
			size_t count = vct.size() << 2;
			std::memcpy(*ptr, vct.data(), count);
			*ptr += count;
		}

		// converts a vector of 64-bit little-endian floating point value to bytes
		static void to_little_bytes(char **ptr, const std::vector<double> &vct)
		{
			size_t count = vct.size() << 3;
			std::memcpy(*ptr, vct.data(), count);
			*ptr += count;
		}

		// converts a vector of 128-bit little-endian floating point value to bytes
		static void to_little_bytes(char **ptr, const std::vector<long double> &vct)
		{
			size_t count = vct.size() << 4;
			std::memcpy(*ptr, vct.data(), count);
			*ptr += count;
		}

		// converts a big-endian wide string to bytes
		static void to_big_bytes(char **ptr, const std::wstring &str)
		{
			size_t count = str.size() << 1;
			const char *a = reinterpret_cast<const char*>(str.data());
			char *b = *ptr;
			for (size_t i = 0; i < count; i += 2)
			{
				b[i + 1] = a[i];
				b[i]     = a[i + 1];
			}
			*ptr += count;
		}

		// converts a vector of 16-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, const std::vector<signed short> &vct)
		{
			size_t count = vct.size() << 1;
			const char *a = reinterpret_cast<const char*>(vct.data());
			char *b = *ptr;
			for (size_t i = 0; i < count; i += 2)
			{
				b[i + 1] = a[i];
				b[i]     = a[i + 1];
			}
			*ptr += count;
		}

		// converts a vector of 16-bit big-endian unsigned integer to bytes
		static void to_big_bytes(char **ptr, const std::vector<unsigned short> &vct)
		{
			size_t count = vct.size() << 1;
			const char *a = reinterpret_cast<const char*>(vct.data());
			char *b = *ptr;
			for (size_t i = 0; i < count; i += 2)
			{
				b[i + 1] = a[i];
				b[i] = a[i + 1];
			}
			*ptr += count;
		}

		// converts a vector of 32-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, const std::vector<signed int> &vct)
		{
			size_t count = vct.size() << 2;
			const char *a = reinterpret_cast<const char*>(vct.data());
			char *b = *ptr;
			for (size_t i = 0; i < count; i += 4)
			{
				b[i + 3] = a[i];
				b[i + 2] = a[i + 1];
				b[i + 1] = a[i + 2];
				b[i]     = a[i + 3];
			}
			*ptr += count;
		}

		// converts a vector of 32-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, const std::vector<unsigned int> &vct)
		{
			size_t count = vct.size() << 2;
			const char *a = reinterpret_cast<const char*>(vct.data());
			char *b = *ptr;
			for (size_t i = 0; i < count; i += 4)
			{
				b[i + 3] = a[i];
				b[i + 2] = a[i + 1];
				b[i + 1] = a[i + 2];
				b[i] = a[i + 3];
			}
			*ptr += count;
		}

		// converts a vector of 32-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, const std::vector<signed long> &vct)
		{
			size_t count = vct.size() << 2;
			const char *a = reinterpret_cast<const char*>(vct.data());
			char *b = *ptr;
			for (size_t i = 0; i < count; i += 4)
			{
				b[i + 3] = a[i];
				b[i + 2] = a[i + 1];
				b[i + 1] = a[i + 2];
				b[i]     = a[i + 3];
			}
			*ptr += count;
		}

		// converts a vector of 32-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, const std::vector<unsigned long> &vct)
		{
			size_t count = vct.size() << 2;
			const char *a = reinterpret_cast<const char*>(vct.data());
			char *b = *ptr;
			for (size_t i = 0; i < count; i += 4)
			{
				b[i + 3] = a[i];
				b[i + 2] = a[i + 1];
				b[i + 1] = a[i + 2];
				b[i]     = a[i + 3];
			}
			*ptr += count;
		}

		// converts a vector of 128-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, const std::vector<signed long long> &vct)
		{
			size_t count = vct.size() << 3;
			const char *a = reinterpret_cast<const char*>(vct.data());
			char *b = *ptr;
			for (size_t i = 0; i < count; i += 8)
			{
				b[i + 7] = a[i];
				b[i + 6] = a[i + 1];
				b[i + 5] = a[i + 2];
				b[i + 4] = a[i + 3];
				b[i + 3] = a[i + 4];
				b[i + 2] = a[i + 5];
				b[i + 1] = a[i + 6];
				b[i]     = a[i + 7];
			}
			*ptr += count;
		}

		// converts a vector of 128-bit big-endian unsigned integer to bytes
		static void to_big_bytes(char **ptr, const std::vector<unsigned long long> &vct)
		{
			size_t count = vct.size() << 3;
			const char *a = reinterpret_cast<const char*>(vct.data());
			char *b = *ptr;
			for (size_t i = 0; i < count; i += 8)
			{
				b[i + 7] = a[i];
				b[i + 6] = a[i + 1];
				b[i + 5] = a[i + 2];
				b[i + 4] = a[i + 3];
				b[i + 3] = a[i + 4];
				b[i + 2] = a[i + 5];
				b[i + 1] = a[i + 6];
				b[i]     = a[i + 7];
			}
			*ptr += count;
		}

		// converts a vector of 32-bit big-endian floating point value to bytes
		static void to_big_bytes(char **ptr, const std::vector<float> &vct)
		{
			size_t count = vct.size() << 2;
			const char *a = reinterpret_cast<const char*>(vct.data());
			char *b = *ptr;
			for (size_t i = 0; i < count; i += 4)
			{
				b[i + 3] = a[i];
				b[i + 2] = a[i + 1];
				b[i + 1] = a[i + 2];
				b[i]     = a[i + 3];
			}
			*ptr += count;
		}

		// converts a vector of 64-bit big-endian floating point value to bytes
		static void to_big_bytes(char **ptr, const std::vector<double> &vct)
		{
			size_t count = vct.size() << 3;
			const char *a = reinterpret_cast<const char*>(vct.data());
			char *b = *ptr;
			for (size_t i = 0; i < count; i += 8)
			{
				b[i + 7] = a[i];
				b[i + 6] = a[i + 1];
				b[i + 5] = a[i + 2];
				b[i + 4] = a[i + 3];
				b[i + 3] = a[i + 4];
				b[i + 2] = a[i + 5];
				b[i + 1] = a[i + 6];
				b[i]     = a[i + 7];
			}
			*ptr += count;
		}

		// converts a vector of 128-bit big-endian floating point value to bytes
		static void to_big_bytes(char **ptr, const std::vector<long double> &vct)
		{
			size_t count = vct.size() << 4;
			const char *a = reinterpret_cast<const char*>(vct.data());
			char *b = *ptr;
			for (size_t i = 0; i < count; i += 16)
			{
				b[i + 15] = a[i];
				b[i + 14] = a[i + 1];
				b[i + 13] = a[i + 2];
				b[i + 12] = a[i + 3];
				b[i + 11] = a[i + 4];
				b[i + 10] = a[i + 5];
				b[i + 9]  = a[i + 6];
				b[i + 8]  = a[i + 7];
				b[i + 7]  = a[i + 8];
				b[i + 6]  = a[i + 9];
				b[i + 5]  = a[i + 10];
				b[i + 4]  = a[i + 11];
				b[i + 3]  = a[i + 12];
				b[i + 2]  = a[i + 13];
				b[i + 1]  = a[i + 14];
				b[i]      = a[i + 15];
			}
			*ptr += count;
		}

		// converts 1 byte to a 8-bit signed integer
		static signed char to_char(const char **ptr)
		{
			const signed char *a = reinterpret_cast<const signed char*>(*ptr);
			*ptr += 1;
			return (*a);
		}

		// converts 1 byte to a 8-bit unsigned integer
		static unsigned char to_uchar(const char **ptr)
		{
			const unsigned char *a = reinterpret_cast<const unsigned char*>(*ptr);
			*ptr += 1;
			return (*a);
		}

		// converts 2 bytes to a 16-bit little-endian signed integer
		static signed short to_little_short(const char **ptr)
		{
			const signed short *a = reinterpret_cast<const signed short*>(*ptr);
			*ptr += 2;
			return (*a);
		}

		// converts 2 bytes to a 16-bit little-endian unsigned integer
		static unsigned short to_little_ushort(const char **ptr)
		{
			const unsigned short *a = reinterpret_cast<const unsigned short*>(*ptr);
			*ptr += 2;
			return (*a);
		}

		// converts 4 bytes to a 32-bit little-endian signed integer
		static signed int to_little_int(const char **ptr)
		{
			const signed int *a = reinterpret_cast<const signed int*>(*ptr);
			*ptr += 4;
			return (*a);
		}

		// converts 4 bytes to a 32-bit little-endian unsigned integer
		static unsigned int to_little_uint(const char **ptr)
		{
			const unsigned int *a = reinterpret_cast<const unsigned int*>(*ptr);
			*ptr += 4;
			return (*a);
		}

		// converts 4 bytes to a 32-bit little-endian signed integer
		static signed long to_little_long(const char **ptr)
		{
			const signed long *a = reinterpret_cast<const signed long*>(*ptr);
			*ptr += 4;
			return (*a);
		}

		// converts 4 bytes to a 32-bit little-endian unsigned integer
		static unsigned long to_little_ulong(const char **ptr)
		{
			const unsigned long *a = reinterpret_cast<const unsigned long*>(*ptr);
			*ptr += 4;
			return (*a);
		}

		// converts 8 bytes to a 64-bit little-endian signed integer
		static signed long long to_little_longlong(const char **ptr)
		{
			const signed long long *a = reinterpret_cast<const signed long long*>(*ptr);
			*ptr += 8;
			return (*a);
		}

		// converts 8 bytes to a 64-bit little-endian unsigned integer
		static unsigned long long to_little_ulonglong(const char **ptr)
		{
			const unsigned long long *a = reinterpret_cast<const unsigned long long*>(*ptr);
			*ptr += 8;
			return (*a);
		}

		// converts 4 bytes to a 32-bit little-endian floating point value
		static float to_little_float(const char **ptr)
		{
			const float *a = reinterpret_cast<const float*>(*ptr);
			*ptr += 4;
			return (*a);
		}

		// converts 8 bytes to a 64-bit little-endian floating point value
		static double to_little_double(const char **ptr)
		{
			const double *a = reinterpret_cast<const double*>(*ptr);
			*ptr += 8;
			return (*a);
		}

		// converts 16 bytes to a 128-bit little-endian floating point value
		static long double to_little_longdouble(const char **ptr)
		{
			const long double *a = reinterpret_cast<const long double*>(*ptr);
			*ptr += 16;
			return (*a);
		}

		// converts bytes to a string
		static std::string to_string(const char **ptr, size_t count)
		{
			const char *first = *ptr;
			const char *last = *ptr + count;
			*ptr += count;
			return std::string(first, last);
		}

		// converts bytes to a wide string
		static std::wstring to_wstring(const char **ptr, size_t count)
		{
			std::wstring str;
			str.resize(count);
			const char *a = *ptr;
			wchar_t *b = const_cast<wchar_t*>(str.data());
			for (size_t i = 0; i < count; ++i)
				b[i] = static_cast<wchar_t>(a[i]);
			*ptr += count;
			return str;
		}

		// converts bytes to a vector of 8-bit signed integer
		static std::vector<signed char> to_char(const char **ptr, size_t count)
		{
			const signed char *first = reinterpret_cast<const signed char*>(*ptr);
			const signed char *last = reinterpret_cast<const signed char*>(*ptr + count);
			*ptr += count;
			return std::vector<signed char>(first, last);
		}

		// converts bytes to a vector of 8-bit unsigned integer
		static std::vector<unsigned char> to_uchar(const char **ptr, size_t count)
		{
			const unsigned char *first = reinterpret_cast<const unsigned char*>(*ptr);
			const unsigned char *last = reinterpret_cast<const unsigned char*>(*ptr + count);
			*ptr += count;
			return std::vector<unsigned char>(first, last);
		}

		// converts bytes to a little-endian wide string
		static std::wstring to_little_wstring(const char **ptr, size_t count)
		{
			const wchar_t *first = reinterpret_cast<const wchar_t*>(*ptr);
			const wchar_t *last = reinterpret_cast<const wchar_t*>(*ptr + count);
			*ptr += count;
			return std::wstring(first, last);
		}

		// converts bytes to a vector of 16-bit little-endian signed integer
		static std::vector<signed short> to_little_short(const char **ptr, size_t count)
		{
			const signed short *first = reinterpret_cast<const signed short*>(*ptr);
			const signed short *last = reinterpret_cast<const signed short*>(*ptr + count);
			*ptr += count;
			return std::vector<signed short>(first, last);
		}

		// converts bytes to a vector of 16-bit little-endian unsigned integer
		static std::vector<unsigned short> to_little_ushort(const char **ptr, size_t count)
		{
			const unsigned short *first = reinterpret_cast<const unsigned short*>(*ptr);
			const unsigned short *last = reinterpret_cast<const unsigned short*>(*ptr + count);
			*ptr += count;
			return std::vector<unsigned short>(first, last);
		}

		// converts bytes to a vector of 32-bit little-endian signed integer
		static std::vector<signed int> to_little_int(const char **ptr, size_t count)
		{
			const signed int *first = reinterpret_cast<const signed int*>(*ptr);
			const signed int *last = reinterpret_cast<const signed int*>(*ptr + count);
			*ptr += count;
			return std::vector<signed int>(first, last);
		}

		// converts bytes to a vector of 32-bit little-endian unsigned integer
		static std::vector<unsigned int> to_little_uint(const char **ptr, size_t count)
		{
			const unsigned int *first = reinterpret_cast<const unsigned int*>(*ptr);
			const unsigned int *last = reinterpret_cast<const unsigned int*>(*ptr + count);
			*ptr += count;
			return std::vector<unsigned int>(first, last);
		}

		// converts bytes to a vector of 32-bit little-endian signed integer
		static std::vector<signed long> to_little_long(const char **ptr, size_t count)
		{
			const signed long *first = reinterpret_cast<const signed long*>(*ptr);
			const signed long *last = reinterpret_cast<const signed long*>(*ptr + count);
			*ptr += count;
			return std::vector<signed long>(first, last);
		}

		// converts bytes to a vector of 32-bit little-endian unsigned integer
		static std::vector<unsigned long> to_little_ulong(const char **ptr, size_t count)
		{
			const unsigned long *first = reinterpret_cast<const unsigned long*>(*ptr);
			const unsigned long *last = reinterpret_cast<const unsigned long*>(*ptr + count);
			*ptr += count;
			return std::vector<unsigned long>(first, last);
		}

		// converts bytes to a vector of 64-bit little-endian signed integer
		static std::vector<signed long long> to_little_longlong(const char **ptr, size_t count)
		{
			const signed long long *first = reinterpret_cast<const signed long long*>(*ptr);
			const signed long long *last = reinterpret_cast<const signed long long*>(*ptr + count);
			*ptr += count;
			return std::vector<signed long long>(first, last);
		}

		// converts bytes to a vector of 64-bit little-endian unsigned integer
		static std::vector<unsigned long long> to_little_ulonglong(const char **ptr, size_t count)
		{
			const unsigned long long *first = reinterpret_cast<const unsigned long long*>(*ptr);
			const unsigned long long *last = reinterpret_cast<const unsigned long long*>(*ptr + count);
			*ptr += count;
			return std::vector<unsigned long long>(first, last);
		}

		// converts bytes to a vector of 32-bit little-endian floating point value
		static std::vector<float> to_little_float(const char **ptr, size_t count)
		{
			const float *first = reinterpret_cast<const float*>(*ptr);
			const float *last = reinterpret_cast<const float*>(*ptr + count);
			*ptr += count;
			return std::vector<float>(first, last);
		}

		// converts bytes to a vector of 64-bit little-endian floating point value
		static std::vector<double> to_little_double(const char **ptr, size_t count)
		{
			const double *first = reinterpret_cast<const double*>(*ptr);
			const double *last = reinterpret_cast<const double*>(*ptr + count);
			*ptr += count;
			return std::vector<double>(first, last);
		}

		// converts bytes to a vector of 128-bit little-endian floating point value
		static std::vector<long double> to_little_longdouble(const char **ptr, size_t count)
		{
			const long double *first = reinterpret_cast<const long double*>(*ptr);
			const long double *last = reinterpret_cast<const long double*>(*ptr + count);
			*ptr += count;
			return std::vector<long double>(first, last);
		}

		// converts 2 bytes to a 16-bit big-endian signed integer
		static signed short to_big_short(const char **ptr)
		{
			signed short val;
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(&val);
			b[1] = a[0];
			b[0] = a[1];
			*ptr += 2;
			return val;
		}

		// converts 2 bytes to a 16-bit big-endian unsigned integer
		static unsigned short to_big_ushort(const char **ptr)
		{
			unsigned short val;
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(&val);
			b[1] = a[0];
			b[0] = a[1];
			*ptr += 2;
			return val;
		}

		// converts 4 bytes to a 32-bit big-endian signed integer
		static signed int to_big_int(const char **ptr)
		{
			signed int val;
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(&val);
			b[3] = a[0];
			b[2] = a[1];
			b[1] = a[2];
			b[0] = a[3];
			*ptr += 4;
			return val;
		}

		// converts 4 bytes to a 32-bit big-endian unsigned integer
		static unsigned int to_big_uint(const char **ptr)
		{
			unsigned int val;
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(&val);
			b[3] = a[0];
			b[2] = a[1];
			b[1] = a[2];
			b[0] = a[3];
			*ptr += 4;
			return val;
		}

		// converts 4 bytes to a 32-bit big-endian signed integer
		static signed long to_big_long(const char **ptr)
		{
			signed long val;
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(&val);
			b[3] = a[0];
			b[2] = a[1];
			b[1] = a[2];
			b[0] = a[3];
			*ptr += 4;
			return val;
		}

		// converts 4 bytes to a 32-bit big-endian unsigned integer
		static unsigned long to_big_ulong(const char **ptr)
		{
			unsigned long val;
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(&val);
			b[3] = a[0];
			b[2] = a[1];
			b[1] = a[2];
			b[0] = a[3];
			*ptr += 4;
			return val;
		}

		// converts 8 bytes to a 64-bit big-endian signed integer
		static signed long long to_big_longlong(const char **ptr)
		{
			signed long long val;
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(&val);
			b[7] = a[0];
			b[6] = a[1];
			b[5] = a[2];
			b[4] = a[3];
			b[3] = a[4];
			b[2] = a[5];
			b[1] = a[6];
			b[0] = a[7];
			*ptr += 8;
			return val;
		}

		// converts 8 bytes to a 64-bit big-endian unsigned integer
		static unsigned long long to_big_ulonglong(const char **ptr)
		{
			unsigned long long val;
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(&val);
			b[7] = a[0];
			b[6] = a[1];
			b[5] = a[2];
			b[4] = a[3];
			b[3] = a[4];
			b[2] = a[5];
			b[1] = a[6];
			b[0] = a[7];
			*ptr += 8;
			return val;
		}

		// converts 4 bytes to a 32-bit big-endian floating point value
		static float to_big_float(const char **ptr)
		{
			float val;
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(&val);
			b[3] = a[0];
			b[2] = a[1];
			b[1] = a[2];
			b[0] = a[3];
			*ptr += 4;
			return val;
		}

		// converts 8 bytes to a 64-bit big-endian floating point value
		static double to_big_double(const char **ptr)
		{
			double val;
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(&val);
			b[7] = a[0];
			b[6] = a[1];
			b[5] = a[2];
			b[4] = a[3];
			b[3] = a[4];
			b[2] = a[5];
			b[1] = a[6];
			b[0] = a[7];
			*ptr += 8;
			return val;
		}

		// converts 16 bytes to a 128-bit big-endian floating point value
		static long double to_big_longdouble(const char **ptr)
		{
			long double val;
			const char *a = *ptr;
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
			*ptr += 16;
			return val;
		}

		// converts bytes to a big-endian wide string
		static std::wstring to_big_wstring(const char **ptr, size_t count)
		{
			std::wstring str;
			str.resize(count >> 1);
			const char *a = *ptr;
			char *b = const_cast<char*>(reinterpret_cast<const char*>(str.data()));
			for (size_t i = 0; i < count; i += 2)
			{
				b[i + 1] = a[i];
				b[i]     = a[i + 1];
			}
			*ptr += count;
			return str;
		}

		// converts bytes to a vector of 16-bit big-endian signed integer
		static std::vector<signed short> to_big_short(const char **ptr, size_t count)
		{
			std::vector<signed short> vct(count >> 1);
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 2)
			{
				b[i + 1] = a[i];
				b[i]     = a[i + 1];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 16-bit big-endian unsigned integer
		static std::vector<unsigned short> to_big_ushort(const char **ptr, size_t count)
		{
			std::vector<unsigned short> vct(count >> 1);
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 2)
			{
				b[i + 1] = a[i];
				b[i]     = a[i + 1];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 32-bit big-endian signed integer
		static std::vector<signed int> to_big_int(const char **ptr, size_t count)
		{
			std::vector<signed int> vct(count >> 2);
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 4)
			{
				b[i + 3] = a[i];
				b[i + 2] = a[i + 1];
				b[i + 1] = a[i + 2];
				b[i]     = a[i + 3];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 32-bit big-endian unsigned integer
		static std::vector<unsigned int> to_big_uint(const char **ptr, size_t count)
		{
			std::vector<unsigned int> vct(count >> 2);
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 4)
			{
				b[i + 3] = a[i];
				b[i + 2] = a[i + 1];
				b[i + 1] = a[i + 2];
				b[i]     = a[i + 3];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 32-bit big-endian signed integer
		static std::vector<signed long> to_big_long(const char **ptr, size_t count)
		{
			std::vector<signed long> vct(count >> 2);
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 4)
			{
				b[i + 3] = a[i];
				b[i + 2] = a[i + 1];
				b[i + 1] = a[i + 2];
				b[i]     = a[i + 3];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 32-bit big-endian unsigned integer
		static std::vector<unsigned long> to_big_ulong(const char **ptr, size_t count)
		{
			std::vector<unsigned long> vct(count >> 2);
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 4)
			{
				b[i + 3] = a[i];
				b[i + 2] = a[i + 1];
				b[i + 1] = a[i + 2];
				b[i]     = a[i + 3];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 64-bit big-endian signed integer
		static std::vector<signed long long> to_big_longlong(const char **ptr, size_t count)
		{
			std::vector<signed long long> vct(count >> 3);
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 8)
			{
				b[i + 7] = a[i];
				b[i + 6] = a[i + 1];
				b[i + 5] = a[i + 2];
				b[i + 4] = a[i + 3];
				b[i + 3] = a[i + 4];
				b[i + 2] = a[i + 5];
				b[i + 1] = a[i + 6];
				b[i]     = a[i + 7];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 64-bit big-endian unsigned integer
		static std::vector<unsigned long long> to_big_ulonglong(const char **ptr, size_t count)
		{
			std::vector<unsigned long long> vct(count >> 3);
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 8)
			{
				b[i + 7] = a[i];
				b[i + 6] = a[i + 1];
				b[i + 5] = a[i + 2];
				b[i + 4] = a[i + 3];
				b[i + 3] = a[i + 4];
				b[i + 2] = a[i + 5];
				b[i + 1] = a[i + 6];
				b[i]     = a[i + 7];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 32-bit big-endian floating point value
		static std::vector<float> to_big_float(const char **ptr, size_t count)
		{
			std::vector<float> vct(count >> 2);
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 4)
			{
				b[i + 3] = a[i];
				b[i + 2] = a[i + 1];
				b[i + 1] = a[i + 2];
				b[i]     = a[i + 3];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 64-bit big-endian floating point value
		static std::vector<double> to_big_double(const char **ptr, size_t count)
		{
			std::vector<double> vct(count >> 3);
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 8)
			{
				b[i + 7] = a[i];
				b[i + 6] = a[i + 1];
				b[i + 5] = a[i + 2];
				b[i + 4] = a[i + 3];
				b[i + 3] = a[i + 4];
				b[i + 2] = a[i + 5];
				b[i + 1] = a[i + 6];
				b[i]     = a[i + 7];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 128-bit big-endian floating point value
		static std::vector<long double> to_big_longdouble(const char **ptr, size_t count)
		{
			std::vector<long double> vct(count >> 4);
			const char *a = *ptr;
			char *b = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 16)
			{
				b[i + 15] = a[i];
				b[i + 14] = a[i + 1];
				b[i + 13] = a[i + 2];
				b[i + 12] = a[i + 3];
				b[i + 11] = a[i + 4];
				b[i + 10] = a[i + 5];
				b[i + 9]  = a[i + 6];
				b[i + 8]  = a[i + 7];
				b[i + 7]  = a[i + 8];
				b[i + 6]  = a[i + 9];
				b[i + 5]  = a[i + 10];
				b[i + 4]  = a[i + 11];
				b[i + 3]  = a[i + 12];
				b[i + 2]  = a[i + 13];
				b[i + 1]  = a[i + 14];
				b[i]      = a[i + 15];
			}
			*ptr += count;
			return vct;
		}

	};

} // namespace core

#endif
