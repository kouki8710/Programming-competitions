//#define _GLIBCXX_DEBUG
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
    int n;cin>>n;
    string s;cin>>s;
    string ans = "";
    int J=0,O=0, I=0;
    rep(i,0,n){
        if (s[i]=='J') J++;
        else if (s[i]=='O') O++;
        else I++;
    }

    rep(i,0,J){
        ans += "J";
    }
    rep(i,0,O) ans += "O";
    rep(i,0,I) ans += "I";
    cout<<ans<<endl;
}