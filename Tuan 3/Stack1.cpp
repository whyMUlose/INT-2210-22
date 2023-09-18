#include <bits/stdc++.h>
using namespace std;
int n = 0, st[10001];
void push(int x) {
st[n] =  x;
n++;
}
void pop() {
if(n>=1)
{
    n--;
}
}
int top(){
return st[n-1];}
int size() {
return n;
}
int main() {
push(1);
push(2);
push(3);
push(4);
pop();
pop();
push(5);
for(int i = 0;i < n;i++){
    cout << st[i]<< " ";
}
}
