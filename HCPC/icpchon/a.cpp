//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while (1){
        int n;cin>>n;
        if (n==0) break;
        int ans = 0;
        vector<ll> b(n);
        rep(i,0,n){
            int a;cin>>a;
            b[i] = a;
        }
        rep(i,0,n-3){
            if (b[i]==2 && b[i+1]==0 && b[i+2]==2 && b[i+3]==0){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    
}
