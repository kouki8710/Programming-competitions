#define _GLIBCXX_DEBUG
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
    ll n,m;cin>>n>>m;
    vector<ll> a(m),b(m), c(30),d(30);
    rep(i,0,m) cin>>a[i]>>b[i];
    int k;cin>>k;
    rep(i,0,k){
        int b1,b2;cin>>b1>>b2;
        b1--;b2--;
        c[i] = b1; d[i] = b2;
    }

    rep(i,0,m){
        a[i]--;b[i]--;
    }

    ll ans = 0;
    rep(i,0,1<<k){
        vector<ll> num(n);
        rep(j,0,k){
            if (i & (1<<j)){
                num[c[j]]++;
            }else{
                num[d[j]]++;
            }
        }
        ll num2 = 0;
        rep(j,0,m){
            if (num[a[j]]>=1 && num[b[j]]>=1) num2++;
        }

        ans = max(ans, num2);
    }
    cout<<ans<<endl;
}