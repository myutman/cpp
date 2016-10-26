all: mkdir main

mkdir:
	mkdir -p bin

main: main.o xml.o
	gcc bin/main.o bin/xml.o -lexpat -o main

main.o: main.c
	gcc -c main.c -o bin/main.o

xml.o: xml.c
	gcc -c xml.c -o bin/xml.o

clean:
	rm -rf bin main
