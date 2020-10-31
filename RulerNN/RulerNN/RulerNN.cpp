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
void impl_zig(T* b, const T* a, size_t lda, size_t m, size_t n);


float* trp_block(float* b, const float* a, size_t lda)
{
	const float* ptr_a0 = a;
	const float* ptr_a1 = a + lda;
	const float* ptr_a2 = ptr_a1 + lda;
	const float* ptr_a3 = ptr_a2 + lda;
	const float* ptr_a4 = ptr_a3 + lda;
	const float* ptr_a5 = ptr_a4 + lda;
	const float* ptr_a6 = ptr_a5 + lda;
	const float* ptr_a7 = ptr_a6 + lda;
	__m256 ymm_a0 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_a0));
	__m256 ymm_a1 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_a1));
	__m256 ymm_a2 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_a2));
	__m256 ymm_a3 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_a3));
	__m256 ymm_a4 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_a0 + 4));
	__m256 ymm_a5 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_a1 + 4));
	__m256 ymm_a6 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_a2 + 4));
	__m256 ymm_a7 = _mm256_castps128_ps256(_mm_loadu_ps(ptr_a3 + 4));
	__m256 ymm_b0 = _mm256_insertf128_ps(ymm_a0, _mm_loadu_ps(ptr_a4), 1);
	__m256 ymm_b1 = _mm256_insertf128_ps(ymm_a1, _mm_loadu_ps(ptr_a5), 1);
	__m256 ymm_b2 = _mm256_insertf128_ps(ymm_a2, _mm_loadu_ps(ptr_a6), 1);
	__m256 ymm_b3 = _mm256_insertf128_ps(ymm_a3, _mm_loadu_ps(ptr_a7), 1);
	__m256 ymm_b4 = _mm256_insertf128_ps(ymm_a4, _mm_loadu_ps(ptr_a4 + 4), 1);
	__m256 ymm_b5 = _mm256_insertf128_ps(ymm_a5, _mm_loadu_ps(ptr_a5 + 4), 1);
	__m256 ymm_b6 = _mm256_insertf128_ps(ymm_a6, _mm_loadu_ps(ptr_a6 + 4), 1);
	__m256 ymm_b7 = _mm256_insertf128_ps(ymm_a7, _mm_loadu_ps(ptr_a7 + 4), 1);
	ymm_a0 = _mm256_shuffle_ps(ymm_b0, ymm_b1, _MM_SHUFFLE(1, 0, 1, 0));
	ymm_a1 = _mm256_shuffle_ps(ymm_b2, ymm_b3, _MM_SHUFFLE(1, 0, 1, 0));
	ymm_a2 = _mm256_shuffle_ps(ymm_b0, ymm_b1, _MM_SHUFFLE(3, 2, 3, 2));
	ymm_a3 = _mm256_shuffle_ps(ymm_b2, ymm_b3, _MM_SHUFFLE(3, 2, 3, 2));
	ymm_a4 = _mm256_shuffle_ps(ymm_b4, ymm_b5, _MM_SHUFFLE(1, 0, 1, 0));
	ymm_a5 = _mm256_shuffle_ps(ymm_b6, ymm_b7, _MM_SHUFFLE(1, 0, 1, 0));
	ymm_a6 = _mm256_shuffle_ps(ymm_b4, ymm_b5, _MM_SHUFFLE(3, 2, 3, 2));
	ymm_a7 = _mm256_shuffle_ps(ymm_b6, ymm_b7, _MM_SHUFFLE(3, 2, 3, 2));
	ymm_b0 = _mm256_shuffle_ps(ymm_a0, ymm_a1, _MM_SHUFFLE(2, 0, 2, 0));
	ymm_b1 = _mm256_shuffle_ps(ymm_a0, ymm_a1, _MM_SHUFFLE(3, 1, 3, 1));
	ymm_b2 = _mm256_shuffle_ps(ymm_a2, ymm_a3, _MM_SHUFFLE(2, 0, 2, 0));
	ymm_b3 = _mm256_shuffle_ps(ymm_a2, ymm_a3, _MM_SHUFFLE(3, 1, 3, 1));
	ymm_b4 = _mm256_shuffle_ps(ymm_a4, ymm_a5, _MM_SHUFFLE(2, 0, 2, 0));
	ymm_b5 = _mm256_shuffle_ps(ymm_a4, ymm_a5, _MM_SHUFFLE(3, 1, 3, 1));
	ymm_b6 = _mm256_shuffle_ps(ymm_a6, ymm_a7, _MM_SHUFFLE(2, 0, 2, 0));
	ymm_b7 = _mm256_shuffle_ps(ymm_a6, ymm_a7, _MM_SHUFFLE(3, 1, 3, 1));
	_mm256_storeu_ps(b, ymm_b0);
	_mm256_storeu_ps(b + 8, ymm_b1);
	_mm256_storeu_ps(b + 16, ymm_b2);
	_mm256_storeu_ps(b + 24, ymm_b3);
	_mm256_storeu_ps(b + 32, ymm_b4);
	_mm256_storeu_ps(b + 40, ymm_b5);
	_mm256_storeu_ps(b + 48, ymm_b6);
	_mm256_storeu_ps(b + 56, ymm_b7);
	return b + 64;
}

float* trp_tiny(float* b, const float* a, size_t lda, size_t m, size_t n)
{
	__m256 ymm_a = _mm256_setzero_ps();
	for (size_t i = 0; i < n; ++i)
	{
		switch (m)
		{
		case 8: reinterpret_cast<float*>(&ymm_a)[7] = a[lda * 7];
		case 7: reinterpret_cast<float*>(&ymm_a)[6] = a[lda * 6];
		case 6: reinterpret_cast<float*>(&ymm_a)[5] = a[lda * 5];
		case 5: reinterpret_cast<float*>(&ymm_a)[4] = a[lda * 4];
		case 4: reinterpret_cast<float*>(&ymm_a)[3] = a[lda * 3];
		case 3: reinterpret_cast<float*>(&ymm_a)[2] = a[lda * 2];
		case 2: reinterpret_cast<float*>(&ymm_a)[1] = a[lda];
		case 1: reinterpret_cast<float*>(&ymm_a)[0] = a[0];
		}
		_mm256_storeu_ps(b, ymm_a);
		a += 1;
		b += 8;
	}
	return b;
}

inline void trp_tiny1(float* b, size_t ldb, const float* a, size_t lda, size_t m, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		switch (m)
		{
		case 8: b[7] = a[lda * 7]; [[fallthrough]];
		case 7: b[6] = a[lda * 6]; [[fallthrough]];
		case 6: b[5] = a[lda * 5]; [[fallthrough]];
		case 5: b[4] = a[lda * 4]; [[fallthrough]];
		case 4: b[3] = a[lda * 3]; [[fallthrough]];
		case 3: b[2] = a[lda * 2]; [[fallthrough]];
		case 2: b[1] = a[lda]; [[fallthrough]];
		case 1: b[0] = a[0]; [[fallthrough]];
		}
		a += 1;
		b += ldb;
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

		float a[64] = {
			11, 12, 13, 14, 15, 16, 17, 18,
			21, 22, 23, 24, 25, 26, 27, 28,
			31, 32, 33, 34, 35, 36, 37, 38,
			41, 42, 43, 44, 45, 46, 47, 48,
			51, 52, 53, 54, 55, 56, 57, 58,
			61, 62, 63, 64, 65, 66, 67, 68,
			71, 72, 73, 74, 75, 76, 77, 78,
			81, 82, 83, 84, 85, 86, 87, 88
		};
		float b[64];
		trp_tiny1(b, 8, a, 8, 8, 8);

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				std::cout << a[i * 8 + j] << "\t";
			std::cout << "\n";
		}
		std::cout << "\n";
		for (int i = 0; i < 8; i++)
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

// Function template zigzag_block_m
template<class T>
constexpr size_t zigzag_block_m(void)
{
	return static_cast<size_t>(8);
}

// Function template zigzag_block_n
template<class T>
constexpr size_t zigzag_block_n(void)
{
	return static_cast<size_t>(8);
}

template <class T>
void impl_zig(T* b, const T* a, size_t lda, size_t m, size_t n)
{
	constexpr size_t block_m = zigzag_block_m<T>();
	constexpr size_t block_n = zigzag_block_n<T>();
	size_t i = 0;
	size_t j = 0;
	std::stack<std::tuple<const T*, size_t, size_t, size_t, size_t>> task;
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
			const T* p = a + m0 * lda;
			if (n > block_n)
			{
				// exp = log2(n - 1)
				float tmp = static_cast<float>(n - 1);
				size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
				// n0 = pow(2, exp)
				size_t n0 = static_cast<size_t>(1) << exp;
				size_t n1 = n - n0;
				// push the elements
				task.emplace(p + n0, i + m0, j + n0, m1, n1);
				task.emplace(p,      i + m0, j,      m1, n0);
				task.emplace(a + n0, i,      j + n0, m0, n1);
				task.emplace(a,      i,      j,      m0, n0);
			}
			else
			{
				task.emplace(p, i + m0, j, m1, n);
				task.emplace(a, i,      j, m0, n);
			}
		}
		else
		{
			if (n > block_n)
			{
				// exp = log2(n - 1)
				float tmp = static_cast<float>(n - 1);
				size_t exp = ((*reinterpret_cast<unsigned int*>(&tmp)) >> 23 & 0xFFu) - 0x7Fu;
				// n0 = pow(2, exp)
				size_t n0 = static_cast<size_t>(1) << exp;
				size_t n1 = n - n0;
				// push the elements
				task.emplace(a + n0, i, j + n0, m, n1);
				task.emplace(a,      i, j,      m, n0);
			}
			else
			{
				if (m == block_m && n == block_n)
				{
					//b = zigzag_block(b, a, lda);
					std::cout << "block: (" << i << ", " << j << ") " << m << " x " << n << "\n";
				}
				else
				{
					//b = zigzag_tiny(b, a, lda, m, n);
					std::cout << "tiny: (" << i << ", " << j << ") " << m << " x " << n << "\n";
				}
			}
		}
		if (task.empty())
			break;
		a = std::get<0>(task.top());
		i = std::get<1>(task.top());
		j = std::get<2>(task.top());
		m = std::get<3>(task.top());
		n = std::get<4>(task.top());
		task.pop();
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