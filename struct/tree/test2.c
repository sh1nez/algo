#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

struct tree {     
  char *word;     
  int count;     
  struct tree *left; 
  struct tree *right;
};

struct tree *addtree(struct tree *, char *);
void treeprint(struct tree *);
struct tree *talloc(void);

int main() {
  struct tree *s;
  char word[MAXWORD];
  FILE *file = fopen("words.txt", "r"); 
  s = NULL;
  while (fscanf(file, "%s", word) == 1)
    if (isalpha(word[0]))
      s = addtree(s, word);
  treeprint(s);
  return 0;
}

void treeprint(struct tree *p) {
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}
struct tree *talloc(){
	return (struct tree *) malloc(sizeof(struct tree));
}

struct tree *addtree(struct tree *p, char *w) {
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


