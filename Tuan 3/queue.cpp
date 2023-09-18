#include <bits/stdc++.h>
using namespace std;
int a[100000], maxInt = 100000;
int n = 0;
int size() {
return n;
}
bool empty() {
return n==0;
}
void enqueue(int x){
if(n == maxInt) return;
else a[n] =x ;
++n;
}
void dequeue(){
if(empty()) return;
else {
    for(int i =0; i < n-1; i++){
        a[i] = a[i+1];
    }
    --n;
}
}
int front(){
return a[0];}
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    dequeue();
    enqueue(5);
    for(int i = 0;i <n;i++){
        cout << a[i] << " ";
    }
}
