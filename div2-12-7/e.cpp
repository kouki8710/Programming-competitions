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
    vector<ll> a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    int r=0 ,l=0;
    ll ans = 0;
    while (r<n && l<n){
        if (r+1<n){
            if (a[r]<a[r+1]){
                r++;
                continue;
            }else{
                ll num = r-l+1;
                ans += num*(num+1)/2;
                l = r+1;
                r++;
            }
        }else{
            ll num = r-l+1;
            ans += num*(num+1)/2;
            r++;
        }
    }
    cout<<ans<<endl;
}