#define _GLIBCXX_DEBUG
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
    int sx,sy;cin>>sx>>sy;
    int gx,gy;cin>>gx>>gy;
    sx--;sy--;gx--;gy--;
    vector<string> ma(h);
    rep(i,0,h){
        string s1;cin>>s1;
        ma[i] = s1;
    }
    queue<pair<int,int>> q;
    q.push(mp(sx,sy));
    int num[100][100];
    rep(i,0,100){
        rep(j,0,100){
            num[i][j] = -1;
        }
    }
    num[sx][sy] = 0;
    int move[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        int px = now.first;
        int py = now.second;
        if (gx==px && gy==py){
            break;
        }
        for (auto m : move){
            int nx = px + m[0];
            int ny = py + m[1];
            if (ma[nx][ny]=='.' && num[nx][ny]==-1){
                num[nx][ny] = num[px][py] + 1;
                q.push(mp(nx,ny));
                
            }
        }
    }
    cout<<num[gx][gy]<<endl;
    
}