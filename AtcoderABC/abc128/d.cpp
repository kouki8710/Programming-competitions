//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define INFL 
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
    vector<ll> v(n);
    rep(i,0,n) cin>>v[i];
    ll ans = 0;
    ll min_n_k = min(n,k);
    rep(i,0,n+1){
        rep(j,0,n+1){
            if (0<i+j && i+j<=min_n_k){
                vector<ll> num;
                ll sub_ans = 0;
                rep(s,0,i){
                    num.push_back(v[s]);
                    sub_ans += v[s];
                }
                rep(s,0,j){
                    num.push_back(v[n-1-s]);
                    sub_ans += v[n-1-s];
                }
                sort(num.begin(),num.end());
                rep(s,0,k-i-j){
                    if (num[s]<0 && s < (int)num.size()){
                        sub_ans -= num[s];
                    }
                }
                ans = max(ans,sub_ans);
            }
        }
    }
    cout<<ans<<endl;
}
