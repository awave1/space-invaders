; File: 	super.s
; Author: 	Artem Golovinm, Daniel Artuso
	xdef	super_on
	xdef	super_off

super_on:
	move.l	d0,-(sp)
	clr.l	-(sp)
	move.w 	#$20,-(sp)
	trap	#1
	addq.l	#6,sp
	move.l	d0,old_ssp
	move.l	(sp)+,d0
	rts

super_off:
	move.l 	d0,-(sp)
	move.l	(old_ssp),-(sp)
	move.w	#$20,-(sp)
	trap	#1
	addq.l 	#6,sp
	move.l 	(sp)+,d0
	rts

old_ssp:	ds.l	1
