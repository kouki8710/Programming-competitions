// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define INFL 
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
    int h,w;cin>>h>>w;
    int sx,sy;cin>>sx>>sy;
    int gx,gy;cin>>gx>>gy;
    sx--;sy--;gx--;gy--;
    vector<string> G(h);
    rep(i,0,h){
        string s;cin>>s;
        G[i] = s;
    }

    priority_queue<T,vector<T>,greater<T>> que;
    vector<vector<ll>> dist(h,vector<ll>(w,INF));
    que.push(tp(0,sx,sy));

    int move[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    dist[sx][sy] = 0;
    
    while (que.size()){
        T p = que.top();
        que.pop();
        int d = get<0>(p);
        int px = get<1>(p);
        int py = get<2>(p);
        if (dist[px][py]<d) continue;
        for (auto m : move){
            int nx = px + m[0];
            int ny = py + m[1];
            if (0<=nx && nx<h && 0<=ny && ny<w && G[nx][ny]=='.'){
                if (dist[nx][ny]>dist[px][py]){
                    dist[nx][ny] = d;
                    que.push(tp(d,nx,ny));
                }
            }
        }
        rep(i,-2,3){
            rep(j,-2,3){
                int nx = px + i;
                int ny = py + j;
                if (0<=nx && nx<h && 0<=ny && ny<w && G[nx][ny]=='.'){
                    if (dist[nx][ny]>dist[px][py]+1){
                        dist[nx][ny] = d+1;
                        que.push(tp(d+1,nx,ny));
                    }
                }
            }
        }
    }
    if (dist[gx][gy]==INF){
        cout<<-1<<endl;
    }else{
        cout<<dist[gx][gy]<<endl;
    }
}
