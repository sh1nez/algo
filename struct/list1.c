#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char val;
	struct node *next;
};

typedef struct list {
	struct node* begin;
	struct node* end;
} list;

struct node* new(char data)
{
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp->val = data;
	tmp->next = NULL;
	return tmp;
}

list init(char* string)
{
	if (!string[0]){
		perror("string must exists");
		exit(1);
	}

	struct node *start = new(string[0]);
	struct node *tail = start;

	for (int i = 1; string[i]; ++i){
		tail->next = new(string[i]);
		tail = tail->next;
	}
	list ans = (list){.begin = start, .end = tail};
	
	return ans;
}

int main() {
	char* string = "abcdefghigklmonp";
	list my = init(string);

	for (struct node* i = my.begin ; ; i = i->next){
		printf("%c", i->val);
		if (NULL == i->next)
			break;
	}
	
    return 0;
}
