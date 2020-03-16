#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>

using namespace std;

class Node{
    public:
    int value;
    int parentIndex;

    Node(){

    }

    Node(int x, int y){
        value = x;
        parentIndex = y;
    }
};

void insert(int value);
void max_heap(int index);
void heapify_above(int index);
void heapify_below(int index);
int parentIndex(int index);
