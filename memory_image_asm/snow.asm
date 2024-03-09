; Snow simulator (suffers from the dreaded "bars of doom" syndrome)
;
; Loaded with LOADSUB
;
;

; ---------------------------------------------------------
;
;
;
;  Code begins
;

; Memory position for vectors
;
;
vector		@EQU	%DDB000
vector.COLOR	@EQU	vector			; Offsets for color, x and y position
vector.XPOS	@EQU	vector+1
vector.YPOS	@EQU	vector+2
vector.LENGTH	@EQU	vector+3 - vector	; Length of a vector in memory

@ORG	%DDD000
	; Bootstrap function
	;
	; Read page 2 from disk into page 2 in memory
	LDA	#2
	LDY	#2
	JSR	(jumpvector.fl_read_block)
        ; ... and page 3
	LDA	#3
	LDY	#3
	JSR	(jumpvector.fl_read_block)

	JMP	snow

; These won't be copied. They are also present in the host at the same
; memory location. 

@ORG	%001000
jumpvector:
.getstring:	@DW	0
.feedvector:	@DW	0
.putchar:	@DW	0
.putnon:	@DW	0
.puts:		@DW	0
.strcmp:	@DW	0
.strlen:	@DW	0
.index:		@DW	0
.strspn:	@DW	0
.strcspn:	@DW	0
.memset6:	@DW	0
.random:	@DW	0
.between:	@DW	0
.repaint:	@DW	0
.fl_read_block: @DW	0
.fl_write_block: @DW	0
.mouse.x       : @DW	0
.mouse.y       : @DW	0


@ORG	%002000

snow:
		LDA	#150		; Lower this value if too slow, increase if too fast
		STA	%444441
		JSR	init
		LDX	#%DDD

; Increment Y position and add random values to x position
;

.loop:
		LDA	vector.YPOS,X
		INC 	A
		STA	vector.YPOS,X
		JSR	(jumpvector.random)
		EOR	%#001
		ADD	vector.XPOS,X
		STA	vector.XPOS,X

		LDA	vector.YPOS+vector.LENGTH,X
		INC	A
		STA	vector.YPOS+vector.LENGTH,X
		LDA	vector.XPOS,X
		INC	A
		STA	vector.XPOS+vector.LENGTH,X

		LDA	vector.YPOS+2*vector.LENGTH,X
		INC	A
		STA	vector.YPOS+2*vector.LENGTH,X
		LDA	vector.XPOS,X
		STA	vector.XPOS+2*vector.LENGTH,X

		TXA
		CLC
		ADD	#9
		TAX

		JMP	.loop
	


; Initiate vectors
;
;
;

init:
		LDA	#%003
		STA	%DDDDDB
		LDX	#%DDD
.loop:
		; Vector #1
		LDA	#%DDD
		STA	vector.COLOR,X
		JSR	(jumpvector.random)
		STA	vector.XPOS,X
		JSR	(jumpvector.random)
		STA	vector.YPOS,X

		; Vector #2
		LDA	#%444
		STA	vector.COLOR+vector.LENGTH,X
		LDA	vector.XPOS,X
		INC	A
		STA	vector.XPOS+vector.LENGTH,X
		LDA	vector.YPOS,X
		STA	vector.YPOS+vector.LENGTH,X
	
		; Vector #3
		LDA	#%444
		STA	vector.COLOR+2*vector.LENGTH,X
		LDA	vector.XPOS,X
		STA	vector.XPOS+2*vector.LENGTH,X
		LDA	vector.YPOS,X
		INC	A
		STA	vector.YPOS+2*vector.LENGTH,X
	
		TXA
		CLC
		ADD	#9
		TAX
		CMP	#%DDD
		JNE	.loop


		RST

progend 	@EQU	$$
