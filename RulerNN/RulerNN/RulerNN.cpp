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

template<class T>
void test_trp(const size_t m, const size_t n);

template<class T>
void test_gemm(const size_t m, const size_t p, const size_t n);

int main()
{
	try
	{
		// Enable OpenMP support.
		core::openmp::enable();
		// Print number of threads.
		std::cout << "threads: " << core::openmp::num_thread << "\n";
		// Print L2 cache size.
		// std::cout << "L2 cache: " << core::simd::l2_cache_size << "\n";

		//test_trp<float>(10000, 10000);
		test_gemm<float>(100, 100, 100);
	}
	catch (std::exception err)
	{
		std::cout << err.what() << "\n";
	}
}

template<class T>
void test_trp(const size_t m, const size_t n)
{
	core::device device;
	core::device_cpu cpu;
	core::matrix<T> a(m, n, 1);
	core::matrix<T> b(n, m, 1);

	// Matrix initialization.
	T* ptr_a = a.data();
	T* ptr_b = b.data();
	for (size_t i = 0; i < a.size(); ++i)
		ptr_a[i] = i;
	for (size_t i = 0; i < b.size(); ++i)
		ptr_b[i] = i;
	// Matrix Transpose.
	auto start = core::device::steady_time();
	device.trp(b, a);
	auto end = core::device::steady_time();
	auto duration = core::device::get_milliseconds(start, end);
	std::cout << "device.transpose(): " << duration << "ms\n";
	// Matrix Transpose.
	start = core::device::steady_time();
	cpu.trp(b, a);
	end = core::device::steady_time();
	duration = core::device::get_milliseconds(start, end);
	std::cout << "cpu.transpose(): " << duration << "ms\n";
}

template<class T>
void test_gemm(const size_t m, const size_t p, const size_t n)
{
	core::device device;
	core::device_cpu cpu;
	core::matrix<T> a(m, p, 1);
	core::matrix<T> b(p, n, 1);
	core::matrix<T> c(m, n, 1, T(0));

	// Matrix initialization.
	T* ptr_a = a.data();
	T* ptr_b = b.data();
	T* ptr_c = c.data();
	for (size_t i = 0; i < a.size(); ++i)
		ptr_a[i] = i;
	for (size_t i = 0; i < b.size(); ++i)
		ptr_b[i] = i;
	// Matrix Multiply.
	auto start = core::device::steady_time();

	device.gemm(c, a, b);
	device.gemm(c, a, b);
	device.gemm(c, a, b);
	device.gemm(c, a, b);
	device.gemm(c, a, b);
	device.gemm(c, a, b);
	device.gemm(c, a, b);
	device.gemm(c, a, b);
	device.gemm(c, a, b);
	device.gemm(c, a, b);

	auto end = core::device::steady_time();
	auto duration = core::device::get_microseconds(start, end) / 10;
	std::cout << "device.gemm(): " << duration << "us\n";
	std::cout << "device.gemm(): " << 2 * 9.31322574615478515625E-4 * m * p * n / duration << " GFOPS\n";

	std::cout << std::setiosflags(std::ios::scientific) << std::setprecision(8);
	std::cout << ptr_c[0] << "\t" << ptr_c[1] << "\t" << ptr_c[2] << "\n";
	std::cout << ptr_c[c.size() - 3] << "\t" << ptr_c[c.size() - 2] << "\t" << ptr_c[c.size() - 1];
}
