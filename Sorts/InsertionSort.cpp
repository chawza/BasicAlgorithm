#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* array, int size);
int findMin(int* array, int first, int last);
void printArray(int *array, int size);
void swap(int* a, int* b);
void printCurrentIndex(int* array, int size, int curr);

int main(){
    int array[100];
    int size;
    printf("Enter array size: ");
    scanf("%d" , &size);
    getchar();
    size = size % 100;

    //genereate the array with given size
    for(int a = 0; a < size; a++){
        array[a] = rand() % 100;
    }

    printf("Initial Array:\n");
    printArray(array, size);
    puts("");

    insertionSort(array, size);

    puts("");
    printf("Array after Insertion Sort\n");
    printArray(array, size);
}

void insertionSort(int* array, int size){
    for(int a = 0; a < size; a++){
        printCurrentIndex(array, size, a);
        int min = findMin(array, a, size);
        swap(&array[a], &array[min]);
        printArray(array, size);
    }
}

int findMin(int* array, int first, int last){
    int min = first;
    for(int a = first; a <= last; a++){
        if(array[a] < array[min])
            min = a;
    }
    return min;
}

void printArray(int *array, int size){
    for(int a = 0; a < size; a++) printf("========");
    puts("");

    for(int a = 0; a < size; a++){
        printf("%d\t", array[a]);
    }
    puts("");

    for(int a = 0; a < size; a++) printf("========");
    puts("");
}

void printCurrentIndex(int* array, int size, int curr){
    for(int a = 0; a < curr; a++) printf("\t");
    printf("Curr\n");
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b =temp;
}