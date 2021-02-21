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
    string a,b;cin>>a>>b;
    ll a_s = a.size();
    ll a_i = 0, a_j=0;
    ll ans = 0;
    while(a_j<a_s){
        string k = "";
        rep(i,a_i,a_j+1){
            k += a[i];
        }
        if (b.find(k) != string::npos){
            a_j++;
            ans = max(ans, (ll)k.size());
        }else{
            
            if (a_i==a_j){
                a_i++;a_j++;
            }else{
                a_i++;
            }
        }
    }
    cout<<ans<<endl;
}