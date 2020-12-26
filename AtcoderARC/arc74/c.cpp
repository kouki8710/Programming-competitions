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
    ll h,w;cin>>h>>w;

    ll ans = INF;

    ll n = h;
    ll m = w;
    ll a=0, b=0, c=0;

    // yoko
    a = n/2*m; // b >= a

    n = h-h/2;
    m = w;

    // yoko
    b = n/2*m; c=(h-h/2-n/2)*m;

    ans = min( max(a,max(b,c))-min(a,min(b,c)) ,ans );

    ////
    n = h;
    m = w;
    a=0, b=0, c=0;

    // yoko
    a = n/2*m; // b >= a

    n = h-h/2;
    m = w;

    // tate
    b = n*(m/2); c=n*(m-m/2);

    ans = min( max(a,max(b,c))-min(a,min(b,c)) ,ans );

    /////////
    n = h;
    m = w;
    a=0, b=0, c=0;

    // tate
    a = n*(m/2); // b >= a

    n = h;
    m = w-w/2;

    // yoko
    b = (n/2)*m; c=(h-n/2)*m;

    ans = min( max(a,max(b,c))-min(a,min(b,c)) ,ans );

    /////////
    n = h;
    m = w;
    a=0, b=0, c=0;

    // tate
    a = n*(m/2); // b >= a

    n = h;
    m = w-w/2;

    // tate
    b = n*(m/2); c=n*(m-m/2);

    ans = min( max(a,max(b,c))-min(a,min(b,c)) ,ans );

    cout<<ans<<endl;

}