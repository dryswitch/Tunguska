@EQU	tmp	%DDD443
@ORG	236196
;  Begin function strlen
strlen:
		LDA	#-4
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+4,X
		PLL	__VS+3,X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
.while0begin:
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		CMP	#0
		JLT	.while0done
		JEQ	.while0done
		LDX	__VSS
		LAD	__VS+1,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		LDX	__VSS
		LAD	__VS+3,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		JMP	.while0begin
.while0done:
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#4
		STA	__VSS
		RST

		LDA	#4
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function strlen



;  Begin function strnlen
strnlen:
		LDA	#-6
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+6,X
		PLL	__VS+5,X
		PLL	__VS+4,X
		PLL	__VS+3,X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
.while0begin:
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PSH	#0
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#1
		PRM	#1
		PSH	A
		CMP	#0
		JLT	.and1_false
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		PLL	tmp
		AND	tmp
		PSH	A
		JMP	.and1_done
.and1_false:
		PLL	A
		PSH	#%00A
.and1_done:
		PLL	A
		CMP	#0
		JLT	.while0done
		JEQ	.while0done
		LDX	__VSS
		LAD	__VS+1,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		LDX	__VSS
		LAD	__VS+5,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		JMP	.while0begin
.while0done:
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#6
		STA	__VSS
		RST

		LDA	#6
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function strnlen



;  Begin function index
index:
		LDA	#-3
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+3,X
		PLL	__VS+2,X
		PLL	__VS+1, X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
.while0begin:
		LDY	__VSS
		LDX	__VS+2,Y
		LDY	__VS+3,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PSH	#0
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#1
		PRM	#1
		CMP	#0
		JLT	.while0done
		JEQ	.while0done
		LDY	__VSS
		LDA	__VS+1,Y
		PSH	A
		LDY	__VSS
		LDX	__VS+2,Y
		LDY	__VS+3,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		LDY	__VSS
		LDX	__VS+2,Y
		LDY	__VS+3,Y
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#3
		STA	__VSS
		RST

		JMP	.if1done
.if1else:
.if1done:
		LDX	__VSS
		LAD	__VS+2,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		JMP	.while0begin
.while0done:
		LAD	0	; const word
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#3
		STA	__VSS
		RST

		LDA	#3
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function index



;  Begin function rindex
rindex:
		LDA	#-3
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+3,X
		PLL	__VS+2,X
		PLL	__VS+1, X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
.while0begin:
		LDY	__VSS
		LDX	__VS+2,Y
		LDY	__VS+3,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PSH	#0
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#1
		PRM	#1
		CMP	#0
		JLT	.while0done
		JEQ	.while0done
		LDY	__VSS
		LDX	__VS+2,Y
		LDY	__VS+3,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		LDY	__VSS
		LDA	__VS+1,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#1
		PRM	#1
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		LDY	__VSS
		LDX	__VS+2,Y
		LDY	__VS+3,Y
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#3
		STA	__VSS
		RST

		JMP	.if1done
.if1else:
.if1done:
		LDX	__VSS
		LAD	__VS+2,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		JMP	.while0begin
.while0done:
		LAD	0	; const word
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#3
		STA	__VSS
		RST

		LDA	#3
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function rindex



;  Begin function strcmp
strcmp:
		LDA	#-4
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+4,X
		PLL	__VS+3,X
		PLL	__VS+2,X
		PLL	__VS+1,X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
.while0begin:
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.while0done
		JEQ	.while0done
		PSH	#0
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		PSH	#0
		PLL	A
		PLY
		PLX
		PSH	A
		PHX
		PHY

		LDA	__VSS
		CLC
		ADD	#4
		STA	__VSS
		RST

		JMP	.if1done
.if1else:
.if1done:
		LDX	__VSS
		LAD	__VS+3,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		LDX	__VSS
		LAD	__VS+1,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		JMP	.while0begin
.while0done:
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		EOR	#%444
		PLL	tmp
		CLC
		ADD	tmp
		PLY
		PLX
		PSH	A
		PHX
		PHY

		LDA	__VSS
		CLC
		ADD	#4
		STA	__VSS
		RST

		LDA	#4
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function strcmp



;  Begin function strncmp
strncmp:
		LDA	#-8
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+8,X
		PLL	__VS+7,X
		PLL	__VS+6,X
		PLL	__VS+5,X
		PLL	__VS+4,X
		PLL	__VS+3,X
		PSH	A
		PHY
;  Initialize variables 
		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
;  Begin code
.while0begin:
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.while0done
		JEQ	.while0done
		PSH	#0
		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		PSH	#0
		PLL	A
		PLY
		PLX
		PSH	A
		PHX
		PHY

		LDA	__VSS
		CLC
		ADD	#8
		STA	__VSS
		RST

		JMP	.if1done
.if1else:
.if1done:
		LDX	__VSS
		LAD	__VS+1,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		LDX	__VSS
		LAD	__VS+1,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		CMP	#0
		JLT	.if2else
		JEQ	.if2else
		PSH	#0
		PLL	A
		PLY
		PLX
		PSH	A
		PHX
		PHY

		LDA	__VSS
		CLC
		ADD	#8
		STA	__VSS
		RST

		JMP	.if2done
.if2else:
.if2done:
		LDX	__VSS
		LAD	__VS+7,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		LDX	__VSS
		LAD	__VS+5,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		JMP	.while0begin
.while0done:
		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		EOR	#%444
		PLL	tmp
		CLC
		ADD	tmp
		PLY
		PLX
		PSH	A
		PHX
		PHY

		LDA	__VSS
		CLC
		ADD	#8
		STA	__VSS
		RST

		LDA	#8
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function strncmp



;  Begin function atoi
atoi:
		LDA	#-8
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+8,X
		PLL	__VS+7,X
		PSH	A
		PHY
;  Initialize variables 
		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
		LAD	1	; const word
		TXA
		LDX	__VSS
		STA	__VS+3,X
		STY	__VS+4,X
		TAX
		LAD	__DATA+0	; const char*
		TXA
		LDX	__VSS
		STA	__VS+5,X
		STY	__VS+6,X
		TAX
;  Begin code
.while0begin:
		PSH	#1
		LAD	0	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.while0done
		JEQ	.while0done
		LDX	__VSS
		LAD	__VS+7,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		JMP	.while0begin
.while0done:
		PSH	#87
		LAD	0	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		LAD	-1	; const word
		TXA
		LDX	__VSS
		STA	__VS+3,X
		STY	__VS+4,X
		TAX

		LDX	__VSS
		LAD	__VS+7,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		JMP	.if1done
.if1else:
.if1done:
.for2begin:
		LAD	0	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		CMP	#0
		JLT	.for2done
		JEQ	.for2done
		LDA	#-2
		CLC
		ADD	__VSS
		STA	__VSS
		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
.for3begin:
		LAD	10	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		TSH	#%001
		CMP	#0
		JLT	.for3done
		JEQ	.for3done
		LDY	__VSS
		LDX	__VS+9,Y
		LDY	__VS+10,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if4else
		JEQ	.if4else
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		LAD	10	; const word
		MLW	X,Y
		ADW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+3,X
		STY	__VS+4,X
		TAX

		JMP	.for3done
		JMP	.if4done
.if4else:
.if4done:
.for3continue:
		LDX	__VSS
		LAD	__VS+1,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX
		JMP	.for3begin
.for3done:
		LAD	11	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if5else
		JEQ	.if5else
		LAD	0	; const word
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#10
		STA	__VSS
		RST

		JMP	.if5done
.if5else:
.if5done:
		LDA	__VSS
		CLC
		ADD	#2
		STA	__VSS
.for2continue:
		LDX	__VSS
		LAD	__VS+7,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX
		JMP	.for2begin
.for2done:
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		MLW	X,Y
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#8
		STA	__VSS
		RST

		LDA	#8
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function atoi



;  Begin function memcpy
memcpy:
		LDA	#-6
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+6,X
		PLL	__VS+5,X
		PLL	__VS+4,X
		PLL	__VS+3,X
		PLL	__VS+2,X
		PLL	__VS+1,X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		PHX
		PHY
		PSH	#10
		JSR	sys_agdp

		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#6
		STA	__VSS
		RST

		LDA	#6
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function memcpy



;  Begin function memset
memset:
		LDA	#-6
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+6,X
		PLL	__VS+5,X
		PLL	__VS+4,X
		PLL	__VS+3,X
		PLL	__VS+2,X
		PLL	__VS+1,X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		PHX
		PHY
		PSH	#11
		JSR	sys_agdp

		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#6
		STA	__VSS
		RST

		LDA	#6
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function memset



;  Begin function scroll
scroll:
;  Initialize variables 
;  Begin code
		LAD	264208	; const word
		PHX
		PHY
		LAD	-262804	; const word
		ADW	X,Y
		PHX
		PHY
		LAD	-264208	; const word
		PHX
		PHY
		LAD	-264262	; const word
		PHX
		PHY
		JSR	memcpy
		PLY
		PLX

		LAD	54	; const word
		PHX
		PHY
		LAD	0	; const word
		PHX
		PHY
		LAD	-54	; const word
		PHX
		PHY
		LAD	-262804	; const word
		ADW	X,Y
		PHX
		PHY
		JSR	memset
		PLY
		PLX

		RST
;  Function variables
; End function scroll



;  Begin function putc
putc:
		DEC	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+1, X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
		PSH	#2
		LDY	__VSS
		LDA	__VS+1,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if0else
		JEQ	.if0else
		PSH	#0
		PLL	A
		STA	.col

		INC	.row
		PSH	.row
		PSH	#26
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		PSH	#26
		PLL	A
		STA	.row

		JSR	scroll

		JMP	.if1done
.if1else:
.if1done:
		LDA	__VSS
		CLC
		ADD	#1
		STA	__VSS
;
		RST
		JMP	.if0done
.if0else:
		PSH	.col
		PSH	#54
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		TSH	#%001
		CMP	#0
		JLT	.if2else
		JEQ	.if2else
		PSH	#0
		PLL	A
		STA	.col

		INC	.row
		PSH	.row
		PSH	#26
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		CMP	#0
		JLT	.if3else
		JEQ	.if3else
		PSH	#26
		PLL	A
		STA	.row

		JSR	scroll

		JMP	.if3done
.if3else:
.if3done:
		JMP	.if2done
.if2else:
.if2done:
.if0done:
		LDY	__VSS
		LDA	__VS+1,Y
		PSH	A
		PSH	.col
		PSH	#1
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		PSH	.row
		PSH	#54
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		LAD	sys_text_buffer
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	.col
		INC	.col
		PLL	A

		LDA	#1
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
.col:	@DT 0
.row:	@DT 0
; End function putc



;  Begin function puts
puts:
		LDA	#-2
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+2,X
		PLL	__VS+1,X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
.for0begin:
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PSH	#0
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#1
		PRM	#1
		CMP	#0
		JLT	.for0done
		JEQ	.for0done
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		JSR	putc

.for0continue:
		LDX	__VSS
		LAD	__VS+1,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX
		JMP	.for0begin
.for0done:
		LDA	#2
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function puts



;  Begin function putnum
putnum:
		LDA	#-8
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+8,X
		PLL	__VS+7,X
		PSH	A
		PHY
;  Initialize variables 
		LAD	__DATA+11	; const char*
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+3,X
		STY	__VS+4,X
		TAX
		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+5,X
		STY	__VS+6,X
		TAX
;  Begin code
		LAD	0	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if0else
		JEQ	.if0else
		PSH	#36
		JSR	putc

		LDA	__VSS
		CLC
		ADD	#8
		STA	__VSS
;
		RST
		JMP	.if0done
.if0else:
		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		PHX
		PHY
		LAD	0	; const word
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		PSH	#87
		JSR	putc

		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		PHX
		PHY
		PLX
		PLL	A
		EOR	#%444
		PSH	A
		TXA
		EOR	#%444
		PSH	A
		PLY
		PLX
		TXA
		LDX	__VSS
		STA	__VS+7,X
		STY	__VS+8,X
		TAX

		JMP	.if1done
.if1else:
.if1done:
.if0done:
.while2begin:
		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		CAD	0
		JLT	.while2done
		JEQ	.while2done
		LDA	#-2
		CLC
		ADD	__VSS
		STA	__VSS
		LAD	10	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+9,Y
		LDY	__VS+10,Y
		MDW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LAD	10	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		MLW	X,Y
		ADW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+5,X
		STY	__VS+6,X
		TAX

		LDX	__VSS
		LAD	__VS+7,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		LAD	10	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+9,Y
		LDY	__VS+10,Y
		DVW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+9,X
		STY	__VS+10,X
		TAX

		LDA	__VSS
		CLC
		ADD	#2
		STA	__VSS
		JMP	.while2begin
.while2done:
.while3begin:
		LDX	__VSS
		LAD	__VS+5,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		DEC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX
		CAD	0
		JLT	.while3done
		JEQ	.while3done
		LDA	#-2
		CLC
		ADD	__VSS
		STA	__VSS
		LAD	10	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		MDW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		JSR	putc

		LAD	10	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		DVW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+5,X
		STY	__VS+6,X
		TAX

		LDA	__VSS
		CLC
		ADD	#2
		STA	__VSS
		JMP	.while3begin
.while3done:
		LDA	#8
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function putnum



;  Begin function putsmallnum
putsmallnum:
		LDA	#-5
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+5, X
		PSH	A
		PHY
;  Initialize variables 
		LAD	__DATA+22	; const char*
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
		PSH	#0
		PLL	A
		LDX	__VSS
		STA	__VS+3,X
		PSH	#0
		PLL	A
		LDX	__VSS
		STA	__VS+4,X
;  Begin code
		PSH	#0
		LDY	__VSS
		LDA	__VS+5,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if0else
		JEQ	.if0else
		PSH	#36
		JSR	putc

		LDA	__VSS
		CLC
		ADD	#5
		STA	__VSS
;
		RST
		JMP	.if0done
.if0else:
		LDY	__VSS
		LDA	__VS+5,Y
		PSH	A
		PSH	#0
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		PSH	#87
		JSR	putc

		LDY	__VSS
		LDA	__VS+5,Y
		EOR	#%444
		LDX	__VSS
		STA	__VS+5,X

		JMP	.if1done
.if1else:
.if1done:
.if0done:
.while2begin:
		LDY	__VSS
		LDA	__VS+5,Y
		CMP	#0
		JLT	.while2done
		JEQ	.while2done
		DEC	__VSS
		PSH	#10
		LDY	__VSS
		LDA	__VS+6,Y
		PLL	tmp
		MOD	tmp
		LDX	__VSS
		STA	__VS+1,X
		PSH	#10
		LDY	__VSS
		LDA	__VS+4,Y
		PLL	tmp
		MLL	tmp
		PSH	A
		LDY	__VSS
		LDA	__VS+1,Y
		PLL	tmp
		CLC
		ADD	tmp
		LDX	__VSS
		STA	__VS+4,X

		LDX	__VSS
		LAD	__VS+5,X
		STX	tmp
		STY	tmp+1
		PSH	(tmp)
		INC	(tmp)
		PLL	A

		PSH	#10
		LDY	__VSS
		LDA	__VS+6,Y
		PLL	tmp
		DIV	tmp
		LDX	__VSS
		STA	__VS+6,X

		INC	__VSS
		JMP	.while2begin
.while2done:
.while3begin:
		LDX	__VSS
		LAD	__VS+4,X
		STX	tmp
		STY	tmp+1
		PSH	(tmp)
		DEC	(tmp)
		PLL	A
		CMP	#0
		JLT	.while3done
		JEQ	.while3done
		DEC	__VSS
		PSH	#10
		LDY	__VSS
		LDA	__VS+4,Y
		PLL	tmp
		MOD	tmp
		LDX	__VSS
		STA	__VS+1,X
		LDY	__VSS
		LDA	__VS+1,Y
		PSH	A
		PSH	#1
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		LDY	__VSS
		LDX	__VS+2,Y
		LDY	__VS+3,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		JSR	putc

		PSH	#10
		LDY	__VSS
		LDA	__VS+4,Y
		PLL	tmp
		DIV	tmp
		LDX	__VSS
		STA	__VS+4,X

		INC	__VSS
		JMP	.while3begin
.while3done:
		LDA	#5
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function putsmallnum



;  Begin function getc_noblock
getc_noblock:
		LDA	#-3
		CLC
		ADD	__VSS
		STA	__VSS
;  Initialize variables 
		JSR	get_ms
		PLY
		PLX
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
;  Begin code
		PSH	#0
		LAD	0	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if0else
		JEQ	.if0else
		PSH	#0
		PLL	A
		PLY
		PLX
		PSH	A
		PHX
		PHY

		LDA	__VSS
		CLC
		ADD	#3
		STA	__VSS
		RST

		JMP	.if0done
.if0else:
.if0done:
		LAD	0	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		LDX	__VSS
		STA	__VS+3,X

		PSH	#0
		LAD	0	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		LAD	5	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		LDY	__VSS
		LDA	__VS+3,Y
		PSH	A
		JSR	putc

		JMP	.if1done
.if1else:
.if1done:
		LDY	__VSS
		LDA	__VS+3,Y
		PLY
		PLX
		PSH	A
		PHX
		PHY

		LDA	__VSS
		CLC
		ADD	#3
		STA	__VSS
		RST

		LDA	#3
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function getc_noblock



;  Begin function getc
getc:
		LDA	#-3
		CLC
		ADD	__VSS
		STA	__VSS
;  Initialize variables 
		JSR	get_ms
		PLY
		PLX
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
;  Begin code
.while0begin:
		PSH	#0
		LAD	0	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.while0done
		JEQ	.while0done
		JMP	.while0begin
.while0done:
		LAD	0	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		LDX	__VSS
		STA	__VS+3,X

		PSH	#0
		LAD	0	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		LAD	5	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		LDY	__VSS
		LDA	__VS+3,Y
		PSH	A
		JSR	putc

		JMP	.if1done
.if1else:
.if1done:
		LDY	__VSS
		LDA	__VS+3,Y
		PLY
		PLX
		PSH	A
		PHX
		PHY

		LDA	__VSS
		CLC
		ADD	#3
		STA	__VSS
		RST

		LDA	#3
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function getc



;  Begin function gets
gets:
		LDA	#-6
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+6,X
		PLL	__VS+5,X
		PLL	__VS+4,X
		PLL	__VS+3,X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
.for0begin:
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		CMP	#0
		JLT	.for0done
		JEQ	.for0done
		DEC	__VSS
		JSR	getc
		PLL	A
		LDX	__VSS
		STA	__VS+1,X
		LDY	__VSS
		LDA	__VS+1,Y
		PSH	A
		LDY	__VSS
		LDX	__VS+2,Y
		LDY	__VS+3,Y
		PHX
		PHY
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+6,Y
		LDY	__VS+7,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	#0
		LDY	__VSS
		LDA	__VS+1,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		LDY	__VSS
		LDX	__VS+2,Y
		LDY	__VS+3,Y
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#7
		STA	__VSS
		RST

		JMP	.if1done
.if1else:
.if1done:
		PSH	#2
		LDY	__VSS
		LDA	__VS+1,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if2else
		JEQ	.if2else
		PSH	#0
		LDY	__VSS
		LDX	__VS+2,Y
		LDY	__VS+3,Y
		PHX
		PHY
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+6,Y
		LDY	__VS+7,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		LDY	__VSS
		LDX	__VS+2,Y
		LDY	__VS+3,Y
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#7
		STA	__VSS
		RST

		JMP	.if2done
.if2else:
.if2done:
		INC	__VSS
.for0continue:
		LDX	__VSS
		LAD	__VS+1,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX
		JMP	.for0begin
.for0done:
		PSH	#0
		LAD	-1	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#6
		STA	__VSS
		RST

		LDA	#6
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function gets



;  Begin function sqrti
sqrti:
		LDA	#-6
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+6,X
		PLL	__VS+5,X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		PHX
		PHY
		LAD	0	; const word
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		CMP	#0
		JLT	.if0else
		JEQ	.if0else
		LAD	1	; const word
		PHX
		PHY
		PLX
		PLL	A
		EOR	#%444
		PSH	A
		TXA
		EOR	#%444
		PSH	A
		PLY
		PLX
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#6
		STA	__VSS
		RST

		JMP	.if0done
.if0else:
.if0done:
		LAD	2	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		PHX
		PHY
		JSR	log3i
		PLY
		PLX
		MLW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+3,X
		STY	__VS+4,X
		TAX

		LAD	2	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		DVW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX

.while1begin:
		LDX	__VSS
		LAD	__VS+3,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		DEC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX
		CAD	0
		JLT	.while1done
		JEQ	.while1done
		LAD	2	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		DVW	X,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		DVW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX

		JMP	.while1begin
.while1done:
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#6
		STA	__VSS
		RST

		LDA	#6
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function sqrti



;  Begin function sqrtfi
sqrtfi:
		LDA	#-6
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+6,X
		PLL	__VS+5,X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		PHX
		PHY
		LAD	0	; const word
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		CMP	#0
		JLT	.if0else
		JEQ	.if0else
		LAD	1	; const word
		PHX
		PHY
		PLX
		PLL	A
		EOR	#%444
		PSH	A
		TXA
		EOR	#%444
		PSH	A
		PLY
		PLX
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#6
		STA	__VSS
		RST

		JMP	.if0done
.if0else:
.if0done:
		LAD	2	; const word
		PHX
		PHY
		LAD	81	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		DVW	X,Y
		PHX
		PHY
		JSR	log3i
		PLY
		PLX
		MLW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+3,X
		STY	__VS+4,X
		TAX

		LAD	2	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		DVW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX

.while1begin:
		LDX	__VSS
		LAD	__VS+3,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		DEC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX
		CAD	0
		JLT	.while1done
		JEQ	.while1done
		LAD	2	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LAD	81	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		MLW	X,Y
		DVW	X,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		DVW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX

		JMP	.while1begin
.while1done:
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#6
		STA	__VSS
		RST

		LDA	#6
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function sqrtfi



;  Begin function log3i
log3i:
		LDA	#-4
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+4,X
		PLL	__VS+3,X
		PSH	A
		PHY
;  Initialize variables 
		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
;  Begin code
.while0begin:
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		LAD	0	; const word
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#1
		PRM	#1
		CMP	#0
		JLT	.while0done
		JEQ	.while0done
		LAD	3	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		DVW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+3,X
		STY	__VS+4,X
		TAX

		LDX	__VSS
		LAD	__VS+1,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		JMP	.while0begin
.while0done:
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#4
		STA	__VSS
		RST

		LDA	#4
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function log3i



;  Begin function log10i
log10i:
		LDA	#-4
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+4,X
		PLL	__VS+3,X
		PSH	A
		PHY
;  Initialize variables 
		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
;  Begin code
.while0begin:
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		LAD	0	; const word
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#1
		PRM	#1
		CMP	#0
		JLT	.while0done
		JEQ	.while0done
		LAD	10	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		DVW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+3,X
		STY	__VS+4,X
		TAX

		LDX	__VSS
		LAD	__VS+1,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		JMP	.while0begin
.while0done:
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1

		LDA	__VSS
		CLC
		ADD	#4
		STA	__VSS
		RST

		LDA	#4
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function log10i



;  Begin function cos
cos:
		DEC	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+1, X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
		LDY	__VSS
		LDA	__VS+1,Y
		PSH	A
		LDY	__VSS
		LDA	__VS+1,Y
		CMP	#0
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		PSH	A
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LAD	.lookup_table
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLY
		PLX
		PSH	A
		PHX
		PHY

		LDA	__VSS
		CLC
		ADD	#1
		STA	__VSS
		RST

		LDA	#1
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
.lookup_table:
@DT 364
@DT 363
@DT 363
@DT 363
@DT 363
@DT 363
@DT 363
@DT 363
@DT 363
@DT 362
@DT 362
@DT 362
@DT 362
@DT 361
@DT 361
@DT 360
@DT 360
@DT 360
@DT 359
@DT 359
@DT 358
@DT 358
@DT 357
@DT 356
@DT 356
@DT 355
@DT 354
@DT 354
@DT 353
@DT 352
@DT 351
@DT 351
@DT 350
@DT 349
@DT 348
@DT 347
@DT 346
@DT 345
@DT 344
@DT 343
@DT 342
@DT 341
@DT 340
@DT 339
@DT 338
@DT 336
@DT 335
@DT 334
@DT 333
@DT 331
@DT 330
@DT 329
@DT 327
@DT 326
@DT 325
@DT 323
@DT 322
@DT 320
@DT 319
@DT 317
@DT 316
@DT 314
@DT 313
@DT 311
@DT 309
@DT 308
@DT 306
@DT 304
@DT 303
@DT 301
@DT 299
@DT 297
@DT 295
@DT 294
@DT 292
@DT 290
@DT 288
@DT 286
@DT 284
@DT 282
@DT 280
@DT 278
@DT 276
@DT 274
@DT 272
@DT 270
@DT 268
@DT 266
@DT 263
@DT 261
@DT 259
@DT 257
@DT 255
@DT 252
@DT 250
@DT 248
@DT 246
@DT 243
@DT 241
@DT 239
@DT 236
@DT 234
@DT 231
@DT 229
@DT 226
@DT 224
@DT 222
@DT 219
@DT 216
@DT 214
@DT 211
@DT 209
@DT 206
@DT 204
@DT 201
@DT 198
@DT 196
@DT 193
@DT 190
@DT 188
@DT 185
@DT 182
@DT 180
@DT 177
@DT 174
@DT 171
@DT 169
@DT 166
@DT 163
@DT 160
@DT 157
@DT 155
@DT 152
@DT 149
@DT 146
@DT 143
@DT 140
@DT 137
@DT 134
@DT 132
@DT 129
@DT 126
@DT 123
@DT 120
@DT 117
@DT 114
@DT 111
@DT 108
@DT 105
@DT 102
@DT 99
@DT 96
@DT 93
@DT 90
@DT 87
@DT 84
@DT 80
@DT 77
@DT 74
@DT 71
@DT 68
@DT 65
@DT 62
@DT 59
@DT 56
@DT 53
@DT 50
@DT 46
@DT 43
@DT 40
@DT 37
@DT 34
@DT 31
@DT 28
@DT 25
@DT 21
@DT 18
@DT 15
@DT 12
@DT 9
@DT 6
@DT 3
@DT 0
@DT -3
@DT -6
@DT -9
@DT -12
@DT -15
@DT -18
@DT -21
@DT -25
@DT -28
@DT -31
@DT -34
@DT -37
@DT -40
@DT -43
@DT -46
@DT -50
@DT -53
@DT -56
@DT -59
@DT -62
@DT -65
@DT -68
@DT -71
@DT -74
@DT -77
@DT -80
@DT -84
@DT -87
@DT -90
@DT -93
@DT -96
@DT -99
@DT -102
@DT -105
@DT -108
@DT -111
@DT -114
@DT -117
@DT -120
@DT -123
@DT -126
@DT -129
@DT -132
@DT -134
@DT -137
@DT -140
@DT -143
@DT -146
@DT -149
@DT -152
@DT -155
@DT -157
@DT -160
@DT -163
@DT -166
@DT -169
@DT -171
@DT -174
@DT -177
@DT -180
@DT -182
@DT -185
@DT -188
@DT -190
@DT -193
@DT -196
@DT -198
@DT -201
@DT -204
@DT -206
@DT -209
@DT -211
@DT -214
@DT -216
@DT -219
@DT -222
@DT -224
@DT -226
@DT -229
@DT -231
@DT -234
@DT -236
@DT -239
@DT -241
@DT -243
@DT -246
@DT -248
@DT -250
@DT -252
@DT -255
@DT -257
@DT -259
@DT -261
@DT -263
@DT -266
@DT -268
@DT -270
@DT -272
@DT -274
@DT -276
@DT -278
@DT -280
@DT -282
@DT -284
@DT -286
@DT -288
@DT -290
@DT -292
@DT -294
@DT -295
@DT -297
@DT -299
@DT -301
@DT -303
@DT -304
@DT -306
@DT -308
@DT -309
@DT -311
@DT -313
@DT -314
@DT -316
@DT -317
@DT -319
@DT -320
@DT -322
@DT -323
@DT -325
@DT -326
@DT -327
@DT -329
@DT -330
@DT -331
@DT -333
@DT -334
@DT -335
@DT -336
@DT -338
@DT -339
@DT -340
@DT -341
@DT -342
@DT -343
@DT -344
@DT -345
@DT -346
@DT -347
@DT -348
@DT -349
@DT -350
@DT -351
@DT -351
@DT -352
@DT -353
@DT -354
@DT -354
@DT -355
@DT -356
@DT -356
@DT -357
@DT -358
@DT -358
@DT -359
@DT -359
@DT -360
@DT -360
@DT -360
@DT -361
@DT -361
@DT -362
@DT -362
@DT -362
@DT -362
@DT -363
@DT -363
@DT -363
@DT -363
@DT -363
@DT -363
@DT -363
@DT -363
@DT -364
; End function cos



;  Begin function sin
sin:
		DEC	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+1, X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
		PSH	#182
		LDY	__VSS
		LDA	__VS+1,Y
		EOR	#%444
		PLL	tmp
		CLC
		ADD	tmp
		PSH	A
		JSR	cos
		PLL	A
		PLY
		PLX
		PSH	A
		PHX
		PHY

		LDA	__VSS
		CLC
		ADD	#1
		STA	__VSS
		RST

		LDA	#1
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function sin



;  Begin function test
test:
		LDA	#-2
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+2,X
		PLL	__VS+1,X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
		LAD	__DATA+33	; const char*
		PHX
		PHY
		JSR	puts

		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		JSR	putnum

		PSH	#2
		JSR	putc

		LDY	__VSS
		LDA	__VS+2,Y
		PLY
		PLX
		PSH	A
		PHX
		PHY

		LDA	__VSS
		CLC
		ADD	#2
		STA	__VSS
		RST

		LDA	#2
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function test



;  Begin function main
main:
		LDA	#-3
		CLC
		ADD	__VSS
		STA	__VSS
;  Initialize variables 
		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
		PSH	#1
		PLL	A
		LDX	__VSS
		STA	__VS+3,X
;  Begin code
		LAD	__DATA+42	; const char*
		PHX
		PHY
		JSR	puts

.for0begin:
		LDX	__VSS
		LAD	__VS+1,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		JSR	putnum

		LAD	__DATA+77	; const char*
		PHX
		PHY
		JSR	puts

		LAD	50	; const word
		PHX
		PHY
		LAD	.s.s001
		PHX
		PHY
		JSR	gets
		PLY
		PLX
		CAD	0
		JLT	.if1else
		JEQ	.if1else
		LAD	.s.s001
		PHX
		PHY
		JSR	user_input
		PLL	A
		EOR	#%444
		CMP	#0
		JLT	.if2else
		JEQ	.if2else
		LAD	.s.s001
		PHX
		PHY
		JSR	puts

		LAD	__DATA+87	; const char*
		PHX
		PHY
		JSR	puts

		JMP	.if2done
.if2else:
.if2done:
		JMP	.if1done
.if1else:
.if1done:
.for0continue:
		JMP	.for0begin
.for0done:
		LDA	#3
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
.p:	@REST 20
.s.s001:	@REST 50
; End function main



;  Begin function user_input
user_input:
		LDA	#-4
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+4,X
		PLL	__VS+3,X
		PSH	A
		PHY
;  Initialize variables 
		JSR	get_ms
		PLY
		PLX
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
;  Begin code
		PSH	#0
		LAD	__DATA+97	; const char*
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		JSR	strcmp
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if0else
		JEQ	.if0else
		LAD	__DATA+102	; const char*
		PHX
		PHY
		JSR	puts

		JMP	.if0done
.if0else:
		PSH	#0
		LAD	__DATA+554	; const char*
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		JSR	strcmp
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		LAD	__DATA+560	; const char*
		PHX
		PHY
		JSR	puts

		PSH	#0
		LAD	1	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		JSR	putnum

		PSH	#73
		JSR	putc

		PSH	#0
		LAD	2	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		JSR	putnum

		PSH	#2
		JSR	putc

		JMP	.if1done
.if1else:
		PSH	#0
		LAD	__DATA+579	; const char*
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		JSR	strcmp
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if2else
		JEQ	.if2else
		LAD	__DATA+586	; const char*
		PHX
		PHY
		JSR	puts

		JSR	random
		PLL	A
		PSH	#0
		PSH	A
		JSR	putnum

		PSH	#2
		JSR	putc

		JMP	.if2done
.if2else:
		PSH	#0
		LAD	__DATA+598	; const char*
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		JSR	strcmp
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if3else
		JEQ	.if3else
		JSR	paint

		JMP	.if3done
.if3else:
		PSH	#0
		LAD	__DATA+604	; const char*
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		JSR	strcmp
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if4else
		JEQ	.if4else
		JSR	mandelbrot

		JMP	.if4done
.if4else:
		PSH	#0
		LAD	__DATA+615	; const char*
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		JSR	strcmp
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if5else
		JEQ	.if5else
		JSR	brown

		JMP	.if5done
.if5else:
		PSH	#0
		LAD	__DATA+621	; const char*
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		JSR	strcmp
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if6else
		JEQ	.if6else
		JSR	spin

		JMP	.if6done
.if6else:
		PSH	#1
		PLL	A
		EOR	#%444
		PLY
		PLX
		PSH	A
		PHX
		PHY

		LDA	__VSS
		CLC
		ADD	#4
		STA	__VSS
		RST

.if6done:
.if5done:
.if4done:
.if3done:
.if2done:
.if1done:
.if0done:
		PSH	#1
		PLL	A
		PLY
		PLX
		PSH	A
		PHX
		PHY

		LDA	__VSS
		CLC
		ADD	#4
		STA	__VSS
		RST

		LDA	#4
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function user_input



;  Begin function sys_agdp
sys_agdp:
		LDA	#-7
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+7, X
		PLL	__VS+6,X
		PLL	__VS+5,X
		PLL	__VS+4,X
		PLL	__VS+3,X
		PLL	__VS+2,X
		PLL	__VS+1,X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
		PHP
		SEI
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		STX	sys_agdp_registers
		STY	sys_agdp_registers+1

		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		STX	sys_agdp_registers+2
		STY	sys_agdp_registers+2+1

		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		STX	sys_agdp_registers+4
		STY	sys_agdp_registers+4+1

		LDY	__VSS
		LDA	__VS+7,Y
		STA	sys_agdp_operation

		PLP
		LDA	#7
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function sys_agdp



;  Begin function repaint
repaint:
		LDA	#-2
		CLC
		ADD	__VSS
		STA	__VSS
;  Initialize variables 
		JSR	get_ms
		PLY
		PLX
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
;  Begin code
		LAD	6	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PSH	.video_mode_register
		PSH	.video_mode_register+1
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		LDA	#2
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
.video_mode_register:	@DW -265718
; End function repaint



;  Begin function random
random:
		LDA	#-2
		CLC
		ADD	__VSS
		STA	__VSS
;  Initialize variables 
		JSR	get_ms
		PLY
		PLX
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
;  Begin code
.while0begin:
		PSH	#0
		LAD	4	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.while0done
		JEQ	.while0done
		JMP	.while0begin
.while0done:
		PSH	#0
		LAD	4	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		LAD	3	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLY
		PLX
		PSH	A
		PHX
		PHY

		LDA	__VSS
		CLC
		ADD	#2
		STA	__VSS
		RST

		LDA	#2
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function random



;  Begin function get_ms
get_ms:
;  Initialize variables 
;  Begin code
		LAD	.ms
		PLL	tmp+1
		PLL	tmp
		PHX
		PHY
		PSH	tmp
		PSH	tmp+1
		RST

		RST
;  Function variables
.ms:	@REST 7
; End function get_ms



@EQU	__CURRENT_LOCATION	$$
@ORG	-265720
sys_irqno:	@REST 1
sys_irqdata:	@REST 1
sys_graphics_register:	@REST 1
sys_disk_op:	@REST 1
sys_agdp_operation:	@REST 1
sys_agdp_registers:	@REST 6
@ORG	-264262
sys_text_buffer:	@REST 1458
@ORG	-264262
sys_raster_buffer:	@REST 78732
@ORG	-264262
sys_raster_buffer_tri:	@REST 13122
@ORG	-264262
sys_vector_buffer:	@REST 363
@ORG	0
;  Begin function boot
boot:
;  Initialize variables 
;  Begin code
		SEI
		LAD	264992	; const word
		PHX
		PHY
		LAD	265718	; const word
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		LDY	#1
		PLL	(tmp),Y
		PLL	(tmp)
		PSH	(tmp)
		PSH	(tmp),Y
		PLY
		PLX

		PSH	#364
		LAD	265717	; const word
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	#0
		LAD	265716	; const word
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		CLI
		PSH	#1
		LAD	5	; const word
		PHX
		PHY
		JSR	get_ms
		PLY
		PLX
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	#1
		LAD	6	; const word
		PHX
		PHY
		JSR	get_ms
		PLY
		PLX
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	.bootstrapped
		PSH	.bootstrapped+1
		PLY
		PLX
		CAD	0
		JLT	.if0else
		JEQ	.if0else
		LAD	__DATA+626	; const char*
		PHX
		PHY
		JSR	puts

		JMP	.if0done
.if0else:
.if0done:
		LAD	1	; const word
		STX	.bootstrapped
		STY	.bootstrapped+1

		JSR	main

		RST
;  Function variables
.bootstrapped:	@DW 0
; End function boot



@ORG	264992
;  Begin function isr
isr:
;  Initialize variables 
;  Begin code
		PSH tmp
		PSH tmp+1
		JSR	get_ms
		PLY
		PLX
		STX	.ms
		STY	.ms+1

		PSH	#0
		PSH	sys_irqno
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if0else
		JEQ	.if0else
		PSH	sys_irqdata
		LAD	0	; const word
		PHX
		PHY
		PSH	.ms
		PSH	.ms+1
		PLY
		PLX
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		JMP	.if0done
.if0else:
		PSH	#1
		PSH	sys_irqno
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		PSH	sys_irqdata
		LAD	3	; const word
		PHX
		PHY
		PSH	.ms
		PSH	.ms+1
		PLY
		PLX
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	#1
		LAD	4	; const word
		PHX
		PHY
		PSH	.ms
		PSH	.ms+1
		PLY
		PLX
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	.count
		PSH	.count+1
		INC	.count+1
		LDA	.count
		ADD	#0
		STA	.count
		LAD	10	; const word
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		CMP	#0
		JLT	.if2else
		JEQ	.if2else
		JSR	repaint

		LAD	0	; const word
		STX	.count
		STY	.count+1

		JMP	.if2done
.if2else:
.if2done:
		JMP	.if1done
.if1else:
		PSH	#5
		PSH	sys_irqno
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if3else
		JEQ	.if3else
		LAD	1	; const word
		PHX
		PHY
		PSH	.ms
		PSH	.ms+1
		PLY
		PLX
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PSH	#27
		PSH	sys_irqdata
		PLL	A
		PLL	tmp
		DIV	tmp
		PLL	tmp
		CLC
		ADD	tmp
		PSH	A
		LAD	1	; const word
		PHX
		PHY
		PSH	.ms
		PSH	.ms+1
		PLY
		PLX
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		LAD	2	; const word
		PHX
		PHY
		PSH	.ms
		PSH	.ms+1
		PLY
		PLX
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PSH	sys_irqdata
		PSH	#-13
		PLL	A
		PLL	tmp
		EOR	tmp
		PLL	tmp
		CLC
		ADD	tmp
		PSH	A
		LAD	2	; const word
		PHX
		PHY
		PSH	.ms
		PSH	.ms+1
		PLY
		PLX
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		JMP	.if3done
.if3else:
.if3done:
.if1done:
.if0done:
		PLL tmp+1
		PLL tmp
		RTI
		RST
;  Function variables
.count:	@DW 0
.ms:	@REST 2
; End function isr



@ORG	__CURRENT_LOCATION+1
;  Begin function clear_screen
clear_screen:
		LDA	#-2
		CLC
		ADD	__VSS
		STA	__VSS
;  Initialize variables 
		JSR	get_ms
		PLY
		PLX
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
;  Begin code
		PSH	#7
		LAD	6	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if0else
		JEQ	.if0else
		LAD	13122	; const word
		PHX
		PHY
		LAD	-364	; const word
		PHX
		PHY
		LAD	-264262	; const word
		PHX
		PHY
		JSR	memset
		PLY
		PLX

		JMP	.if0done
.if0else:
		PSH	#-2
		LAD	6	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		LAD	78732	; const word
		PHX
		PHY
		LAD	-364	; const word
		PHX
		PHY
		LAD	-264262	; const word
		PHX
		PHY
		JSR	memset
		PLY
		PLX

		JMP	.if1done
.if1else:
		LAD	364	; const word
		PHX
		PHY
		LAD	0	; const word
		PHX
		PHY
		LAD	-264262	; const word
		PHX
		PHY
		JSR	memset
		PLY
		PLX

.if1done:
.if0done:
		LDA	#2
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function clear_screen



;  Begin function putpixel
putpixel:
		LDA	#-5
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+5, X
		PLL	__VS+4, X
		PLL	__VS+3, X
		PSH	A
		PHY
;  Initialize variables 
		JSR	get_ms
		PLY
		PLX
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
;  Begin code
		LDY	__VSS
		LDA	__VS+5,Y
		CMP	#0
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		PSH	A
		LDY	__VSS
		LDA	__VS+5,Y
		PLL	tmp
		MLL	tmp
		PSH	A
		PLL	A
		LDX	__VSS
		STA	__VS+5,X

		LDY	__VSS
		LDA	__VS+4,Y
		CMP	#0
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		PSH	A
		LDY	__VSS
		LDA	__VS+4,Y
		PLL	tmp
		MLL	tmp
		PSH	A
		PLL	A
		LDX	__VSS
		STA	__VS+4,X

		LDY	__VSS
		LDA	__VS+5,Y
		PSH	A
		PSH	#324
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		TSH	#%001
		PSH	A
		CMP	#0
		JGT	.or1_true
		LDY	__VSS
		LDA	__VS+4,Y
		PSH	A
		PSH	#243
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		TSH	#%001
		PLL	tmp
		ORA	tmp
		PSH	A
		JMP	.or1_done
.or1_true:
		PLL	A
		PSH	#%001
.or1_done:
		PLL	A
		CMP	#0
		JLT	.if0else
		JEQ	.if0else
		LDA	__VSS
		CLC
		ADD	#5
		STA	__VSS
;
		RST
		JMP	.if0done
.if0else:
.if0done:
		PSH	#7
		LAD	6	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if2else
		JEQ	.if2else
		LDY	__VSS
		LDA	__VS+3,Y
		PSH	A
		LDY	__VSS
		LDA	__VS+4,Y
		PSH	A
		LDY	__VSS
		LDA	__VS+5,Y
		PSH	A
		JSR	putpixel_tricolor

		JMP	.if2done
.if2else:
		PSH	#-2
		LAD	6	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if3else
		JEQ	.if3else
		LDY	__VSS
		LDA	__VS+3,Y
		PSH	A
		LDY	__VSS
		LDA	__VS+4,Y
		PSH	A
		LDY	__VSS
		LDA	__VS+5,Y
		PSH	A
		JSR	putpixel_hicolor

		JMP	.if3done
.if3else:
.if3done:
.if2done:
		LDA	#5
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function putpixel



;  Begin function putpixel_tricolor
putpixel_tricolor:
		LDA	#-9
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+9, X
		PLL	__VS+8, X
		PLL	__VS+7, X
		PSH	A
		PHY
;  Initialize variables 
		PSH	#243
		PLL	A
		LDX	__VSS
		STA	__VS+1,X
		PSH	#81
		PLL	A
		LDX	__VSS
		STA	__VS+2,X
		PSH	#27
		PLL	A
		LDX	__VSS
		STA	__VS+3,X
		PSH	#9
		PLL	A
		LDX	__VSS
		STA	__VS+4,X
		PSH	#3
		PLL	A
		LDX	__VSS
		STA	__VS+5,X
		PSH	#1
		PLL	A
		LDX	__VSS
		STA	__VS+6,X
;  Begin code
		LDY	__VSS
		LDA	__VS+7,Y
		CMP	#0
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		PSH	A
		PSH	#6
		LDY	__VSS
		LDA	__VS+9,Y
		PLL	tmp
		MOD	tmp
		PSH	A
		PSH	#1
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		LDX	__VSS
		LAD	__VS+1,X
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		MLL	tmp
		PSH	A
		PLL	A
		LDX	__VSS
		STA	__VS+7,X

		PSH	#6
		LDY	__VSS
		LDA	__VS+9,Y
		PLL	tmp
		DIV	tmp
		PSH	A
		PSH	#1
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		LDY	__VSS
		LDA	__VS+8,Y
		PSH	A
		PSH	#54
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		LAD	sys_raster_buffer_tri
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PSH	#6
		LDY	__VSS
		LDA	__VS+9,Y
		PLL	tmp
		MOD	tmp
		PSH	A
		PSH	#1
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		LDX	__VSS
		LAD	__VS+1,X
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PSH	#-364
		PLL	A
		PLL	tmp
		TSH	tmp
		PLL	tmp
		ORA	tmp
		PSH	A
		PSH	#6
		LDY	__VSS
		LDA	__VS+9,Y
		PLL	tmp
		DIV	tmp
		PSH	A
		PSH	#1
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		LDY	__VSS
		LDA	__VS+8,Y
		PSH	A
		PSH	#54
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		LAD	sys_raster_buffer_tri
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	#6
		LDY	__VSS
		LDA	__VS+9,Y
		PLL	tmp
		DIV	tmp
		PSH	A
		PSH	#1
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		LDY	__VSS
		LDA	__VS+8,Y
		PSH	A
		PSH	#54
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		LAD	sys_raster_buffer_tri
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		LDY	__VSS
		LDA	__VS+7,Y
		PLL	tmp
		TSH	tmp
		PSH	A
		PSH	#6
		LDY	__VSS
		LDA	__VS+9,Y
		PLL	tmp
		DIV	tmp
		PSH	A
		PSH	#1
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		LDY	__VSS
		LDA	__VS+8,Y
		PSH	A
		PSH	#54
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		LAD	sys_raster_buffer_tri
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		LDA	#9
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function putpixel_tricolor



;  Begin function putpixel_hicolor
putpixel_hicolor:
		LDA	#-3
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+3, X
		PLL	__VS+2, X
		PLL	__VS+1, X
		PSH	A
		PHY
;  Initialize variables 
;  Begin code
		LDY	__VSS
		LDA	__VS+1,Y
		PSH	A
		LDY	__VSS
		LDA	__VS+3,Y
		PSH	A
		PSH	#1
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		LDY	__VSS
		LDA	__VS+2,Y
		PSH	A
		PSH	#324
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		LAD	sys_raster_buffer
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		LDA	#3
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function putpixel_hicolor



;  Begin function mandelbrot_test
mandelbrot_test:
		LDA	#-16
		CLC
		ADD	__VSS
		STA	__VSS
;  Load arguments
		PLY
		PLL	A
		LDX	__VSS
		PLL	__VS+16,X
		PLL	__VS+15,X
		PLL	__VS+14,X
		PLL	__VS+13,X
		PLL	__VS+12,X
		PLL	__VS+11,X
		PSH	A
		PHY
;  Initialize variables 
		LDY	__VSS
		LDX	__VS+15,Y
		LDY	__VS+16,Y
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
		LDY	__VSS
		LDX	__VS+13,Y
		LDY	__VS+14,Y
		TXA
		LDX	__VSS
		STA	__VS+3,X
		STY	__VS+4,X
		TAX
		LAD	81	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		MLW	X,Y
		DVW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+5,X
		STY	__VS+6,X
		TAX
		LAD	81	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		MLW	X,Y
		DVW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+7,X
		STY	__VS+8,X
		TAX
		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+9,X
		STY	__VS+10,X
		TAX
;  Begin code
.for0begin:
		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		ADW	X,Y
		PHX
		PHY
		LAD	324	; const word
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		CMP	#0
		JLT	.for0done
		JEQ	.for0done
		LDY	__VSS
		LDX	__VS+13,Y
		LDY	__VS+14,Y
		PHX
		PHY
		LAD	81	; const word
		PHX
		PHY
		LAD	2	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		MLW	X,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		MLW	X,Y
		DVW	X,Y
		ADW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+3,X
		STY	__VS+4,X
		TAX

		LDY	__VSS
		LDX	__VS+15,Y
		LDY	__VS+16,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		PHX
		PHY
		PLX
		PLL	A
		EOR	#%444
		PSH	A
		TXA
		EOR	#%444
		PSH	A
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		ADW	X,Y
		ADW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX

		LAD	81	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		MLW	X,Y
		DVW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+5,X
		STY	__VS+6,X
		TAX

		LAD	81	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		MLW	X,Y
		DVW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+7,X
		STY	__VS+8,X
		TAX

		LDY	__VSS
		LDX	__VS+9,Y
		LDY	__VS+10,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+11,Y
		LDY	__VS+12,Y
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		PSH	#364
		PLL	A
		PLY
		PLX
		PSH	A
		PHX
		PHY

		LDA	__VSS
		CLC
		ADD	#16
		STA	__VSS
		RST

		JMP	.if1done
.if1else:
.if1done:
.for0continue:
		LDX	__VSS
		LAD	__VS+9,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX
		JMP	.for0begin
.for0done:
		PSH	#-364
		PLL	A
		PLY
		PLX
		PSH	A
		PHX
		PHY

		LDA	__VSS
		CLC
		ADD	#16
		STA	__VSS
		RST

		LDA	#16
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function mandelbrot_test



;  Begin function mandelbrot
mandelbrot:
		LDA	#-18
		CLC
		ADD	__VSS
		STA	__VSS
;  Initialize variables 
		JSR	get_ms
		PLY
		PLX
		TXA
		LDX	__VSS
		STA	__VS+17,X
		STY	__VS+18,X
		TAX
;  Begin code
		LAD	__DATA+664	; const char*
		PHX
		PHY
		JSR	puts

		LAD	__DATA+716	; const char*
		PHX
		PHY
		JSR	puts

		LAD	10	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		PHX
		PHY
		JSR	gets
		PLY
		PLX

		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		PHX
		PHY
		JSR	atoi
		PLY
		PLX
		TXA
		LDX	__VSS
		STA	__VS+5,X
		STY	__VS+6,X
		TAX

.while0begin:
		LAD	0	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		TSH	#%001
		CMP	#0
		JLT	.while0done
		JEQ	.while0done
		LAD	__DATA+832	; const char*
		PHX
		PHY
		JSR	puts

		LAD	10	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		PHX
		PHY
		JSR	gets
		PLY
		PLX

		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		PHX
		PHY
		JSR	atoi
		PLY
		PLX
		TXA
		LDX	__VSS
		STA	__VS+5,X
		STY	__VS+6,X
		TAX

		JMP	.while0begin
.while0done:
		PSH	#-2
		LAD	6	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+17,Y
		LDY	__VS+18,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		JSR	clear_screen

		PSH	#-1
		LAD	5	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+17,Y
		LDY	__VS+18,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
.for1begin:
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LAD	324	; const word
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		CMP	#0
		JLT	.for1done
		JEQ	.for1done
		LDA	#-4
		CLC
		ADD	__VSS
		STA	__VSS
		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
		LDY	__VSS
		LDX	__VS+9,Y
		LDY	__VS+10,Y
		PHX
		PHY
		LAD	0	; const word
		PHX
		PHY
		LAD	-162	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		ADW	X,Y
		PHX
		PHY
		JSR	mandelbrot_test
		PLL	A
		PSH	#0
		PSH	A
		PLY
		PLX
		TXA
		LDX	__VSS
		STA	__VS+3,X
		STY	__VS+4,X
		TAX
		LDY	__VSS
		LDA	__VS+4,Y
		PSH	A
		LDY	__VSS
		LDX	__VS+5,Y
		LDY	__VS+6,Y
		PHX
		PHY
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LAD	sys_raster_buffer+39204
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+7,X
		STY	__VS+8,X
		TAX
.for2begin:
		LDY	__VSS
		LDX	__VS+7,Y
		LDY	__VS+8,Y
		PHX
		PHY
		LAD	121	; const word
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		CMP	#0
		JLT	.for2done
		JEQ	.for2done
		DEC	__VSS
		LDY	__VSS
		LDX	__VS+2,Y
		LDY	__VS+3,Y
		PHX
		PHY
		LAD	10	; const word
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		PSH	A
		CMP	#0
		JLT	.and4_false
		LAD	364	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+4,Y
		LDY	__VS+5,Y
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		PLL	tmp
		AND	tmp
		PSH	A
		JMP	.and4_done
.and4_false:
		PLL	A
		PSH	#%00A
.and4_done:
		PLL	A
		CMP	#0
		JLT	.if3else
		JEQ	.if3else
		PSH	#364
		PLL	A
		LDX	__VSS
		STA	__VS+1,X

		JMP	.if3done
.if3else:
		LDY	__VSS
		LDX	__VS+10,Y
		LDY	__VS+11,Y
		PHX
		PHY
		LAD	3	; const word
		PHX
		PHY
		LAD	4	; const word
		PHX
		PHY
		LAD	-121	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+8,Y
		LDY	__VS+9,Y
		ADW	X,Y
		MLW	X,Y
		DVW	X,Y
		PHX
		PHY
		LAD	-162	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+6,Y
		LDY	__VS+7,Y
		ADW	X,Y
		PHX
		PHY
		JSR	mandelbrot_test
		PLL	A
		LDX	__VSS
		STA	__VS+1,X

		PSH	#364
		LDY	__VSS
		LDA	__VS+1,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if5else
		JEQ	.if5else
		LDX	__VSS
		LAD	__VS+2,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX

		JMP	.if5done
.if5else:
.if5done:
.if3done:
		LDY	__VSS
		LDA	__VS+1,Y
		PSH	A
		LDY	__VSS
		LDX	__VS+6,Y
		LDY	__VS+7,Y
		PHX
		PHY
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+8,Y
		LDY	__VS+9,Y
		PHX
		PHY
		LAD	324	; const word
		MLW	X,Y
		PHX
		PHY
		LAD	sys_raster_buffer
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		LDY	__VSS
		LDA	__VS+1,Y
		PSH	A
		LDY	__VSS
		LDX	__VS+6,Y
		LDY	__VS+7,Y
		PHX
		PHY
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+8,Y
		LDY	__VS+9,Y
		PHX
		PHY
		PLX
		PLL	A
		EOR	#%444
		PSH	A
		TXA
		EOR	#%444
		PSH	A
		LAD	242	; const word
		ADW	X,Y
		PHX
		PHY
		LAD	324	; const word
		MLW	X,Y
		PHX
		PHY
		LAD	sys_raster_buffer
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		INC	__VSS
.for2continue:
		LDX	__VSS
		LAD	__VS+7,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX
		JMP	.for2begin
.for2done:
		JSR	getc_noblock
		PSH	#0
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#1
		PRM	#1
		CMP	#0
		JLT	.if6else
		JEQ	.if6else
		LDA	__VSS
		CLC
		ADD	#4
		STA	__VSS
		JMP	.for1done
		JMP	.if6done
.if6else:
.if6done:
		LDA	__VSS
		CLC
		ADD	#4
		STA	__VSS
.for1continue:
		LDX	__VSS
		LAD	__VS+1,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX
		JMP	.for1begin
.for1done:
		LAD	324	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if7else
		JEQ	.if7else
		JSR	getc
		PLL	A

		JMP	.if7done
.if7else:
.if7done:
		PSH	#1
		LAD	5	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+17,Y
		LDY	__VS+18,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	#1
		LAD	6	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+17,Y
		LDY	__VS+18,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		LDA	#18
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function mandelbrot



;  Begin function brown
brown:
		LDA	#-5
		CLC
		ADD	__VSS
		STA	__VSS
;  Initialize variables 
		PSH	#100
		PLL	A
		LDX	__VSS
		STA	__VS+1,X
		PSH	#100
		PLL	A
		LDX	__VSS
		STA	__VS+2,X
		JSR	get_ms
		PLY
		PLX
		TXA
		LDX	__VSS
		STA	__VS+3,X
		STY	__VS+4,X
		TAX
		PSH	#0
		PLL	A
		LDX	__VSS
		STA	__VS+5,X
;  Begin code
		PSH	#-2
		LAD	6	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		JSR	clear_screen

		PSH	#-1
		LAD	5	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

.while0begin:
		PSH	#0
		JSR	getc_noblock
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.while0done
		JEQ	.while0done
		DEC	__VSS
		JSR	random
		PLL	A
		LDX	__VSS
		STA	__VS+1,X
		LDY	__VSS
		LDA	__VS+2,Y
		PSH	A
		LDY	__VSS
		LDA	__VS+1,Y
		PSH	A
		PSH	#1
		PLL	A
		PLL	tmp
		EOR	tmp
		PLL	tmp
		CLC
		ADD	tmp
		LDX	__VSS
		STA	__VS+2,X

		LDY	__VSS
		LDA	__VS+3,Y
		PSH	A
		LDY	__VSS
		LDA	__VS+1,Y
		CMP	#0
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		PLL	tmp
		CLC
		ADD	tmp
		LDX	__VSS
		STA	__VS+3,X

		LDY	__VSS
		LDA	__VS+6,Y
		PSH	A
		PSH	#3
		LDY	__VSS
		LDA	__VS+1,Y
		PSH	A
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		PLY
		PLX
		PHY
		PLL	A
		CMP	#0
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		PLL	tmp
		CLC
		ADD	tmp
		LDX	__VSS
		STA	__VS+6,X

		LDY	__VSS
		LDA	__VS+2,Y
		CMP	#0
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		PSH	A
		LDY	__VSS
		LDA	__VS+2,Y
		PLL	tmp
		MLL	tmp
		PSH	A
		PLL	A
		LDX	__VSS
		STA	__VS+2,X

		LDY	__VSS
		LDA	__VS+3,Y
		CMP	#0
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		PSH	A
		LDY	__VSS
		LDA	__VS+3,Y
		PLL	tmp
		MLL	tmp
		PSH	A
		PLL	A
		LDX	__VSS
		STA	__VS+3,X

		LDY	__VSS
		LDA	__VS+2,Y
		PSH	A
		PSH	#324
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		TSH	#%001
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		PSH	#323
		PLL	A
		LDX	__VSS
		STA	__VS+2,X

		JMP	.if1done
.if1else:
.if1done:
		LDY	__VSS
		LDA	__VS+3,Y
		PSH	A
		PSH	#243
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		TSH	#%001
		CMP	#0
		JLT	.if2else
		JEQ	.if2else
		PSH	#242
		PLL	A
		LDX	__VSS
		STA	__VS+3,X

		JMP	.if2done
.if2else:
.if2done:
		LDY	__VSS
		LDA	__VS+6,Y
		PSH	A
		LDY	__VSS
		LDA	__VS+3,Y
		PSH	A
		LDY	__VSS
		LDA	__VS+2,Y
		PSH	A
		JSR	putpixel

		INC	__VSS
		JMP	.while0begin
.while0done:
		PSH	#1
		LAD	5	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	#1
		LAD	6	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		JSR	clear_screen

		LDA	#5
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function brown



;  Begin function paint
paint:
		LDA	#-3
		CLC
		ADD	__VSS
		STA	__VSS
;  Initialize variables 
		JSR	get_ms
		PLY
		PLX
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
		PSH	#364
		PLL	A
		LDX	__VSS
		STA	__VS+3,X
;  Begin code
		PSH	#-2
		LAD	6	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		JSR	clear_screen

		PSH	#-1
		LAD	5	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

.for0begin:
		LDA	#-3
		CLC
		ADD	__VSS
		STA	__VSS
		LAD	1	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+4,Y
		LDY	__VS+5,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		LDX	__VSS
		STA	__VS+1,X
		LAD	2	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+4,Y
		LDY	__VS+5,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		LDX	__VSS
		STA	__VS+2,X
		JSR	getc_noblock
		PLL	A
		LDX	__VSS
		STA	__VS+3,X
		LDY	__VSS
		LDA	__VS+6,Y
		PSH	A
		LDY	__VSS
		LDA	__VS+2,Y
		PSH	A
		LDY	__VSS
		LDA	__VS+1,Y
		PSH	A
		JSR	putpixel

		PSH	#66
		LDY	__VSS
		LDA	__VS+3,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		PSH	A
		CMP	#0
		JGT	.or2_true
		PSH	#26
		LDY	__VSS
		LDA	__VS+3,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		PLL	tmp
		ORA	tmp
		PSH	A
		JMP	.or2_done
.or2_true:
		PLL	A
		PSH	#%001
.or2_done:
		PLL	A
		CMP	#0
		JLT	.if1else
		JEQ	.if1else
		LDA	__VSS
		CLC
		ADD	#3
		STA	__VSS
		JMP	.for0done
		JMP	.if1done
.if1else:
		PSH	#36
		LDY	__VSS
		LDA	__VS+3,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if3else
		JEQ	.if3else
		PSH	#364
		PLL	A
		LDX	__VSS
		STA	__VS+6,X

		JMP	.if3done
.if3else:
		PSH	#37
		LDY	__VSS
		LDA	__VS+3,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if4else
		JEQ	.if4else
		PSH	#273
		PLL	A
		LDX	__VSS
		STA	__VS+6,X

		JMP	.if4done
.if4else:
		PSH	#38
		LDY	__VSS
		LDA	__VS+3,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if5else
		JEQ	.if5else
		PSH	#182
		PLL	A
		LDX	__VSS
		STA	__VS+6,X

		JMP	.if5done
.if5else:
		PSH	#39
		LDY	__VSS
		LDA	__VS+3,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if6else
		JEQ	.if6else
		PSH	#91
		PLL	A
		LDX	__VSS
		STA	__VS+6,X

		JMP	.if6done
.if6else:
		PSH	#40
		LDY	__VSS
		LDA	__VS+3,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if7else
		JEQ	.if7else
		PSH	#0
		PLL	A
		LDX	__VSS
		STA	__VS+6,X

		JMP	.if7done
.if7else:
		PSH	#41
		LDY	__VSS
		LDA	__VS+3,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if8else
		JEQ	.if8else
		PSH	#-91
		PLL	A
		LDX	__VSS
		STA	__VS+6,X

		JMP	.if8done
.if8else:
		PSH	#42
		LDY	__VSS
		LDA	__VS+3,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if9else
		JEQ	.if9else
		PSH	#-182
		PLL	A
		LDX	__VSS
		STA	__VS+6,X

		JMP	.if9done
.if9else:
		PSH	#43
		LDY	__VSS
		LDA	__VS+3,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if10else
		JEQ	.if10else
		PSH	#-273
		PLL	A
		LDX	__VSS
		STA	__VS+6,X

		JMP	.if10done
.if10else:
		PSH	#44
		LDY	__VSS
		LDA	__VS+3,Y
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%100
		DIV	#%100
		EOR	A
		PRM	#%001
		PRM	#%001
		EOR	#%001
		CMP	#0
		JLT	.if11else
		JEQ	.if11else
		PSH	#-364
		PLL	A
		LDX	__VSS
		STA	__VS+6,X

		JMP	.if11done
.if11else:
.if11done:
.if10done:
.if9done:
.if8done:
.if7done:
.if6done:
.if5done:
.if4done:
.if3done:
.if1done:
		LDA	__VSS
		CLC
		ADD	#3
		STA	__VSS
.for0continue:
		JMP	.for0begin
.for0done:
		PSH	#1
		LAD	5	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		JSR	clear_screen

		PSH	#1
		LAD	6	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		LDA	#3
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function paint



;  Begin function spin
spin:
		LDA	#-31
		CLC
		ADD	__VSS
		STA	__VSS
;  Initialize variables 
		JSR	get_ms
		PLY
		PLX
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
		PSH	#0
		PLL	A
		LDX	__VSS
		STA	__VS+3,X
		PSH	#0
		PLL	A
		LDX	__VSS
		STA	__VS+4,X
		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+24,X
		STY	__VS+25,X
		TAX
		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+26,X
		STY	__VS+27,X
		TAX
		LAD	1	; const word
		TXA
		LDX	__VSS
		STA	__VS+30,X
		STY	__VS+31,X
		TAX
;  Begin code
		JSR	clear_screen

		PSH	#3
		LAD	6	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	#-1
		LAD	5	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	#0
		PLL	A
		LDX	__VSS
		STA	__VS+3,X
.for0begin:
		LDY	__VSS
		LDA	__VS+3,Y
		PSH	A
		PSH	#5
		PLL	A
		PLL	tmp
		CMP	tmp
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		CMP	#0
		JLT	.for0done
		JEQ	.for0done
		PSH	#-364
		LAD	0	; const word
		PHX
		PHY
		PSH	#5
		LDY	__VSS
		LDA	__VS+3,Y
		PSH	A
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		LAD	3	; const word
		MLW	X,Y
		PHX
		PHY
		LAD	sys_vector_buffer
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	#324
		LAD	0	; const word
		PHX
		PHY
		LAD	1	; const word
		PHX
		PHY
		PSH	#5
		LDY	__VSS
		LDA	__VS+3,Y
		PSH	A
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		PLY
		PLX
		ADW	X,Y
		PHX
		PHY
		LAD	3	; const word
		MLW	X,Y
		PHX
		PHY
		LAD	sys_vector_buffer
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	#4
		LAD	0	; const word
		PHX
		PHY
		LAD	2	; const word
		PHX
		PHY
		PSH	#5
		LDY	__VSS
		LDA	__VS+3,Y
		PSH	A
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		PLY
		PLX
		ADW	X,Y
		PHX
		PHY
		LAD	3	; const word
		MLW	X,Y
		PHX
		PHY
		LAD	sys_vector_buffer
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	#324
		LAD	0	; const word
		PHX
		PHY
		LAD	3	; const word
		PHX
		PHY
		PSH	#5
		LDY	__VSS
		LDA	__VS+3,Y
		PSH	A
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		PLY
		PLX
		ADW	X,Y
		PHX
		PHY
		LAD	3	; const word
		MLW	X,Y
		PHX
		PHY
		LAD	sys_vector_buffer
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	#4
		LAD	0	; const word
		PHX
		PHY
		LAD	4	; const word
		PHX
		PHY
		PSH	#5
		LDY	__VSS
		LDA	__VS+3,Y
		PSH	A
		PLY
		PLX
		TXA
		STY	tmp
		MLH	tmp
		PSH	A
		TXA
		MLL	tmp
		PSH	A
		PLY
		PLX
		ADW	X,Y
		PHX
		PHY
		LAD	3	; const word
		MLW	X,Y
		PHX
		PHY
		LAD	sys_vector_buffer
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

.for0continue:
		LDX	__VSS
		LAD	__VS+3,X
		STX	tmp
		STY	tmp+1
		PSH	(tmp)
		INC	(tmp)
		PLL	A
		JMP	.for0begin
.for0done:
		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+26,X
		STY	__VS+27,X
		TAX
.for1begin:
		LDY	__VSS
		LDX	__VS+30,Y
		LDY	__VS+31,Y
		CAD	0
		JLT	.for1done
		JEQ	.for1done
		LAD	9	; const word
		PHX
		PHY
		LDY	__VSS
		LDA	__VS+27,Y
		PSH	A
		JSR	cos
		PLL	A
		PSH	#0
		PSH	A
		PLY
		PLX
		DVW	X,Y
		TXA
		LDX	__VSS
		STA	__VS+28,X
		STY	__VS+29,X
		TAX

		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+24,X
		STY	__VS+25,X
		TAX
.for2begin:
		LDY	__VSS
		LDX	__VS+24,Y
		LDY	__VS+25,Y
		PHX
		PHY
		LAD	1458	; const word
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		CMP	#0
		JLT	.for2done
		JEQ	.for2done
		LDA	#-4
		CLC
		ADD	__VSS
		STA	__VSS
		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
.for3begin:
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LAD	4	; const word
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		CMP	#0
		JLT	.for3done
		JEQ	.for3done
		LAD	364	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+32,Y
		LDY	__VS+33,Y
		PHX
		PHY
		PSH	#2
		LDY	__VSS
		LDA	__VS+29,Y
		PLL	tmp
		DIV	tmp
		PSH	A
		LDY	__VSS
		LDA	__VS+2,Y
		PSH	A
		PSH	#182
		PLL	A
		PLL	tmp
		MLL	tmp
		PSH	A
		PLL	A
		PLL	tmp
		CLC
		ADD	tmp
		PSH	A
		JSR	cos
		PLL	A
		PSH	#0
		PSH	A
		PLY
		PLX
		MLW	X,Y
		DVW	X,Y
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LDX	__VSS
		LAD	__VS+19,X
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		LAD	364	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+32,Y
		LDY	__VS+33,Y
		PHX
		PHY
		PSH	#2
		LDY	__VSS
		LDA	__VS+29,Y
		PLL	tmp
		DIV	tmp
		PSH	A
		LDY	__VSS
		LDA	__VS+2,Y
		PSH	A
		PSH	#182
		PLL	A
		PLL	tmp
		MLL	tmp
		PSH	A
		PLL	A
		PLL	tmp
		CLC
		ADD	tmp
		PSH	A
		JSR	sin
		PLL	A
		PSH	#0
		PSH	A
		PLY
		PLX
		MLW	X,Y
		DVW	X,Y
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LDX	__VSS
		LAD	__VS+23,X
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	#9
		LDY	__VSS
		LDA	__VS+29,Y
		EOR	#%444
		PSH	A
		LDY	__VSS
		LDA	__VS+2,Y
		PSH	A
		PSH	#182
		PLL	A
		PLL	tmp
		MLL	tmp
		PSH	A
		PLL	A
		PLL	tmp
		CLC
		ADD	tmp
		PSH	A
		JSR	cos
		PLL	A
		PLL	tmp
		DIV	tmp
		PSH	A
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LDX	__VSS
		LAD	__VS+9,X
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		LAD	1	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LAD	3	; const word
		MLW	X,Y
		PHX
		PHY
		LAD	sys_vector_buffer
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	#9
		LDY	__VSS
		LDA	__VS+29,Y
		EOR	#%444
		PSH	A
		LDY	__VSS
		LDA	__VS+2,Y
		PSH	A
		PSH	#182
		PLL	A
		PLL	tmp
		MLL	tmp
		PSH	A
		PLL	A
		PLL	tmp
		CLC
		ADD	tmp
		PSH	A
		JSR	sin
		PLL	A
		PLL	tmp
		DIV	tmp
		PSH	A
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LDX	__VSS
		LAD	__VS+14,X
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		LAD	2	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LAD	3	; const word
		MLW	X,Y
		PHX
		PHY
		LAD	sys_vector_buffer
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

.for3continue:
		LDX	__VSS
		LAD	__VS+1,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX
		JMP	.for3begin
.for3done:
		LDY	__VSS
		LDA	__VS+9,Y
		LDX	__VSS
		STA	__VS+13,X
		STA	sys_vector_buffer+13

		LDY	__VSS
		LDA	__VS+14,Y
		LDX	__VSS
		STA	__VS+18,X
		STA	sys_vector_buffer+14

		LAD	1	; const word
		TXA
		LDX	__VSS
		STA	__VS+1,X
		STY	__VS+2,X
		TAX
.for4begin:
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		PHX
		PHY
		LAD	5	; const word
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		CMP	#0
		JLT	.for4done
		JEQ	.for4done
		LAD	0	; const word
		TXA
		LDX	__VSS
		STA	__VS+3,X
		STY	__VS+4,X
		TAX
.for5begin:
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		LAD	5	; const word
		PLL	tmp+1
		PLL	tmp
		CAD	(tmp)
		PHP
		PLL	A
		EOR	#%A00
		DIV	#%100
		CMP	#0
		JLT	.for5done
		JEQ	.for5done
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LDX	__VSS
		LAD	__VS+9,X
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		LAD	-1	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LDX	__VSS
		LAD	__VS+19,X
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CLC
		ADD	tmp
		PSH	A
		LAD	1	; const word
		PHX
		PHY
		LAD	5	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		MLW	X,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		ADW	X,Y
		PHX
		PHY
		LAD	3	; const word
		MLW	X,Y
		PHX
		PHY
		LAD	sys_vector_buffer
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		PHX
		PHY
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LDX	__VSS
		LAD	__VS+14,X
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		LAD	-1	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		LAD	1	; const word
		MLW	X,Y
		PHX
		PHY
		LDX	__VSS
		LAD	__VS+23,X
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PSH	(tmp)
		PLL	A
		PLL	tmp
		CLC
		ADD	tmp
		PSH	A
		LAD	2	; const word
		PHX
		PHY
		LAD	5	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		MLW	X,Y
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+3,Y
		LDY	__VS+4,Y
		ADW	X,Y
		PHX
		PHY
		LAD	3	; const word
		MLW	X,Y
		PHX
		PHY
		LAD	sys_vector_buffer
		ADW	X,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

.for5continue:
		LDX	__VSS
		LAD	__VS+3,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX
		JMP	.for5begin
.for5done:
.for4continue:
		LDX	__VSS
		LAD	__VS+1,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX
		JMP	.for4begin
.for4done:
		JSR	getc_noblock
		PLL	A
		CMP	#0
		JLT	.if6else
		JEQ	.if6else
		LAD	-1	; const word
		TXA
		LDX	__VSS
		STA	__VS+34,X
		STY	__VS+35,X
		TAX

		LDA	__VSS
		CLC
		ADD	#4
		STA	__VSS
		JMP	.for2done
		JMP	.if6done
.if6else:
.if6done:
		PSH	#4
		PLL	A
		STA	sys_graphics_register

		LDA	__VSS
		CLC
		ADD	#4
		STA	__VSS
.for2continue:
		LDX	__VSS
		LAD	__VS+24,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX
		JMP	.for2begin
.for2done:
.for1continue:
		LDX	__VSS
		LAD	__VS+26,X
		STX	tmp
		STY	tmp+1
		LDY	#1
		PSH	(tmp)
		PSH	(tmp),Y
		INC	(tmp),Y
		LDA	(tmp)
		ADD	#0
		STA	(tmp)
		PLY
		PLX
		JMP	.for1begin
.for1done:
		PSH	#1
		LAD	5	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		PSH	#1
		LAD	6	; const word
		PHX
		PHY
		LDY	__VSS
		LDX	__VS+1,Y
		LDY	__VS+2,Y
		ADW	X,Y
		PHX
		PHY
		PLL	tmp+1
		PLL	tmp
		PLL	(tmp)
		PSH	(tmp)
		PLL	A

		JSR	clear_screen

		LDA	#31
		CLC
		ADD	__VSS
		STA	__VSS
		RST
;  Function variables
; End function spin



; Begin string constants
__DATA:
	@DT	 '0123456789',0
	@DT	 '0123456789',0
	@DT	 '0123456789',0
	@DT	 'value = ',0
	@DT	 'Welcome to the 3CC memory image!',2 ,2 ,0
	@DT	 ' PROMPT> ',0
	@DT	 ' -- Huh?',2 ,0
	@DT	 'HELP',0
	@DT	 'If you by HELP mean <I want to help>, press 1.',2 , 'If you by HELP mean <I need help>, press 2.',2 , 'If you by HELP mean <I dont need help>, press 3.',2 , 'Nah, seriously though, available commands are=',2 , '    MOUSE -- Print mouse coordinates. ',2 , '    RANDOM -- Print a random number. ',2 , '    PAINT -- Unleash your inner artist. Anykey exits.',2 , '    MANDELBROT -- Mandelbrot fractal. ',2 , '    BROWN -- Random walk (brownian motion). ',2 , '    SPIN -- Mildly nauseating vector gfx demo. ',2 ,2 ,0
	@DT	 'MOUSE',0
	@DT	 'Mouse coordinates=',0
	@DT	 'RANDOM',0
	@DT	 'random() = ',0
	@DT	 'PAINT',0
	@DT	 'MANDELBROT',0
	@DT	 'BROWN',0
	@DT	 'SPIN',0
	@DT	 'Possible jump to nonsensical address',2 ,0
	@DT	 'MANDELBROT. Press Any Key to exit once rendering.',2 ,2 ,0
	@DT	 'How deep would you like to iterate? (Anything over 200 will take AGES! 50 is a good suggestion)',2 ,2 , 'Iteration limit = ',0
	@DT	 'Thats no good. Positive integer please...',2 , 'Iteration limit = ',0
; Define variable stack pointer
__VSS:		@DT %444
@ORG		%CAADDD
; Define variable stack
@REST		%444
__VS @EQU %CAA000
