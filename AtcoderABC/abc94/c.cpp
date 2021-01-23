//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
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
    vector<ll> ans(n);
    vector<P> a(n);
    rep(i,0,n){
        int b;cin>>b;
        a[i] = mp(b,i+1);
    }
    sort(a.begin(), a.end());

    int k1 = a[n/2-1].first;
    int k2 = a[n/2].first;
    rep(i,0,n){
        if (i+1<=n/2){
            ans[a[i].second-1] = k2;
        }else{
            ans[a[i].second-1] = k1;
        }
    }

    rep(i,0,n){
        cout<<ans[i]<<endl;
    }
}