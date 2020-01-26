; Author: 	Artem Golovinm, Daniel Artuso

	xdef	_ikbd_isr
	xref	_ikbd_req

_ikbd_isr:
	movem.l	d0/a0,-(sp)
	jsr	_ikbd_req
	movem.l	(sp)+,d0/a0
	rte

