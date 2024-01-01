#include <stdio.h>
#include <stdlib.h>

typedef struct nodeJS {
	char val;
	struct nodeJS *prev;
	struct nodeJS *next;
} nodeJS;

typedef struct list2list {
	nodeJS* begin;
	nodeJS* end;
} react;

nodeJS* new(char data, nodeJS* js)
{
	nodeJS *tmp = (struct nodeJS*)malloc(sizeof(struct nodeJS));
	tmp->val = data;
	tmp->next = NULL;
	tmp->prev = js;
	return tmp;
}

react init(char* string)
{
	if (!string[0]){
		perror("string must exitt");
		exit(1);
	}
	react ans;
	nodeJS* start = new(string[0], NULL);
	nodeJS* tail = start;
	for (size_t i = 1; string[i]; ++i){
		tail->next = new(string[i], tail);
		tail->next->prev = tail;
		tail = tail->next;
	}
	ans = (react){.begin = start, .end = tail};
	return ans;
}

void insert(nodeJS* js1, nodeJS* js2, char ch)
{

	nodeJS *new = (struct nodeJS*)malloc(sizeof(struct nodeJS));
	new->val = ch;
	new->prev = js1;
	new->next = js2;
	js1->next = new;
	js2->prev = new;
}

void clean(react* all)
{
	for (nodeJS* i = all->begin; ;i = i->next){
		if (i == all->end){
			free(i);
			break;
		}		
		free(i);
	}
}

void delete(nodeJS* js, react* base)
{
	if (NULL == js->prev){
		js->next->prev = NULL;
		base->begin = base->begin->next;
	}
	else if (NULL == js->next){
		js->prev->next = NULL;
		base->begin = base->end->prev;
	}
	else {
		js->next->prev = js->prev;
		js->prev->next = js->next;
	}
	free(js);
}


int main() {
	char* string = "abcdefgh";
	react list2 = init(string);
	insert(list2.begin, list2.begin->next, 'A');
	delete(list2.begin, &list2);

	for (nodeJS *i = list2.begin; ; i = i->next){
		printf("%c", i->val);
		if (NULL == i->next)
			break;
	}
	clean(&list2);
	/* printf("\n\n"); */
	/* for (nodeJS *i = list2.end; ; i = i->prev){ */
	/* 	printf("%c", i->val); */
	/* 	if (NULL == i->prev) */
	/* 		break; */
	/* } */

    return 0;
}
