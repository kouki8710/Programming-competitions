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
    ll n,c;cin>>n>>c;
    vector<pair<ld,ld>> num;
    map<ll,ll> num2;
    rep(i,0,n){
        int a1,a2,a3;cin>>a1>>a2>>a3;
        num.push_back( mp(a1,a3) );
        num.push_back( mp(a2+1,-a3) );
    }


    sort(num.begin(), num.end());

    ll ans = 0;
    ll sum = 0;
    ll bef = 0;
    rep(i,0,num.size()){
        ll k1 = num[i].first;
        ll k2 = num[i].second;
        if (k1!=bef){
            ans += min(sum,c)*(k1-bef);
        }
        
        bef = k1;
        sum += k2;
    }
    cout<<ans<<endl;
}
