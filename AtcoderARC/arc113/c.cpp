//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 1000000000
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
    string s;cin>>s;
    ll size = s.size();
    ll ans = 0;
    vector<pair<ll,char>> vec; 
    repp(i,size-3,0){
        if (s[i]==s[i+1] && s[i]!=s[i+2]){
            vec.push_back(mp(i,s[i]));
        }
    }
    if (vec.size()==0){
        cout<<0<<endl;
        return 0;
    }
    rep(i,0,vec.size()-1){
        ll i1 = vec[i].first;
        char s1 = vec[i].second;
        ll i2 = vec[i+1].first;
        char s2 = vec[i+1].second;
        ll cnt = 0;
        rep(j,i2+2,i1){
            if (s[j]==s2) cnt++;
        }
        if (s1==s2){
            ans -= (size-i1);
        }
        ans += size - (i2+2) - cnt;
    }
    ll i1 = vec[0].first;
    char s1 = vec[0].second;
    ll cnt = 0;
    rep(j,i1+2,size){
        if (s[j]==s1) cnt++;
    }
    ans += size - (i1+2) - cnt;
    cout<<ans<<endl;
}