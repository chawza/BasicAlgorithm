#include <stdio.h>
#include <stdlib.h>

void generateArray(int* array, int size);
void printArray(int* array, int size);
void quickSort(int* array, int first, int last);
void swap(int* a, int* b);
void printIndexLocation(int* array, int size, int left, int right);

int main(){
    int array[12];
    int array_size = 12;
    generateArray(array, array_size);
    puts("intitial array with 12 integer:\n");
    printArray(array, array_size);
    quickSort(array, 0, 11);
    puts("after Quick sort:");
    printArray(array, array_size);
    getchar();
    return 0;
}

void quickSort(int* array, int first, int last){
    int pivot = first; // we set the left most of the array as the pivot
    int left = first;
    int right = last;
    if(left < right){
        printIndexLocation(array, 12, left, right);
        printArray(array, 12); 
        while(left < right){
            while(array[left] <= array[pivot]) left++;       //left index will get to the right
            while(array[pivot] < array[right]) right--;     //right index will get to the left

            if(left < right)
                swap(&array[left], &array[right]);      //swap the value
            printIndexLocation(array, 12, left, right);
            printArray(array, 12); 
        }
        puts("\n\n");

        swap(&array[pivot], &array[left]);
        quickSort(array, first, right);
        quickSort(array, right+1, last);
    }    
}

void generateArray(int* array, int size){
    for(int a = 0;a < size; a++){
        array[a] = rand() % 100;
    }
}

void printArray(int* array, int size){
    for(int a = 0;a < 12; a++) printf("========");
    puts("");

    for(int a = 0; a< size;a++){
        printf("%d\t", array[a]);
    }
    puts("");

    for(int a = 0;a < 12; a++) printf("========");
    puts("");
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b =temp;
}

void printIndexLocation(int* array, int size, int left, int right){
    for(int a = 0; a<left; a++) printf("\t");

    printf("L\t");
    for(int a = left+1; a < right; a++) printf("\t");
    printf("R\t");

    for(int a = right; a < size; a++) printf("\t");
    puts("");
}
