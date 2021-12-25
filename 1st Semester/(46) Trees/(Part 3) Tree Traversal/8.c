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

void reflect(struct BNode* root)
{
	if (!root)
		return;
	if (root->right && root->left)
	{
		struct BNode* saveLeft = root->left;
		root->left = root->right;
		root->right = saveLeft;
		reflect(root->right);
		reflect(root->left);
	}
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
	reflect(tree);
	printf("\n\n\n");
	printTree(tree, 3);
}
