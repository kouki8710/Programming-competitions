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
    ll x,k,d;cin>>x>>k>>d;

    x = abs(x);
    if (k*d>0 && x-k*d>=0){
        cout<<x-k*d<<endl;
        return 0;
    }

    ll rest = k-x/d;
    if (rest%2==0){
        cout<<x-(x/d)*d<<endl;
    }else{
        cout<<abs( x-(x/d+1)*d )<<endl; 
    }
}