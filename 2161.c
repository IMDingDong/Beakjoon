#include <stdio.h>
#include <stdlib.h>

typedef int LData;

typedef struct Node
{
	LData data;
	struct Node * link;
} Node;

typedef struct LinkedList
{
	Node * head;
	int numOfData;
}LinkedList;

void ListInit(LinkedList * pList)
{
	pList->head = NULL;
	pList->numOfData = 0;
}

void InsertLastNode(LinkedList * pList, LData insertData)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	Node * cur;

	newNode->data = insertData;
	newNode->link = NULL;

	if (pList->head == NULL)
	{
		pList->head = newNode;

		(pList->numOfData)++;
	}

	else
	{
		cur = pList->head;
		while (cur->link != NULL)
		{
			cur = cur->link;
		}

		cur->link = newNode;

		(pList->numOfData)++;
	}
}

int DeleteFirstNode(LinkedList * pList)	// ¼öÁ¤
{
	Node * cur = pList->head;
	int delData;
	if (cur == NULL)
		return 0;

	else
	{
		pList->head = cur->link;
	}
	delData = cur->data;
	free(cur);
	(pList->numOfData)--;

	return delData;
}

int ListCount(LinkedList * pList)
{
	return pList->numOfData;
}

int main()
{
	int num = 0;
	int Lnum;
	LinkedList List;
	ListInit(&List);

	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
	{
		InsertLastNode(&List, i);
	}

	if (ListCount(&List) == 1)
	{
		printf("%d", DeleteFirstNode(&List));
	}
	while (ListCount(&List) != 0)
	{
		printf("%d", DeleteFirstNode(&List));
		Lnum = DeleteFirstNode(&List);
		InsertLastNode(&List, Lnum);
		printf(" ");
		if (ListCount(&List) == 1)
		{
			printf("%d", DeleteFirstNode(&List));
			break;
		}
	}

	return 0;
}