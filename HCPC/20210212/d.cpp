//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 1000000100
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
    ll w,h;cin>>w>>h;
    ll n;cin>>n;
    vector<ll> x(n),y(n);
    vector<PL> p(n); 
    rep(i,0,n){
        cin>>x[i]>>y[i];
        p[i] = mp(x[i],y[i]);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ll x_cost = 0;
    rep(i,0,n/2){
        x_cost -= x[i];
    }
    rep(i,n/2,n){
        x_cost += x[i];
    }
    if (n%2==1) x_cost -= x[n/2];

    ll y_cost = 0;
    rep(i,0,n/2){
        y_cost -= y[i];
    }
    rep(i,n/2,n){
        y_cost += y[i];
    }
    if (n%2==1) y_cost -= y[n/2];

    ll ans = (x_cost+y_cost)*2;

    ll nx = x[n/2];
    ll ny = y[n/2];
    ll maxs = 0;
    rep(i,0,n){
        if (maxs<abs(nx-p[i].first)+abs(ny-p[i].second)){
            maxs = abs(nx-p[i].first)+abs(ny-p[i].second);
        }
    }
    if (n%2==0){
        nx = x[n/2-1];
        ny = y[n/2-1];
    }
    ans -= maxs;

    cout<<ans<<endl;
    cout<<nx<<" "<<ny<<endl;
}