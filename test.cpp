#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int n;
int a[N];

int MaxLeft(int i, int m){
         int ans = a[m], sum = 0;
         for (int k = m; k >= i; k--) {
                  sum += a[k];
                  ans = max(ans, sum);
         }
         return ans;
}

int MaxRight(int m, int j){
         int ans = a[m], sum = 0;
         for (int k = m; k <= j; k++) {
                  sum += a[k];
                  ans = max(ans, sum);
         }
         return ans;
}

int SubSeqMax (int i, int j){
         int mid = (i+j)/2;
         int wL = SubSeqMax(i, mid);
         int wR = SubSeqMax(mid+1, j);

         int wML = MaxLeft(i, mid);
         int wMR = MaxRight(mid+1, j);
         int wM = wML + wMR;
         return max(max(wL, wR), wM);
}

void input(){
         cin >> n;
         for (int i=1; i<=n; i++){
                  cin >> a[i];
         }
}

int main(){
         if (fopen("data.inp", "r")){
                  freopen("data.inp", "r", stdin);
         }
         ios_base::sync_with_stdio(false);
         cin.tie(0); cout.tie(0);
         input();
         cout << SubSeqMax(1, n) << endl;
         return 0;
}