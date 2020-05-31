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

#ifndef __CORE_ERROR_H__
#define __CORE_ERROR_H__

namespace core
{
	//----------------------------------------------------------------
	// +exception
	// |-----bad_alloc:           Exception thrown on failure allocating memory.
	// |-----bad_cast:            Exception thrown on failure to dynamic cast.
	// |-----bad_exception:       Exception thrown by unexpected handler.
	// |-----bad_function_call:   Exception thrown on bad call.
	// |-----bad_typeid:          Exception thrown on typeid of null pointer.
	// |-----bad_weak_ptr:        Bad weak pointer.
	// |-----ios_base::failure:   Base class for stream exceptions.
	// |----+logic_error:         Logic error exception.
	// |    |----domain_error
	// |    |----invalid_argument
	// |    |----length_error
	// |    |----out_of_range
	// |    |----future_error
	// |
	// |----+runtime_error:       Runtime error exception.
	//      |--range_error
	//      |--overflow_error
	//      |--underflow_error
	//      |--system_error

	// bad_alloc
	static constexpr char NOT_ENOUGH_MEMORY[]          = "Not enough storage.";

	// domain_error
	static constexpr char NO_SUPPORT_OPENMP[]          = "OpenMP is disabled. Please specify the /openmp (MVC) or -fopenmp (GCC) compiler options to enable OpenMP support.";
	static constexpr char UNIMPLEMENTED_FUNCTION[]     = "Unimplemented function.";
	static constexpr char SCALAR_IS_INITIALIZED[]      = "Scalar is initialized.";
	static constexpr char SCALAR_NOT_INITIALIZED[]     = "Scalar not initialized.";
	static constexpr char VECTOR_IS_INITIALIZED[]      = "Vector is initialized.";
	static constexpr char VECTOR_NOT_INITIALIZED[]     = "Vector not initialized.";
	static constexpr char MATRIX_IS_INITIALIZED[]      = "Matrix is initialized.";
	static constexpr char MATRIX_NOT_INITIALIZED[]     = "Matrix not initialized.";
	static constexpr char TENSOR_IS_INITIALIZED[]      = "Tensor is initialized.";
	static constexpr char TENSOR_NOT_INITIALIZED[]     = "Tensor not initialized.";
	static constexpr char SCALAR_DIFFERENT_SIZE[]      = "Unable to operate scalars of different size.";
	static constexpr char VECTOR_DIFFERENT_SIZE[]      = "Unable to operate vectors of different size.";
	static constexpr char MATRIX_DIFFERENT_SIZE[]      = "Unable to operate matrixs of different size.";
	static constexpr char TENSOR_DIFFERENT_SIZE[]      = "Unable to operate tensors of different size.";

	// invalid_argument
	static constexpr char INVALID_TEMPLATE_PARAMETER[] = "Invalid template parameter.";
	static constexpr char INVALID_DIMENSION[]          = "Invalid dimension.";
	static constexpr char INVALID_POINTER[]            = "Invalid pointer.";
	static constexpr char INVALID_LENGTH[]             = "Invalid length.";
	static constexpr char INVALID_SIZE[]               = "Invalid size.";
	static constexpr char INVALID_SHAPE[]              = "Invalid shape.";
	static constexpr char INVALID_COPY_MODE[]          = "Invalid copy mode.";
	static constexpr char INVALID_INITIALIZER_LIST[]   = "Invalid initializer list.";
	static constexpr char INVALID_ITERATOR_DISTANCE[]  = "Invalid distance between iterators.";
	static constexpr char INVALID_SCALAR_SIZE[]        = "Invalid scalar size.";
	static constexpr char INVALID_VECTOR_SIZE[]        = "Invalid vector size.";
	static constexpr char INVALID_MATRIX_SIZE[]        = "Invalid matrix size.";
	static constexpr char INVALID_TENSOR_SIZE[]        = "Invalid tensor size.";
//	static constexpr char INVALID_BORDER_SIZE[]        = "Invalid border size.";
//	static constexpr char INVALID_WINDOW_SIZE[]        = "Invalid window size.";
//	static constexpr char INVALID_SLIDING_STRIDE[]     = "Invalid sliding stride.";
//	static constexpr char INVALID_AXIS_PARAMETERS[]    = "Invalid axis parameters.";
//	static constexpr char INVALID_REPEAT_PARAMETERS[]  = "Invalid repeat parameters.";

	// out_of_range
	static constexpr char SCALAR_OUT_OF_RANGE[]        = "Scalar subscript out of range.";
	static constexpr char VECTOR_OUT_OF_RANGE[]        = "Vector subscript out of range.";
	static constexpr char MATRIX_OUT_OF_RANGE[]        = "Matrix subscript out of range.";
	static constexpr char TENSOR_OUT_OF_RANGE[]        = "Tensor subscript out of range.";

} // namespace core

#endif
