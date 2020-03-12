#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include "Heap.hpp"

int sizeList = 7;
Node *unheaped;
Node *heaped;
int count = -1;
int parent = 0;

int main(){
    unheaped = new Node[sizeList];
    heaped = new Node[sizeList];

    int array[] = {11,4,1,1,11,13,2};

    for (size_t i = 0; i < sizeList; i++){
        add_to_heap(array[i]);
    }

    for (size_t i = 0; i < sizeList; i++){
        cout << unheaped[i].value << " " << unheaped[i].parentIndex << endl ;
    }   

    min_heapify();

    cout << "After Heapify" << endl;

    for (size_t i = 0; i < sizeList; i++){
        cout << unheaped[i].value << " " << unheaped[i].parentIndex << endl ;
    }   
    
}

void add_to_heap(int value){
    if(count == -1){
        Node *val = new Node(value, parent);
        unheaped[parent] = *val;
        count++;
    }else{
        if(unheaped[(parent*2)+1].value == 0){
            Node *val = new Node(value, (parent*2)+1);
            unheaped[(parent*2)+1] = *val;
        }else if(unheaped[(parent*2)+2].value == 0){
            Node *val = new Node(value,(parent*2)+2);
            unheaped[(parent*2)+2] = *val;
            parent++;
        }
    }
}

void min_heapify(){
    for (size_t i = 0; i < sizeList; i++){
        if(unheaped[i].value > unheaped[(i*2)+1].value){
            swap(i, (i*2)+1);
        }

        if(unheaped[i].value > unheaped[(i*2)+2].value){
            swap(i, (i*2)+2);
        }
    }
}

void swap(int parent, int child){
    int temp = unheaped[parent].value;
    unheaped[parent].value = unheaped[child].value;
    unheaped[child].value = temp;
}