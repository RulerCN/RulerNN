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

int main()
{
	try
	{
		// Enable OpenMP support.
		core::openmp::enable();
		// Print number of threads.
		std::cout << "threads: " << core::openmp::num_thread << "\n";

		__m256i ymm_src0 = _mm256_castsi128_si256(_mm_setr_epi8(0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f));
		__m256i ymm_src1 = _mm256_castsi128_si256(_mm_setr_epi8(0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f));
		__m256i ymm_src2 = _mm256_castsi128_si256(_mm_setr_epi8(0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f));
		__m256i ymm_src3 = _mm256_castsi128_si256(_mm_setr_epi8(0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f));
		__m256i ymm_src4 = _mm256_castsi128_si256(_mm_setr_epi8(0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f));
		__m256i ymm_src5 = _mm256_castsi128_si256(_mm_setr_epi8(0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f));
		__m256i ymm_src6 = _mm256_castsi128_si256(_mm_setr_epi8(0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f));
		__m256i ymm_src7 = _mm256_castsi128_si256(_mm_setr_epi8(0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f));
		__m256i ymm_src8 = _mm256_castsi128_si256(_mm_setr_epi8(0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f));
		__m256i ymm_src9 = _mm256_castsi128_si256(_mm_setr_epi8(0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f));
		__m256i ymm_srca = _mm256_castsi128_si256(_mm_setr_epi8(0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf));
		__m256i ymm_srcb = _mm256_castsi128_si256(_mm_setr_epi8(0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf));
		__m256i ymm_srcc = _mm256_castsi128_si256(_mm_setr_epi8(0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf));
		__m256i ymm_srcd = _mm256_castsi128_si256(_mm_setr_epi8(0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf));
		__m256i ymm_srce = _mm256_castsi128_si256(_mm_setr_epi8(0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef));
		__m256i ymm_srcf = _mm256_castsi128_si256(_mm_setr_epi8(0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff));
		ymm_src0 = _mm256_insertf128_si256(ymm_src0, _mm_setr_epi8(0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f), 1);
		ymm_src1 = _mm256_insertf128_si256(ymm_src1, _mm_setr_epi8(0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f), 1);
		ymm_src2 = _mm256_insertf128_si256(ymm_src2, _mm_setr_epi8(0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f), 1);
		ymm_src3 = _mm256_insertf128_si256(ymm_src3, _mm_setr_epi8(0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f), 1);
		ymm_src4 = _mm256_insertf128_si256(ymm_src4, _mm_setr_epi8(0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f), 1);
		ymm_src5 = _mm256_insertf128_si256(ymm_src5, _mm_setr_epi8(0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f), 1);
		ymm_src6 = _mm256_insertf128_si256(ymm_src6, _mm_setr_epi8(0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f), 1);
		ymm_src7 = _mm256_insertf128_si256(ymm_src7, _mm_setr_epi8(0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f), 1);
		ymm_src8 = _mm256_insertf128_si256(ymm_src8, _mm_setr_epi8(0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f), 1);
		ymm_src9 = _mm256_insertf128_si256(ymm_src9, _mm_setr_epi8(0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f), 1);
		ymm_srca = _mm256_insertf128_si256(ymm_srca, _mm_setr_epi8(0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf), 1);
		ymm_srcb = _mm256_insertf128_si256(ymm_srcb, _mm_setr_epi8(0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf), 1);
		ymm_srcc = _mm256_insertf128_si256(ymm_srcc, _mm_setr_epi8(0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf), 1);
		ymm_srcd = _mm256_insertf128_si256(ymm_srcd, _mm_setr_epi8(0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf), 1);
		ymm_srce = _mm256_insertf128_si256(ymm_srce, _mm_setr_epi8(0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef), 1);
		ymm_srcf = _mm256_insertf128_si256(ymm_srcf, _mm_setr_epi8(0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff), 1);
		__m256i ymm_dst0 = _mm256_unpacklo_epi8(ymm_src0, ymm_src1);
		__m256i ymm_dst1 = _mm256_unpacklo_epi8(ymm_src2, ymm_src3);
		__m256i ymm_dst2 = _mm256_unpacklo_epi8(ymm_src4, ymm_src5);
		__m256i ymm_dst3 = _mm256_unpacklo_epi8(ymm_src6, ymm_src7);
		__m256i ymm_dst4 = _mm256_unpacklo_epi8(ymm_src8, ymm_src9);
		__m256i ymm_dst5 = _mm256_unpacklo_epi8(ymm_srca, ymm_srcb);
		__m256i ymm_dst6 = _mm256_unpacklo_epi8(ymm_srcc, ymm_srcd);
		__m256i ymm_dst7 = _mm256_unpacklo_epi8(ymm_srce, ymm_srcf);
		__m256i ymm_dst8 = _mm256_unpackhi_epi8(ymm_src0, ymm_src1);
		__m256i ymm_dst9 = _mm256_unpackhi_epi8(ymm_src2, ymm_src3);
		__m256i ymm_dsta = _mm256_unpackhi_epi8(ymm_src4, ymm_src5);
		__m256i ymm_dstb = _mm256_unpackhi_epi8(ymm_src6, ymm_src7);
		__m256i ymm_dstc = _mm256_unpackhi_epi8(ymm_src8, ymm_src9);
		__m256i ymm_dstd = _mm256_unpackhi_epi8(ymm_srca, ymm_srcb);
		__m256i ymm_dste = _mm256_unpackhi_epi8(ymm_srcc, ymm_srcd);
		__m256i ymm_dstf = _mm256_unpackhi_epi8(ymm_srce, ymm_srcf);
		ymm_src0 = _mm256_unpacklo_epi16(ymm_dst0, ymm_dst1);
		ymm_src1 = _mm256_unpacklo_epi16(ymm_dst2, ymm_dst3);
		ymm_src2 = _mm256_unpacklo_epi16(ymm_dst4, ymm_dst5);
		ymm_src3 = _mm256_unpacklo_epi16(ymm_dst6, ymm_dst7);
		ymm_src4 = _mm256_unpackhi_epi16(ymm_dst0, ymm_dst1);
		ymm_src5 = _mm256_unpackhi_epi16(ymm_dst2, ymm_dst3);
		ymm_src6 = _mm256_unpackhi_epi16(ymm_dst4, ymm_dst5);
		ymm_src7 = _mm256_unpackhi_epi16(ymm_dst6, ymm_dst7);
		ymm_src8 = _mm256_unpacklo_epi16(ymm_dst8, ymm_dst9);
		ymm_src9 = _mm256_unpacklo_epi16(ymm_dsta, ymm_dstb);
		ymm_srca = _mm256_unpacklo_epi16(ymm_dstc, ymm_dstd);
		ymm_srcb = _mm256_unpacklo_epi16(ymm_dste, ymm_dstf);
		ymm_srcc = _mm256_unpackhi_epi16(ymm_dst8, ymm_dst9);
		ymm_srcd = _mm256_unpackhi_epi16(ymm_dsta, ymm_dstb);
		ymm_srce = _mm256_unpackhi_epi16(ymm_dstc, ymm_dstd);
		ymm_srcf = _mm256_unpackhi_epi16(ymm_dste, ymm_dstf);

		ymm_dst0 = _mm256_unpacklo_epi32(ymm_src0, ymm_src1);
		ymm_dst1 = _mm256_unpacklo_epi32(ymm_src2, ymm_src3);
		ymm_dst2 = _mm256_unpackhi_epi32(ymm_src0, ymm_src1);
		ymm_dst3 = _mm256_unpackhi_epi32(ymm_src2, ymm_src3);
		ymm_dst4 = _mm256_unpacklo_epi32(ymm_src4, ymm_src5);
		ymm_dst5 = _mm256_unpacklo_epi32(ymm_src6, ymm_src7);
		ymm_dst6 = _mm256_unpackhi_epi32(ymm_src4, ymm_src5);
		ymm_dst7 = _mm256_unpackhi_epi32(ymm_src6, ymm_src7);
		ymm_dst8 = _mm256_unpacklo_epi32(ymm_src8, ymm_src9);
		ymm_dst9 = _mm256_unpacklo_epi32(ymm_srca, ymm_srcb);
		ymm_dsta = _mm256_unpackhi_epi32(ymm_src8, ymm_src9);
		ymm_dstb = _mm256_unpackhi_epi32(ymm_srca, ymm_srcb);
		ymm_dstc = _mm256_unpacklo_epi32(ymm_srcc, ymm_srcd);
		ymm_dstd = _mm256_unpacklo_epi32(ymm_srce, ymm_srcf);
		ymm_dste = _mm256_unpackhi_epi32(ymm_srcc, ymm_srcd);
		ymm_dstf = _mm256_unpackhi_epi32(ymm_srce, ymm_srcf);

		ymm_src0 = _mm256_unpacklo_epi64(ymm_dst0, ymm_dst1);
		ymm_src1 = _mm256_unpackhi_epi64(ymm_dst0, ymm_dst1);
		ymm_src2 = _mm256_unpacklo_epi64(ymm_dst2, ymm_dst3);
		ymm_src3 = _mm256_unpackhi_epi64(ymm_dst2, ymm_dst3);
		ymm_src4 = _mm256_unpacklo_epi64(ymm_dst4, ymm_dst5);
		ymm_src5 = _mm256_unpackhi_epi64(ymm_dst4, ymm_dst5);
		ymm_src6 = _mm256_unpacklo_epi64(ymm_dst6, ymm_dst7);
		ymm_src7 = _mm256_unpackhi_epi64(ymm_dst6, ymm_dst7);
		ymm_src8 = _mm256_unpacklo_epi64(ymm_dst8, ymm_dst9);
		ymm_src9 = _mm256_unpackhi_epi64(ymm_dst8, ymm_dst9);
		ymm_srca = _mm256_unpacklo_epi64(ymm_dsta, ymm_dstb);
		ymm_srcb = _mm256_unpackhi_epi64(ymm_dsta, ymm_dstb);
		ymm_srcc = _mm256_unpacklo_epi64(ymm_dstc, ymm_dstd);
		ymm_srcd = _mm256_unpackhi_epi64(ymm_dstc, ymm_dstd);
		ymm_srce = _mm256_unpacklo_epi64(ymm_dste, ymm_dstf);
		ymm_srcf = _mm256_unpackhi_epi64(ymm_dste, ymm_dstf);

		std::cout << "a" << "\n";
	}
	catch (std::exception err)
	{
		std::cout << err.what() << "\n";
	}
}
