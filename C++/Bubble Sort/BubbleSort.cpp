#include "BubbleSort.h"

int *array;
int sizeA;

int main(){
    sizeA = 5;
    array = new int[sizeA];

    array[0] = 3;
    array[1] = 7;
    array[2] = 2;
    array[3] = 4;
    array[4] = 1;

    sort();

    for (size_t i = 0; i < sizeA; i++){
        cout << array[i] << endl;
    }
    
}

//Sort the Array
void sort(){
    bool isSorted = false;

    //While not sorted keep looping the array
    while(!isSorted){
        isSorted = true;
        for (size_t i = 0; i < sizeA-1; i++){
            //Swap the element if the consecutive element is small
            if(array[i] > array[i+1]){
                swap(i);
                isSorted = false;
            }
        }
    }
}

//Swap the elements
void swap(int i){
    int temp = array[i];
    array[i] = array[i+1];
    array[i+1] = temp;
}