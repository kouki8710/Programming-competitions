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
    ll p;cin>>p;
    vector<ll> dp(100000), loop = {1,1};
    map<PL,ll> seen;
    dp[1] = 1;
    dp[2] = 1;
    ll i = 3;
    if (p==1){
        cout<<1<<endl;
        return 0;
    }
    while(1){
        ll f = 0;
        if (seen[mp(dp[i-1],dp[i-2])]){
            cout<<-1<<endl;
            return 0;
        }
        seen[mp(dp[i-1],dp[i-2])] = 1;
        dp[i] = dp[i-1] + dp[i-2]; 
        dp[i] = dp[i]%p;
        if (dp[i]==0){
            break;
        }
        i++;
    }
    
    cout<<i<<endl;
}