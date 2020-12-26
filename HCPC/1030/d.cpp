#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)

int h,w;
ll ans = 1000000000;

int dfs(int h1,int w1,vector<vector<ll>>& m, vector<vector<ll>>& s,ll d,ll t){
    if (h1==h-1 && w1==w-1){
        ans = min(ans,t-d);
        return 0;
    }
    if (h1-1>=0 && s[h1-1][w1]>=t+(2*d+1)*m[h1-1][w1]+1){
        s[h1-1][w1] = t+(2*d+1)*m[h1-1][w1]+1;
        dfs(h1-1,w1,m,s, d+1 , t+(2*d+1)*m[h1-1][w1]+1 );
    }
    if (h1+1<h && s[h1+1][w1]>=t+(2*d+1)*m[h1+1][w1]+1){
        s[h1+1][w1] = t+(2*d+1)*m[h1+1][w1]+1;
        dfs(h1+1,w1,m,s, d+1 , t+(2*d+1)*m[h1+1][w1]+1 );
    }
    if (w1+1<w && s[h1][w1+1] >= t+(2*d+1)*m[h1][w1+1]+1){
        s[h1][w1+1] = t+(2*d+1)*m[h1][w1+1]+1;
        dfs(h1,w1+1,m,s, d+1 , t+(2*d+1)*m[h1][w1+1]+1 );
    }
    if (w1-1>=0 && s[h1][w1-1] >= t+(2*d+1)*m[h1][w1-1]+1){
        s[h1][w1-1] = t+(2*d+1)*m[h1][w1-1]+1;
        dfs(h1,w1-1,m,s, d+1 , t+(2*d+1)*m[h1][w1-1]+1 );
    }
    return 0;
}

int main(){
    cin>>h>>w;
    vector<vector<ll>> m(h,vector<ll>(w,0)),s(h,vector<ll>(w,10000000000));
    rep(i,0,h){
        rep(j,0,w){
            cin>>m[i][j];
        }
    }
    s[0][0] = 0;
    dfs(0,0,m,s,0,0);
    cout<<ans<<endl;
}