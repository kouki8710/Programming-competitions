#define _GLIBCXX_DEBUG
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
    ll m,n;cin>>m>>n; // n height
    ll b,a;cin>>b>>a; // a height
    vector<vector<ll>> G(n,vector<ll>(m));
    rep(i,0,n){
        rep(j,0,m){
            cin>>G[i][j];
        }
    }
    vector<vector<ll> > s1(n+1, vector<ll>(m+1, 0)), s2(n+1, vector<ll>(m+1, 0));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            s1[i+1][j+1] = s1[i][j+1] + s1[i+1][j] - s1[i][j] + G[i][j];
            s2[i+1][j+1] = s2[i][j+1] + s2[i+1][j] - s2[i][j] + max(G[i][j],(ll)0);
        }
    }
        
            
    
    ll ans = INF;
    rep(i,0,n-a+1){
        rep(j,0,m-b+1){
            // cout<<s1[i+a][j+b]<<" "<<s1[i+a][j]<<" "<<s1[i+1][j+b]<<" "<<s1[i+1][j+1]<<" "<<endl;
            ll num = s1[i+a][j+b] - s1[i+a][j] - s1[i][j+b] + s1[i][j];
            ll num2 = s2[i+a][j+b] - s2[i+a][j] - s2[i][j+b] + s2[i][j];
            if (num==num2){
                ans = min(ans, num);
            }
        }
    }
    cout<<ans<<endl;
}