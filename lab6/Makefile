all: mkdir main

mkdir:
	mkdir -p bin

main: main.o xml.o
	gcc bin/main.o bin/xml.o -lexpat -o main

main.o: src/main.c include/xml.h
	gcc -c src/main.c -o bin/main.o

xml.o: src/xml.c include/xml.h include/names.h
	gcc -c src/xml.c -o bin/xml.o

clean:
	rm -rf bin main
