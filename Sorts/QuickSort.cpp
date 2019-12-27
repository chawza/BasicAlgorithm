#include <stdio.h>
#include <stdlib.h>

void generateArray(int* array, int size);
void printArray(int* array, int size);
void quickSort(int* array, int first, int last);
void swap(int* a, int* b);
void printIndexLocation(int* array, int size, int pivot, int left, int right);

int numPartition = 0;
int array_size = 12;
int simulation_toggle = 1;  //on or off sumulation
int main(){
    //get user input for the array size
    printf("Enter length of the array [Max 100]: ");
    scanf("%d", &array_size);
    getchar();

    //generate array
    int array[100];
    generateArray(array, array_size);

    printf("intitial array with %d integer:\n", array_size);
    printArray(array, array_size);
    puts("");
    quickSort(array, 0, array_size-1);
    puts("\nafter Quick sort:");
    printArray(array, array_size);
    return 0;
}

void quickSort(int* array, int first, int last){
    if(first < last){
        numPartition++;
        int pivot = first; // we set the left most of the array as the pivot
        int left = first;
        int right = last;
        if(simulation_toggle) {
            printf("Number partition : %d\n", numPartition);
            printIndexLocation(array, array_size, pivot, left, right);
            printArray(array, array_size); 
        }
        while(left < right){
            while(array[left] <= array[pivot] && left < last) {
                left++;       //left index will get to the right
                if(simulation_toggle) printIndexLocation(array, array_size, pivot, left, right);
            }
            while(array[right] > array[pivot]) {
                right--;     //right index will get to the left
                if(simulation_toggle) printIndexLocation(array, array_size, pivot, left, right);
            }

            if(left < right){
                swap(&array[left], &array[right]);      //swap the value
                if(simulation_toggle) {
                    printArray(array, array_size); 
                }
            }
        }
        left--;
        right++;
        swap(&array[pivot], &array[left]);
        if (simulation_toggle) {
            printArray(array, array_size); 
            puts("\n\n");
        }
        
        quickSort(array, first, left);
        quickSort(array, left+1, last);
    }    
}

void generateArray(int* array, int size){
    for(int a = 0;a < size; a++){
        array[a] = rand() % 100;
    }
}

void printArray(int* array, int size){
    for(int a = 0;a < size; a++) printf("========");
    puts("");

    for(int a = 0; a< size;a++){
        printf("%d\t", array[a]);
    }
    puts("");

    for(int a = 0;a < size; a++) printf("========");
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

    for(int a = pivot+1; a < left; a++) printf("\t");
    if(left != pivot) printf("L\t");

    for(int a = left+1; a < right; a++) printf("\t");
    if(left != right) printf("R\t");

    for(int a = right; a < size; a++) printf("\t");
    puts("");
}
