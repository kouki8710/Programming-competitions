// #define _GLIBCXX_DEBUG
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

vector<ll> d(200000,-1), dp(200000,INF), seen(200000);
ll max_v;

ll dfs(vector<vector<ll>> &G, int v, int p){

    for (auto nv : G[v]){
        if (nv!=p){
            dp[v] = min(max_v-dfs(G, nv, v), dp[v]);
        }
    }

    return d[v];
}

void dfs2(vector<vector<ll>> &G, int v, int p, ll &cnt, ll &cnt2, ll &k){

    if (seen[v]==1) return;
    seen[v] = 1;
    if (k==1){
        cnt++;
    }else{
        cnt2++;
    }
    ll nv2 = -1, num=INF;
    for (auto nv : G[v]){
        if (nv!=p && seen[nv]==0){
            if (dp[nv]==INF){
                if (k==1){
                    cnt++;
                }else{
                    cnt2++;
                }
                k*=-1;
            }else{
                if (num>dp[nv]){
                    nv2 = nv;
                    num = dp[nv];
                }
            }
        }
    }

    if (nv2==-1) return;

    dfs2(G, nv2, v, cnt, cnt2,k);

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<vector<ll>> G(n);
    d[0] = -1;
    rep(i,1,n){
        ll s;cin>>s;
        s--;
        G[i].push_back(s);
        G[s].push_back(i);
    } 

    queue<ll> que;
    que.push(0);
    d[0] = 0;

    while (que.size()){

        ll p = que.front();
        que.pop();

        for (auto nv : G[p]){
            if (d[nv]==-1){
                d[nv] = d[p]+1;
                que.push(nv);
            }
        }
    }

    max_v = *max_element(d.begin(), d.end());
    dfs(G, 0, -1);

    seen[0] = 1;
    ll ans = 0, num = -1;
    for (auto x : G[0]){
        ll cnt = 0, cnt2 = 0, k = 1;
        dfs2(G, x, 0, cnt, cnt2, k);
        if (num<cnt2){
            ans = cnt;
            num = cnt2;
        }
    }

    cout<<ans+1<<endl;
    
    
}