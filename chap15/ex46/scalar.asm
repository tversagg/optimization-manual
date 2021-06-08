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

;	.globl scalar

	; void scalar(size_t len, complex_num* complex_buffer, float* imaginary_buffer,
	;             float* real_buffer);
	; On entry:
	;     rcx = len (length in elements of )
	;     rdx = complex_buffer
	;     r8 = imaginary_buffer
	;     r9 = real_buffer


.code
scalar PROC public
;	mov r12, rcx
	shr rcx, 1
	xor r10, r10

loop_start:
	lea eax, [r10+r10*1]
	movsxd rax, eax
	inc r10d
	mov r11d, dword ptr [rdx+rax*8]
	mov dword ptr [r9+rax*4], r11d
	mov r11d, dword ptr [rdx+rax*8+4]
	mov dword ptr [r8+rax*4], r11d
	mov r11d, dword ptr [rdx+rax*8+8]
	mov dword ptr [r9+rax*4+4], r11d
	mov r11d, dword ptr [rdx+rax*8+0ch]
	mov dword ptr [r8+rax*4+4], r11d
	cmp r10d, ecx
	jl loop_start

	ret
scalar ENDP
end