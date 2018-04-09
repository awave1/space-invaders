;
;
;

	xdef	_set_ipl

_set_ipl:
	move.w	sr,d0
	move.w	d0,-(sp)