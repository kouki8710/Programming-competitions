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
    ll n;cin>>n;

    ll num2 = n;
    ll max_fact = 0;
    for (ll i=2;i*i<=n;i++){
        while (num2%i==0){
            max_fact = i;
            num2 /= i;
        }
    }
    if (num2!=1){
        max_fact = num2;
        cout<<max_fact<<endl;
        return 0;
    }
    
    ll ans = 1%n;
    ll num = 1;
    while (1){
        num++;
        ans = (ans*num%n)%n;
        if (ans%n==0) break;
    }
    cout<<num<<endl;
}