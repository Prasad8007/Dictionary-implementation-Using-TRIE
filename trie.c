#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ALPHABET_SIZE 26
#include "trie.h"


void init_TRIE(TRIE *t){
    *t=NULL;
}



int letterToInt(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
    {
        return letter - 'A';
    }

    else if (letter >= 'a' && letter <= 'z')
    {
        return letter - 'a';
    }

    return -1;
}



trie_node* new_node() {

    trie_node* nn = (trie_node *) malloc(sizeof(trie_node));

    if (!nn) {
        return NULL;
    }

    nn->end = false;

    for (int i = 0; i < 26; i++) {
        nn->child[i] = NULL;
    }

    return nn;

}



bool trie_insert(TRIE *t ,char word[],char meaning[]){

    int index;
    trie_node *nn1,*nn2;
    nn1=new_node();

    if(*t==NULL){
        *t=nn1;
    }

    trie_node *p=*t;
    int x= strlen(word);

    //printf("%d",x);

    for (int i = 0; i<x ; i++) {
        //printf("%c-",word[i]);
        index=letterToInt(word[i]);
        //printf("%d-",index);
        nn2 = new_node();

        if (p->child[index]==NULL) {
            p->child[index] = nn2;
        }

        p = p->child[index];
        //printf("%d\n",p->end);
    }

    p->end = true;

    strcpy(p->value,meaning);
    //printf("%d %s\n",p->end,meaning);

    return true;
}




void traverse(TRIE t) {
    trie_node *p=t;
    trie_node *q=NULL;
    int data;

    while(!p->end){
       //printf("%d\n",p->end);
       for(int i=0;i<26;i++){
         if(p->child[i]){
            data=i+97;
            //printf("%d-",i);
            printf("%c",data);
            q=p->child[i];
        }
    }
    printf("\n");
    p = q;
    return;
    }
}




void alphabetical_traverse(TRIE t, char Word[], int index)
{
    trie_node* p = t;

    if(!t){
        printf("NO words in the dictionary .");
        return;
    }

    //word is printed with meaning when end becomes true and p becomes null

    if(p != NULL && p->end == true) {

        for(int j = 0; j < index; j++){
            printf("%c",Word[j]);
        }

        printf(" : ");

        printf("%s\n",p->value);

    }

    // Word is retrieved from trie in word array with size of word==index

    for(int i = 0; i < ALPHABET_SIZE; i++){

        if(p->child[i] != NULL) {

            Word[index] = 'a' + i;

            //printf("%d\n",p->end);
            alphabetical_traverse(p->child[i], Word, index + 1);
        }
    }



}




int trie_load(TRIE *t, const char* filename)
{
    FILE *file = fopen(filename, "r");

    if (!file)
    {
        printf("could not find/open file \"%s\"\n", filename);
        return false;
    }

    char word[25];
    char meaning[300];

    int count = 0;

    while (fscanf(file, "%s %[^\n]", word, meaning) > 1)
    {
        if (!trie_insert(t, word, meaning))
        {
            fclose(file);
            return false;
        }

        else
        {
            count++;
        }
    }

    fclose(file);

    return true;
}




bool trie_deleteWord(TRIE *t, char word[]){

    int index;
    trie_node *p = *t;
    int size=strlen(word);

    for (int i = 0; i < size ; i++)
    {
        index = letterToInt(word[i]);

        if (!p->child[index])
            return false;

        p = p->child[index];
    }

    if (p != NULL && p->end)  {
        p->end = false;

    }

    return true;

}





bool trie_search(TRIE t, char word[])
{
    int index;
    trie_node *p = t;
    int size=strlen(word);

    for (int i = 0; i < size; i++)
    {
        index = letterToInt(word[i]);

        if (!p ->child[index])
            return false;

        p = p->child[index];
    }

    if (p != NULL && p->end)  {

        printf("The meaning of the word is: %s\n",p->value);

    }

    return true;
}




bool write_word(const char* filename,char word[],char meaning[]){

    FILE *file = fopen(filename, "a");

    if (!file)
    {
        printf("could not find/open file \"%s\"\n", filename);
        return false;
    }

    fprintf(file, "%s ", word);
    fprintf(file, "%s\n", meaning);

    fclose(file);

    return true;

}



void print_psearch(TRIE t, char Word[], int index, char prefix[])
{
    trie_node * p = t;

    if(p != NULL && p->end == true) {

        printf("%s",prefix);

        for(int j = 0; j < index; j++)  {

            printf("%c",Word[j]);

        }

        printf(":");

        printf("%s\n",p->value);

    }

    for(int i = 0; i < ALPHABET_SIZE; i++)  {

        if(p->child[i] != NULL) {

            Word[index] = 'a' + i;

            print_psearch(p->child[i], Word, index + 1, prefix);
        }
    }
}




void prefix_search(TRIE t , char prefix[])
{
    trie_node* p = t;

    int size=strlen(prefix);

    for(int i = 0; i < size ; i++){

        int index = letterToInt(prefix[i]);

        p = p->child[index];

    }

    char Word[50];

    print_psearch(p, Word, 0, prefix);

}


void Destroy_trie(TRIE *t){

    //*t=NULL;
    trie_node *tmp1;
    int index;


    for(int i = 0; i < ALPHABET_SIZE; i++){

        if((*t)->child[i] != NULL) {

            tmp1=(*t);
            index=i;

            if(((*t)->child[i])->end){

                trie_node *tmp2=((*t)->child[i]);
                free(tmp2);
                tmp1->child[index]=NULL;
                return;

            }

            Destroy_trie(&(*t)->child[i]);
        }

    }

    *t=NULL;

    return;

}


