#include "CycleSort.h"

int *array;
int sizeA;

int main(){
    sizeA = 8;
    array = new int[sizeA];

    array[0] = 1;
    array[1] = 8;
    array[2] = 3;
    array[3] = 9;
    array[4] = 10;
    array[5] = 10;
    array[6] = 2;
    array[7] = 4;

    sort();

    for (size_t i = 0; i < sizeA; i++){
        cout << array[i] << endl;
    }
    
}

void sort(){
    int item;
    int cyclestart; //Where the cycle starts
    int pos;
    int swaps = 0;

    // To traverse the array from 0 to n-2
    for (size_t i = 0; i < sizeA-1; i++){
        item = array[i]; 
        cyclestart = i; // start the cycle from i
        pos = cyclestart; //position the pos to the cycle start

        // to find the position where the item can be swapped with in the unsorted array
        for (size_t j = (cyclestart+1); j < sizeA; j++){
            if(array[j] < item){
                pos++;
            }
        }

        // if the pos is equal to the cycle start then that item is already in the right position
        if (pos == cyclestart){
            continue;
        }

        //To check for duplicates in the array
        while (array[pos] == item){
            pos++;
        }

        swap_ele(&item, &pos); //Swap
        swaps++; 

        //To bring the position back to the cycle start to place the swapped element
        while (pos != cyclestart){
            pos = cyclestart;

            for (size_t j = (cyclestart+1); j < sizeA; j++){
                if(array[j] < item){
                    pos++;
                }
            }

            //Check for Duplicates
            while (array[pos] == item){
                pos++;
            }
            
            swap_ele(&item, &pos);
            swaps++;
        }
    }

    cout << "Total Swaps " << swaps << endl;
}

//Swaping the elements
void swap_ele(int *item, int *pos){
    int temp = *item;
    *item = array[*pos];
    array[*pos] = temp;
}