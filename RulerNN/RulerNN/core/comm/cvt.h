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

#ifndef __CORE_COMM_CVT_H__
#define __CORE_COMM_CVT_H__

#include "error.h"
#include "cvt/cvti8.h"
#include "cvt/cvti16.h"
#include "cvt/cvti32.h"
#include "cvt/cvtu8.h"
#include "cvt/cvtu16.h"
#include "cvt/cvtu32.h"
#include "cvt/cvtps.h"
#include "cvt/cvtpd.h"
#include "cvt/cvtsi8.h"
#include "cvt/cvtsi16.h"
#include "cvt/cvtsi32.h"
#include "cvt/cvtsu8.h"
#include "cvt/cvtsu16.h"
#include "cvt/cvtsu32.h"
#include "cvt/cvtsps.h"
#include "cvt/cvtspd.h"

namespace core
{
	namespace comm
	{
		// Function template impl_cvt

		template <class T, class U>
		void impl_cvt(T* b, const U* a, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_CONVERT);
		}

		template <class T>
		void impl_cvt(T* b, const signed char* a, size_t n)
		{
			impl_cvti8<T>(b, a, n);
		};

		template <class T>
		void impl_cvt(T* b, const signed short* a, size_t n)
		{
			impl_cvti16<T>(b, a, n);
		};

		template <class T>
		void impl_cvt(T* b, const signed int* a, size_t n)
		{
			impl_cvti32<T>(b, a, n);
		};

		template <class T>
		void impl_cvt(T* b, const unsigned char* a, size_t n)
		{
			impl_cvtu8<T>(b, a, n);
		};

		template <class T>
		void impl_cvt(T* b, const unsigned short* a, size_t n)
		{
			impl_cvtu16<T>(b, a, n);
		};

		template <class T>
		void impl_cvt(T* b, const unsigned int* a, size_t n)
		{
			impl_cvtu32<T>(b, a, n);
		};

		template <class T>
		void impl_cvt(T* b, const float* a, size_t n)
		{
			impl_cvtps<T>(b, a, n);
		};

		template <class T>
		void impl_cvt(T* b, const double* a, size_t n)
		{
			impl_cvtpd<T>(b, a, n);
		};

		// Function template impl_cvts

		template <class T, class U>
		void impl_cvts(T* b, const U* a, size_t n)
		{
			throw std::domain_error(UNIMPLEMENTED_CONVERT);
		}

		template <class T>
		void impl_cvts(T* b, const signed char* a, size_t n)
		{
			impl_cvtsi8<T>(b, a, n);
		};

		template <class T>
		void impl_cvts(T* b, const signed short* a, size_t n)
		{
			impl_cvtsi16<T>(b, a, n);
		};

		template <class T>
		void impl_cvts(T* b, const signed int* a, size_t n)
		{
			impl_cvtsi32<T>(b, a, n);
		};

		template <class T>
		void impl_cvts(T* b, const unsigned char* a, size_t n)
		{
			impl_cvtsu8<T>(b, a, n);
		};

		template <class T>
		void impl_cvts(T* b, const unsigned short* a, size_t n)
		{
			impl_cvtsu16<T>(b, a, n);
		};

		template <class T>
		void impl_cvts(T* b, const unsigned int* a, size_t n)
		{
			impl_cvtsu32<T>(b, a, n);
		};

		template <class T>
		void impl_cvts(T* b, const float* a, size_t n)
		{
			impl_cvtsps<T>(b, a, n);
		};

		template <class T>
		void impl_cvts(T* b, const double* a, size_t n)
		{
			impl_cvtspd<T>(b, a, n);
		};

	} // namespace comm

} // namespace core

#endif
