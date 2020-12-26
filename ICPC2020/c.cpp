//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define repp(i, n, s) for (ll i = (ll)(n); i >= (int)(s); i--)
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
    while (true){
        ll n;cin>>n;

        if (n==0){
            break;
        }

        vector<ll> yaku;
        map<ll,ll> p;

        rep(i,1,sqrt(n)+1){
            if (n%i==0){
                yaku.push_back(i);
                yaku.push_back(n/i);
            }
        }

        ll size = yaku.size();
        
        rep(i,0,size){
            ll num3 = sqrt(yaku[i]);
            if (num3*num3 != yaku[i]) num3++;
            ll num2 =  ( ceil( num3 * 2  ) );
            p[yaku[i]] = num2;
        }

        ll ans = (ll)2e62;

        rep(i,0,size){
            if (n%yaku[i]==0){
                ans = min(ans, yaku[i] + p[n/yaku[i]]);
            }
            
        }

        cout<<ans<<endl;
    }
    
}