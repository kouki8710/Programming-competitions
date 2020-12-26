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
    ll n,w;cin>>n>>w;
    int num = 200000 + 100;
    vector<ll> a(num);
    rep(i,0,n){
        ll s,t,p;cin>>s>>t>>p;
        a[s] += p;
        a[t] += -p;
    }
    rep(i,0,num){
        a[i+1] += a[i];
    }
    rep(i,0,num){
        if (a[i]>w){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}