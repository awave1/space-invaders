OBJ_FILES=bin\stage4.o bin\event.o bin\model.o bin\render.o
EXE_NAME=stage4

$(EXE_NAME).tos: $(OBJ_FILES)
	cc68x -g $(OBJ_FILES) -o $(EXE_NAME).tos

bin\stage4.o: src\stage4.c
	cc68x -g -c src\stage4.c -o bin\stage4.o

bin\event.o: src\event.c src\include\event.h src\include\const.h
	cc68x -g -c src\event.c -o bin\event.o

bin\model.o: src\model.c src\include\model.h src\include\const.h
	cc68x -g -c src\model.c -o bin\model.o

bin\render.o: src\render.c src\include\render.h src\include\const.h
	cc68x -g -c src\model.c -o bin\render.o
