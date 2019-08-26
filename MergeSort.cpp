#include <stdio.h>
#include <stdlib.h>

void print_array(int array[], int size);	//for debugging purpose
void merge_sort(int array[], int left, int right);
void merging(int array[], int left, int midL, int midR, int right);

int main() {
	int array[] = { 81,23,2442,12,234,2,55,66,423,1121,324,5,34,434,434232 };
	//int array[] = { 6, 54, 3, 2, 1 };
	int size = sizeof(array) / sizeof(array[0]);

	printf("Original : ");
	print_array(array, size);

	merge_sort(array, 0, size - 1);

	printf("After Sort : ");
	print_array(array, size);
	getchar();
	return 0;
}

void print_array(int array[], int size) {
	for (int a = 0; a < size; a++) {
		printf("%d ", array[a]);
	}
	puts("");
	return;
}

void merge_sort(int array[], int left, int right) {
	if (left >= right)		//stop to prevent overflow
		return;
	int mid = (left + right) / 2;	//divide it
	merge_sort(array, left, mid);
	merge_sort(array, mid + 1, right);

	merging(array, left, mid, mid+1, right);
}

void merging(int array[], int left, int midL, int midR, int right) {
	int temp[100];
	int idx1 = left;	//left index starting point, while midL for end left list
	int idx2 = midR;	//right index starting point, whlie right is the end right list and end sublist
	int idx_temp = 0;	//indexing on temporary array (sub array), increase everytime assigned

	//insert the smallest from two list, idx1 for the left list and idx2 for the right list.
	while (idx1 <= midL && idx2 <= right) {
		if (array[idx1] < array[idx2]) {
			temp[idx_temp++] = array[idx1++];
		}
		else {
			temp[idx_temp++] = array[idx2++];
		}
	}

	//add the remaiming left list	note: it is guarantee left list is smaller that right list if it still remains
	while (idx1 <= midL)
		temp[idx_temp++] = array[idx1++];

	//add the remaining right list	note: either left list remains or the right (this part)
	while (idx2 <= right)
		temp[idx_temp++] = array[idx2++];

	//copy from the sub array to the main array
	for (int a = left, b = 0; a <= right; a++, b++) {
		array[a] = temp[b];
	}
}
