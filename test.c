#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rbtree.h"

#define COUNT 10

int main(int argc, char const *argv[])
{
	printf("\n");
	printf("----------------------------------\n");
	printf("\n");

	int count = COUNT;
	if (argc > 1)
		count = atoi(argv[1]);
	if (count < 1)
		count = 1;

	srand(time(NULL));
	int arr[count], key, again;
	for (int i = 0; i < count; ++i) {
		key = rand()%count + 1, again = 0;
		for (int j = 0; j < i; ++j) 
			if (arr[j] == key && (again = 1)) 
				break;
		again ? --i : (arr[i] = key);
	}
	printf("Красно-черное дерево ввиде одномерного массива\n");
	for (int i = 0; i < count; ++i)
		printf("%2d ", arr[i]);
	printf("\n");

	struct rbroot root = { NULL };
	for (int i = 0; i < count; ++i){
		insert(&root, arr[i]);
		printf("\nДобавляем элемент со значением %d в дерево\n", arr[i]);
		print_rbtree(root.node);
		if (is_rbtree(root.node)) {
			printf("Свойства Красно-черного дерева сохраняются\n");
		} else {
			printf("Свойства Красно-черного дерева не сохраняются !!!\n");
			exit(-1);
		}
		printf("\n");
		printf("----------------------------------\n");
		printf("\n");
	}

	for (int i = 0; i < count; ++i){
		delete(&root, arr[i]);
		printf("\n");
		printf("Удаляем элемент со значением %d из дерева\n", arr[i]);
		print_rbtree(root.node);
		if (is_rbtree(root.node)) {
			printf("Свойства Красно-черного дерева сохраняются\n");
		} else {
			printf("Свойства Красно-черного дерева не сохраняются !!!\n");
			exit(-1);
		}
		printf("\n");
		printf("----------------------------------\n");
		printf("\n");
	}
	return 0;
}


