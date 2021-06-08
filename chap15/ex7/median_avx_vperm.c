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

#include "median_avx_vperm.h"

bool median_avx_vperm_check(float *x, float *y, uint64_t len)
{
	/*
	 * x and y must be non-null and 32 byte aligned
	 */

	if (!x || !y)
		return false;

	if (((uintptr_t)x) % 32 != 0)
		return false;

	if (((uintptr_t)y) % 32 != 0)
		return false;

	/*
	 * len must be divisible by 8.
	 */

	if (len % 8 != 0)
		return false;

	median_avx_vperm(x, y, len);

	return true;
}
