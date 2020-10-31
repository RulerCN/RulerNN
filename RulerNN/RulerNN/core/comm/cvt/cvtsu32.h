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
		void impl_cvtsu32(T* b, const unsigned int* a, size_t n)
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
		void impl_cvtsu32<signed char>(signed char* b, const unsigned int* a, size_t n)
		{
			constexpr size_t block = 8;
			while (n >= block)
			{
				b[0] = a[0] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[0]);
				b[1] = a[1] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[1]);
				b[2] = a[2] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[2]);
				b[3] = a[3] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[3]);
				b[4] = a[4] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[4]);
				b[5] = a[5] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[5]);
				b[6] = a[6] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[6]);
				b[7] = a[7] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[6]);
			case 6: b[5] = a[5] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[5]);
			case 5: b[4] = a[4] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[4]);
			case 4: b[3] = a[3] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[3]);
			case 3: b[2] = a[2] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[2]);
			case 2: b[1] = a[1] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[1]);
			case 1: b[0] = a[0] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtsu32<unsigned char>(unsigned char* b, const unsigned int* a, size_t n)
		{
			constexpr size_t block = 8;
			while (n >= block)
			{
				b[0] = a[0] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[0]);
				b[1] = a[1] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[1]);
				b[2] = a[2] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[2]);
				b[3] = a[3] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[3]);
				b[4] = a[4] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[4]);
				b[5] = a[5] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[5]);
				b[6] = a[6] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[6]);
				b[7] = a[7] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[6]);
			case 6: b[5] = a[5] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[5]);
			case 5: b[4] = a[4] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[4]);
			case 4: b[3] = a[3] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[3]);
			case 3: b[2] = a[2] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[2]);
			case 2: b[1] = a[1] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[1]);
			case 1: b[0] = a[0] > UINT8_MAX ? UINT8_MAX : static_cast<unsigned char>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtsu32<signed short>(signed short* b, const unsigned int* a, size_t n)
		{
			constexpr size_t block = 8;
			while (n >= block)
			{
				b[0] = a[0] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[0]);
				b[1] = a[1] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[1]);
				b[2] = a[2] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[2]);
				b[3] = a[3] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[3]);
				b[4] = a[4] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[4]);
				b[5] = a[5] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[5]);
				b[6] = a[6] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[6]);
				b[7] = a[7] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[6]);
			case 6: b[5] = a[5] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[5]);
			case 5: b[4] = a[4] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[4]);
			case 4: b[3] = a[3] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[3]);
			case 3: b[2] = a[2] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[2]);
			case 2: b[1] = a[1] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[1]);
			case 1: b[0] = a[0] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[0]);
				break;
			}
		}

		template<>
		void impl_cvtsu32<unsigned short>(unsigned short* b, const unsigned int* a, size_t n)
		{
			constexpr size_t block = 8;
			while (n >= block)
			{
				b[0] = a[0] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[0]);
				b[1] = a[1] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[1]);
				b[2] = a[2] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[2]);
				b[3] = a[3] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[3]);
				b[4] = a[4] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[4]);
				b[5] = a[5] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[5]);
				b[6] = a[6] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[6]);
				b[7] = a[7] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[7]);
				a += block;
				b += block;
				n -= block;
			}
			switch (n)
			{
			case 7: b[6] = a[6] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[6]);
			case 6: b[5] = a[5] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[5]);
			case 5: b[4] = a[4] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[4]);
			case 4: b[3] = a[3] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[3]);
			case 3: b[2] = a[2] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[2]);
			case 2: b[1] = a[1] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[1]);
			case 1: b[0] = a[0] > UINT16_MAX ? UINT16_MAX : static_cast<unsigned short>(a[0]);
				break;
			}
		}

		template <>
		inline void impl_cvtsu32<signed int>(signed int* b, const unsigned int* a, size_t n)
		{
			std::memcpy(b, a, n * sizeof(unsigned int));
		}

		template <>
		inline void impl_cvtsu32<unsigned int>(unsigned int* b, const unsigned int* a, size_t n)
		{
			std::memcpy(b, a, n * sizeof(unsigned int));
		}

	} // namespace comm

} // namespace core

#endif
