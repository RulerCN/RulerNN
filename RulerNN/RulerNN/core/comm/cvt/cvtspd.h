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
		void impl_cvtspd(T* b, const double* a, size_t n)
		{
			constexpr size_t block = 8;
			while (n >= block)
			{
				b[0] = static_cast<T>(a[0]);
				b[1] = static_cast<T>(a[1]);
				b[2] = static_cast<T>(a[2]);
				b[3] = static_cast<T>(a[3]);
				b[4] = static_cast<T>(a[4]);
				b[5] = static_cast<T>(a[5]);
				b[6] = static_cast<T>(a[6]);
				b[7] = static_cast<T>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = static_cast<T>(a[6]);
			case 6: b[5] = static_cast<T>(a[5]);
			case 5: b[4] = static_cast<T>(a[4]);
			case 4: b[3] = static_cast<T>(a[3]);
			case 3: b[2] = static_cast<T>(a[2]);
			case 2: b[1] = static_cast<T>(a[1]);
			case 1: b[0] = static_cast<T>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<signed char>(signed char* b, const double* a, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double min = static_cast<double>(INT8_MIN);
			constexpr double max = static_cast<double>(INT8_MAX);
			while (n >= block)
			{
				b[0] = a[0] < min ? INT8_MIN : a[0] > max ? INT8_MAX : static_cast<signed char>(a[0]);
				b[1] = a[1] < min ? INT8_MIN : a[1] > max ? INT8_MAX : static_cast<signed char>(a[1]);
				b[2] = a[2] < min ? INT8_MIN : a[2] > max ? INT8_MAX : static_cast<signed char>(a[2]);
				b[3] = a[3] < min ? INT8_MIN : a[3] > max ? INT8_MAX : static_cast<signed char>(a[3]);
				b[4] = a[4] < min ? INT8_MIN : a[4] > max ? INT8_MAX : static_cast<signed char>(a[4]);
				b[5] = a[5] < min ? INT8_MIN : a[5] > max ? INT8_MAX : static_cast<signed char>(a[5]);
				b[6] = a[6] < min ? INT8_MIN : a[6] > max ? INT8_MAX : static_cast<signed char>(a[6]);
				b[7] = a[7] < min ? INT8_MIN : a[7] > max ? INT8_MAX : static_cast<signed char>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] < min ? INT8_MIN : a[6] > max ? INT8_MAX : static_cast<signed char>(a[6]);
			case 6: b[5] = a[5] < min ? INT8_MIN : a[5] > max ? INT8_MAX : static_cast<signed char>(a[5]);
			case 5: b[4] = a[4] < min ? INT8_MIN : a[4] > max ? INT8_MAX : static_cast<signed char>(a[4]);
			case 4: b[3] = a[3] < min ? INT8_MIN : a[3] > max ? INT8_MAX : static_cast<signed char>(a[3]);
			case 3: b[2] = a[2] < min ? INT8_MIN : a[2] > max ? INT8_MAX : static_cast<signed char>(a[2]);
			case 2: b[1] = a[1] < min ? INT8_MIN : a[1] > max ? INT8_MAX : static_cast<signed char>(a[1]);
			case 1: b[0] = a[0] < min ? INT8_MIN : a[0] > max ? INT8_MAX : static_cast<signed char>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<unsigned char>(unsigned char* b, const double* a, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double max = static_cast<double>(UINT8_MAX);
			while (n >= block)
			{
				b[0] = a[0] < 0 ? 0 : a[0] > max ? UINT8_MAX : static_cast<unsigned char>(a[0]);
				b[1] = a[1] < 0 ? 0 : a[1] > max ? UINT8_MAX : static_cast<unsigned char>(a[1]);
				b[2] = a[2] < 0 ? 0 : a[2] > max ? UINT8_MAX : static_cast<unsigned char>(a[2]);
				b[3] = a[3] < 0 ? 0 : a[3] > max ? UINT8_MAX : static_cast<unsigned char>(a[3]);
				b[4] = a[4] < 0 ? 0 : a[4] > max ? UINT8_MAX : static_cast<unsigned char>(a[4]);
				b[5] = a[5] < 0 ? 0 : a[5] > max ? UINT8_MAX : static_cast<unsigned char>(a[5]);
				b[6] = a[6] < 0 ? 0 : a[6] > max ? UINT8_MAX : static_cast<unsigned char>(a[6]);
				b[7] = a[7] < 0 ? 0 : a[7] > max ? UINT8_MAX : static_cast<unsigned char>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] < 0 ? 0 : a[6] > max ? UINT8_MAX : static_cast<unsigned char>(a[6]);
			case 6: b[5] = a[5] < 0 ? 0 : a[5] > max ? UINT8_MAX : static_cast<unsigned char>(a[5]);
			case 5: b[4] = a[4] < 0 ? 0 : a[4] > max ? UINT8_MAX : static_cast<unsigned char>(a[4]);
			case 4: b[3] = a[3] < 0 ? 0 : a[3] > max ? UINT8_MAX : static_cast<unsigned char>(a[3]);
			case 3: b[2] = a[2] < 0 ? 0 : a[2] > max ? UINT8_MAX : static_cast<unsigned char>(a[2]);
			case 2: b[1] = a[1] < 0 ? 0 : a[1] > max ? UINT8_MAX : static_cast<unsigned char>(a[1]);
			case 1: b[0] = a[0] < 0 ? 0 : a[0] > max ? UINT8_MAX : static_cast<unsigned char>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<signed short>(signed short* b, const double* a, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double min = static_cast<double>(INT16_MIN);
			constexpr double max = static_cast<double>(INT16_MAX);
			while (n >= block)
			{
				b[0] = a[0] < min ? INT16_MIN : a[0] > max ? INT16_MAX : static_cast<signed short>(a[0]);
				b[1] = a[1] < min ? INT16_MIN : a[1] > max ? INT16_MAX : static_cast<signed short>(a[1]);
				b[2] = a[2] < min ? INT16_MIN : a[2] > max ? INT16_MAX : static_cast<signed short>(a[2]);
				b[3] = a[3] < min ? INT16_MIN : a[3] > max ? INT16_MAX : static_cast<signed short>(a[3]);
				b[4] = a[4] < min ? INT16_MIN : a[4] > max ? INT16_MAX : static_cast<signed short>(a[4]);
				b[5] = a[5] < min ? INT16_MIN : a[5] > max ? INT16_MAX : static_cast<signed short>(a[5]);
				b[6] = a[6] < min ? INT16_MIN : a[6] > max ? INT16_MAX : static_cast<signed short>(a[6]);
				b[7] = a[7] < min ? INT16_MIN : a[7] > max ? INT16_MAX : static_cast<signed short>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] < min ? INT16_MIN : a[6] > max ? INT16_MAX : static_cast<signed short>(a[6]);
			case 6: b[5] = a[5] < min ? INT16_MIN : a[5] > max ? INT16_MAX : static_cast<signed short>(a[5]);
			case 5: b[4] = a[4] < min ? INT16_MIN : a[4] > max ? INT16_MAX : static_cast<signed short>(a[4]);
			case 4: b[3] = a[3] < min ? INT16_MIN : a[3] > max ? INT16_MAX : static_cast<signed short>(a[3]);
			case 3: b[2] = a[2] < min ? INT16_MIN : a[2] > max ? INT16_MAX : static_cast<signed short>(a[2]);
			case 2: b[1] = a[1] < min ? INT16_MIN : a[1] > max ? INT16_MAX : static_cast<signed short>(a[1]);
			case 1: b[0] = a[0] < min ? INT16_MIN : a[0] > max ? INT16_MAX : static_cast<signed short>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<unsigned short>(unsigned short* b, const double* a, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double max = static_cast<double>(UINT16_MAX);
			while (n >= block)
			{
				b[0] = a[0] < 0 ? 0 : a[0] > max ? UINT16_MAX : static_cast<unsigned short>(a[0]);
				b[1] = a[1] < 0 ? 0 : a[1] > max ? UINT16_MAX : static_cast<unsigned short>(a[1]);
				b[2] = a[2] < 0 ? 0 : a[2] > max ? UINT16_MAX : static_cast<unsigned short>(a[2]);
				b[3] = a[3] < 0 ? 0 : a[3] > max ? UINT16_MAX : static_cast<unsigned short>(a[3]);
				b[4] = a[4] < 0 ? 0 : a[4] > max ? UINT16_MAX : static_cast<unsigned short>(a[4]);
				b[5] = a[5] < 0 ? 0 : a[5] > max ? UINT16_MAX : static_cast<unsigned short>(a[5]);
				b[6] = a[6] < 0 ? 0 : a[6] > max ? UINT16_MAX : static_cast<unsigned short>(a[6]);
				b[7] = a[7] < 0 ? 0 : a[7] > max ? UINT16_MAX : static_cast<unsigned short>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] < 0 ? 0 : a[6] > max ? UINT16_MAX : static_cast<unsigned short>(a[6]);
			case 6: b[5] = a[5] < 0 ? 0 : a[5] > max ? UINT16_MAX : static_cast<unsigned short>(a[5]);
			case 5: b[4] = a[4] < 0 ? 0 : a[4] > max ? UINT16_MAX : static_cast<unsigned short>(a[4]);
			case 4: b[3] = a[3] < 0 ? 0 : a[3] > max ? UINT16_MAX : static_cast<unsigned short>(a[3]);
			case 3: b[2] = a[2] < 0 ? 0 : a[2] > max ? UINT16_MAX : static_cast<unsigned short>(a[2]);
			case 2: b[1] = a[1] < 0 ? 0 : a[1] > max ? UINT16_MAX : static_cast<unsigned short>(a[1]);
			case 1: b[0] = a[0] < 0 ? 0 : a[0] > max ? UINT16_MAX : static_cast<unsigned short>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<signed int>(signed int* b, const double* a, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double min = static_cast<double>(INT32_MIN);
			constexpr double max = static_cast<double>(INT32_MAX);
			while (n >= block)
			{
				b[0] = a[0] < min ? INT32_MIN : a[0] > max ? INT32_MAX : static_cast<signed int>(a[0]);
				b[1] = a[1] < min ? INT32_MIN : a[1] > max ? INT32_MAX : static_cast<signed int>(a[1]);
				b[2] = a[2] < min ? INT32_MIN : a[2] > max ? INT32_MAX : static_cast<signed int>(a[2]);
				b[3] = a[3] < min ? INT32_MIN : a[3] > max ? INT32_MAX : static_cast<signed int>(a[3]);
				b[4] = a[4] < min ? INT32_MIN : a[4] > max ? INT32_MAX : static_cast<signed int>(a[4]);
				b[5] = a[5] < min ? INT32_MIN : a[5] > max ? INT32_MAX : static_cast<signed int>(a[5]);
				b[6] = a[6] < min ? INT32_MIN : a[6] > max ? INT32_MAX : static_cast<signed int>(a[6]);
				b[7] = a[7] < min ? INT32_MIN : a[7] > max ? INT32_MAX : static_cast<signed int>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] < min ? INT32_MIN : a[6] > max ? INT32_MAX : static_cast<signed int>(a[6]);
			case 6: b[5] = a[5] < min ? INT32_MIN : a[5] > max ? INT32_MAX : static_cast<signed int>(a[5]);
			case 5: b[4] = a[4] < min ? INT32_MIN : a[4] > max ? INT32_MAX : static_cast<signed int>(a[4]);
			case 4: b[3] = a[3] < min ? INT32_MIN : a[3] > max ? INT32_MAX : static_cast<signed int>(a[3]);
			case 3: b[2] = a[2] < min ? INT32_MIN : a[2] > max ? INT32_MAX : static_cast<signed int>(a[2]);
			case 2: b[1] = a[1] < min ? INT32_MIN : a[1] > max ? INT32_MAX : static_cast<signed int>(a[1]);
			case 1: b[0] = a[0] < min ? INT32_MIN : a[0] > max ? INT32_MAX : static_cast<signed int>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<unsigned int>(unsigned int* b, const double* a, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double max = static_cast<double>(UINT32_MAX);
			while (n >= block)
			{
				b[0] = a[0] < 0 ? 0 : a[0] > max ? UINT32_MAX : static_cast<unsigned int>(a[0]);
				b[1] = a[1] < 0 ? 0 : a[1] > max ? UINT32_MAX : static_cast<unsigned int>(a[1]);
				b[2] = a[2] < 0 ? 0 : a[2] > max ? UINT32_MAX : static_cast<unsigned int>(a[2]);
				b[3] = a[3] < 0 ? 0 : a[3] > max ? UINT32_MAX : static_cast<unsigned int>(a[3]);
				b[4] = a[4] < 0 ? 0 : a[4] > max ? UINT32_MAX : static_cast<unsigned int>(a[4]);
				b[5] = a[5] < 0 ? 0 : a[5] > max ? UINT32_MAX : static_cast<unsigned int>(a[5]);
				b[6] = a[6] < 0 ? 0 : a[6] > max ? UINT32_MAX : static_cast<unsigned int>(a[6]);
				b[7] = a[7] < 0 ? 0 : a[7] > max ? UINT32_MAX : static_cast<unsigned int>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] < 0 ? 0 : a[6] > max ? UINT32_MAX : static_cast<unsigned int>(a[6]);
			case 6: b[5] = a[5] < 0 ? 0 : a[5] > max ? UINT32_MAX : static_cast<unsigned int>(a[5]);
			case 5: b[4] = a[4] < 0 ? 0 : a[4] > max ? UINT32_MAX : static_cast<unsigned int>(a[4]);
			case 4: b[3] = a[3] < 0 ? 0 : a[3] > max ? UINT32_MAX : static_cast<unsigned int>(a[3]);
			case 3: b[2] = a[2] < 0 ? 0 : a[2] > max ? UINT32_MAX : static_cast<unsigned int>(a[2]);
			case 2: b[1] = a[1] < 0 ? 0 : a[1] > max ? UINT32_MAX : static_cast<unsigned int>(a[1]);
			case 1: b[0] = a[0] < 0 ? 0 : a[0] > max ? UINT32_MAX : static_cast<unsigned int>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtspd<float>(float* b, const double* a, size_t n)
		{
			constexpr size_t block = 8;
			constexpr double min = static_cast<double>(-FLT_MAX);
			constexpr double max = static_cast<double>(FLT_MAX);
			while (n >= block)
			{
				b[0] = a[0] < min ? -FLT_MAX : a[0] > max ? FLT_MAX : static_cast<float>(a[0]);
				b[1] = a[1] < min ? -FLT_MAX : a[1] > max ? FLT_MAX : static_cast<float>(a[1]);
				b[2] = a[2] < min ? -FLT_MAX : a[2] > max ? FLT_MAX : static_cast<float>(a[2]);
				b[3] = a[3] < min ? -FLT_MAX : a[3] > max ? FLT_MAX : static_cast<float>(a[3]);
				b[4] = a[4] < min ? -FLT_MAX : a[4] > max ? FLT_MAX : static_cast<float>(a[4]);
				b[5] = a[5] < min ? -FLT_MAX : a[5] > max ? FLT_MAX : static_cast<float>(a[5]);
				b[6] = a[6] < min ? -FLT_MAX : a[6] > max ? FLT_MAX : static_cast<float>(a[6]);
				b[7] = a[7] < min ? -FLT_MAX : a[7] > max ? FLT_MAX : static_cast<float>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] < min ? -FLT_MAX : a[6] > max ? FLT_MAX : static_cast<float>(a[6]);
			case 6: b[5] = a[5] < min ? -FLT_MAX : a[5] > max ? FLT_MAX : static_cast<float>(a[5]);
			case 5: b[4] = a[4] < min ? -FLT_MAX : a[4] > max ? FLT_MAX : static_cast<float>(a[4]);
			case 4: b[3] = a[3] < min ? -FLT_MAX : a[3] > max ? FLT_MAX : static_cast<float>(a[3]);
			case 3: b[2] = a[2] < min ? -FLT_MAX : a[2] > max ? FLT_MAX : static_cast<float>(a[2]);
			case 2: b[1] = a[1] < min ? -FLT_MAX : a[1] > max ? FLT_MAX : static_cast<float>(a[1]);
			case 1: b[0] = a[0] < min ? -FLT_MAX : a[0] > max ? FLT_MAX : static_cast<float>(a[0]);
				break;
			}
		}

		template <>
		inline void impl_cvtspd<double>(double* b, const double* a, size_t n)
		{
			std::memcpy(b, a, n * sizeof(double));
		}

	} // namespace comm

} // namespace core

#endif
