#include "Tree.h"

//for Creating TreeNode
TreeNode* CreateNode(int i) {
	TreeNode* result = (TreeNode*)malloc(sizeof(TreeNode));
	if (result == NULL) {
		printf("Error At Creating TreeNode!\n");
		return NULL;
	}
	else
		return result;
}
void DeleteNode(TreeNode* node) {
	free(node);
}
//for HeapTree
HeapTree* CreateHeapTree() {
	HeapTree* tree = (HeapTree*)malloc(sizeof(HeapTree));
	if (tree == NULL) {
		printf("Error At Creating HeapTree!\n");
		return NULL;
	}
	else {
		tree->size = 33;
		tree->root = (int*)malloc(sizeof(int) * tree->size);
		tree->length = 0;
		return tree;
	}
}
void DeleteHeapTree(HeapTree* tree) {
	free(tree->root);
	free(tree);
}
void Heap_Insert(HeapTree* tree, int i) {
	if (tree->length >= tree->size) {
		printf("Cannot Insert Since Tree is FULL!\n");
		return;
	}
	else {
		int position = ++tree->length;
		tree->root[position] = i;
		while (i > tree->root[position / 2]) {
			if (position <= 1)
				break;
			else {
				int temp = tree->root[position];
				tree->root[position] = tree->root[position / 2];
				tree->root[position / 2] = temp;
				position = position / 2;
			}
		}
	}
}
int Heap_Delete(HeapTree* tree) {
	int result = tree->root[1];
	int position = 1;
	tree->root[1] = tree->root[tree->length];
	tree->length--;
	while (true) {
		int temp;
		int max_index = position*2;
		if (position * 2 > tree->length)
			break;

		if (tree->root[max_index] < tree->root[max_index + 1]) {
			max_index += 1;
		}
		if (tree->root[position] < tree->root[max_index]) {
			temp = tree->root[position];
			tree->root[position] = tree->root[position + 1];
			tree->root[position + 1] = temp;
			position = max_index;
		}
		else
			break;
	}
	return result;
}
void PrintHeapTree(HeapTree* tree) {
	for (int i = 1; i <= tree->length; i++) {
		printf("%d ", tree->root[i]);
	}
	printf("\n");
}