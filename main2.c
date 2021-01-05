#include "text.h"
#include <stdio.h>
#define WORD 30

int main(){

    char word[WORD] = {0};
    getword(word,NULL);

    char option = getchar();
    if (option == 'a'){
        print_lines(word);
    }
    else if (option == 'b'){
        print_similar_words(word);
    }
    
    return 0;
}