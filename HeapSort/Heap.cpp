#include "Heap.hpp"

int capacity = 5;
Node *heap;
int sizeL = 0;

int main(){
    heap = new Node[capacity];

    int array[] = {12,13,3,1,14};

    for (size_t i = 0; i < capacity; i++){
        insert(array[i]);
    }

    for (size_t i = 0; i < capacity; i++){
        cout << heap[i].value << " " << heap[i].parentIndex << endl ;
    }   
}

void insert(int value){
    heap[sizeL].value = value;
    max_heap(sizeL);
    sizeL++;
}

void max_heap(int index){
    int addedValue = heap[index].value;
    while(index > 0 && addedValue > heap[parentIndex(index)].value){
        heap[index].value = heap[parentIndex(index)].value;
        index = parentIndex(index);
    }

    heap[index].value = addedValue;
}

int remove_from_heap(int index){
    int ele = heap[index].value;
    int rightmostValue = heap[sizeL].value;
    heap[index].value = rightmostValue;
    heap[sizeL--].value = 0;

    if(heap[index].value > heap[parentIndex(index)].value){
        heapify_above(index);
    }else{
        heapify_below(index);
    }
}

void heapify_above(int index){
    int addedValue = heap[index].value;
    while(index > 0 && addedValue > heap[parentIndex(index)].value){
        heap[index].value = heap[parentIndex(index)].value;
        index = parentIndex(index);
    }

    heap[index].value = addedValue;
}

void heapify_below(int index){

}

int parentIndex(int index){
    return (index-1)/2;
}