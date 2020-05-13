#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

typedef int LData;

typedef struct Node
{
	LData data;
	struct Node * link;
} Node;

typedef struct LinkedList
{
	Node * tail;
	Node * cur;
	Node * before;
	int numOfData;
} LinkedList;

void ListInit(LinkedList * pList)
{
	pList->tail = NULL;
	pList->cur = NULL;
	pList->before = NULL;
	pList->numOfData = 0;
}

void InsertFirstNode(LinkedList * pList, LData insertData)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = insertData;

	if (pList->tail == NULL)
	{
		pList->tail = newNode;
		newNode->link = newNode;
	}

	else
	{
		newNode->link = pList->tail->link;
		pList->tail->link = newNode;
	}

	(pList->numOfData)++;
}

void InsertLastNode(LinkedList * pList, LData insertData)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = insertData;

	if (pList->tail == NULL)
	{
		pList->tail = newNode;
		newNode->link = newNode;
	}

	else
	{
		newNode->link = pList->tail->link;
		pList->tail->link = newNode;
		pList->tail = newNode;
	}

	(pList->numOfData)++;
}

int SearchFirst(LinkedList * pList, LData * pData)
{
	if (pList->tail == NULL)
	{
		return FALSE;
	}

	pList->before = pList->tail;
	pList->cur = pList->tail->link;

	*pData = pList->cur->data;
	return TRUE;
}

int SearchNext(LinkedList * pList, LData * pData)
{
	if (pList->tail == NULL)
	{
		return FALSE;
	}

	pList->before = pList->cur;
	pList->cur = pList->cur->link;

	*pData = pList->cur->data;
	return TRUE;
}

LData DeleteNode(LinkedList * pList)
{
	Node * delNode = pList->cur;
	LData delData = delNode->data;

	if (delNode == pList->tail)
	{
		if (pList->tail == pList->tail->link)
			pList->tail = NULL;
		else
			pList->tail = pList->before;
	}

	pList->before->link = pList->cur->link;
	pList->cur = pList->before;

	free(delNode);
	(pList->numOfData)--;
	return delData;
}

void ShowList(LinkedList * pList)
{
	Node * cur = pList->tail->link;
	for (int i = 0; i < pList->numOfData; i++)
	{
		printf("%d", cur->data);
		cur = cur->link;
		if (i < pList->numOfData - 1)
		{
			printf(", ");
		}
	}
	printf("\n");
}

int ListCount(LinkedList * pList)
{
	return pList->numOfData;
}

int main()
{
	int numN, numM, numData;

	LinkedList List;
	ListInit(&List);

	scanf("%d %d", &numN, &numM);

	for (int i = 1; i <= numN; i++)
	{
		InsertLastNode(&List, i);
	}

	SearchFirst(&List, &numData);
	for (int k = 0; k < numM-1; k++)
	{
		SearchNext(&List, &numData);
	}
	printf("<%d", numData);
	DeleteNode(&List);
	while (ListCount(&List) != 0)
	{
		for (int j = 0; j < numM; j++)
		{
			SearchNext(&List, &numData);
			if (j == numM - 1)
			{
				printf(", %d", numData);
				DeleteNode(&List);
			}
		}
	}

	printf(">");

	return 0;
}