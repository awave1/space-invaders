; 
; 
; 
; 
; 

	xdef	_vbl_isr
	xref	_vbl_isr_request

_vbl_isr:
	movem.l	d0/a0,-(sp)
	jsr	_vbl_isr_request
	movem.l	(sp)+,d0/a0
	rte

