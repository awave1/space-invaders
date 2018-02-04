OBJ_FILES=bin\stage2.o bin\raster.o bin\font.o bin\bitmap.o bin\rast_asm.o
EXE_NAME=stage2

$(EXE_NAME).tos: $(OBJ_FILES)
	cc68x -g $(OBJ_FILES) -o $(EXE_NAME).tos

bin\stage2.o: src\stage2.c src\include\raster.h src\include\bitmap.h
	cc68x -g -c src\stage2.c -o bin\stage2.o

bin\raster.o: bin\font.o src\raster.c src\include\raster.h
	cc68x -g -c src\raster.c -o bin\raster.o

bin\bitmap.o: src\bitmap.c src\include\bitmap.h
	cc68x -g -c src\bitmap.c -o bin\bitmap.o

bin\font.o: src\font.c src\include\font.h
	cc68x -g -c src\font.c -o bin\font.o

bin\rast_asm.o: src\rast_asm.s
	gen -D -L2 src\rast_asm.s -obin\rast_asm.o 
