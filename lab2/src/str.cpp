char * strcpy(char * destination, const char * source){
    int i;
    for (i = 0; source[i] != 0; i++){
        destination[i] = source[i];
    }
    destination[i] = 0;
    return destination;
}

char * strcat(char * destination, const char * source){
    int j;
    for (j = 0; destination[j] != 0; j++);
    for (int i = 0; source[i] != 0; i++){
        destination[j + i] = source[i];
    }
    destination[j + i] = 0;
    return destination;    
}

int strcmp(const char * str1, const char * str2){
    for (int i = 0; str1[i] != 0 || str2[i] != 0; i++){
        if (str1[i] < str2[i]) return -1;
        if (str1[i] > str2[i]) return 1;
    }
    return 0;
}

size_t strlen(conts char * str){
    size_t j;
    for (j = 0; str[j] != 0; j++);
    return j;
}