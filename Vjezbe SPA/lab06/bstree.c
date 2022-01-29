#include <stdio.h>
#include <malloc.h>
#include "bstree.h"
#define max_length 100

BSTree NewBSTree()
{
	return NULL;
}

void CreateNode(BSTree* bst, char* word) {
	*bst = (BSTree)malloc(sizeof(Node));
	(*bst)->left = NULL;
	(*bst)->right = NULL;
	(*bst)->word = word;
}

void AddNode(BSTree* bst, char* word)
{

	if (*bst == NULL) {
		return CreateNode(bst, word);
	}

	else if (strcmp((*bst)->word, word) == 0) {
		return;
	}

	else if (strcmp((*bst)->word, word) > 0) {
		return AddNode(&(*bst)->left, word);
	}

	else if (strcmp((*bst)->word, word) < 0){
		return AddNode(&(*bst)->right, word);
	}

}

int BSTHeight(BSTree bst)
{
	if (bst == NULL) {
		return 0;
	}

	int left_depth = BSTHeight(bst->left);
	int right_depth = BSTHeight(bst->right);

	if (left_depth > right_depth) {
		return left_depth + 1;
	}
	else {
		return right_depth + 1;
	}

	return 0;
}

void PrintBSTree(BSTree bst)
{
	if (bst == NULL) {
		return;
	}
	else {
		PrintBSTree(bst->left);
		printf("String: %s\n", bst->word);
		PrintBSTree(bst->right);
	}

}

void SaveBSTree(BSTree bst, FILE* fd)
{

	if (bst == NULL) {
		return;
	}
	else {
		fprintf(fd, "%s, ", bst->word);
		SaveBSTree(bst->left, fd);
		SaveBSTree(bst->right, fd);
	}
}

void DeleteBSTree(BSTree bst)
{

	if (bst == NULL) {
		return;
	}
	else {
		DeleteBSTree(bst->left);
		DeleteBSTree(bst->right);
		free(bst->word);
		free(bst);
	}
}

BSTree LoadBSTree(FILE* fd)
{
	BSTree bst;
	bst = NewBSTree();
	char buffer[max_length];
	while (readWord(fd, buffer)) {
		AddNode(&bst, _strdup(buffer));
	}
	return bst;
}
