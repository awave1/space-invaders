stage2.tos: stage2.o raster.o font.o bitmap.o rast_asm.o
	cc68x -g stage2.o raster.o font.o bitmap.o rast_asm.o -o stage2.tos

stage2.o: stage2.c raster.h bitmap.h
	cc68x -g -c stage2.c

raster.o: font.o raster.c raster.h
	cc68x -g -c raster.c

bitmap.o: bitmap.c bitmap.h
	cc68x -g -c bitmap.c

font.o: font.c font.h
	cc68x -g -c font.c

rast_asm.o: rast_asm.s
	gen -D -L2 rast_asm.s
