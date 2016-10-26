#include "xml.h"
#include "names.h"

#define BUFFER_SIZE 100000

human_t x;
int ct;

void push_back_human(phonebook_t *book, human_t *human){
//	printf("hello1\n");
	if (book->size + 1 > book->capacity){		
		human_t *tmp = book->humans;
		book->capacity *= 2;
		book->humans = realloc(tmp, book->capacity * sizeof(human_t));
		int i;
		//memcpy(book->humans, tmp, book->size);
		//printf("%d\n", tmp[0]);		
		/*for (i = 0; i < book->size; i++){
			printf("ola\n");		
			book->humans[i] = tmp[i];
		}*/
	}
	book->humans[book->size++] = *human;
}

int phone_number = 0;

void start_element(void *data, const char *element, const char **attribute) {
    /*printf("start_element %s", element);
    int i = 0;
    for (i = 0; attribute[i*]; i += 2) {
        printf(" %s= %s ", attribute[i], attribute[i + 1]);
    }
    printf("\n");*/
	//printf("hello\n");
	//printf("hello5\n");
	if (!strcmp(element, "human")){
		ct = 0;
		char tmp[1024];
		strcpy(tmp, attribute[1]);
		char *pch = strtok(tmp, " ");
		strcpy(x.name, pch);
		pch = strtok(NULL, " ");
		strcpy(x.middle_name, pch);
		pch = strtok(NULL, " ");
		strcpy(x.family_name, pch);
	}
	else if (!strcmp(element, "phone")){
		phone_number = 1;
	}
	//printf("hello6\n");
}

phonebook_t* book_it;

void end_element(void *data, const char *element) {
    //printf("end_element %s\n", element);
	//printf("hello3\n");
	if (!strcmp(element, "human")){
		for (; ct < 10; x.phones[ct++][0] = 0);
		push_back_human(book_it, &x);	
	}
	else if (!strcmp(element, "phone")){
		phone_number = 0;
	}
	//printf("hello4\n");
}

void handle_data(void *data, const char *content, int length) {
	if (phone_number){
		strncpy(x.phones[ct], content, length);
		x.phones[ct++][length] = '\0';
		//printf("%s\n", x.phones[ct - 1]);    
	}
	/*char *tmp = malloc(length);
    strncpy(tmp, content, length);
    tmp[length] = '\0';
    printf("handle_data '%s' (len %d)\n", tmp, length);
    free(tmp);*/	
}

int cmp(void* a, void* b){
	return strcmp(((human_t*)a)->family_name, ((human_t*)b)->family_name);
}

int load_phonebook_xml(const char *filename, phonebook_t *book){
	book_it = book;    
	FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    XML_Parser  parser = XML_ParserCreate(NULL);
    XML_SetElementHandler(parser, start_element, end_element);
    XML_SetCharacterDataHandler(parser, handle_data);

	int buff_size = BUFFER_SIZE;
	char buff[BUFFER_SIZE];
//	printf("hello\n");	
	memset(buff, 0, buff_size);

    size_t len = 0;
    int done = 0;
    do {
        len = fread(buff, sizeof(char), buff_size, fp);
        done = len < buff_size;
	//	printf("hello1\n");
        if (XML_Parse(parser, buff, len, done) == XML_STATUS_ERROR) {
            printf("Error: %s\n", XML_ErrorString(XML_GetErrorCode(parser)));
            return 2;
        }
		//printf("hello2\n");
    } while (!done);
    XML_ParserFree(parser);
    fclose(fp);
	
	qsort(book->humans, book->size, sizeof(human_t), (__compar_fn_t)cmp);

    return 0;
}

void save_human(FILE* fp, human_t* human){
	fprintf(fp, "\t<human name=\"%s %s %s\">\n", human->name, human->middle_name, human->family_name);
	int i;	
	for (i = 0; i < 10 && human->phones[i][0] != '\0'; i++){
		fprintf(fp, "\t\t<phone>%s</phone>\n", human->phones[i]);
	}
	fprintf(fp, "\t</human>\n");
}

int save_phonebook_xml(const char *filename, phonebook_t *book){
	FILE* fp;
	fp = fopen(filename, "w");
	if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
	fprintf(fp, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	fprintf(fp, "<phonebook>\n");
	int i;
	for (i = 0; i < book->size; i++){
		save_human(fp, &book->humans[i]);
	}
	fprintf(fp, "</phonebook>\n");		
}

void print_human(human_t *human){
	printf("name: %s\n", human->name);
	printf("middle name: %s\n", human->middle_name);
	printf("family name: %s\n", human->family_name);
	int i;	
	for (i = 0; i < 10 && human->phones[i][0] != '\0'; i++){
		printf("phone: %s\n", human->phones[i]);
	}
	printf("\n");
}

void print_phonebook(phonebook_t *book){
	printf("%d\n", (int)book->size);
	int i;
	for (i = 0; i < book->size; i++){
		print_human(&book->humans[i]);
	}
}

void clear_phonebook(phonebook_t *book){
	book->capacity = 2;
	book->size = 0;
	book->humans = realloc(book->humans, 2*sizeof(human_t));
}

human_t rand_human(){
	human_t x;
	strcpy(x.name, kNames[rand() % NAMES_CNT]);
	strcpy(x.family_name, kFamilyNames[rand() % FAMILY_NAMES_CNT]);
	strcpy(x.middle_name, kMiddleNames[rand() % MIDDLE_NAMES_CNT]);
	int i, ct = 1 + rand() % 10;
	for (i = 0; i < ct; i++){
		int j, k = 1 + rand() % 20;
		for (j = 0; j < k; j++){
			x.phones[i][j] = '0' + rand()%10;
		}
		x.phones[i][k] = '\0';
	}
	for (i = ct; i < 10; i++){
		x.phones[i][0] = '\0';
	}
	return x;
}

void gen_phonebook(phonebook_t *book, size_t size){
	int i;
	for (i = 0; i < size; i++){
		//printf("hello1\n");		
		human_t x = rand_human();
		//printf("hello2\n");
		push_back_human(book, &x);
		//printf("hello3\n");
	}
}

human_t get_human(phonebook_t *book, char* family_name);
