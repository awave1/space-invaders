OBJ_FILES=bin\space.o bin\render.o bin\event.o bin\model.o bin\raster.o bin\font.o bin\sprites.o bin\clear_qk.o
EXE_NAME=space

$(EXE_NAME).tos: $(OBJ_FILES)
	cc68x -g $(OBJ_FILES) -o $(EXE_NAME).tos

bin\space.o: src\space.c src\include\space.h
	cc68x -g -c src\space.c -o bin\space.o

bin\event.o: src\event.c src\include\event.h src\include\const.h
	cc68x -g -c src\event.c -o bin\event.o

bin\model.o: src\model.c src\include\model.h src\include\const.h
	cc68x -g -c src\model.c -o bin\model.o

bin\render.o: src\render.c src\include\render.h src\include\const.h
	cc68x -g -c src\render.c -o bin\render.o

bin\raster.o: bin\font.o src\raster.c src\include\raster.h
	cc68x -g -c src\raster.c -o bin\raster.o

bin\sprites.o: src\sprites.c src\include\sprites.h
	cc68x -g -c src\sprites.c -o bin\sprites.o

bin\font.o: src\font.c src\include\font.h
	cc68x -g -c src\font.c -o bin\font.o

bin\clear_qk.o: src\asm\clear_qk.s src\include\clear_qk.h
	gen -D -L2 src\asm\clear_qk.s -obin\clear_qk.o
