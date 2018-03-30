;
; 
; 
;

	xdef	_get_video_base

SCREEN	equ 	$FFFF8201

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
