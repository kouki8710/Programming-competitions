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
    ll n,d,a;cin>>n>>d>>a;
    vector<PL> mons;
    vector<ll> pos(n);
    rep(i,0,n){
        ll x,h;
        cin>>x>>h;
        mons.push_back(mp(x,h));
        pos[i] = x;
    }

    sort(mons.begin(), mons.end());
    sort(pos.begin(), pos.end());

    vector<ll> dp(n+2); // 1が初め
    ll ans = 0;
    rep(i,0,n){
        dp[i+1] += dp[i];
        if (mons[i].second - dp[i+1]<=0) continue;
        ll x = mons[i].first;
        ll hp = mons[i].second - dp[i+1];
        ll r = lower_bound(pos.begin(), pos.end(), x+2*d) - pos.begin();
        
        if (r>=n || pos[r] != x+2*d) r--;
        ll damage = a * ((hp+a-1) / (a));

        dp[i+1] +=  damage;
        dp[r+2] -= damage;
        ans += (hp+a-1) / (a);
    }

    cout<<ans<<endl;
}