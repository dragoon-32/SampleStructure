#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tree.h"

int* CreateRandomArray(int size);
void printArray(int* arr, int size);

int main(void) {
	HeapTree* tree = CreateHeapTree();

	int size = 32;
	int* data = CreateRandomArray(size);
	printArray(data, size);
	
	for (int i = 0; i < size; i++) {
		Heap_Insert(tree, data[i]);
	}
	PrintHeapTree(tree);

	printf("%d\n", Heap_Delete(tree));
	PrintHeapTree(tree);

	free(data);
	DeleteHeapTree(tree);
	return 0;
}

int* CreateRandomArray(int size) {
	srand(time(NULL));
	int* array = (int*)malloc(sizeof(int) * size);
	if (array == NULL) {
		printf("Error at Creating RandomArray!\n");
		return NULL;
	}
	else {
		for (int i = 0; i < size; i++) {
			array[i] = i;
		}
		for (int i = size - 1; i > 1; i--) {
			int index = (rand() % i);
			int temp = array[index];
			array[index] = array[i];
			array[i] = temp;
		}
		return array;
	}
}

void printArray(int* arr, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}