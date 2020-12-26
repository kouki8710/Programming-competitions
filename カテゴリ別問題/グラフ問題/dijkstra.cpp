//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 10000000000000000
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
ll mod = 1000000007;
ll mod2 = 998244353;


//ダイクストラ法はdistが一回しか更新されない
//なのでdist!=INFはその頂点を更新する必要がないことを意味する
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll v, e, r;
    cin >> v >> e >> r;
    vector<PL> G[v];
    rep(i, 0, e) {
        ll s, t, d;
        cin >> s >> t >> d;
        G[s].push_back(mp(t, d));
    }

    priority_queue<PL, vector<PL>, greater<PL>> que;
    vector<ll> d(v, INF);
    d[r] = 0;
    que.push(mp(0, r));
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
    rep(i, 0, v) {
        if (d[i] == INF) {
            cout << "INF" << endl;
        }
        else {
            cout << d[i] << endl;
        }
    }
}