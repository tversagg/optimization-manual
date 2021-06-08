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

#include "register_broadcast.h"

bool register_broadcast_check(const uint16_t *input, uint16_t *output,
			      uint64_t count, uint32_t *broadcast,
			      uint16_t *indices)
{
	/*
	 * input, output, broadcast, indices must be non-NULL.
	 * count must be > 0.
	 */

	if (!output || !input || !broadcast || !indices)
		return false;

	if (count == 0)
		return false;

	register_broadcast(input, output, count, broadcast, indices);

	return true;
}
