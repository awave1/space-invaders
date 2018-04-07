; 
; 
; 
; 
; 

	xdef	_vbl_isr
	xref	_vbl_req

_vbl_isr:
	movem.l	d0/a0,-(sp)
	jsr	_vbl_req
	movem.l	(sp)+,d0/a0
	rte

