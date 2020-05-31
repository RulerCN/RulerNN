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

#ifndef __CORE_OPENMP_H__
#define __CORE_OPENMP_H__

#include <stdexcept>
#include "define.h"

// Support OpenMP
#ifdef _OPENMP
#include <omp.h>
#endif

namespace core
{
	// Class openmp
	class openmp
	{
	public:
		// Enable OpenMP support.
		static void enable(signed int number = 0)
		{
		#ifndef _OPENMP
			throw std::domain_error(NO_SUPPORT_OPENMP);
		#else
			signed int max_thread = omp_get_num_procs();
			// Specify absolute number of threads.
			if (number > 0)
				num_thread = number;
			// Specify relative number of threads.
			else if (max_thread + number > 0)
				num_thread = max_thread + number;
			else
				num_thread = 1;
			// Sets the number of threads in subsequent parallel regions.
			omp_set_num_threads(num_thread);
		#endif
		}
	public:
		static signed int num_thread;
	};

	// Initialize static variables.
	signed int openmp::num_thread = 1;

} // namespace core

#endif
