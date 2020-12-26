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
    int n,m;cin>>n>>m;
    vector<ll> a(n),b(m), dp(min(n,m)+1, INF);
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,m){
        cin>>b[i];
    }
    
    dp[0] = n+m;
    ll num = min(n,m);
    rep(i,0,num){
        ll j = 0;ll k=0;
        ll cnt = 0;
        while(j<n && k < m){
            if (a[j] == b[k]){
                k++;
                j++;
                cnt++;
            }else{
                k++;
            }
        }
        
        if (cnt>=i+1){
            dp[i+1] = dp[i] - 2;
        }else{
            dp[i+1] = dp[i] - 1;
        }
    }
    cout<< *min_element(dp.begin(), dp.end()) <<endl;
}