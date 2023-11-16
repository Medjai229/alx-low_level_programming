section 	.data
	format db 'Hello, Holberton', 0xA, 0

section 	.text
	extern printf
	global main

main:
	mov 	edi, format
	mov	eax, 0
	call	printf
