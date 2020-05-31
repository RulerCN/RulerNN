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

#ifndef __CORE_COMM_CVTSPD_H__
#define __CORE_COMM_CVTSPD_H__

#include <cstddef>
#include <cstdint>
#include <cfloat>
#include <cstring>

namespace core
{
	namespace comm
	{
		// Function template impl_cvtspd

		template <class T>
		void impl_cvtspd(T* dst, const double* src, size_t n)
		{
			constexpr size_t block = 8;
			while (n >= block)
			{
				dst[0] = static_cast<T>(src[0]);
				dst[1] = static_cast<T>(src[1]);
				dst[2] = static_cast<T>(src[2]);
				dst[3] = static_cast<T>(src[3]);
				dst[4] = static_cast<T>(src[4]);
				dst[5] = static_cast<T>(src[5]);
				dst[6] = static_cast<T>(src[6]);
				dst[7] = static_cast<T>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = static_cast<T>(src[6]);
			case 6: dst[5] = static_cast<T>(src[5]);
			case 5: dst[4] = static_cast<T>(src[4]);
			case 4: dst[3] = static_cast<T>(src[3]);
			case 3: dst[2] = static_cast<T>(src[2]);
			case 2: dst[1] = static_cast<T>(src[1]);
			case 1: dst[0] = static_cast<T>(src[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<signed char>(signed char* dst, const double* src, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double min = static_cast<double>(INT8_MIN);
			constexpr double max = static_cast<double>(INT8_MAX);
			while (n >= block)
			{
				dst[0] = src[0] < min ? INT8_MIN : src[0] > max ? INT8_MAX : static_cast<signed char>(src[0]);
				dst[1] = src[1] < min ? INT8_MIN : src[1] > max ? INT8_MAX : static_cast<signed char>(src[1]);
				dst[2] = src[2] < min ? INT8_MIN : src[2] > max ? INT8_MAX : static_cast<signed char>(src[2]);
				dst[3] = src[3] < min ? INT8_MIN : src[3] > max ? INT8_MAX : static_cast<signed char>(src[3]);
				dst[4] = src[4] < min ? INT8_MIN : src[4] > max ? INT8_MAX : static_cast<signed char>(src[4]);
				dst[5] = src[5] < min ? INT8_MIN : src[5] > max ? INT8_MAX : static_cast<signed char>(src[5]);
				dst[6] = src[6] < min ? INT8_MIN : src[6] > max ? INT8_MAX : static_cast<signed char>(src[6]);
				dst[7] = src[7] < min ? INT8_MIN : src[7] > max ? INT8_MAX : static_cast<signed char>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] < min ? INT8_MIN : src[6] > max ? INT8_MAX : static_cast<signed char>(src[6]);
			case 6: dst[5] = src[5] < min ? INT8_MIN : src[5] > max ? INT8_MAX : static_cast<signed char>(src[5]);
			case 5: dst[4] = src[4] < min ? INT8_MIN : src[4] > max ? INT8_MAX : static_cast<signed char>(src[4]);
			case 4: dst[3] = src[3] < min ? INT8_MIN : src[3] > max ? INT8_MAX : static_cast<signed char>(src[3]);
			case 3: dst[2] = src[2] < min ? INT8_MIN : src[2] > max ? INT8_MAX : static_cast<signed char>(src[2]);
			case 2: dst[1] = src[1] < min ? INT8_MIN : src[1] > max ? INT8_MAX : static_cast<signed char>(src[1]);
			case 1: dst[0] = src[0] < min ? INT8_MIN : src[0] > max ? INT8_MAX : static_cast<signed char>(src[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<unsigned char>(unsigned char* dst, const double* src, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double max = static_cast<double>(UINT8_MAX);
			while (n >= block)
			{
				dst[0] = src[0] < 0 ? 0 : src[0] > max ? UINT8_MAX : static_cast<unsigned char>(src[0]);
				dst[1] = src[1] < 0 ? 0 : src[1] > max ? UINT8_MAX : static_cast<unsigned char>(src[1]);
				dst[2] = src[2] < 0 ? 0 : src[2] > max ? UINT8_MAX : static_cast<unsigned char>(src[2]);
				dst[3] = src[3] < 0 ? 0 : src[3] > max ? UINT8_MAX : static_cast<unsigned char>(src[3]);
				dst[4] = src[4] < 0 ? 0 : src[4] > max ? UINT8_MAX : static_cast<unsigned char>(src[4]);
				dst[5] = src[5] < 0 ? 0 : src[5] > max ? UINT8_MAX : static_cast<unsigned char>(src[5]);
				dst[6] = src[6] < 0 ? 0 : src[6] > max ? UINT8_MAX : static_cast<unsigned char>(src[6]);
				dst[7] = src[7] < 0 ? 0 : src[7] > max ? UINT8_MAX : static_cast<unsigned char>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] < 0 ? 0 : src[6] > max ? UINT8_MAX : static_cast<unsigned char>(src[6]);
			case 6: dst[5] = src[5] < 0 ? 0 : src[5] > max ? UINT8_MAX : static_cast<unsigned char>(src[5]);
			case 5: dst[4] = src[4] < 0 ? 0 : src[4] > max ? UINT8_MAX : static_cast<unsigned char>(src[4]);
			case 4: dst[3] = src[3] < 0 ? 0 : src[3] > max ? UINT8_MAX : static_cast<unsigned char>(src[3]);
			case 3: dst[2] = src[2] < 0 ? 0 : src[2] > max ? UINT8_MAX : static_cast<unsigned char>(src[2]);
			case 2: dst[1] = src[1] < 0 ? 0 : src[1] > max ? UINT8_MAX : static_cast<unsigned char>(src[1]);
			case 1: dst[0] = src[0] < 0 ? 0 : src[0] > max ? UINT8_MAX : static_cast<unsigned char>(src[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<signed short>(signed short* dst, const double* src, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double min = static_cast<double>(INT16_MIN);
			constexpr double max = static_cast<double>(INT16_MAX);
			while (n >= block)
			{
				dst[0] = src[0] < min ? INT16_MIN : src[0] > max ? INT16_MAX : static_cast<signed short>(src[0]);
				dst[1] = src[1] < min ? INT16_MIN : src[1] > max ? INT16_MAX : static_cast<signed short>(src[1]);
				dst[2] = src[2] < min ? INT16_MIN : src[2] > max ? INT16_MAX : static_cast<signed short>(src[2]);
				dst[3] = src[3] < min ? INT16_MIN : src[3] > max ? INT16_MAX : static_cast<signed short>(src[3]);
				dst[4] = src[4] < min ? INT16_MIN : src[4] > max ? INT16_MAX : static_cast<signed short>(src[4]);
				dst[5] = src[5] < min ? INT16_MIN : src[5] > max ? INT16_MAX : static_cast<signed short>(src[5]);
				dst[6] = src[6] < min ? INT16_MIN : src[6] > max ? INT16_MAX : static_cast<signed short>(src[6]);
				dst[7] = src[7] < min ? INT16_MIN : src[7] > max ? INT16_MAX : static_cast<signed short>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] < min ? INT16_MIN : src[6] > max ? INT16_MAX : static_cast<signed short>(src[6]);
			case 6: dst[5] = src[5] < min ? INT16_MIN : src[5] > max ? INT16_MAX : static_cast<signed short>(src[5]);
			case 5: dst[4] = src[4] < min ? INT16_MIN : src[4] > max ? INT16_MAX : static_cast<signed short>(src[4]);
			case 4: dst[3] = src[3] < min ? INT16_MIN : src[3] > max ? INT16_MAX : static_cast<signed short>(src[3]);
			case 3: dst[2] = src[2] < min ? INT16_MIN : src[2] > max ? INT16_MAX : static_cast<signed short>(src[2]);
			case 2: dst[1] = src[1] < min ? INT16_MIN : src[1] > max ? INT16_MAX : static_cast<signed short>(src[1]);
			case 1: dst[0] = src[0] < min ? INT16_MIN : src[0] > max ? INT16_MAX : static_cast<signed short>(src[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<unsigned short>(unsigned short* dst, const double* src, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double max = static_cast<double>(UINT16_MAX);
			while (n >= block)
			{
				dst[0] = src[0] < 0 ? 0 : src[0] > max ? UINT16_MAX : static_cast<unsigned short>(src[0]);
				dst[1] = src[1] < 0 ? 0 : src[1] > max ? UINT16_MAX : static_cast<unsigned short>(src[1]);
				dst[2] = src[2] < 0 ? 0 : src[2] > max ? UINT16_MAX : static_cast<unsigned short>(src[2]);
				dst[3] = src[3] < 0 ? 0 : src[3] > max ? UINT16_MAX : static_cast<unsigned short>(src[3]);
				dst[4] = src[4] < 0 ? 0 : src[4] > max ? UINT16_MAX : static_cast<unsigned short>(src[4]);
				dst[5] = src[5] < 0 ? 0 : src[5] > max ? UINT16_MAX : static_cast<unsigned short>(src[5]);
				dst[6] = src[6] < 0 ? 0 : src[6] > max ? UINT16_MAX : static_cast<unsigned short>(src[6]);
				dst[7] = src[7] < 0 ? 0 : src[7] > max ? UINT16_MAX : static_cast<unsigned short>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] < 0 ? 0 : src[6] > max ? UINT16_MAX : static_cast<unsigned short>(src[6]);
			case 6: dst[5] = src[5] < 0 ? 0 : src[5] > max ? UINT16_MAX : static_cast<unsigned short>(src[5]);
			case 5: dst[4] = src[4] < 0 ? 0 : src[4] > max ? UINT16_MAX : static_cast<unsigned short>(src[4]);
			case 4: dst[3] = src[3] < 0 ? 0 : src[3] > max ? UINT16_MAX : static_cast<unsigned short>(src[3]);
			case 3: dst[2] = src[2] < 0 ? 0 : src[2] > max ? UINT16_MAX : static_cast<unsigned short>(src[2]);
			case 2: dst[1] = src[1] < 0 ? 0 : src[1] > max ? UINT16_MAX : static_cast<unsigned short>(src[1]);
			case 1: dst[0] = src[0] < 0 ? 0 : src[0] > max ? UINT16_MAX : static_cast<unsigned short>(src[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<signed int>(signed int* dst, const double* src, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double min = static_cast<double>(INT32_MIN);
			constexpr double max = static_cast<double>(INT32_MAX);
			while (n >= block)
			{
				dst[0] = src[0] < min ? INT32_MIN : src[0] > max ? INT32_MAX : static_cast<signed int>(src[0]);
				dst[1] = src[1] < min ? INT32_MIN : src[1] > max ? INT32_MAX : static_cast<signed int>(src[1]);
				dst[2] = src[2] < min ? INT32_MIN : src[2] > max ? INT32_MAX : static_cast<signed int>(src[2]);
				dst[3] = src[3] < min ? INT32_MIN : src[3] > max ? INT32_MAX : static_cast<signed int>(src[3]);
				dst[4] = src[4] < min ? INT32_MIN : src[4] > max ? INT32_MAX : static_cast<signed int>(src[4]);
				dst[5] = src[5] < min ? INT32_MIN : src[5] > max ? INT32_MAX : static_cast<signed int>(src[5]);
				dst[6] = src[6] < min ? INT32_MIN : src[6] > max ? INT32_MAX : static_cast<signed int>(src[6]);
				dst[7] = src[7] < min ? INT32_MIN : src[7] > max ? INT32_MAX : static_cast<signed int>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] < min ? INT32_MIN : src[6] > max ? INT32_MAX : static_cast<signed int>(src[6]);
			case 6: dst[5] = src[5] < min ? INT32_MIN : src[5] > max ? INT32_MAX : static_cast<signed int>(src[5]);
			case 5: dst[4] = src[4] < min ? INT32_MIN : src[4] > max ? INT32_MAX : static_cast<signed int>(src[4]);
			case 4: dst[3] = src[3] < min ? INT32_MIN : src[3] > max ? INT32_MAX : static_cast<signed int>(src[3]);
			case 3: dst[2] = src[2] < min ? INT32_MIN : src[2] > max ? INT32_MAX : static_cast<signed int>(src[2]);
			case 2: dst[1] = src[1] < min ? INT32_MIN : src[1] > max ? INT32_MAX : static_cast<signed int>(src[1]);
			case 1: dst[0] = src[0] < min ? INT32_MIN : src[0] > max ? INT32_MAX : static_cast<signed int>(src[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<unsigned int>(unsigned int* dst, const double* src, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double max = static_cast<double>(UINT32_MAX);
			while (n >= block)
			{
				dst[0] = src[0] < 0 ? 0 : src[0] > max ? UINT32_MAX : static_cast<unsigned int>(src[0]);
				dst[1] = src[1] < 0 ? 0 : src[1] > max ? UINT32_MAX : static_cast<unsigned int>(src[1]);
				dst[2] = src[2] < 0 ? 0 : src[2] > max ? UINT32_MAX : static_cast<unsigned int>(src[2]);
				dst[3] = src[3] < 0 ? 0 : src[3] > max ? UINT32_MAX : static_cast<unsigned int>(src[3]);
				dst[4] = src[4] < 0 ? 0 : src[4] > max ? UINT32_MAX : static_cast<unsigned int>(src[4]);
				dst[5] = src[5] < 0 ? 0 : src[5] > max ? UINT32_MAX : static_cast<unsigned int>(src[5]);
				dst[6] = src[6] < 0 ? 0 : src[6] > max ? UINT32_MAX : static_cast<unsigned int>(src[6]);
				dst[7] = src[7] < 0 ? 0 : src[7] > max ? UINT32_MAX : static_cast<unsigned int>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] < 0 ? 0 : src[6] > max ? UINT32_MAX : static_cast<unsigned int>(src[6]);
			case 6: dst[5] = src[5] < 0 ? 0 : src[5] > max ? UINT32_MAX : static_cast<unsigned int>(src[5]);
			case 5: dst[4] = src[4] < 0 ? 0 : src[4] > max ? UINT32_MAX : static_cast<unsigned int>(src[4]);
			case 4: dst[3] = src[3] < 0 ? 0 : src[3] > max ? UINT32_MAX : static_cast<unsigned int>(src[3]);
			case 3: dst[2] = src[2] < 0 ? 0 : src[2] > max ? UINT32_MAX : static_cast<unsigned int>(src[2]);
			case 2: dst[1] = src[1] < 0 ? 0 : src[1] > max ? UINT32_MAX : static_cast<unsigned int>(src[1]);
			case 1: dst[0] = src[0] < 0 ? 0 : src[0] > max ? UINT32_MAX : static_cast<unsigned int>(src[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<float>(float* dst, const double* src, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double min = static_cast<double>(-FLT_MAX);
			constexpr double max = static_cast<double>(FLT_MAX);
			while (n >= block)
			{
				dst[0] = src[0] < min ? -FLT_MAX : src[0] > max ? FLT_MAX : static_cast<float>(src[0]);
				dst[1] = src[1] < min ? -FLT_MAX : src[1] > max ? FLT_MAX : static_cast<float>(src[1]);
				dst[2] = src[2] < min ? -FLT_MAX : src[2] > max ? FLT_MAX : static_cast<float>(src[2]);
				dst[3] = src[3] < min ? -FLT_MAX : src[3] > max ? FLT_MAX : static_cast<float>(src[3]);
				dst[4] = src[4] < min ? -FLT_MAX : src[4] > max ? FLT_MAX : static_cast<float>(src[4]);
				dst[5] = src[5] < min ? -FLT_MAX : src[5] > max ? FLT_MAX : static_cast<float>(src[5]);
				dst[6] = src[6] < min ? -FLT_MAX : src[6] > max ? FLT_MAX : static_cast<float>(src[6]);
				dst[7] = src[7] < min ? -FLT_MAX : src[7] > max ? FLT_MAX : static_cast<float>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] < min ? -FLT_MAX : src[6] > max ? FLT_MAX : static_cast<float>(src[6]);
			case 6: dst[5] = src[5] < min ? -FLT_MAX : src[5] > max ? FLT_MAX : static_cast<float>(src[5]);
			case 5: dst[4] = src[4] < min ? -FLT_MAX : src[4] > max ? FLT_MAX : static_cast<float>(src[4]);
			case 4: dst[3] = src[3] < min ? -FLT_MAX : src[3] > max ? FLT_MAX : static_cast<float>(src[3]);
			case 3: dst[2] = src[2] < min ? -FLT_MAX : src[2] > max ? FLT_MAX : static_cast<float>(src[2]);
			case 2: dst[1] = src[1] < min ? -FLT_MAX : src[1] > max ? FLT_MAX : static_cast<float>(src[1]);
			case 1: dst[0] = src[0] < min ? -FLT_MAX : src[0] > max ? FLT_MAX : static_cast<float>(src[0]);
				break;
			}
		}

		template <>
		inline void impl_cvtspd<double>(double* dst, const double* src, size_t n)
		{
			std::memcpy(dst, src, n * sizeof(double));
		}

	} // namespace comm

} // namespace core

#endif
