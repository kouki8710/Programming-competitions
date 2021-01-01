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
    int h,w;cin>>h>>w;
    vector<string> s(h);
    rep(i,0,h){
        string k;cin>>k;
        s[i] = k;
    }
    ll ans = 1;
    rep(i,0,h){
        rep(j,0,w){
            if (s[i][j]=='#'){
                if ( (0<=i-1 && s[i-1][j]=='.') && 
                (i+1<h && s[i+1][j]=='.') &&
                (j-1>=0 && s[i][j-1]=='.') &&
                (j+1<w && s[i][j+1]=='.')){
                    ans = 0;
                }
            }
        }
    }
    if (ans){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}