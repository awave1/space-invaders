		xdef 		_clear_game

base: 		equ 		64

_clear_game:	movem.l		d0-7/a0-6,-(sp)
		lea		black_fill,a0
		movem.l		(a0)+,d1-7/a1-6
		movea.l		base(sp),a0
		adda.l		#32000,a0
		move.w		#560,d0
fill_loop_g:	movem.l		d1-7/a1-6,-(a0)
		dbra		d0,fill_loop_g
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