#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char**** get_document(char* text) {
     char**** document = NULL;
    int paragraph_count = 0;

    // Count paragraphs first
    for(int i = 0; text[i]; i++){
        if(text[i] == '\n')
            paragraph_count++;
    }
    paragraph_count++;  // last paragraph

    document = (char****) malloc(sizeof(char***) * paragraph_count);
    int p = 0;   // paragraph index
    char* paragraph_save_ptr;

    char* paragraph = strtok_r(text, "\n", &paragraph_save_ptr);

    while(paragraph){

        int sentence_count = 0;

        // Count sentences
        for(int i = 0; paragraph[i]; i++){
            if(paragraph[i] == '.')
                sentence_count++;
        }

        document[p] = (char***) malloc(sizeof(char**) * sentence_count);

        int s = 0;  // sentence index
        char* sentence_save_ptr;

        char* sentence = strtok_r(paragraph, ".", &sentence_save_ptr);

        while(sentence){

            int word_count = 0;

            // Count words
            for(int i = 0; sentence[i]; i++){
                if(sentence[i] == ' ')
                    word_count++;
            }
            word_count++;

            document[p][s] = (char**) malloc(sizeof(char*) * word_count);

            int w = 0;  // word index
            char* word_save_ptr;

            char* word = strtok_r(sentence, " ", &word_save_ptr);

            while(word){
                document[p][s][w] = (char*) malloc(sizeof(char) * (strlen(word)+1));
                strcpy(document[p][s][w], word);
                word = strtok_r(NULL, " ", &word_save_ptr);
                w++;
            }
            sentence = strtok_r(NULL, ".", &sentence_save_ptr);
            s++;
        }
        paragraph = strtok_r(NULL, "\n", &paragraph_save_ptr);
        p++;
    }
    return document;

}


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}