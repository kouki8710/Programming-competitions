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
    int n;cin>>n;

    vector<vector<ll>> G(n);
    vector<ll> ans(n),q1(n-1),q2(n-1);
    map<P,ll> m;
    rep(i,0,n-1){
        ll a,b;cin>>a>>b;
        a--; b--;
        m[mp(a,b)] = i+1;
        m[mp(b,a)] = -(i+1);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int q;cin>>q;
    rep(i,0,q){
        ll t,e,x;cin>>t>>e>>x;
        e--;
        if (t==1){
            q1[e] += x;
        }else{
            q2[e] += x;
        }
    }

    queue<ll> que;
    que.push(0);
    vector<ll> seen(n);

    while(que.size()){

        int p = que.front();
        que.pop();

        if (seen[p]==1){
            continue;
        }
        seen[p] = 1;

        for (int nex : G[p]){
            if (seen[nex]==1) continue;
            if (m[mp(p,nex)]>0){
                int edge = m[mp(p,nex)]-1;
                ans[nex] += q2[edge];
                ans[0] += q1[edge];
                ans[nex] -= q1[edge];

            }else if(m[mp(p,nex)]<0){

                int edge = -m[mp(p,nex)]-1;
                ans[nex] += q1[edge];
                ans[0] += q2[edge];
                ans[nex] -= q2[edge];
            }
            que.push(nex);
        }
    }

    que.push(0);

    vector<ll> seen2(n);

    while(que.size()){

        int p = que.front();
        que.pop();

        if (seen2[p]==1) continue;
        seen2[p] = 1;

        for (int nex : G[p]){
            if (seen2[nex]==1) continue;
            que.push(nex);
            ans[nex] += ans[p];
        }
    }

    rep(i,0,n){
        cout<<ans[i]<<endl;
    }
    
}