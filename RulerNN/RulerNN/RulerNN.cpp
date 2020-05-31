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

#include <iostream>
#include <sstream>
#include "core/core.h"
#include "core/cpu/simd.h"

int main()
{
	try
	{
		// Enable OpenMP support.
		core::openmp::enable();
		// Print number of threads.
		std::cout << "threads: " << core::openmp::num_thread << "\n";

		core::simd::detect_l2_cache();
		//auto l2_line_size = core::simd::detect_l2_line_szie();
		//auto l3_line_size = core::simd::detect_l3_line_szie();
		//auto l2_cache = core::simd::detect_l2_cache();
		//auto l3_cache = core::simd::detect_l3_cache();
		//std::cout << "L1 line size: " << l1_line_size << "byte\n";
		//std::cout << "L2 line size: " << l2_line_size << "byte\n";
		//std::cout << "L3 line size: " << l3_line_size << "byte\n";
		//std::cout << "L2 cache: " << l2_cache << "k\n";
		//std::cout << "L3 cache: " << l3_cache << "k\n";

		short a = core::string::to_short("1F1E", std::hex);
		std::cout << "a: " << a << "\n";

	}
	catch (std::exception err)
	{
		std::cout << err.what() << "\n";
	}
}
