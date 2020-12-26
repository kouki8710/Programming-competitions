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
    ll n;cin>>n;
    ll ans = 0;
    rep(i,1,n+1){
        ll num = i;
        ll f = 1;
        while(num>0){
            if (num%10==7){
                f = 0;
                break;
            }
            num /= 10;
        }
        num = i;
        while(num>0){
            if (num%8==7){
                f = 0;
                break;
            }
            num /= 8;
        }

        if (f) ans++;
    }

    cout<<ans<<endl;
}