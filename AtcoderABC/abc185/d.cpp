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
    ll n,m;cin>>n>>m;
    vector<ll> a(m+2), w;
    rep(i,1,m+1) cin>>a[i];
    
    a[0] = 0;
    a[m+1] = n+1;

    sort(a.begin(), a.end());

    rep(i,0,m+1){
        if (a[i+1] - a[i] - 1 > 0){
            w.push_back(a[i+1] - a[i] - 1);
        }
    }

    if (w.size()==0){
        cout<<0<<endl;
        return 0;
    }

    ll ans = 0;

    ll num = *min_element(w.begin(), w.end());

    rep(i,0,w.size()){
        ans += (w[i]/num);
        if (w[i]%num!=0){
            ans++;
        }
    }

    cout<<ans<<endl;
}