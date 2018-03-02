; quick clear (uses movem to reduce fetch-execute cycle overhead)
;
; takes about half the number of clock cycles as the code in clear.s, and
; so runs in about 1/100th of a second (at 8MHz) instead of 1/50th

		xdef		_clear_qk

base		equ		64		; offset from SP, not A6

_clear_qk:	movem.l		d0-7/a0-6,-(sp)
		lea		black_fill,a0
		movem.l		(a0)+,d1-7/a1-6
		movea.l		base(sp),a0
		adda.l		#32000,a0
		move.w		#614,d0
fill_loop:	movem.l		d1-7/a1-6,-(a0)
		dbra		d0,fill_loop
		movem.l		d1-5,-(a0)
		movem.l		(sp)+,d0-7/a0-6
		rts

black_fill:	dc.l		$FFFFFFFF
		dc.l		$FFFFFFFF
		dc.l		$FFFFFFFF
		dc.l		$FFFFFFFF
		dc.l		$FFFFFFFF
		dc.l		$FFFFFFFF
		dc.l		$FFFFFFFF
		dc.l		$FFFFFFFF
		dc.l		$FFFFFFFF
		dc.l		$FFFFFFFF
		dc.l		$FFFFFFFF
		dc.l		$FFFFFFFF
		dc.l		$FFFFFFFF
