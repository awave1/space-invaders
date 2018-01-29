stage2exe: stage2.o raster.o rast_asm.o
	cc68x -g stage2.o raster.o rast_asm.o -o stage2exe

stage2.o: stage2.c raster.h
	cc68x -g -c stage2.c

raster.o: raster.c raster.h
	cc68x -g -c raster.c

rast_asm.o: rast_asm.s
	gen -D -L2 rast_asm.s
