#include <bits/stdc++.h>
using namespace std;
struct Node {
    int value;
    Node*next;
    Node*prev;
};
Node* makeNode(int x) {
Node* newNode = new Node();
newNode-> value = x;
Node* next = NULL;
Node* prev = NULL;
return newNode;
}

void duyet(Node* head) {
while(head!= NULL){
    cout<< head->value << " ";
    head = head->next;
}
}
void themcuoi (Node *& head, int x) {
Node * newNode = makeNode(x);
if(head == NULL) {head = newNode; return;}
else{
Node * tmp = head;
while(tmp->next != NULL){
    tmp = tmp->next;
}
tmp->next = newNode;
newNode->prev = tmp;
}
}
int count_triplets(struct Node* head)
{
    Node* ptr1 = NULL, *ptr2 = NULL, *ptr3 = NULL;
    int count = 0;
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
            for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next)


                if ((ptr1->value + ptr2->value+ ptr3->value) == 0)
                    count++;
    return count;
}
int main() {
int n;
cin >> n;
int a[n];
Node *head = NULL;
for(int i =0 ;i < n;i++)
{
    cin >> a[i];

}
for(int i = 0 ;i <n ; i++) {
    themcuoi(head, a[i]);
}

cout << count_triplets(head);
return 0;
}
