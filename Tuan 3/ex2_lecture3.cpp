#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
typedef struct Node* node;
node makeNode(int x)
{
    node tmp = new Node();
    tmp -> data =x;
    tmp -> next = NULL;
    return tmp;
}
bool empty(node a){
  return a == NULL;
}
int Size(node a)
{
    int cnt =0;
    while (a!= NULL){
        ++cnt;
        a = a->next; // gan dia chi node tiep theo cho node hien tai
    }
    return cnt;
}
void insertFirst(node &a, int x)
{
    node tmp = makeNode( x);
    if(a = NULL)
    {
        a = tmp;
    } else {
    tmp->next = a;
    a = tmp;
    }
}
//Them mot phan tu vao cuoi danh sach
void insertLast (node &a, int x)
{
    node tmp = makeNode( x);
    if(a == NULL)
    {
        a =tmp;
    }
    else {
        node p =a;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p -> next = tmp;
    }
}
// Them mot phan tu vao giua
void insert(node& a, int pos, int x)
{
    int n =Size(a);
    if(pos<0 || pos > n) cout << "khong hop le";
    if(pos ==0 ) {insertFirst(a, x); return;}
    else if(pos == n) {insertLast(a, x); return ;}
    node p =a;
    for(int i =1;i<pos;i++)
    {
        p = p->next;
    }
    node tmp = makeNode(x);
tmp->next = p->next;  p->next = tmp;
}
void deletee(node &a, int pos)
{
    if(pos <= 0 || pos >Size(a)) return;
    node truoc =NULL, sau = a;
    for(int i =0; i<pos;i++)
    {
        truoc = sau;
        sau =sau->next;
    }
    if(truoc == NULL) a =a->next;
    else truoc->next = sau->next;
}
void in(node a)
{
    while(a!= NULL)
    {
        cout << a-> data << " ";
        a = a->next;
    }
}
int main() {
    node head = NULL;
    insert(head, 0, 1 );
       insert(head, 1, 3 );
          insert(head, 1, 4 );
             insert(head, 2, 2 );
             deletee(head, 1);
             in(head);
return NULL;
}
