output : main.o trie.o 
	gcc main.o trie.o -o output

main.o : main.c 
	gcc -c main.c

trie.o : trie.c trie.h
	gcc -c trie.c
