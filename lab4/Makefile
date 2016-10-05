all: init ms_cli

init:
	mkdir -p bin

ms_cli: mergesort.o ms_cli.o util.o
	gcc bin/mergesort.o bin/ms_cli.o bin/util.o -o ms_cli

mergesort.o: src/mergesort.c include/util.h
	gcc -g -c src/mergesort.c -o bin/mergesort.o

util.o: src/util.c include/util.h
	gcc -g -c src/util.c -o bin/util.o

ms_cli.o: src/ms_cli.c include/util.h
	gcc -g -c src/ms_cli.c -o bin/ms_cli.o

clean:
	rm -rf bin
	rm -rf ms_cli
