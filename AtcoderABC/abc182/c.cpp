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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;cin>>s;
    ll ans = INF;
    rep(i,0,pow(2,s.size())){
        ll num = 0;
        ll erase = 0;
        rep(j,0,s.size()){
            if (i & (1<<j)){
                num += s[j] - '0';
            }else{
                erase++;
            }
        }
        if (num%3==0 && erase!=(ll)s.size()){
            ans = min(ans,erase);
        }
    }
    if (ans==INF){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
    
}
