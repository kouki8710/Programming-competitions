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
    vector<ll> a(n);
    rep(i,0,n) cin>>a[i];
    ll ans = 0;
    ll num = 0;
    rep(i,0,n){
        if (num>0 && a[i]==0){
            ans = max(ans, num);
            num = 0;
        }
        if (a[i]==1){
            num++;
        }
        
    }
    ans = max(ans, num);
    cout<<ans+1<<endl;
}