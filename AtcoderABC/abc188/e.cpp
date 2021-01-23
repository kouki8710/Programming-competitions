//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 10000000000000000
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
    vector<ll> a(n), b(n, -1);
    rep(i,0,n) cin>>a[i];

    vector<vector<ll>> G(n);
    rep(i,0,m){
        int a1,a2;cin>>a1>>a2;
        a1--; a2--;
        G[a2].push_back(a1);
    }

    // queue<ll> q;
    // repp(i,n-1,0){
    //     if (b[i]!=-1){
    //         continue;
    //     }
    //     q.push(i);

    //     while (!q.empty())
    //     {
    //         auto p = q.front();
    //         q.pop();
            
    //         for (ll nex : G[p]){
    //             q.push(nex);
    //             b[nex] = max(b[nex], max(a[p],b[p]));
    //         }
    //     }
    // }
    
    repp(i,n-1,0){
        int p = i;
        for (ll nex : G[p]){
            b[nex] = max(b[nex], max(a[p],b[p]));
        }
    }

    ll ans = -INF;

    rep(i,0,n){
        if (b[i]!=-1){
            ans = max(ans,b[i]-a[i]);
        }
    }
    
    cout<<ans<<endl;
}