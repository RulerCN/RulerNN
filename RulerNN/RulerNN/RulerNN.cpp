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


template <class T>
void impl_gemm(T* zc, T* za, T* zb, T* c, size_t ldc, const T* a, size_t lda, const T* b, size_t ldb, size_t m, size_t p, size_t n)
{
	constexpr size_t block_m = gemm_block_m<T>();
	constexpr size_t block_p = gemm_block_p<T>();
	constexpr size_t block_n = gemm_block_n<T>();
	// Zigzag encoding cache
	auto a_list = core::cpu::impl_zig(za, a, lda, m, p, false);
	auto b_list = core::cpu::impl_vzig(zb, b, ldb, p, n, false);
	auto c_list = core::cpu::impl_zig(zc, c, ldc, m, n, false);

	size_t x = 0, y = 0, z = 0;
	std::stack<std::tuple<size_t, size_t, size_t, size_t, size_t, size_t>> task;
	for (;;)
	{
		if (m > block_m)
		{
			// exp = log2(m - 1)
			float tmp = static_cast<float>(m - 1);
			size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
			// m0 = pow(2, exp)
			size_t m0 = static_cast<size_t>(1) << exp;
			size_t m1 = m - m0;
			if (p > block_p)
			{
				// exp = log2(p - 1)
				float tmp = static_cast<float>(p - 1);
				size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
				// p0 = pow(2, exp)
				size_t p0 = static_cast<size_t>(1) << exp;
				size_t p1 = p - p0;
				if (n > block_n)
				{
					// exp = log2(n - 1)
					float tmp = static_cast<float>(n - 1);
					size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
					// n0 = pow(2, exp)
					size_t n0 = static_cast<size_t>(1) << exp;
					size_t n1 = n - n0;
					// push the elements
					task.emplace(x + m0, y + p0, z + n0, m1, p1, n1);
					task.emplace(x + m0, y,      z + n0, m1, p0, n1);
					task.emplace(x + m0, y + p0, z,      m1, p1, n0);
					task.emplace(x + m0, y,      z,      m1, p0, n0);
					task.emplace(x,      y + p0, z + n0, m0, p1, n1);
					task.emplace(x,      y,      z + n0, m0, p0, n1);
					task.emplace(x,      y + p0, z,      m0, p1, n0);
					task.emplace(x,      y,      z,      m0, p0, n0);
				}
				else
				{
					task.emplace(x + m0, y + p0, z, m1, p1, n);
					task.emplace(x + m0, y,      z, m1, p0, n);
					task.emplace(x,      y + p0, z, m0, p1, n);
					task.emplace(x,      y,      z, m0, p0, n);
				}
			}
			else
			{
				// exp = log2(p - 1)
				float tmp = static_cast<float>(p - 1);
				size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
				// p0 = pow(2, exp)
				size_t p0 = static_cast<size_t>(1) << exp;
				size_t p1 = p - p0;
				if (n > block_n)
				{
					// exp = log2(n - 1)
					float tmp = static_cast<float>(n - 1);
					size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
					// n0 = pow(2, exp)
					size_t n0 = static_cast<size_t>(1) << exp;
					size_t n1 = n - n0;
					// push the elements
					task.emplace(x + m0, y, z + n0, m1, p, n1);
					task.emplace(x + m0, y, z,      m1, p, n0);
					task.emplace(x,      y, z + n0, m0, p, n1);
					task.emplace(x,      y, z,      m0, p, n0);
				}
				else
				{
					task.emplace(x + m0, y, z, m1, p, n);
					task.emplace(x,      y, z, m0, p, n);
				}
			}
		}
		else
		{
			if (p > block_p)
			{
				// exp = log2(p - 1)
				float tmp = static_cast<float>(p - 1);
				size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
				// p0 = pow(2, exp)
				size_t p0 = static_cast<size_t>(1) << exp;
				size_t p1 = p - p0;
				if (n > block_n)
				{
					// exp = log2(n - 1)
					float tmp = static_cast<float>(n - 1);
					size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
					// n0 = pow(2, exp)
					size_t n0 = static_cast<size_t>(1) << exp;
					size_t n1 = n - n0;
					// push the elements
					task.emplace(x, y + p0, z + n0, m, p1, n1);
					task.emplace(x, y,      z + n0, m, p0, n1);
					task.emplace(x, y + p0, z,      m, p1, n0);
					task.emplace(x, y,      z,      m, p0, n0);
				}
				else
				{
					task.emplace(x, y + p0, z, m, p1, n);
					task.emplace(x, y,      z, m, p0, n);
				}
			}
			else
			{
				// exp = log2(p - 1)
				float tmp = static_cast<float>(p - 1);
				size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
				// p0 = pow(2, exp)
				size_t p0 = static_cast<size_t>(1) << exp;
				size_t p1 = p - p0;
				if (n > block_n)
				{
					// exp = log2(n - 1)
					float tmp = static_cast<float>(n - 1);
					size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
					// n0 = pow(2, exp)
					size_t n0 = static_cast<size_t>(1) << exp;
					size_t n1 = n - n0;
					// push the elements
					task.emplace(x, y, z + n0, m, p, n1);
					task.emplace(x, y, z,      m, p, n0);
				}
				else
				{
					task.emplace(x, y, z, m, p, n);
				}
			}
		}
	}

	// General matrix multiplication
	task.emplace(c, a, b, m, p, n);
	while (!task.empty())
	{
		auto c0 = std::get<0>(task.top());
		auto a0 = std::get<1>(task.top());
		auto b0 = std::get<2>(task.top());
		size_t m0 = std::get<3>(task.top());
		size_t p0 = std::get<4>(task.top());
		size_t n0 = std::get<5>(task.top());
		task.pop();
		if (m0 > block_m)
		{
			// Calculate: exp = log2(m0 - 1)
			float tmp = static_cast<float>(m0 - 1);
			size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
			// Calculate: m1 = pow(2, exp)
			size_t m1 = static_cast<size_t>(1) << exp;
			auto a1 = a0 + m1 * lda;
			auto c1 = c0 + m1 * ldc;
			if (p0 > block_p)
			{
				// Calculate: exp = log2(p0 - 1)
				float tmp = static_cast<float>(p0 - 1);
				size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
				// Calculate: n1 = pow(2, exp)
				size_t p1 = static_cast<size_t>(1) << exp;
				auto b1 = b0 + p1 * ldb;
				if (n0 > block_n)
				{
					// Calculate: exp = log2(n0 - 1)
					float tmp = static_cast<float>(n0 - 1);
					size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
					// Calculate: n1 = pow(2, exp)
					size_t n1 = static_cast<size_t>(1) << exp;
					// Block matrix multiplication
					task.emplace(c0, a0, b0, m1, p1, n1);
					task.emplace(c0, a0 + p1, b1, m1, p0 - p1, n1);
					task.emplace(c0 + n1, a0, b0 + n1, m1, p1, n0 - n1);
					task.emplace(c0 + n1, a0 + p1, b1 + n1, m1, p0 - p1, n0 - n1);
					task.emplace(c1, a1, b0, m0 - m1, p1, n1);
					task.emplace(c1, a1 + p1, b1, m0 - m1, p0 - p1, n1);
					task.emplace(c1 + n1, a1, b0 + n1, m0 - m1, p1, n0 - n1);
					task.emplace(c1 + n1, a1 + p1, b1 + n1, m0 - m1, p0 - p1, n0 - n1);
				}
				else
				{
					// Block matrix multiplication
					task.emplace(c0, a0, b0, m1, p1, n0);
					task.emplace(c0, a0 + p1, b1, m1, p0 - p1, n0);
					task.emplace(c1, a1, b0, m0 - m1, p1, n0);
					task.emplace(c1, a1 + p1, b1, m0 - m1, p0 - p1, n0);
				}
			}
			else
			{
				if (n0 > block_n)
				{
					// Calculate: exp = log2(n0 - 1)
					float tmp = static_cast<float>(n0 - 1);
					size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
					// Calculate: n1 = pow(2, exp)
					size_t n1 = static_cast<size_t>(1) << exp;
					// Block matrix multiplication
					task.emplace(c0, a0, b0, m1, p0, n1);
					task.emplace(c0 + n1, a0, b0 + n1, m1, p0, n0 - n1);
					task.emplace(c1, a1, b0, m0 - m1, p0, n1);
					task.emplace(c1 + n1, a1, b0 + n1, m0 - m1, p0, n0 - n1);
				}
				else
				{
					// Block matrix multiplication
					task.emplace(c0, a0, b0, m1, p0, n0);
					task.emplace(c1, a1, b0, m0 - m1, p0, n0);
				}
			}
		}
		else
		{
			if (p0 > block_p)
			{
				// Calculate: exp = log2(p0 - 1)
				float tmp = static_cast<float>(p0 - 1);
				size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
				// Calculate: n1 = pow(2, exp)
				size_t p1 = static_cast<size_t>(1) << exp;
				auto b1 = b0 + p1 * ldb;
				if (n0 > block_n)
				{
					// Calculate: exp = log2(n0 - 1)
					float tmp = static_cast<float>(n0 - 1);
					size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
					// Calculate: n1 = pow(2, exp)
					size_t n1 = static_cast<size_t>(1) << exp;
					// Block matrix multiplication
					task.emplace(c0, a0, b0, m0, p1, n1);
					task.emplace(c0, a0 + p1, b1, m0, p0 - p1, n1);
					task.emplace(c0 + n1, a0, b0 + n1, m0, p1, n0 - n1);
					task.emplace(c0 + n1, a0 + p1, b1 + n1, m0, p0 - p1, n0 - n1);
				}
				else
				{
					// Block matrix multiplication
					task.emplace(c0, a0, b0, m0, p1, n0);
					task.emplace(c0, a0 + p1, b1, m0, p0 - p1, n0);
				}
			}
			else
			{
				if (n0 > block_n)
				{
					// Calculate: exp = log2(n0 - 1)
					float tmp = static_cast<float>(n0 - 1);
					size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
					// Calculate: n1 = pow(2, exp)
					size_t n1 = static_cast<size_t>(1) << exp;
					// Block matrix multiplication
					task.emplace(c0, a0, b0, m0, p0, n1);
					task.emplace(c0 + n1, a0, b0 + n1, m0, p0, n0 - n1);
				}
				else
				{
					if (m0 == block_m && n0 == block_n)
						add_dot_block(c0, ldc, a0, lda, b0, ldb, p0);
					else
						add_dot_tiny(c0, ldc, a0, lda, b0, ldb, m0, p0, n0);
				}
			}
		}
	}
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
		// std::cout << "L2 cache: " << core::simd::l2_cache_size << "\n";

		core::matrix<float> a(20, 20, 1);
		core::matrix<float> b(60, 8, 1);
		core::matrix<float> c(60, 8, 1);

		float* pa = a.data();
		float* pb = b.data();
		float* pc = c.data();

		for (int i = 0; i < a.size(); i++)
			pa[i] = i;
		std::cout << a << "\n";

		core::cpu::impl_zig(pb, pa, a.line(), a.rows(), a.cols(), false);
		std::cout << b << "\n";

		core::cpu::impl_vzig(pb, pa, a.line(), a.rows(), a.cols(), false);
		std::cout << b << "\n";

		core::cpu::impl_zig(pc, pa, a.line(), a.rows(), a.cols(), true);
		std::cout << c << "\n";

		core::cpu::impl_vzig(pc, pa, a.line(), a.rows(), a.cols(), true);
		std::cout << c << "\n";

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