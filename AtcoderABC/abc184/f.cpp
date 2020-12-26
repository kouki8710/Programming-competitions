//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

vector<pair<ll,int>> bit_tansaku(vector<ll> a){
    vector<pair<ll,int>> res;
    rep(i,0,pow(2,a.size())){
        ll num = 0,cnt=0;
        rep(j,0,a.size()){
            if (i & (1<<j)){
                num += a[j];
                cnt++;
            }
        }
        res.push_back(mp(num,cnt));
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,t;cin>>n>>t;
    vector<ll> a,b;
    vector<pair<ll,int>> former,later;
    int h = n/2;
    rep(i,0,h){
        ll s;cin>>s;
        a.push_back(s);
    }
    rep(i,0,n-h){
        ll s;cin>>s;
        b.push_back(s);
    }
    former = bit_tansaku(a);
    later = bit_tansaku(b);
    sort(former.begin(), former.end());
    sort(later.begin(), later.end());
    ll ans = 0;
    rep(i,0,former.size()){
        
        ll index = upper_bound(later.begin(), later.end(), mp(t-former[i].first,INF)) - later.begin();
        if (index==0) continue;
        index--;
        if (former[i].first + later[index].first <= t){
            ll num = former[i].first + later[index].first;
            ans = max(ans,num);
        }
    }
    cout<<ans<<endl;
}