//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;
vector<vector<ll>> G;
vector<ll> seen,prime(100000);
int n,m,s,t;

void hurui(){
    rep(i,0,100000){
        prime[i] = 1;
    }
    prime[0] = 0;prime[1] = 0;
    for (int i=2;i<100000;i++){
        if (prime[i]==0) continue;
        for (int j=i*2;j<100000;j+=i){
            prime[j] = 0;
        }
    }
}

void dfs(int index,int num){
    if (seen[index]==1) return;
    seen[index] = 1;
    if (index==t){
        if (num==2){
            cout<<2<<endl;
        }
    }
    for (ll g:G[index]){
        dfs(g,num+1);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m>>s>>t;
    s--;t--;
    G.resize(n);
    seen.resize(n);
    hurui();
    rep(i,0,m){
        int p1,p2;cin>>p1>>p2;
        p1--; p2--;
        G[p1].push_back(p2);
        G[p2].push_back(p1);
    }
    dfs(s,0);
}