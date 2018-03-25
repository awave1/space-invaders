OBJ_FILES=bin\space.o bin\splash.o bin\menu.o bin\render.o bin\event.o bin\model.o bin\raster.o bin\font.o bin\sprites.o bin\psg.o bin\effects.o bin\music.o bin\clear_qk.o bin\clear_game.o
EXE_NAME=space

$(EXE_NAME).tos: $(OBJ_FILES)
	cc68x -g $(OBJ_FILES) -o $(EXE_NAME).tos

bin\space.o: src\space.c src\include\space.h
	cc68x -g -c src\space.c -o bin\space.o

bin\menu.o: src\menu.c src\include\menu.h
	cc68x -g -c src\menu.c -o bin\menu.o

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

bin\psg.o: src\psg.c src\include\psg.h
	cc68x -g -c src\psg.c -o bin\psg.o

bin\music.o: src\music.c src\include\music.h
	cc68x -g -c src\music.c -o bin\music.o

bin\effects.o: src\effects.c src\include\effects.h
	cc68x -g -c src\effects.c -o bin\effects.o

bin\splash.o: src\splash.c src\include\splash.h
	cc68x -g -c src\splash.c -o bin\splash.o

bin\clear_qk.o: src\asm\clear_qk.s src\include\clear_qk.h
	gen -D -L2 src\asm\clear_qk.s -obin\clear_qk.o

bin\clear_game.o: src\asm\clear_game.s src\include\clear_game.h
	gen -D -L2 src\asm\clear_game.s -obin\clear_game.o
