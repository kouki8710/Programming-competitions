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
    ll ans = 10000000000;
    ll num = 0;
    rep(i,0,s.size()){
        if (i%2==0){
            if (s[i] == '1') num++;
        }else{
            if (s[i] == '0') num++;
        }
    }
    ans = num;
    num = 0;
    rep(i,0,s.size()){
        if (i%2==1){
            if (s[i] == '1') num++;
        }else{
            if (s[i] == '0') num++;
        }
    }
    ans = min(ans,num);
    cout<<ans<<endl;
}