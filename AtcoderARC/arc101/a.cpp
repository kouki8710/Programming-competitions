#define _GLIBCXX_DEBUG
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
    ll n,k;cin>>n>>k;
    vector<ll> a1,a2;
    rep(i,0,n){
        ll x;cin>>x;
        if (x<0){
            a1.push_back(x);
        }else if(x>0){
            a2.push_back(x);
        }else{
            k--;
        }
    }

    if (k==0){
        cout<<0<<endl;
        return 0;
    }

    sort(a1.rbegin(), a1.rend());

    ll ans = (ll)2e62;
    rep(i,0,a2.size()){
        if (i+1==k){
            ans = min(ans, a2[i]);
        }else if (i+1<k && k-i-2 < (ll)a1.size() ){
            ans = min(ans, 2*a2[i] - a1[k-i-2]);
        }
    }

    rep(i,0,a1.size()){
        if (i+1==k){
            ans = min(ans, -1*a1[i]);
        }else if(i+1<k  && k-i-2 < (ll)a2.size() ){
            ans = min(ans, -2*a1[i] + a2[k-i-2]);
        }
    }

    cout<<ans<<endl;
}