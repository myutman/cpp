all: init main

init:
	mkdir -p bin

main: main.o clist.o intrusive.o str.o
	g++ bin/main.o bin/clist.o bin/str.o bin/intrusive.o -o main

main.o: src/main.cpp include/clist.h include/str.h include/intrusive.h 
	g++ -c src/main.cpp -o bin/main.o

clist.o: src/clist.cpp include/clist.h 
	g++ -c src/clist.cpp -o bin/clist.o

intrusive.o: src/intrusive.cpp include/clist.h include/intrusive.h
	g++ -c src/intrusive.cpp -o bin/intrusive.o

str.o: src/str.cpp include/str.h
	g++ -c src/str.cpp -o bin/str.o
clean:
	rm -rf bin
	rm -rf main
