#include <cstdio>
#include "../include/str.h"

void test_strcpy(){
    char c[100];
    printf("%s\n", strcpy(c, "42"));
    printf("%s\n", c);
    printf("%s\n", strcpy(c, ""));
    printf("%s\n", c);        
    printf("%s\n", strcpy(c, "1488239228"));
    printf("%s\n", c);
    printf("%s\n", strcpy(c, "148823922"));
    printf("%s\n", c);
}

void test_strcat(){
    char c[100];
    printf("%s\n", strcpy(c, "aba"));
    printf("%s\n", strcat(c, "caba"));
    printf("%s\n", c);
    printf("%s\n", strcpy(c, "aba")); 
    printf("%s\n", strcat(c, ""));
    printf("%s\n", c);    
    printf("%s\n", strcpy(c, ""));
    printf("%s\n", strcat(c, "caba"));
    printf("%s\n", c);
    printf("%s\n", strcpy(c, ""));
    printf("%s\n", strcat(c, ""));
    printf("%s\n", c);
    printf("%s\n", strcpy(c, "yesterday all "));
    printf("%s\n", strcat(c, " my troubles!!!!"));
    printf("%s\n", c);
}

void print(int x){
    if (x < 0) printf("LESS\n");
    else if (x > 0) printf("MORE\n");
    else printf("EQUAL\n");
}

void test_strcmp(){
    print(strcmp("", ""));
    print(strcmp("", "abacaba"));
    print(strcmp("abacaba", ""));
    print(strcmp("abacaba", "abacaba"));
    print(strcmp("abacaba", "abacabad"));
    print(strcmp("abacabad", "abacaba"));
}

void test_strlen(){
    printf("%d\n", strlen(""));
    printf("%d\n", strlen("abacaba"));
    printf("%d\n", strlen("Hello world!"));
    printf("%d\n", strlen("?!@#$%^&*()_+= \\/{};:/,.<>\n"));
}