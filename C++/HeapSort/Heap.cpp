#include "Heap.hpp"

int capacity = 8;
Node *heap;
int sizeL = 0;

int main(){
    heap = new Node[capacity];

    int array[] = {80,75,60,68,55,40,52,67};

    for (size_t i = 0; i < capacity; i++){
        insert(array[i]);
    }
    
    printarray();

    cout << "Value removed " << remove_from_heap(5) << endl;
    cout << "New Heap" << endl;

    printarray();
}//main: Testing

void insert(int value){
    heap[sizeL].value = value;
    max_heap(sizeL);
    sizeL++;
}// Insert elements

void max_heap(int index){
    int addedValue = heap[index].value;
    while(index > 0 && addedValue > heap[parentIndex(index)].value){
        heap[index].value = heap[parentIndex(index)].value;
        index = parentIndex(index);
    }

    heap[index].value = addedValue;
}// Heapify

int remove_from_heap(int index){
    int ele = heap[index].value; //Delete the ele
    int rightmostValue = heap[--sizeL].value; //save the rightmost ele
    heap[index].value = rightmostValue;

    if(heap[index].value > heap[parentIndex(index)].value){
        heapify_above(index);
    }else{
        heapify_below(index);
    }

    return ele;
}//remove from heap

void heapify_above(int index){
    int addedValue = heap[index].value;
    while(index > 0 && addedValue > heap[parentIndex(index)].value){
        heap[index].value = heap[parentIndex(index)].value;
        index = parentIndex(index);
    }

    heap[index].value = addedValue;
}

void heapify_below(int index){
    int updatevalue = heap[index].value;
    while(index < capacity && heap[index].value < heap[leftChild(index)].value ||  heap[index].value < heap[rightChild(index)].value ){
       if(heap[index].value < heap[leftChild(index)].value){
           heap[index].value = heap[leftChild(index)].value;
           heap[leftChild(index)].value = updatevalue;
       }else if(heap[index].value < heap[rightChild(index)].value){
           heap[index].value = heap[rightChild(index)].value;
           heap[rightChild(index)].value = updatevalue;
       }
    }
}

void printarray(){
    for (size_t i = 0; i < sizeL; i++){
        cout << heap[i].value << endl ;
    }
}

int leftChild(int index){
    return (index*2)+1;
}

int rightChild(int index){
    return (index*2)+2;
}

int parentIndex(int index){
    return (index-1)/2;
}