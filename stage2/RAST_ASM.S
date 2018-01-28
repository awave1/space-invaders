			xdef		_plot_something_2

; [TO DO] delete this example function

y			equ		14
x			equ		12
base			equ		8

_plot_something_2:	link		a6,#0
			movea.l		base(a6),a0
			move.w		x(a6),d0
			move.w		y(a6),d1
		;	...		...
			unlk		a6
			rts

; recall: cc68x assumes d0-2/a0-2 are *not* preserved across subroutine calls!
