#include <bits/stdc++.h>
using namespace std;
int main() {
int n,S;
cin >> n >>S;
int w[n + 1], v[n+1], m[n+1], p[n+1];
for(int i = 1;i <= n;i++) cin >> w[i];
for(int i = 1 ; i <= n; i++) cin >> v[i];
for(int i = 1; i <= n; i++){
      m[i] = v[i] / w[i];
}
for(int i = 1; i <= n - 1; i++){
       for(int j = i + 1; j <= n; j++)
       if (m[i] < m[j])
       swap(w[i], w[j]);
}
int i =1,  sum =0;
while(S >= 0 && i <= n) {
            m[i]= S / w[i];
            S -= m[i] * w[i];
            sum += v[i];
            i++;
      }
      cout << sum;
return 0;
}
