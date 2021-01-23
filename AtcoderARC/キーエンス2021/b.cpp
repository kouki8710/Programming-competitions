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
    vector<ll> a(n);
    rep(i,0,n) cin>>a[i];
    map<ll,ll> num;
    rep(i,0,n){
        num[a[i]]++;
    }

    ll ans = 0;
    ll num2 = 0;
    ll cnt = 0;
    while (cnt<k){
        if (num[num2]==0){
            if (num2==0){
                break;
            }else{
                ans += num2;
                num2 = 0;
                cnt++;
                continue;
            }
        }

        num[num2]--;
        num2++;

    }
    cout<<ans<<endl;
}