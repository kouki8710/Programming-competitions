//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 1000000000
#define INFL 1000000000000000000
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
#define tp make_tuple
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef tuple<int,int,int> T;
typedef tuple<ll,ll,ll> TL;
ll mod = 1000000007;
ll mod2 = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;cin>>n;
    vector<ll> a(n),b(n),c(n+1);
    rep(i,0,n) cin>>a[i];
    rep(i,0,n) cin>>b[i];
    
    ll a1 = 0; ll a2=0;
    rep(i,0,n){
        c[i+1] = max(c[i], a[i]*b[i]);
        c[i+1] = max(c[i+1], a1*b[i]);
        a1 = max(a1, a[i]);
        a2 = max(a2, b[i]);
    }

    rep(i,0,n){
        cout<<c[i+1]<<endl;
    }
}