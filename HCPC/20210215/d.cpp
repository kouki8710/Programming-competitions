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
    ll n,m,k;cin>>n>>m>>k;
    vector<vector<PL>> G(n);
    rep(i,0,m){
        ll a,b,l;cin>>a>>b>>l;
        a--;b--;
        G[a].push_back(mp(b,l));
        G[b].push_back(mp(a,l));
    }
    vector<ll> shop(k);
    rep(i,0,k){
        cin>>shop[i];
        shop[i]--;
    }

    vector<ll> toshopd(n,INF);
    ll ans = INF;

    rep(i1,0,k){
        priority_queue<PL, vector<PL>, greater<PL>> que;
        vector<ll> d(n, INF);
        d[shop[i1]] = 0;
        que.push(mp(0, shop[i1]));
        while (que.size()) {
            PL p = que.top();
            que.pop();
            ll v = p.second;

            if (d[v] < p.first) continue;

            for (auto nv : G[v]) {
                //nv first 頂点 second cost
                if (nv.second + d[v] < d[nv.first]) {

                    d[nv.first] = nv.second + d[v];
                    que.push(mp(d[nv.first], nv.first));
                }
            }
        }

        ll max_d = *max_element(d.begin(), d.end());
        // ll cnt = 0;
        // rep(i,0,n){
        //     if (d[i]==max_d) cnt++;
        // }
        // if (cnt>=2){
        //     max_d++;
        // }
        ans = min(ans, max_d);
    }
    cout<<ans<<endl;
    
}