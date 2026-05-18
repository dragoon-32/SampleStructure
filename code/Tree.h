#pragma once
#include <stdlib.h>
#include <stdio.h>

//Tree node for binary tree
typedef struct TreeNode {
	int content;
	struct TreeNode* child_l;
	struct TreeNode* child_r;
}TreeNode;
//BinaryTree struct
typedef struct {
	TreeNode* root;
}BinaryTree;
//HeapTree struct
typedef struct {
	//defined as a array
	int* root;
	int length;
	int size;
}HeapTree;

//for TreeNode
TreeNode* CreateNode(int i);
void DeleteNode(TreeNode* node);
//for HeapTree
HeapTree* CreateHeapTree();
void DeleteHeapTree(HeapTree* tree);
void Heap_Insert(HeapTree* tree, int i);
int Heap_Delete(HeapTree* tree);
void PrintHeapTree(HeapTree* tree);
//for BinaryTree