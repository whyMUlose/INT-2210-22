
#include <bits/stdc++.h>

using namespace std;


void selectionsort(int a[], int n){
    //O(n^2)
    for(int i = 0 ; i<n-1;i++){
            int min_pos = i;
        for(int j =i+1;j < n;j++){
          if(a[j]<a[min_pos]) {min_pos = j;}
        }

        swap(a[i], a[min_pos]);
    }

}
void bubblesort(int a[], int n){
//O(n^2)
for(int i =0;i <n-1;i ++){
    for(int j = 0;j<n-i-1;j++){
        if(a[j]>a[j+1]){swap(a[j], a[j+1]);}
    }
}
}
void insertionsort(int a[], int n){
for(int i = 1 ;i <n ;i++){
int x = a[i]; int pos = i-1;
while(pos >= 0  && x<a[pos]){
    a[pos+1] = a[pos];
    --pos;
}
 a[pos+1] = x;
}
}
int partition1(int a[], int l,int r){
    int pivot = a[l];
int i = l-1; int j = r+1;
while(1){
    do{
        ++i;
    }while(a[i]< pivot);
    do{
        --j;
    }while(a[j]>pivot);
    if(i<j) {swap(a[i],a[j]);}
   else return j;
}
}
void quicksort(int a[], int l, int r){
if(l>= r) return;
int p = partition1(a,l,r);
quicksort(a,l,p);
quicksort(a,p+1,r);
}
void merge(int a[], int l, int m, int r){
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);
    int i=0;int j=0;
    while(i<x.size() && j<y.size()){
        if(x[i]<=y[j]){
            a[l++] = x[i++];
        };
        if(x[i]>=y[j]){
            a[l++] = y[j++];
        }
    }
    while(i<x.size()) a[l++] = x[i++];
    while(j<y.size()) a[l++] = y[j++];

}
void mergesort(int a[],int l, int r){
    if(l>=r) return;
int m = (l+r)/2;
mergesort(a,l,m);
mergesort(a,m+1,r);
merge(a,l,m,r);
}


int main(){
    int n;
     cin >> n;
     int a[1000];
     srand(time(NULL));
    for(int i =0 ;i < n;i++) {a[i] = rand()%1000;}


   quicksort(a, 0 , n-1);


    for(int i =0 ;i < n;i++) {cout << a[i]<<" ";}

return 0;
}
