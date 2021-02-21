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
    ll n;cin>>n;
    vector<ll> op(n), dp(n+1),dp2(n+1);
    rep(i,0,n){
        string s;cin>>s;
        if (s=="AND"){
            op[i] = 1; //and
        }else{
            op[i] = 0; //or
        }
    }
    dp[0] = 1;
    dp2[0] = 1;
    rep(i,0,n){
        if (op[i]==0){
            dp2[i+1] += dp2[i]*2+dp[i];
            dp[i+1] += dp[i];
        }else{
            dp2[i+1] += dp2[i];
            dp[i+1] += dp[i]*2+dp2[i];
        }
    }
    cout<<dp2[n]<<endl;
}