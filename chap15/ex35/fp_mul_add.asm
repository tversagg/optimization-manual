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

;	.globl fp_mul_add

	; void fp_mul_add(float *a, float *c1, float *c2, uint32_t len)
	; On entry:
	;     rcx = a
	;     rdx = c1
	;     r8 = c2
	;     r9 = len


.code
fp_mul_add PROC public

	push rbx

	mov eax, r9d
	mov rbx, rcx
	mov rcx, rdx

	vmovups ymm0, ymmword ptr [rbx] ; A
	vmovups ymm1, ymmword ptr [rcx] ; C1
	vmovups ymm2, ymmword ptr [r8] ; C2
loop_start:
	vmulps ymm4, ymm0 ,ymm2 ; A * C2
	vaddps ymm0, ymm1, ymm4
	dec eax
	jnz loop_start
	vmovups ymmword ptr[rbx], ymm0 ; store A

	pop rbx
	vzeroupper
	ret
fp_mul_add ENDP
end