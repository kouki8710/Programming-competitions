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
    ll cnt = 0;
    ll ans = 0;
    vector<ll> s(m);
    rep(i,0,m){
        ll a,b;cin>>a>>b;
        s[i] = b;
    }
    sort(s.begin(), s.end());
    rep(i,0,m){
        if (cnt==m-1) break;
        if (s[i]>n){
            ans += s[i]-n;
            cnt++;
        }else{
            cnt++;
        }
    }
    cout<<ans<<endl;
}