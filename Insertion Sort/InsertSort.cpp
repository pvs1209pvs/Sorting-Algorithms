#include "InsertSort.h"

int *unsorted;
int sizeA;

int main(){
    sizeA = 5;
    unsorted = new int[sizeA];

    unsorted[0] = 2;
    unsorted[1] = 5;
    unsorted[2] = 4;
    unsorted[3] = 3;
    unsorted[4] = 1;
    
    sort();
    for(int i=0; i<sizeA ; i++){
        cout << unsorted[i] << endl;
    }
}

void sort(){
    for (size_t i = 1; i < sizeA; i++){
        int temp = unsorted[i]; // 5
        int j = i-1;
        while (j>=0 && unsorted[j] > temp){
            unsorted[j+1] = unsorted[j];
            j--;
        }
        unsorted[j+1] = temp;
    }
    
}