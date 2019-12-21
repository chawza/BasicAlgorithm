#include <stdio.h>
#include <stdlib.h>

void generateArray(int* array, int size);
void printArray(int* array, int size);
void quickSort(int* array, int first, int last);
void swap(int* a, int* b);
void printIndexLocation(int* array, int size, int pivot, int left, int right);

int numPartition = 0;
int main(){
    int array[12];
    int array_size = 12;
    generateArray(array, array_size);
    puts("intitial array with 12 integer:");
    printArray(array, array_size);
    puts("");
    quickSort(array, 0, 11);
    puts("\nafter Quick sort:");
    printArray(array, array_size);
    return 0;
}

void quickSort(int* array, int first, int last){
    if(first < last){
        numPartition++;
        int pivot = first; // we set the left most of the array as the pivot
        int left = first+1;
        int right = last;
        printf("Number partition : %d\n", numPartition);
        printIndexLocation(array, 12, pivot, left, right);
        printArray(array, 12); 
        while(left < right){
            while(array[left] < array[pivot] && left < last) left++;       //left index will get to the right
            while(array[right] > array[pivot]) right--;     //right index will get to the left

            if(left < right){
                swap(&array[left], &array[right]);      //swap the value
                printIndexLocation(array, 12, pivot, left, right);
                printArray(array, 12); 
            }
            else printf("Partition Finish\n");
        }
        puts("\n\n");

        swap(&array[pivot], &array[left]);
        quickSort(array, first, left-1);
        quickSort(array, left+1, last);
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

void printIndexLocation(int* array, int size, int pivot, int left, int right){
    for(int a = 0; a<pivot; a++) printf("\t");
    
    printf("[P]\t");
    for(int a = pivot+1; a< left; a++);

    printf("L\t");
    for(int a = left+1; a < right; a++) printf("\t");
    printf("R\t");

    for(int a = right; a < size; a++) printf("\t");
    puts("");
}