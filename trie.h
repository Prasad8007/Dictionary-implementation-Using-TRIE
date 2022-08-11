#include <stdbool.h>

typedef struct t_node{
    struct t_node * child[26];
    bool end;
    char value[200];
}trie_node;

typedef trie_node *TRIE;

void init_TRIE(TRIE *t);
trie_node* new_node();
void traverse(TRIE t);
bool trie_insert(TRIE *t ,char word[],char meaning[]);
void alphabetical_traverse(TRIE t, char allWords[], int index);
int trie_load(TRIE *t, const char* filename);
bool trie_search(TRIE t, char word[]);
bool trie_deleteWord(TRIE *t, char word[]);
bool write_word(const char* filename,char word[],char meaning[]);
void prefix_search(TRIE t , char prefix[]);
void Destroy_trie(TRIE *t);
