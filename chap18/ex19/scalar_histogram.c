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

#include <immintrin.h>

#include "scalar_histogram.h"

bool scalar_histogram_check(const int32_t *input, uint32_t *output,
			    uint64_t num_inputs, uint64_t bins)
{
	/* input and output must be non null */

	if (!input || !output)
		return false;

	/* num_inputs must be > 0 and an even number */

	if (num_inputs == 0 || (num_inputs & 1))
		return false;

	/* bins must be > 0 and a power of 2 */

	if (_mm_popcnt_u64(bins) != 1)
		return false;

	scalar_histogram(input, output, num_inputs, bins);

	return true;
}
