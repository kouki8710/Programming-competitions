//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define INFL 
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
ll mod = 1000000007;
ll mod2 = 998244353;
typedef tuple<int,int,int> T;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;cin>>h>>w;
    vector<string> G(h);
    rep(i,0,h){
        string s;cin>>s;
        G[i] = s;
    }
    int sx = 0;
    int sy = 0;
    int gx = 0;
    int gy = 0;
    rep(i,0,h){
        rep(j,0,w){
            if (G[i][j]=='s'){
                sx = i; sy = j;
            }else if(G[i][j]=='g'){
                gx = i; gy = j;
            }
        }
    }

    priority_queue<T,vector<T>,greater<T>> que;
    que.push(make_tuple(0,sx,sy));
    vector<vector<int>> dist(h,vector<int>(w,INF));
    int move[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    while (que.size()){
        T p = que.top();
        que.pop();
        int d = get<0>(p);
        int px = get<1>(p);
        int py = get<2>(p);
        if (dist[px][py]!=INF) continue;
        dist[px][py] = d;
        
        if (d>2) continue;
        for (auto m : move){
            int nx = px + m[0];
            int ny = py + m[1];
            if (0<=nx && nx<h && 0<=ny && ny<w){
                if (G[nx][ny]=='#'){
                    if (dist[nx][ny]==INF){
                        que.push(make_tuple(d+1,nx,ny));
                        // dist[nx][ny] = d+1;
                    }
                }else{
                    if (dist[nx][ny]==INF){
                        que.push(make_tuple(d,nx,ny));
                        // dist[nx][ny] = d;
                    }
                }
            }
        }
    }
    if (dist[gx][gy]==INF){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
}
