	xdef	_super_on
	xdef	_super_off

_super_on:
	move.l	d0,-(sp)
	clr.l	-(sp)
	move.w 	#$20,-(sp)
	trap	#1
	addq.l	#6,sp
	move.l	d0,old_ssp
	move.l	(sp)+,d0
	rts

_super_off:
	move.l 	d0,-(sp)
	move.l	(old_ssp),-(sp)
	move.w	#$20,-(sp)
	trap	#1
	addq.l 	#6,sp
	move.l 	(sp)+,d0
	rts

old_ssp:	ds.l	1
