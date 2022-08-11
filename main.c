#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include"trie.h"

int main()
{
    TRIE t1;
    init_TRIE(&t1);
    bool loop=true;
    int input=0;
    char word[20];
    char meaning[200];
    //char name1[]="Hello";
    //char name2[]="Name";
    //char mean1[]="Hi or hey";
    //char mean2[]="Identity";
    //char allwords[300];
    //trie_insert(&t1,name1 , mean1);
    //write_word("Dictionary2.txt",name1,mean1);
    //trie_insert(&t1,name2 , mean2);
    //write_word("Dictionary2.txt",name2,mean2);

    //trie_load(&t1,"Dictionary.txt");
    //return 0;


    //deleteWord(&t1,"alter");
    //printf("found - %d\n",search(t1,"alter"));
    //printf("found - %d",search(t1,"prasad"));
    //char allwords[50];
    //alphabetical_traverse(t1,allwords,0);
    //trie_insert(&t1,name3 , 7);
    //printf("%c",x);

    printf("-------WELCOME TO OUR DICTIONARY-------");
    while(loop){

        printf("\n\n# Choose an option \n");
        printf("1. Insert a word in the trie.\n");
        printf("2. Search a word in the trie.\n");
        printf("3. Delete a word from the trie.\n");
        printf("4. Load dictionary into trie. \n");
        printf("5. Print dictionary in alphabetical order.\n");
        printf("6. Add a new word to dictionary .\n");
        printf("7. Print prefix search .\n");
        printf("8. Destroy the TRIE .\n");
        printf("9. STOP !!! .\n\n");

        scanf("%d",&input);
        printf("\n");


        if(input==1){
            printf("Enter the word to be inserted : ");
            scanf("%s",word);
            printf("Enter its meaning : ");
            fflush(stdin);
            //gets(meaning);
            scanf("%s",meaning);

            if(trie_insert(&t1, word, meaning)) {
                        printf("%s has been added to the Dictionary.\n",word);
                    }
            }


        else if(input==2){
            printf("Enter the word to be searched : ");
            scanf("%s",word);
            if(!trie_search(t1, word)){
                printf("Sorry !!! the word you searched for doesn't exist. Would you like to add it to the Dictionary.(Yes=1/No=0) ");
                int add;
                scanf("%d",&add);

                if(add==1){
                    printf("Enter its meaning : ");
                    fflush(stdin);
                    //gets(meaning);
                    scanf("%s",meaning);
                }

                if(trie_insert(&t1, word, meaning)){
                    printf("%s has been added to the Dictionary.\n",word);
                    }
                }
            }

        else if(input==3){
            printf("Enter the word to be deleted : ");
            scanf("%s",word);

            if(trie_deleteWord(&t1, word))  {
                printf("%s has been deleted from the Dictionary.\n",word);
            }

            else{
                printf("No such word exists in the Dictionary.\n");
            }

        }

        else if(input==4){
            if(trie_load(&t1,"Dictionary2.txt")){
                printf("All words from Dictionary are inserted into trie .\n");
            }

        }

        else if(input==5){
            char Word[30];
            alphabetical_traverse(t1, Word, 0);
            printf("\n");
        }

        else if(input==6){
            printf("Enter the word to be inserted in Dictionary: ");
            scanf("%s",word);
            printf("Enter its meaning : ");
            fflush(stdin);
            //gets(meaning);
            scanf("%s",meaning);

            if(write_word("Dictionary2.txt", word, meaning)) {
                    printf("%s has been added to the Dictionary.\n",word);

                }

        }

        else if(input==7){
            printf("Enter the prefix of a word to be searched in Dictionary: ");
            scanf("%s",word);
            prefix_search(t1,word);

        }


        else if(input==8){
            printf("TRIE has been Destroyed . ");
            Destroy_trie(&t1);
            Destroy_trie(&t1);

        }

        else if(input==9){
                printf("\n\nTHANK YOU !!!");
                break;
        }

    }

    return 0;

}



