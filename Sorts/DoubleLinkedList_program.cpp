#include <stdio.h>
#include <stdlib.h>

struct DoubleLinkedList {
	int value;
	DoubleLinkedList *next;
	DoubleLinkedList *prev;
}*head = NULL, *tail = NULL, *node;

void addNode(int input);		//add node to the tail
void printForward();			//print list from head to tail
void printBackward();			//print list from tail to head
void delNode(int delValue);		//delete member list from based from user input
void printBlank();				//print new lines to craete blanks

int main() {
	//insert the each member of list a value
	int len = 10;
	for (int a = 1; a <= len; a++) {
		addNode(a*a);
		printf("node[%d] = %d\n", a-1, a * a);
	}
	printf("press enter to continue...");

	//menu screen
	int input = NULL;
	while (input != 5) {
		printBlank();
		printf("1. print list in forward\n2. print list in backward\n3. Add node\n4. delete node\n5. exit application\n\nUser choice : ");
		scanf("%d", &input);
		puts("\n");
		getchar();

		if (input == 1) {
			printForward();		//print list from head to tail
		}
		else if (input == 2) {
			printBackward();	//print list from tail to head
		}
		else if (input == 3) {	//add node to the list
			puts("insert value to add");
			int userAddValue;
			scanf("%d", &userAddValue);
			getchar();
			addNode(userAddValue);
			puts("list after added new node: ");
			printForward();

			len++;				//increment length becuase new mamber of list has been added
		}
		else if(input == 4){	//delete member list from based from user input
			printForward();
			puts("choose value to delete!");
			int userDelValue;
			scanf("%d", &userDelValue);
			getchar();
			delNode(userDelValue);

			len--;				//decrement length because a node has been deleted
		}
		else if (input == 5) {	//program exits
			puts("Exiting program");
			getchar();
		}
		else {					//wrong input
			puts("please re-renter the choice!");
		}
		printf("press enter to continue...");
	}

	getchar();
	return 0;
}

void addNode(int input) {
	node = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	node->value = input;

	if (head == NULL && tail == NULL) {
		head = tail = node;
		head->next = tail->prev = node;
		head->prev = NULL;
	}
	else {
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	tail->next = NULL;
}

void printForward() {
	node = head;
	do {
		printf("%d ", node->value);
		node = node->next;
	} while (node != NULL);
	puts("\n");
}

void printBackward() {
	node = tail;
	do {
		printf("%d ", node->value);
		node = node->prev;
	} while (node != NULL);
	puts("\n");
}

void delNode(int delValue) {
	node = head;

	if (head == NULL && tail == NULL) {
		free(node);
		head = tail = NULL;
	}
	else {
		int flag = 0;
		for (node = head; node != NULL; node = node->next) {
			if (node->value == delValue) {
				if (node == head) {
					node->next->prev = NULL;
					head = node->next;
					free(node);
					flag = 1;
					break;
				}
				node->prev->next = node->next;
				node->next->prev = node->prev;
				free(node);
				flag = 1;
				break;
			}
		}

		if (flag == 0) {
			puts("value is not found in the list");
		}
		else {
			puts("list after the deletion: ");
			printForward();
		}
	}
}

void printBlank() {
	getchar();
	for (int a = 0; a < 25; a++) {
		printf("\n");
	}
}
