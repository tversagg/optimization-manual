/*
 * Copyright (C) 2021 by Intel Corporation
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef COMPLEX_CONV_SSE_H__
#define COMPLEX_CONV_SSE_H__

#include <stdbool.h>
#include <stddef.h>

#include "complex_num.h"

#ifdef __cplusplus
extern "C" {
#endif
void complex_conv_sse(complex_num *complex_buffer, float *real_buffer,
		      float *imaginary_buffer, size_t len);
bool complex_conv_sse_check(complex_num *complex_buffer, float *real_buffer,
			    float *imaginary_buffer, size_t len);
#ifdef __cplusplus
}
#endif

#endif
