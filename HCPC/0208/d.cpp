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
    ll n,k;cin>>n>>k;
    vector<vector<ll>> G(n);
    vector<PL> cr(n);
    rep(i,0,n){
        ll a,b;cin>>a>>b;
        cr[i] = mp(a,b);
    }
    rep(i,0,k){
        ll a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    priority_queue<PL, vector<PL>, greater<PL>> que;
    vector<ll> d(n, INF);
    vector<ll> seen_d(n);
    d[0] = 0;

    que.push(mp(cr[0].first,0));

    while (que.size()){
        PL p = que.top();
        que.pop();
        ll v = p.second;

        if (seen_d[v]==1) continue;
        seen_d[v] = 1;

        queue<ll> que2;
        que2.push(v);
        vector<ll> dis(n);
        while (que2.size()){
            ll p2 = que2.front();
            que2.pop();

            for (auto nv : G[p2]){
                if (dis[nv]==0 && dis[p2]+1<=cr[v].second){
                    dis[nv] = dis[p2]+1;
                    que2.push(nv);
                    if (d[nv]==INF){
                        d[nv] = d[v] + cr[v].first;
                        que.push(mp(d[nv]+cr[nv].first,nv));
                    }
                }
            }
        }
    }
    cout<<d[n-1]<<endl;
}