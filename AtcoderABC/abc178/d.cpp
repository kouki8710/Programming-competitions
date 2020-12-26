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
    int s;cin>>s;
    vector<ll> m(s+10);
    m[0] = 1;
    rep(i,3,s+1){
        rep(j,0,i-2){
            m[i] = (m[i]+m[j])%mod; 
        }
    }
    cout<<m[s]%mod<<endl;
}