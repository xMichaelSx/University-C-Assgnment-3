#include "text.h"
#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30

int getLine(char s[]){
    char c = getchar();
    int num_of_chars = 0;
    if (c != '\n'){
        num_of_chars++;
        s[0] = c;
    } 
    for(int i=1; c != '\n' && i<LINE && c != EOF; i++){
        c = getchar();
        s[i] = c;
        num_of_chars++;
    }
    return num_of_chars;
}


int getword(char w[], char *end){

    char c = getchar();
    if (c == '\n' || c == ' ' || c == '\t' || c == EOF) return -2;
    int num_of_chars = 0;
    
    for(int i=0; c != '\n' && c != ' ' && c != '\t' && i<WORD && c != EOF ;i++){
        w[i] = c;
        num_of_chars++;
        c = getchar();
       
        if (c == '\n'){ 
            num_of_chars--;
        } 
    }

    if (c == EOF) end[0] = -1;
    return num_of_chars;
}

int substring(char *str1, char *str2){

    int similar = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (len1 < len2) return 0;

    for (int i=0; i<len1-len2+1; i++){
        for (int j=0; j<len2; j++){
            if (*(str1+i+j) == *(str2+j)){
                similar++;
            }
            else break; // else move to next i (faster this way)
        }
        if (similar == len2){
            return 1;
        }
        else similar = 0;
    }
    
    return 0;
}

int similar(char *s, char *t, int n, int len_s){ 

    int similarity = 0;
    int len_of_t = strlen(t);

    if (len_s < len_of_t) return 0;

    int i=0,j=0;

    while(i<len_of_t && j<len_s){
        if (*(t+i) == *(s+j)){
            similarity++;
            i++,j++;
        }
        else{
            j++;
        } 
    }
    if (len_s - similarity <= n) return 1; 

    return 0;
}

void print_lines(char *str){
    
    int line_len = 0;
    int print = 0;
    while (line_len != 1){
        char line[LINE] = {0};
        line_len = getLine(line);
        print = substring(line,str);
        
        if (print){
            for (int i = 0; i < line_len; i++){
                printf("%c",line[i]);
            }
        }
    }

}

void print_similar_words(char *str){

    int word_len = 0;
    int print = 0;
    char end[1] = {0};

    while (end[0] != -1){

        char word[WORD] = {0};
        word_len = getword(word, end);
        if (word_len == -2) return;

        print = similar(word,str,1,word_len);
        
        if (print){
            
            for (int i = 0; i < word_len; i++){
                printf("%c",word[i]);
            }
            printf("\n");
        }
    }
}

