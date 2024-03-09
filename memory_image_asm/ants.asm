
; Ant colony
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

	JMP	ant

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
.mouse.x:	 @DW	0
.mouse.y:	@DW	0
.putpixel:	@DW	0
.getpixel:	@DW	0
.putpixel3:	@DW	0		


@ORG	%002000

@EQU	ANTS	10	; Total number of ants
ant:
		; Use AGDP to clear screen
		; 
		;
		;
		LAD	%DDBDDD
		STX	%DDDDD1
		STY	%DDDDD2
		LDA	#0
		STA	%DDDDD3
		LDA	#%DDD
		STA	%DDDDD4
		LAD	108*729
		STX	%DDDDCD
		STY	%DDDDCC
		LDA	#11
		STA	%DDDDD0

		; Enable raster729-mode
		LDA	%DDDDDB
		AND	#%44B
		STA	%DDDDDB

		LDX	#0

		; Give the ants random initial positions
		;
.init:		
		JSR	(jumpvector.random)
		PHX
		LDX	#%000
		LDY	#%400
		JSR	(jumpvector.between)
		PLX
		STA	.X,X
		JSR	(jumpvector.random)
		PHX
		LDX	#%000
		LDY	#%300
		JSR	(jumpvector.between)
		PLX
		STA	.Y,X
		
		INX
		TXA
		CMP	#ANTS
		JNE	.init	

		LDX	#0

		; Main loop
.loop:

		; Increase X position of the X:th ant
		JSR	(jumpvector.random)	; Get random value
		EOR	#%001			; Mask all but last trit
		CLC
		ADD	.X,X			; Add to X pos
		PHX
		LDX	#%000
		LDY	#%400
		JSR	(jumpvector.between)	; Impose screen clamps
		PLX
		STA	.X,X			; Store in .X[X]

		JSR	(jumpvector.random)	; Get a random value
		EOR	#%001			; mask out all but last trit
		CLC
		ADD	.Y,X			; Add to Y pos
		PHX
		LDX	#%000
		LDY	#%300
		JSR	(jumpvector.between)	; Impose clamps
		PLX
		STA	.Y,X			; Store in .Y[X]

		PHX				; Draw pixel on screen
		TXA				;
		LDY	.Y,X			;
		LDX	.X,X			;
		JSR	(jumpvector.putpixel)	; <-- here
		PLX

		INX				; Increase X until all
		TXA				; ants have been drawn,
		CMP	#ANTS			; then reset
		JNE	.notrimx
		LDX	#0
.notrimx:	
		JMP	.loop

.X:		@REST	ANTS
.Y:		@REST	ANTS		


