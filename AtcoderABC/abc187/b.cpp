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
    int n;cin>>n;
    vector<ll> x(n),y(n);
    rep(i,0,n){
        int a,b;cin>>a>>b;
        x[i] = a;
        y[i] = b;
    }

    ll ans = 0;
    rep(i,0,n){
        rep(j,0,n){
            if (i<j){
                if (x[j]-x[i]>0){
                    if ( -(x[j]-x[i])<=y[j]-y[i] && y[j]-y[i]<=x[j]-x[i] ) ans++;
                }else{
                    if ( (x[j]-x[i])<=y[j]-y[i] && y[j]-y[i]<=-x[j]+x[i] ) ans++;
                }
                
            }
        }
    }
    cout<<ans<<endl;
}