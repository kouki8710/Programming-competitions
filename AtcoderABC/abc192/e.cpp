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
    ll n,m,x,y;cin>>n>>m>>x>>y;
    x--;y--;
    vector<vector<pair<ll,PL>>> G(n);
    rep(i,0,m){
        ll a,b,t,k;cin>>a>>b>>t>>k;
        a--;b--;
        G[a].push_back(mp(b,mp(t,k)));
        G[b].push_back(mp(a,mp(t,k)));
    }

    priority_queue<PL, vector<PL>, greater<PL>> que;
    vector<ll> d(n, INFL);
    d[x] = 0;
    que.push(mp(0, x));
    while (que.size()) {
        PL p = que.top();
        que.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;

        ll t = d[v];

        for (auto nv : G[v]) {
            //nv first 頂点 second cost
            ll num2 = t%nv.second.second;
            if (num2!=0) num2 = nv.second.second - t%nv.second.second;
            if (nv.second.first + num2 + d[v] < d[nv.first]) {
                
                d[nv.first] = nv.second.first + num2 + d[v];
                que.push(mp(d[nv.first], nv.first));
            }
        }
    }

    if (d[y]==INFL){
        cout<<-1<<endl;
    }else{
        cout<<d[y]<<endl;
    }
}