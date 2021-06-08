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

#ifndef AVX512_VECTOR_DP_H__
#define AVX512_VECTOR_DP_H__

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

double avx512_vector_dp(const uint32_t *a_index, const double *a_value,
			const uint32_t *b_index, const double *b_value,
			uint64_t max_els);

bool avx512_vector_dp_check(const uint32_t *a_index, const double *a_value,
			    const uint32_t *b_index, const double *b_value,
			    uint64_t max_els, double *val);

#ifdef __cplusplus
}
#endif

#endif
