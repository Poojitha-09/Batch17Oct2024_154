SRC = ./../src/
OBJ = ./../obj/
BIN = ./../bin/
GFLAGS = gcc
INC = ./../include/
CFLAGS = -c -g -Wall
OFLAGS = -lm -o
IFLAGS = -I./../include/
VFLAGS = v --tool=memcheck --leak-check=yes --show-reachable=yes
EXECS = $(BIN)final


$(BIN)final :$(OBJ)main.o $(OBJ)function.o
	$(GFLAGS) $(OFLAGS)final $(OBJ)main.o $(OBJ)function.o
	mv final $(BIN)

$(OBJ)main.o:$(SRC)main.c $(INC)header.h 
	$(GFLAGS) $(CFLAGS) $(SRC)main.c $(IFLAGS)
	mv main.o $(OBJ)

$(OBJ)function.o:$(SRC)function.c $(INC)header.h
	$(GFLAGS) $(CFLAGS) $(SRC)function.c $(IFLAGS)
	mv function.o $(OBJ)

clean:
	rm $(OBJ)*
	rm $(BIN)final

valgrind:$(EXECS)
	valgrind $(VFLAGS) $(BIN)final

