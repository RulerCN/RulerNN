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

		float a[100] = {
			 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
			10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
			20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
			30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
			40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
			50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
			60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
			70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
			80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
			90, 91, 92, 93, 94, 95, 96, 97, 98, 99
		};
		float b[256];
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
				std::cout << a[i * 10 + j] << "\t";
			std::cout << "\n";
		}
		std::cout << "\n";

		core::cpu::impl_vzig(b, a, 10, 10, 10);
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 8; j++)
				std::cout << b[i * 8 + j] << "\t";
			std::cout << "\n";
		}
		std::cout << "\n";

		core::cpu::impl_vzig(b, a, 10, 10, 10, true);
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 8; j++)
				std::cout << b[i * 8 + j] << "\t";
			std::cout << "\n";
		}

		//impl_zig((float*)nullptr, (float*)nullptr, 45, 45, 45);

		//test_trp<float>(10000, 10000);
		//test_gemm<float>(  50,   50,   50);
		//test_gemm<float>(  60,   60,   60);
		//test_gemm<float>(  70,   70,   70);
		//test_gemm<float>(  80,   80,   80);
		//test_gemm<float>(  90,   90,   90);
		//test_gemm<float>( 100,  100,  100);
		//test_gemm<float>( 200,  200,  200);
		//test_gemm<float>( 300,  300,  300);
		//test_gemm<float>( 400,  400,  400);
		//test_gemm<float>( 500,  500,  500);
		//test_gemm<float>( 600,  600,  600);
		//test_gemm<float>( 700,  700,  700);
		//test_gemm<float>( 800,  800,  800);
		//test_gemm<float>( 900,  900,  900);
		//test_gemm<float>(1000, 1000, 1000);
		//test_gemm<float>(1100, 2100, 1100);
		//test_gemm<float>(1200, 2200, 1200);
		//test_gemm<float>(1300, 2300, 1300);
		//test_gemm<float>(1400, 2400, 1400);
		//test_gemm<float>(1500, 2500, 1500);
		//test_gemm<float>(1600, 2600, 1600);
		//test_gemm<float>(1700, 2700, 1700);
		//test_gemm<float>(1800, 2800, 1800);
		//test_gemm<float>(1900, 2900, 1900);
		//test_gemm<float>(2000, 2000, 2000);
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
	float max = static_cast<float>(1024 * 1024 * 1024);
	float size = static_cast<float>(m * p * n);
	size_t loop = static_cast<size_t>(std::ceilf(max / size));
	loop = 1000;
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
	for (size_t i = 0 ; i < loop; ++i)
		cpu.gemm(c, a, b);
	auto end = core::device::steady_time();
	auto duration = core::device::get_microseconds(start, end);

	std::cout << "cpu.gemm() "
		<< "size: " << size << "\t"
		<< "loop: " << loop << "\t"
		<< "time: " << duration << "us\t"
		<< 2.0f * size * loop / max * 1000000 / duration << " GFOPS\n";

	std::cout << std::setiosflags(std::ios::scientific) << std::setprecision(8);
	std::cout << ptr_c[0] << "\t" << ptr_c[1] << "\t" << ptr_c[2] << "\n";
	std::cout << ptr_c[c.size() - 3] << "\t" << ptr_c[c.size() - 2] << "\t" << ptr_c[c.size() - 1];
}


template<class T>
void test_gemm2(const size_t m, const size_t p, const size_t n)
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
		ptr_a[i] = i * 1.0e-4f;
	for (size_t i = 0; i < b.size(); ++i)
		ptr_b[i] = i * 1.0e-4f;
	// Matrix Multiply.
	auto start = core::device::steady_time();
	cpu.gemm(c, a, b);
	auto end = core::device::steady_time();
	auto duration = core::device::get_microseconds(start, end);

	std::cout << "cpu.gemm() "
		<< "time: " << duration << "us\n";

	//std::cout << std::setiosflags(std::ios::scientific) << std::setprecision(8);
	//std::cout << ptr_c[0] << "\t" << ptr_c[1] << "\t" << ptr_c[2] << "\n";
	//std::cout << ptr_c[c.size() - 3] << "\t" << ptr_c[c.size() - 2] << "\t" << ptr_c[c.size() - 1];
}