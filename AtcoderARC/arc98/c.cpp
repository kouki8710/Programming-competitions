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
    string s;cin>>s;
    vector<ll> w(n+1),e(n+1);
    rep(i,0,n){
        if (s[i]=='E'){
            w[i]++;
        }else{
            e[i+1]++;
        }
    }
    rep(i,0,n){
        e[i+1] += e[i];
    }
    repp(i,n,1){
        w[i-1] += w[i];
    }

    ll ans = INF;
    rep(i,0,n){
        ans = min(ans,e[i]+w[i+1]);
    }
    cout<<ans<<endl;
}