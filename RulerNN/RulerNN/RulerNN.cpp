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

template<class A>
std::ostream& operator<<(std::ostream& os, const core::matrix<signed char, A>& mat)
{
	std::cout << std::hex << std::setfill('0');
	for (auto j = mat.vbegin(); j != mat.vend(); ++j)
	{
		for (auto i = mat.begin(j); i != mat.end(j); ++i)
			std::cout << std::setw(2) << static_cast<signed int>(*i & 0xff) << " ";
		std::cout << std::endl;
	}
	return os;
}

template<class A>
std::ostream& operator<<(std::ostream& os, const core::matrix<signed short, A>& mat)
{
	std::cout << std::hex << std::setfill('0');
	for (auto j = mat.vbegin(); j != mat.vend(); ++j)
	{
		for (auto i = mat.begin(j); i != mat.end(j); ++i)
			std::cout << std::setw(4) << static_cast<signed int>(*i & 0xffff) << " ";
		std::cout << std::endl;
	}
	return os;
}

template<class A>
std::ostream& operator<<(std::ostream& os, const core::matrix<signed int, A>& mat)
{
	std::cout << std::hex << std::setfill('0');
	for (auto j = mat.vbegin(); j != mat.vend(); ++j)
	{
		for (auto i = mat.begin(j); i != mat.end(j); ++i)
			std::cout << std::setw(4) << static_cast<signed int>(*i & 0xffff) << " ";
		std::cout << std::endl;
	}
	return os;
}

template<class A>
std::ostream& operator<<(std::ostream& os, const core::matrix<unsigned int, A>& mat)
{
	std::cout << std::hex << std::setfill('0');
	for (auto j = mat.vbegin(); j != mat.vend(); ++j)
	{
		for (auto i = mat.begin(j); i != mat.end(j); ++i)
			std::cout << std::setw(4) << static_cast<unsigned int>(*i & 0xffff) << " ";
		std::cout << std::endl;
	}
	return os;
}

template<class A>
std::ostream& operator<<(std::ostream& os, const core::matrix<float, A>& mat)
{
	std::cout << std::setfill('0');
	for (auto j = mat.vbegin(); j != mat.vend(); ++j)
	{
		for (auto i = mat.begin(j); i != mat.end(j); ++i)
			std::cout << std::setw(4) << *i << " ";
		std::cout << std::endl;
	}
	return os;
}

template<class A>
std::ostream& operator<<(std::ostream& os, const core::matrix<double, A>& mat)
{
	std::cout << std::setfill('0');
	for (auto j = mat.vbegin(); j != mat.vend(); ++j)
	{
		for (auto i = mat.begin(j); i != mat.end(j); ++i)
			std::cout << std::setw(4) << *i << " ";
		std::cout << std::endl;
	}
	return os;
}

int main()
{
	try
	{
		// Enable OpenMP support.
		core::openmp::enable();
		// Print number of threads.
		std::cout << "threads: " << core::openmp::num_thread << "\n";
		// Print L2 cache size.
		std::cout << "L2 cache: " << core::simd::l2_cache_size << "\n";

		core::device device;
		core::device_cpu cpu;
		core::device::steady_time_point start, end;
		long long duration1, duration2;

		size_t m = 10000;
		size_t n = 10000;
		signed char* x = new signed char[m * n];
		signed char* y = new signed char[m * n];

		core::matrix<signed char> src(m, n, 1, x, core::WITHOUT_COPY);
		core::matrix<signed char> dst(m, n, 1, y, core::WITHOUT_COPY);

		for (size_t i = 0; i < m * n; ++i)
		{
			x[i] = i;
			y[i] = 0;
		}
		//std::cout << src;

		start = core::device::steady_time();
		//cpu.trp(dst, src);
		device.trp(dst, src);
		end = core::device::steady_time();
		duration1 = core::device::get_milliseconds(start, end);
		std::cout << "cpu:" << duration1 << "\n";

		//start = core::device::steady_time();
		//cpu.trp(dst, src);
		//end = core::device::steady_time();
		//duration2 = core::device::get_milliseconds(start, end);
		//std::cout << "cpu:" << duration2 << "\n";

		//std::cout << dst;
		delete[] x;
		delete[] y;
	}
	catch (std::exception err)
	{
		std::cout << err.what() << "\n";
	}
}
