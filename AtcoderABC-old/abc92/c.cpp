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
    vector<ll> a(n+2);
    rep(i,0,n){
        cin>>a[i+1];
    }
    ll sum = 0;
    rep(i,1,n+2){
        sum += abs(a[i-1]-a[i]);
    }
    rep(i,1,n+1){
        if (a[i-1]<=a[i] && a[i]<=a[i+1]){
            cout<<sum<<endl;
            continue;
        } 
        if (a[i-1]>=a[i] && a[i]>=a[i+1]){
            cout<<sum<<endl;
            continue;
        }

        ll num = sum;
        num -= abs(a[i]-a[i-1])+abs(a[i]-a[i+1]);
        num += abs(a[i-1]-a[i+1]);
        cout<<num<<endl;
    }
}