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
    vector<ll> a(n),b(n);
    ll sum_a=0,sum_b=0;
    vector<PL> sum(n);
    rep(i,0,n){
        cin>>b[i]>>a[i];
        sum_b += b[i];
        sum[i] = mp(a[i]+2*b[i],i);
    }

    sort(sum.begin(), sum.end(), greater<PL>());

    ll ans = 0;
    rep(i,0,n){
        if (sum_a > sum_b){
            break;
        } 
        ans += 1;

        sum_a += a[sum[i].second] + b[sum[i].second];
        sum_b -= b[sum[i].second];
    }

    cout<<ans<<endl;
}