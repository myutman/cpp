#pragma once
#include <stddef.h>
#include <expat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct human_s {
    char name[256];
    char middle_name[256];
    char family_name[256];
    char phones[10][21];
};

typedef struct human_s human_t;

struct phonebook_s {
    human_t *humans;
    size_t size;
    size_t capacity;
};

typedef struct phonebook_s phonebook_t;

int load_phonebook_xml(const char *filename, phonebook_t *book);
int save_phonebook_xml(const char *filename, phonebook_t *book);
void print_phonebook(phonebook_t *book);
void gen_phonebook(phonebook_t *book, size_t size);
void clear_phonebook(phonebook_t *book);
human_t get_human(phonebook_t *book, char* family_name);

// служебная функция
void push_back_human(phonebook_t *book, human_t *human);
