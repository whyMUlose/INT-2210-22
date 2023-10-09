#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y);

class MinHeap {
int *harr;
int capacity; // max size of heap;
int heap_size;// current number of elements heap

public:
    MinHeap (int capacity);

    void MinHeapify(int );
    int parent(int i) { return (i-1)/2;}

     int left(int i) {return 2*i+1;}

     int right(int i ) {return 2*i+2;}


        int removeRoot();

    // Deletes a key stored at index i
    void deleteKey(int v);

    // Inserts a new key 'k'
    void insertKey(int k);
     int getMin();

};
 MinHeap :: MinHeap(int cap) {
heap_size = 0;
capacity = cap;
harr = new int [cap];
}
void MinHeap :: insertKey(int k) {
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    heap_size++;
    int i = heap_size -1;
    harr[i] = k;
    while(i!= 0 && harr[parent(i)] > harr[i]){
        swap(&harr[i], & harr[parent(i)]);
        i = parent(i);
    }
}
int MinHeap :: removeRoot() {
if(heap_size <= 0) {return INT_MAX;}
if(heap_size == 1) {
    heap_size --;
    return harr[0];
}
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return root;

}
void MinHeap :: MinHeapify(int i) {
int l = left(i);
int r = right(i);
int smallest = i;
if(l < heap_size && harr[l] < harr[i]) {
    smallest = l;
}
if(r < heap_size && harr[r] < harr[smallest]){
    smallest = r;
}
if(smallest != i)
{
swap(&harr[smallest], &harr[i]);
MinHeapify(smallest);
}
}
void MinHeap::deleteKey(int v) {
    int curr = -1;
    for(int i =0 ; i< heap_size ; i++) {
        if(harr[i] = v) {
            curr = i;
            break;
        }
    }
    if(curr == -1 ) return;
    harr[curr] = harr[heap_size-1];
    heap_size --;
    MinHeapify( curr);

}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int MinHeap :: getMin() {
return harr[0];
}
int main () {
MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.removeRoot() << " ";
    cout << h.getMin() << " ";
    return 0;
}
