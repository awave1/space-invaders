; File: 	video.s
; Author: 	Artem Golovinm, Daniel Artuso

	xdef	_get_video_base
	xdef	_set_video_base
	xref 	super_on
	xref 	super_off

SCREEN	equ 	$FFFF8201
OFFSET 	equ 	8

; 
; Subroutine: _get_video_base
; Description: gets video base and returns its address
_get_video_base:
	move.l	a0,-(sp) 	
	clr.l	d0		

	jsr	super_on

	lea	SCREEN,a0
	movep.w	(a0),d0		
	lsl.l 	#8,d0

	jsr	super_off

	move.l 	(sp)+,a0
	rts

; 
; Subroutine: _set_video_base
; Parameters: video base
; Description: sets passed video base
_set_video_base:
	link	a6,#0
	movem.l	d0/a0,-(sp)

	jsr	super_on

	move.l 	OFFSET(a6),d0
	lsr.l 	#8,d0
	lea 	SCREEN,a0
	movep.w d0,0(a0)

	jsr	super_off

	movem.l (sp)+,d0/a0
	unlk	a6
	rts

old_ssp:	ds.l	1
