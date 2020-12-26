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
vector<string> G;
vector<vector<int>> seen(1550,vector<int>(1550)), seen2(1550,vector<int>(1550));
ll ans;
int h,w,n,m;

void dfs_yoko(int a,int b){
    if (b<0 || b>=w || G[a][b]=='2' || seen[a][b]==1){
        return;
    }
    seen[a][b] = 1;
    ans++;
    dfs_yoko(a,b-1);
    dfs_yoko(a,b+1);
}

void dfs_tate(int a,int b){
    if (a<0 || a>=h || G[a][b]=='2' || seen2[a][b]==1){
        return;
    }
    seen2[a][b] = 1;
    if (seen[a][b]==0){
        ans++;
    }
    dfs_tate(a+1,b);
    dfs_tate(a-1,b);
}


int main() {
    //0 なし 1 明かり 2 ブロック
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>h>>w>>n>>m;
    G.resize(h);
    ans = 0;
    vector<pair<int,int>> light(n);
    rep(i,0,h){
        string s = "";
        rep(j,0,w) s+="0";
        G[i] = s;
    }
    rep(i,0,n){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a][b] = '1';
        light[i] = mp(a,b);
    }
    rep(i,0,m){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a][b] = '2';
    }
    rep(i,0,n){
        dfs_yoko(light[i].first,light[i].second);
    }
    rep(i,0,n){
        dfs_tate(light[i].first,light[i].second);
    }
    cout<<ans<<endl;
}
