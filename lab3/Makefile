all: init pose_db

init:
	mkdir -p bin

pose_db: main.o clist.o
	g++ bin/main.o bin/clist.o -o pose_db

main.o: src/main.cpp include/clist.h 
	g++ -c src/main.cpp -o bin/main.o

clist.o: src/clist.cpp include/clist.h 
	g++ -c src/clist.cpp -o bin/clist.o

clean:
	rm -rf bin
	rm -rf pose_db