#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 100

struct tree {
	char* word;
	int count;
	struct tree* left;
	struct tree* right;
};

void* talloc() {
	return (struct tree*) malloc(sizeof(struct tree));
}

struct tree* addtree(struct tree* p, char* w)
{
	int cond;
	if (p == NULL) { 
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++; 
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else 
		p->right = addtree(p->right, w);
	return p;
}

void printTree(struct tree* p){
	if (p != NULL){
		printTree(p->left);
		printf("word %s input %d times\n",  p->word, p->count);
		printTree(p->right);
	}
}


int main() {
	FILE *file = fopen("words.txt", "r");
	char word[BUF];
	fscanf(file, "%s", word);

	struct tree s  = {word, 1, NULL, NULL};

	while (fscanf(file, "%99s", word) == 1) addtree(&s, word);

	printTree(&s);

    return 0;
}

