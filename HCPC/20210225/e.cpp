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
typedef pair<pair<ll,ll>,ll> PPL;
typedef tuple<int,int,int> T;
typedef tuple<ll,ll,ll> TL;
ll mod = 1000000007;
ll mod2 = 998244353;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;cin>>n>>m;
    vector<ll> a(n);
    ll error = 0;
    vector<PPL> info(m);
    rep(i,0,m){
        ll l,r,x;cin>>l>>r>>x;
        l--;
        info[i] = mp(mp(l,r),x);
    }

    ll ans = -1;
    rep(i,0,1<<n){
        vector<ll> num(n);
        ll cnt2 = 0;
        rep(j,0,n){
            if (i & 1<<j){
                num[j]=1;
                cnt2++;
            } 
        }
        
        ll f = 1;
        rep(j,0,m){
            PL range = info[j].first;
            ll x = info[j].second;
            ll cnt = 0;
            rep(k,range.first,range.second){
                if (num[k]==1) cnt++;
            }
            if (cnt!=x){
                f = 0;
                break;
            }
        }
        if (f){
            ans = max(ans,cnt2);
        }
        
    }

    cout<<ans<<endl;
}