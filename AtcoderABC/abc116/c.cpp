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
    vector<ll> h(n);
    rep(i,0,n) cin>>h[i];
    int ans = 0;
    while (1){
        int f = 1, f2=0;
        rep(i,0,n){
            if (h[i]>0){
                f = 0;
                h[i]--;
                if (f2==0){
                    f2 = 1;
                    ans++;
                }
            }else{
                f2 = 0;
            }
        }
        if (f) break;
    }
    cout<<ans<<endl;
}