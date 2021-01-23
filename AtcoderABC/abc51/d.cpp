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

    int n,m;cin>>n>>m;

    vector<vector<PL>> G(n);
    vector<ll> ans(m);
    map<PL,ll> edge2index;
    rep(i, 0, m) {
        ll s, t, d;
        cin >> s >> t >> d;
        s--;t--;
        G[s].push_back(mp(t, d));
        G[t].push_back(mp(s, d));
        edge2index[mp(s,t)] = i;
        edge2index[mp(t,s)] = i;
    }

    rep(i,0,n){
        priority_queue<TL, vector<TL>, greater<TL>> que;
        vector<ll> d(n, INF), edge(m);

        que.push(tp(0, i, -1));
        d[i] = 0;

        while (que.size()){

            TL p = que.top();
            que.pop();
            ll vc = get<0>(p);
            ll va = get<1>(p);
            ll vb = get<2>(p);

            // vの最短距離より大きい経路は切る (終盤の余り)
            if (vb != -1){

                if (d[va] < vc ){ //ここでは同じ場合を弾かない。下のfot文の中で弾く
                    continue; 
                }

                // 最短経路
                ll edgeIndex = edge2index[mp(va,vb)];
                edge[edgeIndex] = 1;
            }
            

            for (auto nvp : G[va]){
                ll nv = nvp.first; //vertex
                ll nc = nvp.second; // cost

                if (nc + d[va] < d[nv]) {
                    d[nv] = nc + d[va];
                    que.push(tp(d[nv], nv, va));
                }
            }
        }

        rep(i,0,m){
            if (edge[i]){
                ans[i] = 1;
            }
        }
    }
    
    ll cnt = 0;
    rep(i,0,m){
        cnt += ans[i];
    }
    cout<<m-cnt<<endl;
}