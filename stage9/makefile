OBJ_FILES=bin\spaceinv.o bin\game.o bin\splash.o bin\menu.o bin\render.o bin\isr.o bin\event.o bin\model.o bin\raster.o bin\font.o bin\sprites.o bin\psg.o bin\effects.o bin\music.o bin\clear.o bin\video.o bin\vbl.o
EXE_NAME=spaceinv

$(EXE_NAME).tos: $(OBJ_FILES)
	cc68x -g $(OBJ_FILES) -o $(EXE_NAME).tos

bin\spaceinv.o: src\spaceinv.c src\include\spaceinv.h
	cc68x -g -c src\spaceinv.c -o bin\spaceinv.o

bin\game.o: src\game.c src\include\game.h
	cc68x -g -c src\game.c -o bin\game.o

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

bin\isr.o: src\isr.c src\include\isr.h
	cc68x -g -c src\isr.c -o bin\isr.o

bin\vector.o: src\vector.c src\include\vector.h
	cc68x -g -c src\vector.c -o bin\vector.o

bin\clear.o: src\asm\clear.s src\include\clear.h
	gen -D -L2 src\asm\clear.s -obin\clear.o

bin\video.o: src\asm\video.s src\include\video.h
	gen -D -L2 src\asm\video.s -obin\video.o

bin\vbl.o: src\asm\vbl.s src\include\vbl.h
	gen -D -L2 src\asm\vbl.s -obin\vbl.o
