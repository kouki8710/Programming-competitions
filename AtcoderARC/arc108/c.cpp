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

vector<vector<P>> G(100050);
vector<ll> ans(100050);
int n,m;

void dfs(int index){
    for (auto g : G[index]){
        int nv = g.first;
        int cv = g.second;
        if (ans[nv]==0){
            if (ans[index]==cv){
                if (cv + 1 >n) {
                    ans[nv] = 1;
                }else{
                    ans[nv] = cv + 1;
                }
                dfs(nv);
            }else{
                ans[nv] = cv;
                dfs(nv);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;

    rep(i,0,m){
        int a,b,c;cin>>a>>b>>c;
        a--;
        b--;
        G[a].push_back(mp(b,c));
        G[b].push_back(mp(a,c));
    }
    
    dfs(0);
    
    rep(i,0,n){
        cout<<ans[i]<<endl;
    }
}