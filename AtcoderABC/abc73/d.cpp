//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 1000000000
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
    ll n,m,r;cin>>n>>m>>r;
    vector<ll> arr(r);
    rep(i,0,r){
        cin>>arr[i];
        arr[i]--;
    } 
    sort(arr.begin(), arr.end());
    vector<vector<PL>> G(n);
    rep(i,0,m){
        ll a,b,c;cin>>a>>b>>c;
        a--;b--;
        G[a].push_back(mp(b,c));
        G[b].push_back(mp(a,c));
    }

    vector<vector<ll>> d(n,vector<ll>(n,INF));

    rep(i,0,n){

        priority_queue<PL, vector<PL>, greater<PL>> que;

        que.push(mp(0,i));
        d[i][i] = 0;

        while (que.size()){
            PL p = que.top();
            que.pop();
            ll v = p.second;
            ll c = p.first;

            if (c > d[i][v]) continue;

            for (auto nvp : G[v]){
                ll nv = nvp.first;
                ll nc = nvp.second;
                if (d[i][v]+nc < d[i][nv] ){
                    d[i][nv] = d[i][v]+nc;
                    que.push(mp(d[i][nv],nv));
                }
            }
        }
    }

    ll ans = INF;
    do{

        ll num = 0;
        rep(i,0,r-1){
            num += d[arr[i]][arr[i+1]];
        }

        ans = min(num,ans);

    }while(next_permutation(arr.begin(), arr.end()));

    cout<<ans<<endl;
}

    
    

    