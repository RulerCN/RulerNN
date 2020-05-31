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
			signed char *dst = reinterpret_cast<signed char*>(*ptr);
			*dst = val;
			*ptr += 1;
		}

		// converts a 8-bit unsigned integer to bytes
		static void to_bytes(char **ptr, unsigned char val)
		{
			unsigned char *dst = reinterpret_cast<unsigned char*>(*ptr);
			*dst = val;
			*ptr += 1;
		}

		// converts a 16-bit little-endian signed integer to bytes
		static void to_little_bytes(char **ptr, signed short val)
		{
			signed short *dst = reinterpret_cast<signed short*>(*ptr);
			*dst = val;
			*ptr += 2;
		}

		// converts a 16-bit little-endian unsigned integer to bytes
		static void to_little_bytes(char **ptr, unsigned short val)
		{
			unsigned short *dst = reinterpret_cast<unsigned short*>(*ptr);
			*dst = val;
			*ptr += 2;
		}

		// converts a 32-bit little-endian signed integer to bytes
		static void to_little_bytes(char **ptr, signed int val)
		{
			signed int *dst = reinterpret_cast<signed int*>(*ptr);
			*dst = val;
			*ptr += 4;
		}

		// converts a 32-bit little-endian unsigned integer to bytes
		static void to_little_bytes(char **ptr, unsigned int val)
		{
			unsigned int *dst = reinterpret_cast<unsigned int*>(*ptr);
			*dst = val;
			*ptr += 4;
		}

		// converts a 32-bit little-endian signed integer to bytes
		static void to_little_bytes(char **ptr, signed long val)
		{
			signed long *dst = reinterpret_cast<signed long*>(*ptr);
			*dst = val;
			*ptr += 4;
		}

		// converts a 32-bit little-endian unsigned integer to bytes
		static void to_little_bytes(char **ptr, unsigned long val)
		{
			unsigned long *dst = reinterpret_cast<unsigned long*>(*ptr);
			*dst = val;
			*ptr += 4;
		}

		// converts a 64-bit little-endian signed integer to bytes
		static void to_little_bytes(char **ptr, signed long long val)
		{
			signed long long *dst = reinterpret_cast<signed long long*>(*ptr);
			*dst = val;
			*ptr += 8;
		}

		// converts a 64-bit little-endian unsigned integer to bytes
		static void to_little_bytes(char **ptr, unsigned long long val)
		{
			unsigned long long *dst = reinterpret_cast<unsigned long long*>(*ptr);
			*dst = val;
			*ptr += 8;
		}

		// converts a 32-bit little-endian floating point value to bytes
		static void to_little_bytes(char **ptr, float val)
		{
			float *dst = reinterpret_cast<float*>(*ptr);
			*dst = val;
			*ptr += 4;
		}

		// converts a 64-bit little-endian floating point value to bytes
		static void to_little_bytes(char **ptr, double val)
		{
			double *dst = reinterpret_cast<double*>(*ptr);
			*dst = val;
			*ptr += 8;
		}

		// converts a 128-bit little-endian floating point value to bytes
		static void to_little_bytes(char **ptr, long double val)
		{
			long double *dst = reinterpret_cast<long double*>(*ptr);
			*dst = val;
			*ptr += 16;
		}

		// converts a 16-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, signed short val)
		{
			const char *src = reinterpret_cast<const char*>(&val);
			char *dst = *ptr;
			dst[1] = src[0];
			dst[0] = src[1];
			*ptr += 2;
		}

		// converts a 16-bit big-endian unsigned integer to bytes
		static void to_big_bytes(char **ptr, unsigned short val)
		{
			const char *src = reinterpret_cast<const char*>(&val);
			char *dst = *ptr;
			dst[1] = src[0];
			dst[0] = src[1];
			*ptr += 2;
		}

		// converts a 32-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, signed int val)
		{
			const char *src = reinterpret_cast<const char*>(&val);
			char *dst = *ptr;
			dst[3] = src[0];
			dst[2] = src[1];
			dst[1] = src[2];
			dst[0] = src[3];
			*ptr += 4;
		}

		// converts a 32-bit big-endian unsigned integer to bytes
		static void to_big_bytes(char **ptr, unsigned int val)
		{
			const char *src = reinterpret_cast<const char*>(&val);
			char *dst = *ptr;
			dst[3] = src[0];
			dst[2] = src[1];
			dst[1] = src[2];
			dst[0] = src[3];
			*ptr += 4;
		}

		// converts a 32-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, signed long val)
		{
			const char *src = reinterpret_cast<const char*>(&val);
			char *dst = *ptr;
			dst[3] = src[0];
			dst[2] = src[1];
			dst[1] = src[2];
			dst[0] = src[3];
			*ptr += 4;
		}

		// converts a 32-bit big-endian unsigned integer to bytes
		static void to_big_bytes(char **ptr, unsigned long val)
		{
			const char *src = reinterpret_cast<const char*>(&val);
			char *dst = *ptr;
			dst[3] = src[0];
			dst[2] = src[1];
			dst[1] = src[2];
			dst[0] = src[3];
			*ptr += 4;
		}

		// converts a 64-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, signed long long val)
		{
			const char *src = reinterpret_cast<const char*>(&val);
			char *dst = *ptr;
			dst[7] = src[0];
			dst[6] = src[1];
			dst[5] = src[2];
			dst[4] = src[3];
			dst[3] = src[4];
			dst[2] = src[5];
			dst[1] = src[6];
			dst[0] = src[7];
			*ptr += 8;
		}

		// converts a 64-bit big-endian unsigned integer to bytes
		static void to_big_bytes(char **ptr, unsigned long long val)
		{
			const char *src = reinterpret_cast<const char*>(&val);
			char *dst = *ptr;
			dst[7] = src[0];
			dst[6] = src[1];
			dst[5] = src[2];
			dst[4] = src[3];
			dst[3] = src[4];
			dst[2] = src[5];
			dst[1] = src[6];
			dst[0] = src[7];
			*ptr += 8;
		}

		// converts a 32-bit big-endian floating point value to bytes
		static void to_big_bytes(char **ptr, float val)
		{
			const char *src = reinterpret_cast<const char*>(&val);
			char *dst = *ptr;
			dst[3] = src[0];
			dst[2] = src[1];
			dst[1] = src[2];
			dst[0] = src[3];
			*ptr += 4;
		}

		// converts a 64-bit big-endian floating point value to bytes
		static void to_big_bytes(char **ptr, double val)
		{
			const char *src = reinterpret_cast<const char*>(&val);
			char *dst = *ptr;
			dst[7] = src[0];
			dst[6] = src[1];
			dst[5] = src[2];
			dst[4] = src[3];
			dst[3] = src[4];
			dst[2] = src[5];
			dst[1] = src[6];
			dst[0] = src[7];
			*ptr += 8;
		}

		// converts a 128-bit big-endian floating point value to bytes
		static void to_big_bytes(char **ptr, long double val)
		{
			const char *src = reinterpret_cast<const char*>(&val);
			char *dst = *ptr;
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
			const char *src = reinterpret_cast<const char*>(str.data());
			char *dst = *ptr;
			for (size_t i = 0; i < count; i += 2)
			{
				dst[i + 1] = src[i];
				dst[i]     = src[i + 1];
			}
			*ptr += count;
		}

		// converts a vector of 16-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, const std::vector<signed short> &vct)
		{
			size_t count = vct.size() << 1;
			const char *src = reinterpret_cast<const char*>(vct.data());
			char *dst = *ptr;
			for (size_t i = 0; i < count; i += 2)
			{
				dst[i + 1] = src[i];
				dst[i]     = src[i + 1];
			}
			*ptr += count;
		}

		// converts a vector of 16-bit big-endian unsigned integer to bytes
		static void to_big_bytes(char **ptr, const std::vector<unsigned short> &vct)
		{
			size_t count = vct.size() << 1;
			const char *src = reinterpret_cast<const char*>(vct.data());
			char *dst = *ptr;
			for (size_t i = 0; i < count; i += 2)
			{
				dst[i + 1] = src[i];
				dst[i] = src[i + 1];
			}
			*ptr += count;
		}

		// converts a vector of 32-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, const std::vector<signed int> &vct)
		{
			size_t count = vct.size() << 2;
			const char *src = reinterpret_cast<const char*>(vct.data());
			char *dst = *ptr;
			for (size_t i = 0; i < count; i += 4)
			{
				dst[i + 3] = src[i];
				dst[i + 2] = src[i + 1];
				dst[i + 1] = src[i + 2];
				dst[i]     = src[i + 3];
			}
			*ptr += count;
		}

		// converts a vector of 32-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, const std::vector<unsigned int> &vct)
		{
			size_t count = vct.size() << 2;
			const char *src = reinterpret_cast<const char*>(vct.data());
			char *dst = *ptr;
			for (size_t i = 0; i < count; i += 4)
			{
				dst[i + 3] = src[i];
				dst[i + 2] = src[i + 1];
				dst[i + 1] = src[i + 2];
				dst[i] = src[i + 3];
			}
			*ptr += count;
		}

		// converts a vector of 32-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, const std::vector<signed long> &vct)
		{
			size_t count = vct.size() << 2;
			const char *src = reinterpret_cast<const char*>(vct.data());
			char *dst = *ptr;
			for (size_t i = 0; i < count; i += 4)
			{
				dst[i + 3] = src[i];
				dst[i + 2] = src[i + 1];
				dst[i + 1] = src[i + 2];
				dst[i]     = src[i + 3];
			}
			*ptr += count;
		}

		// converts a vector of 32-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, const std::vector<unsigned long> &vct)
		{
			size_t count = vct.size() << 2;
			const char *src = reinterpret_cast<const char*>(vct.data());
			char *dst = *ptr;
			for (size_t i = 0; i < count; i += 4)
			{
				dst[i + 3] = src[i];
				dst[i + 2] = src[i + 1];
				dst[i + 1] = src[i + 2];
				dst[i]     = src[i + 3];
			}
			*ptr += count;
		}

		// converts a vector of 128-bit big-endian signed integer to bytes
		static void to_big_bytes(char **ptr, const std::vector<signed long long> &vct)
		{
			size_t count = vct.size() << 3;
			const char *src = reinterpret_cast<const char*>(vct.data());
			char *dst = *ptr;
			for (size_t i = 0; i < count; i += 8)
			{
				dst[i + 7] = src[i];
				dst[i + 6] = src[i + 1];
				dst[i + 5] = src[i + 2];
				dst[i + 4] = src[i + 3];
				dst[i + 3] = src[i + 4];
				dst[i + 2] = src[i + 5];
				dst[i + 1] = src[i + 6];
				dst[i]     = src[i + 7];
			}
			*ptr += count;
		}

		// converts a vector of 128-bit big-endian unsigned integer to bytes
		static void to_big_bytes(char **ptr, const std::vector<unsigned long long> &vct)
		{
			size_t count = vct.size() << 3;
			const char *src = reinterpret_cast<const char*>(vct.data());
			char *dst = *ptr;
			for (size_t i = 0; i < count; i += 8)
			{
				dst[i + 7] = src[i];
				dst[i + 6] = src[i + 1];
				dst[i + 5] = src[i + 2];
				dst[i + 4] = src[i + 3];
				dst[i + 3] = src[i + 4];
				dst[i + 2] = src[i + 5];
				dst[i + 1] = src[i + 6];
				dst[i]     = src[i + 7];
			}
			*ptr += count;
		}

		// converts a vector of 32-bit big-endian floating point value to bytes
		static void to_big_bytes(char **ptr, const std::vector<float> &vct)
		{
			size_t count = vct.size() << 2;
			const char *src = reinterpret_cast<const char*>(vct.data());
			char *dst = *ptr;
			for (size_t i = 0; i < count; i += 4)
			{
				dst[i + 3] = src[i];
				dst[i + 2] = src[i + 1];
				dst[i + 1] = src[i + 2];
				dst[i]     = src[i + 3];
			}
			*ptr += count;
		}

		// converts a vector of 64-bit big-endian floating point value to bytes
		static void to_big_bytes(char **ptr, const std::vector<double> &vct)
		{
			size_t count = vct.size() << 3;
			const char *src = reinterpret_cast<const char*>(vct.data());
			char *dst = *ptr;
			for (size_t i = 0; i < count; i += 8)
			{
				dst[i + 7] = src[i];
				dst[i + 6] = src[i + 1];
				dst[i + 5] = src[i + 2];
				dst[i + 4] = src[i + 3];
				dst[i + 3] = src[i + 4];
				dst[i + 2] = src[i + 5];
				dst[i + 1] = src[i + 6];
				dst[i]     = src[i + 7];
			}
			*ptr += count;
		}

		// converts a vector of 128-bit big-endian floating point value to bytes
		static void to_big_bytes(char **ptr, const std::vector<long double> &vct)
		{
			size_t count = vct.size() << 4;
			const char *src = reinterpret_cast<const char*>(vct.data());
			char *dst = *ptr;
			for (size_t i = 0; i < count; i += 16)
			{
				dst[i + 15] = src[i];
				dst[i + 14] = src[i + 1];
				dst[i + 13] = src[i + 2];
				dst[i + 12] = src[i + 3];
				dst[i + 11] = src[i + 4];
				dst[i + 10] = src[i + 5];
				dst[i + 9]  = src[i + 6];
				dst[i + 8]  = src[i + 7];
				dst[i + 7]  = src[i + 8];
				dst[i + 6]  = src[i + 9];
				dst[i + 5]  = src[i + 10];
				dst[i + 4]  = src[i + 11];
				dst[i + 3]  = src[i + 12];
				dst[i + 2]  = src[i + 13];
				dst[i + 1]  = src[i + 14];
				dst[i]      = src[i + 15];
			}
			*ptr += count;
		}

		// converts 1 byte to a 8-bit signed integer
		static signed char to_char(const char **ptr)
		{
			const signed char *src = reinterpret_cast<const signed char*>(*ptr);
			*ptr += 1;
			return (*src);
		}

		// converts 1 byte to a 8-bit unsigned integer
		static unsigned char to_uchar(const char **ptr)
		{
			const unsigned char *src = reinterpret_cast<const unsigned char*>(*ptr);
			*ptr += 1;
			return (*src);
		}

		// converts 2 bytes to a 16-bit little-endian signed integer
		static signed short to_little_short(const char **ptr)
		{
			const signed short *src = reinterpret_cast<const signed short*>(*ptr);
			*ptr += 2;
			return (*src);
		}

		// converts 2 bytes to a 16-bit little-endian unsigned integer
		static unsigned short to_little_ushort(const char **ptr)
		{
			const unsigned short *src = reinterpret_cast<const unsigned short*>(*ptr);
			*ptr += 2;
			return (*src);
		}

		// converts 4 bytes to a 32-bit little-endian signed integer
		static signed int to_little_int(const char **ptr)
		{
			const signed int *src = reinterpret_cast<const signed int*>(*ptr);
			*ptr += 4;
			return (*src);
		}

		// converts 4 bytes to a 32-bit little-endian unsigned integer
		static unsigned int to_little_uint(const char **ptr)
		{
			const unsigned int *src = reinterpret_cast<const unsigned int*>(*ptr);
			*ptr += 4;
			return (*src);
		}

		// converts 4 bytes to a 32-bit little-endian signed integer
		static signed long to_little_long(const char **ptr)
		{
			const signed long *src = reinterpret_cast<const signed long*>(*ptr);
			*ptr += 4;
			return (*src);
		}

		// converts 4 bytes to a 32-bit little-endian unsigned integer
		static unsigned long to_little_ulong(const char **ptr)
		{
			const unsigned long *src = reinterpret_cast<const unsigned long*>(*ptr);
			*ptr += 4;
			return (*src);
		}

		// converts 8 bytes to a 64-bit little-endian signed integer
		static signed long long to_little_longlong(const char **ptr)
		{
			const signed long long *src = reinterpret_cast<const signed long long*>(*ptr);
			*ptr += 8;
			return (*src);
		}

		// converts 8 bytes to a 64-bit little-endian unsigned integer
		static unsigned long long to_little_ulonglong(const char **ptr)
		{
			const unsigned long long *src = reinterpret_cast<const unsigned long long*>(*ptr);
			*ptr += 8;
			return (*src);
		}

		// converts 4 bytes to a 32-bit little-endian floating point value
		static float to_little_float(const char **ptr)
		{
			const float *src = reinterpret_cast<const float*>(*ptr);
			*ptr += 4;
			return (*src);
		}

		// converts 8 bytes to a 64-bit little-endian floating point value
		static double to_little_double(const char **ptr)
		{
			const double *src = reinterpret_cast<const double*>(*ptr);
			*ptr += 8;
			return (*src);
		}

		// converts 16 bytes to a 128-bit little-endian floating point value
		static long double to_little_longdouble(const char **ptr)
		{
			const long double *src = reinterpret_cast<const long double*>(*ptr);
			*ptr += 16;
			return (*src);
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
			const char *src = *ptr;
			wchar_t *dst = const_cast<wchar_t*>(str.data());
			for (size_t i = 0; i < count; ++i)
				dst[i] = static_cast<wchar_t>(src[i]);
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
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(&val);
			dst[1] = src[0];
			dst[0] = src[1];
			*ptr += 2;
			return val;
		}

		// converts 2 bytes to a 16-bit big-endian unsigned integer
		static unsigned short to_big_ushort(const char **ptr)
		{
			unsigned short val;
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(&val);
			dst[1] = src[0];
			dst[0] = src[1];
			*ptr += 2;
			return val;
		}

		// converts 4 bytes to a 32-bit big-endian signed integer
		static signed int to_big_int(const char **ptr)
		{
			signed int val;
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(&val);
			dst[3] = src[0];
			dst[2] = src[1];
			dst[1] = src[2];
			dst[0] = src[3];
			*ptr += 4;
			return val;
		}

		// converts 4 bytes to a 32-bit big-endian unsigned integer
		static unsigned int to_big_uint(const char **ptr)
		{
			unsigned int val;
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(&val);
			dst[3] = src[0];
			dst[2] = src[1];
			dst[1] = src[2];
			dst[0] = src[3];
			*ptr += 4;
			return val;
		}

		// converts 4 bytes to a 32-bit big-endian signed integer
		static signed long to_big_long(const char **ptr)
		{
			signed long val;
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(&val);
			dst[3] = src[0];
			dst[2] = src[1];
			dst[1] = src[2];
			dst[0] = src[3];
			*ptr += 4;
			return val;
		}

		// converts 4 bytes to a 32-bit big-endian unsigned integer
		static unsigned long to_big_ulong(const char **ptr)
		{
			unsigned long val;
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(&val);
			dst[3] = src[0];
			dst[2] = src[1];
			dst[1] = src[2];
			dst[0] = src[3];
			*ptr += 4;
			return val;
		}

		// converts 8 bytes to a 64-bit big-endian signed integer
		static signed long long to_big_longlong(const char **ptr)
		{
			signed long long val;
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(&val);
			dst[7] = src[0];
			dst[6] = src[1];
			dst[5] = src[2];
			dst[4] = src[3];
			dst[3] = src[4];
			dst[2] = src[5];
			dst[1] = src[6];
			dst[0] = src[7];
			*ptr += 8;
			return val;
		}

		// converts 8 bytes to a 64-bit big-endian unsigned integer
		static unsigned long long to_big_ulonglong(const char **ptr)
		{
			unsigned long long val;
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(&val);
			dst[7] = src[0];
			dst[6] = src[1];
			dst[5] = src[2];
			dst[4] = src[3];
			dst[3] = src[4];
			dst[2] = src[5];
			dst[1] = src[6];
			dst[0] = src[7];
			*ptr += 8;
			return val;
		}

		// converts 4 bytes to a 32-bit big-endian floating point value
		static float to_big_float(const char **ptr)
		{
			float val;
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(&val);
			dst[3] = src[0];
			dst[2] = src[1];
			dst[1] = src[2];
			dst[0] = src[3];
			*ptr += 4;
			return val;
		}

		// converts 8 bytes to a 64-bit big-endian floating point value
		static double to_big_double(const char **ptr)
		{
			double val;
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(&val);
			dst[7] = src[0];
			dst[6] = src[1];
			dst[5] = src[2];
			dst[4] = src[3];
			dst[3] = src[4];
			dst[2] = src[5];
			dst[1] = src[6];
			dst[0] = src[7];
			*ptr += 8;
			return val;
		}

		// converts 16 bytes to a 128-bit big-endian floating point value
		static long double to_big_longdouble(const char **ptr)
		{
			long double val;
			const char *src = *ptr;
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
			*ptr += 16;
			return val;
		}

		// converts bytes to a big-endian wide string
		static std::wstring to_big_wstring(const char **ptr, size_t count)
		{
			std::wstring str;
			str.resize(count >> 1);
			const char *src = *ptr;
			char *dst = const_cast<char*>(reinterpret_cast<const char*>(str.data()));
			for (size_t i = 0; i < count; i += 2)
			{
				dst[i + 1] = src[i];
				dst[i]     = src[i + 1];
			}
			*ptr += count;
			return str;
		}

		// converts bytes to a vector of 16-bit big-endian signed integer
		static std::vector<signed short> to_big_short(const char **ptr, size_t count)
		{
			std::vector<signed short> vct(count >> 1);
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 2)
			{
				dst[i + 1] = src[i];
				dst[i]     = src[i + 1];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 16-bit big-endian unsigned integer
		static std::vector<unsigned short> to_big_ushort(const char **ptr, size_t count)
		{
			std::vector<unsigned short> vct(count >> 1);
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 2)
			{
				dst[i + 1] = src[i];
				dst[i]     = src[i + 1];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 32-bit big-endian signed integer
		static std::vector<signed int> to_big_int(const char **ptr, size_t count)
		{
			std::vector<signed int> vct(count >> 2);
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 4)
			{
				dst[i + 3] = src[i];
				dst[i + 2] = src[i + 1];
				dst[i + 1] = src[i + 2];
				dst[i]     = src[i + 3];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 32-bit big-endian unsigned integer
		static std::vector<unsigned int> to_big_uint(const char **ptr, size_t count)
		{
			std::vector<unsigned int> vct(count >> 2);
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 4)
			{
				dst[i + 3] = src[i];
				dst[i + 2] = src[i + 1];
				dst[i + 1] = src[i + 2];
				dst[i]     = src[i + 3];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 32-bit big-endian signed integer
		static std::vector<signed long> to_big_long(const char **ptr, size_t count)
		{
			std::vector<signed long> vct(count >> 2);
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 4)
			{
				dst[i + 3] = src[i];
				dst[i + 2] = src[i + 1];
				dst[i + 1] = src[i + 2];
				dst[i]     = src[i + 3];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 32-bit big-endian unsigned integer
		static std::vector<unsigned long> to_big_ulong(const char **ptr, size_t count)
		{
			std::vector<unsigned long> vct(count >> 2);
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 4)
			{
				dst[i + 3] = src[i];
				dst[i + 2] = src[i + 1];
				dst[i + 1] = src[i + 2];
				dst[i]     = src[i + 3];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 64-bit big-endian signed integer
		static std::vector<signed long long> to_big_longlong(const char **ptr, size_t count)
		{
			std::vector<signed long long> vct(count >> 3);
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 8)
			{
				dst[i + 7] = src[i];
				dst[i + 6] = src[i + 1];
				dst[i + 5] = src[i + 2];
				dst[i + 4] = src[i + 3];
				dst[i + 3] = src[i + 4];
				dst[i + 2] = src[i + 5];
				dst[i + 1] = src[i + 6];
				dst[i]     = src[i + 7];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 64-bit big-endian unsigned integer
		static std::vector<unsigned long long> to_big_ulonglong(const char **ptr, size_t count)
		{
			std::vector<unsigned long long> vct(count >> 3);
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 8)
			{
				dst[i + 7] = src[i];
				dst[i + 6] = src[i + 1];
				dst[i + 5] = src[i + 2];
				dst[i + 4] = src[i + 3];
				dst[i + 3] = src[i + 4];
				dst[i + 2] = src[i + 5];
				dst[i + 1] = src[i + 6];
				dst[i]     = src[i + 7];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 32-bit big-endian floating point value
		static std::vector<float> to_big_float(const char **ptr, size_t count)
		{
			std::vector<float> vct(count >> 2);
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 4)
			{
				dst[i + 3] = src[i];
				dst[i + 2] = src[i + 1];
				dst[i + 1] = src[i + 2];
				dst[i]     = src[i + 3];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 64-bit big-endian floating point value
		static std::vector<double> to_big_double(const char **ptr, size_t count)
		{
			std::vector<double> vct(count >> 3);
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 8)
			{
				dst[i + 7] = src[i];
				dst[i + 6] = src[i + 1];
				dst[i + 5] = src[i + 2];
				dst[i + 4] = src[i + 3];
				dst[i + 3] = src[i + 4];
				dst[i + 2] = src[i + 5];
				dst[i + 1] = src[i + 6];
				dst[i]     = src[i + 7];
			}
			*ptr += count;
			return vct;
		}

		// converts bytes to a vector of 128-bit big-endian floating point value
		static std::vector<long double> to_big_longdouble(const char **ptr, size_t count)
		{
			std::vector<long double> vct(count >> 4);
			const char *src = *ptr;
			char *dst = reinterpret_cast<char*>(vct.data());
			for (size_t i = 0; i < count; i += 16)
			{
				dst[i + 15] = src[i];
				dst[i + 14] = src[i + 1];
				dst[i + 13] = src[i + 2];
				dst[i + 12] = src[i + 3];
				dst[i + 11] = src[i + 4];
				dst[i + 10] = src[i + 5];
				dst[i + 9]  = src[i + 6];
				dst[i + 8]  = src[i + 7];
				dst[i + 7]  = src[i + 8];
				dst[i + 6]  = src[i + 9];
				dst[i + 5]  = src[i + 10];
				dst[i + 4]  = src[i + 11];
				dst[i + 3]  = src[i + 12];
				dst[i + 2]  = src[i + 13];
				dst[i + 1]  = src[i + 14];
				dst[i]      = src[i + 15];
			}
			*ptr += count;
			return vct;
		}

	};

} // namespace core

#endif
