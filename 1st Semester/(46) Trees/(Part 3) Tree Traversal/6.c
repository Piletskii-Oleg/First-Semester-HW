#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
struct BNode
{
	int data;
	struct BNode* left, *right;
};

void destroy(struct BNode* root)
{
	if (!root)
		return;

	destroy(root->right);
	destroy(root->left);
	free(root);
}

struct BNode* newTree(int data, struct BNode* left, struct BNode* right)
{
	struct BNode* root = (struct BNode*)malloc(sizeof(struct BNode));
	root->data = data;
	root->left = left;
	root->right = right;
	return root;
}

void printTree(struct BNode* root, int offset)
{
	if (root == NULL)
		return;

	printTree(root->right, offset + 3);
	for (int i = 0; i < offset; i++)
	{
		printf(" ");
	}
	printf("%d\n", root->data);
	printTree(root->left, offset + 3);
}

int main()
{
	struct BNode* tree = newTree(9, newTree(2, newTree(4, 0, 0), newTree(5, 0, 0)), newTree(3, newTree(6, 0, 0), 0));

	printTree(tree, 3);
	printf("%p", find(tree, 2)->right);
}
