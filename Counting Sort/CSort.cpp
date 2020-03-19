#include "CSort.h"

int *unsorted;
int *sorted;
int sizeA = 7;

int main(){
    unsorted = new int[sizeA];
    sorted = new int[(sizeA+1)];

    unsorted[0]= 1;
    unsorted[1]= 4;
    unsorted[2]= 1;
    unsorted[3]= 2;
    unsorted[4]= 7;
    unsorted[5]= 5;
    unsorted[6]= 2;

    int *intarray = new int[10];
    sort(intarray);

    for (size_t i = 0; i < (sizeA+1); i++){
        if(sorted[i] == 0){
            continue;
        }
        cout << sorted[i] << endl;
    }
    
    
}

void sort(int *intarray){
    for (size_t i = 0; i < sizeA; i++){
        intarray[unsorted[i]] = intarray[unsorted[i]] + 1;
    }

    for (size_t i = 1; i < 10; i++){
        intarray[i] = intarray[i-1] + intarray[i];
    }
    
    for (size_t i = 0; i < sizeA; i++){
        int temp = intarray[unsorted[i]];
        sorted[temp] = unsorted[i];
        intarray[unsorted[i]] =  intarray[unsorted[i]] -1;
    }
}

