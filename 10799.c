#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

typedef int SData;

typedef struct Node
{
	SData data;
	struct Node * link;
} Node;

typedef struct ListStack
{
	Node * head;
	int numOfData;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack * pStack)
{
	pStack->head = NULL;
	pStack->numOfData = 0;
}

int SIsEmpty(Stack * pStack)
{
	if (pStack->head == NULL)
		return TRUE;

	else
		return FALSE;
}

void SPush(Stack * pStack, SData data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));

	newNode->data = data;
	newNode->link = pStack->head;

	pStack->head = newNode;

	(pStack->numOfData)++;
}

SData SPop(Stack * pStack)
{
	SData delData;
	Node * delNode;

	if (SIsEmpty(pStack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	delData = pStack->head->data;
	delNode = pStack->head;

	pStack->head = pStack->head->link;
	free(delNode);

	(pStack->numOfData)--;

	return delData;
}

SData SPeek(Stack * pStack)
{
	if (SIsEmpty(pStack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pStack->head->data;
}

int StackCount(Stack * pStack)
{
	return pStack->numOfData;
}

int main(void)
{
	Stack stack;
	StackInit(&stack);
	char inputArr[100001] = { 0, };
	int numOfPiece = 0;
	int i = 0;

	scanf("%s", inputArr);

	while (inputArr[i] != 0)
	{
		if (inputArr[i] == '(')
		{
			SPush(&stack, i);
		}

		else if (inputArr[i] == ')')
		{
			if (inputArr[i - 1] == '(')
			{
				SPop(&stack);
				numOfPiece += StackCount(&stack);
			}

			else
			{
				SPop(&stack);
				numOfPiece++;
			}
		}
		i++;
	}

	printf("%d", numOfPiece);

	return 0;
}