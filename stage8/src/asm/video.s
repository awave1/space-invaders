;
; 
; 
;

	xdef	_get_video_base
	xdef	_set_video_base

SCREEN	equ 	$FFFF8201
OFFSET 	equ 	8

; 
; it works, i think
; 
_get_video_base:
	move.l	a0,-(sp) 	; save a0
	clr.l	d0		; clear d0
	lea	SCREEN,a0
	movep.w	(a0),d0		
	lsl.l 	#8,d0
	move.l 	(sp)+,a0
	rts

_set_video_base:
	link	a6,#0
	movem.l	d0/a0,-(sp)

	move.l 	OFFSET(a6),d0
	lsr.l 	#8,d0
	lea 	SCREEN,a0
	movep.w d0,0(a0)

	movem.l (sp)+,d0/a0
	unlk	a6
	rts