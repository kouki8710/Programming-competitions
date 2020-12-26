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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;cin>>h>>w;
    vector<string> ma(h);
    vector<vector<ll>> dp(h,vector<ll>(w)),tate(h+1,vector<ll>(w+1)),yoko(h+1,vector<ll>(w+1)),naname(h+1,vector<ll>(w+1));
    rep(i,0,h){
        cin>>ma[i];
    }
    dp[0][0] = 1;
    tate[1][1] = 1;
    yoko[1][1] = 1;
    naname[1][1] = 1;
    rep(i,0,h){
        rep(j,0,w){
            if (i==0 && j==0) continue;
            if (ma[i][j]=='#'){
                yoko[i+1][j+1] = 0;
                tate[i+1][j+1] = 0;
                naname[i+1][j+1] = 0;
                continue;
            }
            dp[i][j] = (yoko[i+1][j] + tate[i][j+1] + naname[i][j])%mod;
            yoko[i+1][j+1] = (yoko[i+1][j]+dp[i][j])%mod;
            tate[i+1][j+1] = (tate[i][j+1]+dp[i][j])%mod;
            naname[i+1][j+1] = (naname[i][j]+dp[i][j])%mod;
        }
    }
    cout<<dp[h-1][w-1]<<endl;
}