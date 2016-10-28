#include "../include/xml.h"
#include <time.h>

#define MAXSZ 1000

int main(int argc, char* argv[]){
	srand(time(NULL));
	phonebook_t book;
	book.capacity = 2;
	book.size = 0;
	book.humans = (human_t*) malloc(2 * sizeof(human_t));
	//printf("hello\n");
	int err = load_phonebook_xml(argv[1], &book);
	print_phonebook(&book);
	clear_phonebook(&book);
	gen_phonebook(&book, 1 + rand() % MAXSZ);
	err = save_phonebook_xml(argv[2], &book);
	free(book.humans);
	return 0;
} 
