OBJ_FILES=bin\stage3.o bin\event.o bin\model.o
EXE_NAME=stage3

$(EXE_NAME).tos: $(OBJ_FILES)
	cc68x -g $(OBJ_FILES) -o $(EXE_NAME).tos

bin\stage3.o: src\stage3.c 
	cc68x -g -c src\stage3.c -o bin\stage3.o

bin\event.o: src\event.c src\include\event.h src\include\const.h
	cc68x -g -c src\event.c -o bin\event.o

bin\model.o: src\model.c src\include\model.h src\include\const.h
	cc68x -g -c src\model.c -o bin\model.o
