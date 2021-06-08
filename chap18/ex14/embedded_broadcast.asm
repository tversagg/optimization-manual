;
; Copyright (C) 2021 by Intel Corporation
;
; Permission to use, copy, modify, and/or distribute this software for any
; purpose with or without fee is hereby granted.
;
; THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
; REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
; AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
; INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
; LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
; OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
; PERFORMANCE OF THIS SOFTWARE.
;


;	.globl embedded_broadcast

	; void embedded_broadcast(const uint32_t *input, uint32_t *output, uint64_t count,
	;                         uint32_t *broadcast, uint32_t *indices);
	; On entry:
	;     rcx = input
	;     rdx = output
	;     r8 = count
	;     r9 = broadcast
	;     [rsp+40] = indices


.code
embedded_broadcast PROC public


	mov r10, [rsp+40]
	vmovdqu32 zmm3, [r10]
	vmovdqu32 zmm1, [rcx]

loop1:
	vpaddd zmm2, zmm1, DWORD bcst [r9]
	vpermd zmm2, zmm3, zmm2
	add r9, 04h
	sub r8, 01h
	jnz loop1

	vmovdqu32 [rdx], zmm2
	vzeroupper
	ret
embedded_broadcast ENDP
end