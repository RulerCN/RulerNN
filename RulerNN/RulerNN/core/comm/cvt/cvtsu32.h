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

#ifndef __CORE_COMM_CVTSU32_H__
#define __CORE_COMM_CVTSU32_H__

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace core
{
	namespace comm
	{
		// Function template impl_cvtsu32

		template <class T>
		void impl_cvtsu32(T* dst, const unsigned int* src, size_t n)
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
		void impl_cvtsu32<signed char>(signed char* dst, const unsigned int* src, size_t n)
		{
			constexpr size_t block = 8;
			while (n >= block)
			{
				dst[0] = src[0] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[0]);
				dst[1] = src[1] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[1]);
				dst[2] = src[2] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[2]);
				dst[3] = src[3] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[3]);
				dst[4] = src[4] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[4]);
				dst[5] = src[5] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[5]);
				dst[6] = src[6] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[6]);
				dst[7] = src[7] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[6]);
			case 6: dst[5] = src[5] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[5]);
			case 5: dst[4] = src[4] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[4]);
			case 4: dst[3] = src[3] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[3]);
			case 3: dst[2] = src[2] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[2]);
			case 2: dst[1] = src[1] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[1]);
			case 1: dst[0] = src[0] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[0]);
				break;
			}
		}

		template<>
		void impl_cvtsu32<unsigned char>(unsigned char* dst, const unsigned int* src, size_t n)
		{
			constexpr size_t block = 8;
			while (n >= block)
			{
				dst[0] = src[0] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[0]);
				dst[1] = src[1] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[1]);
				dst[2] = src[2] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[2]);
				dst[3] = src[3] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[3]);
				dst[4] = src[4] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[4]);
				dst[5] = src[5] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[5]);
				dst[6] = src[6] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[6]);
				dst[7] = src[7] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[6]);
			case 6: dst[5] = src[5] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[5]);
			case 5: dst[4] = src[4] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[4]);
			case 4: dst[3] = src[3] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[3]);
			case 3: dst[2] = src[2] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[2]);
			case 2: dst[1] = src[1] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[1]);
			case 1: dst[0] = src[0] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(src[0]);
				break;
			}
		}

		template<>
		void impl_cvtsu32<signed short>(signed short* dst, const unsigned int* src, size_t n)
		{
			constexpr size_t block = 8;
			while (n >= block)
			{
				dst[0] = src[0] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[0]);
				dst[1] = src[1] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[1]);
				dst[2] = src[2] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[2]);
				dst[3] = src[3] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[3]);
				dst[4] = src[4] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[4]);
				dst[5] = src[5] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[5]);
				dst[6] = src[6] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[6]);
				dst[7] = src[7] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[6]);
			case 6: dst[5] = src[5] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[5]);
			case 5: dst[4] = src[4] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[4]);
			case 4: dst[3] = src[3] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[3]);
			case 3: dst[2] = src[2] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[2]);
			case 2: dst[1] = src[1] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[1]);
			case 1: dst[0] = src[0] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[0]);
				break;
			}
		}

		template<>
		void impl_cvtsu32<unsigned short>(unsigned short* dst, const unsigned int* src, size_t n)
		{
			constexpr size_t block = 8;
			while (n >= block)
			{
				dst[0] = src[0] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[0]);
				dst[1] = src[1] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[1]);
				dst[2] = src[2] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[2]);
				dst[3] = src[3] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[3]);
				dst[4] = src[4] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[4]);
				dst[5] = src[5] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[5]);
				dst[6] = src[6] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[6]);
				dst[7] = src[7] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[7]);
				src += block;
				dst += block;
				n -= block;
			}
			switch (n)
			{
			case 7: dst[6] = src[6] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[6]);
			case 6: dst[5] = src[5] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[5]);
			case 5: dst[4] = src[4] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[4]);
			case 4: dst[3] = src[3] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[3]);
			case 3: dst[2] = src[2] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[2]);
			case 2: dst[1] = src[1] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[1]);
			case 1: dst[0] = src[0] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(src[0]);
				break;
			}
		}

		template <>
		inline void impl_cvtsu32<signed int>(signed int* dst, const unsigned int* src, size_t n)
		{
			std::memcpy(dst, src, n * sizeof(unsigned int));
		}

		template <>
		inline void impl_cvtsu32<unsigned int>(unsigned int* dst, const unsigned int* src, size_t n)
		{
			std::memcpy(dst, src, n * sizeof(unsigned int));
		}

	} // namespace comm

} // namespace core

#endif
