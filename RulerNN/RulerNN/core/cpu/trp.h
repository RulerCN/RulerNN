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

#ifndef __CORE_CPU_TRP_H__
#define __CORE_CPU_TRP_H__

#include "error.h"
#include "trp/trpi8.h"

namespace core
{
	namespace cpu
	{
		// Function template impl_trp

		template <class T, class U>
		void impl_trp(T* dst, const U* src, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_CONVERT);
		}

		template <class T>
		void impl_trp(T* dst, const signed char* src, size_t n)
		{
			impl_trpi8<T>(dst, src, n);
		};

		//template <class T>
		//void impl_trp(T* dst, const signed short* src, size_t n)
		//{
		//	impl_trpi16<T>(dst, src, n);
		//};

		//template <class T>
		//void impl_trp(T* dst, const signed int* src, size_t n)
		//{
		//	impl_trpi32<T>(dst, src, n);
		//};

		//template <class T>
		//void impl_trp(T* dst, const unsigned char* src, size_t n)
		//{
		//	impl_trpu8<T>(dst, src, n);
		//};

		//template <class T>
		//void impl_trp(T* dst, const unsigned short* src, size_t n)
		//{
		//	impl_trpu16<T>(dst, src, n);
		//};

		//template <class T>
		//void impl_trp(T* dst, const unsigned int* src, size_t n)
		//{
		//	impl_trpu32<T>(dst, src, n);
		//};

		//template <class T>
		//void impl_trp(T* dst, const float* src, size_t n)
		//{
		//	impl_trpps<T>(dst, src, n);
		//};

		//template <class T>
		//void impl_trp(T* dst, const double* src, size_t n)
		//{
		//	impl_trppd<T>(dst, src, n);
		//};

	} // namespace cpu

} // namespace core

#endif
