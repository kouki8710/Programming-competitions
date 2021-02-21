#define _GLIBCXX_DEBUG
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
    ll n;cin>>n;
    vector<ll> x(n);
    rep(i,0,n) cin>>x[i];
    ll m;cin>>m;
    vector<ll> a(m), aru(2020);
    rep(i,0,m){
        cin>>a[i];
        a[i]--;
    } 
    rep(i,0,n){
        aru[x[i]] = 1;
    }
    rep(i,0,m){
        if (x[a[i]]+1<=2019 && aru[x[a[i]]+1]==0){
            aru[x[a[i]]] = 0;
            aru[x[a[i]]+1] = 1;
            x[a[i]]++;
        }
    }

    rep(i,0,n){
        cout<<x[i]<<endl;
    }
}