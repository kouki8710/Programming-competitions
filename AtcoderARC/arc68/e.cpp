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
    ll n,m;cin>>n>>m;
    vector<ll> len(m+1),len_wa(m+1);
    rep(i,0,n){
        ll l,r;cin>>l>>r;
        len[r-l+1]++;
        len_wa[r-l+1]++;
    }
    
    repp(i,m-1,1){
        len_wa[i] += len_wa[i+1];
    }

    
}