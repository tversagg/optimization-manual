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

;	.globl saxpy32

	; void saxpy32(float* src, float *src2, size_t len, float *dst, float alpha);
	; On entry:
	;     rcx = src
	;     rdx = src2
	;     r8 = len (length in bytes of all three arrays)
	;     r9 = dst
	;     [rsp+40] = alpha

.code
saxpy32 PROC public
;	push rbx

	mov rax, rcx
	xor r10, r10
	vbroadcastss ymm0, dword ptr[rsp+40];xmm0

start_loop:
	vmovups ymm1, [rax + r10]
	vmulps ymm1, ymm1, ymm0
	vmovups ymm2, [rdx + r10]
	vaddps ymm1, ymm1, ymm2
	vmovups [r9 + r10], ymm1
	vmovups ymm1, [rax+r10+32]
	vmulps ymm1, ymm1, ymm0
	vmovups ymm2, [rdx+r10+32]
	vaddps ymm1, ymm1, ymm2
	vmovups [r9+r10+32], ymm1
	add r10, 64
	cmp r10, r8
	jl start_loop

	vzeroupper
;	pop rbx
	ret
saxpy32 ENDP
end