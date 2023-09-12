#include <bits/stdc++.h>
using namespace std;

int getMax(int a[], int n ){
int maxx = a[0];
for(int i =1;i<n;i++){
    if(a[i] > maxx) maxx = a[i];
}
return maxx;
}
void countingSort(int a[], int sizee, int place) {
    const int ma = 10;
    int count[ma];
    int output[sizee];
    for(int i =0;i <ma;i++){
        count[i] = 0;
     }
     for(int i =0;i <sizee;i++){
        count[(a[i]/place)%10] ++;
     }
     for(int  i =1; i< ma; i++){
        count[i] += count[i-1];
     }
     for(int i =sizee-1;i>=0;i--){
        output[count[(a[i]/place)%10]-1] = a[i];
        count[(a[i]/place)%10]--;
     }
     for(int i =0;i<sizee;i++){
        a[i] = output[i];
     }
}


void radixSort(int a[], int sizee){
int maxxx = getMax(a, sizee);
for(int place =1; maxxx/place > 0; place *= 10){
    countingSort(a, sizee, place);
}
}

////

  void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
      largest = left;

    if (right < n && a[right] > a[largest])
      largest = right;

    if (largest != i) {
      swap(a[i], a[largest]);
      heapify(a, n, largest);
    }
  }


  void heapSort(int a[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(a, n, i);


    for (int i = n - 1; i >= 0; i--) {
      swap(a[0], a[i]);

      heapify(a, i, 0);
    }
  }
  void printarray(int a[], int n){
for(int i =0 ;i <n;i++){
    cout << a[i] << " ";
}
}

int main() {
  int a[] = {121, 432, 564, 23, 1, 45, 788};
  int n = sizeof(a) / sizeof(a[0]);
  heapSort(a, n);
  printarray(a, n);
  return 0;
}
