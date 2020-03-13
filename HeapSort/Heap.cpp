#include "Heap.hpp"

int sizeList = 7;
Node *unheaped;
Node *heaped;
int count = -1;
int parent = 0;

int main(){
    unheaped = new Node[sizeList];
    heaped = new Node[sizeList];

    int array[] = {3,7,5,1,2,4,6};

    for (size_t i = 0; i < sizeList; i++){
        add_to_heap(array[i]);
    }

    for (size_t i = 0; i < sizeList; i++){
        cout << unheaped[i].value << " " << unheaped[i].parentIndex << endl ;
    }   

    heapify(0);

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
            Node *val = new Node(value, parent);
            unheaped[(parent*2)+1] = *val;
        }else if(unheaped[(parent*2)+2].value == 0){
            Node *val = new Node(value,parent);
            unheaped[(parent*2)+2] = *val;
            parent++;
        }
    }
}

void heapify(int index){
    
}

void swap(int parent, int child){
    int temp = unheaped[parent].value;
    unheaped[parent].value = unheaped[child].value;
    unheaped[child].value = temp;
}