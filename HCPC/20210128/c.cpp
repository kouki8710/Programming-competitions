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
    int n,k;cin>>n>>k;
    vector<ll> a(n), b(k);
    rep(i,0,n) cin>>a[i];
    rep(i,0,k) cin>>b[i];

    int i=0, j=0;
    ll ans = -1;
    while(j<k){

        int i1=i, num1=j-i+1;
        rep(s,0,n){
            if (num1==0) break;
            if (b[i1]==a[s]){
                num1--;
                i1++;
            }
        }
        if (num1==0){
            ans = max(ans, ll(j-i+1));
            j++;
        }else{
            i++;
        }
    }
    cout<<ans<<endl;
}