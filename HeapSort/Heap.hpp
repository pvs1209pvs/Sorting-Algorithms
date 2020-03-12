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

void add_to_heap(int value);
void min_heapify();
void swap(int parent, int child);