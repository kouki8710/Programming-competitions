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
    ll n;cin>>n;
    vector<ll> a(n);
    set<ll> b;
    rep(i,0,n) cin>>a[i];
    sort(a.begin(), a.end());
    b.insert(a[0]);
    rep(i,1,n){
        for (auto x: b){
            b.insert(__gcd(a[i],x));
        }
        rep(j,0,i){
            b.insert(__gcd(a[j],a[i]));
        }
    }

    ll ans = 0;
    for (auto x: b){
        if (x<=a[0]) ans++;
    }
    cout<<ans<<endl;
}