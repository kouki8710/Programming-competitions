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
    ll k; cin>>k;
    const int num = 50;
    vector<ll> a(num,num-1);
    ll mod1 = k%num;
    rep(i,0,mod1){
        a[i] += num - (mod1-1);
    }
    repp(i,num-1,mod1){
        a[i] -= mod1;
    }
    cout<<50<<endl;
    rep(i,0,num){
        cout<<a[i]+k/num<<" ";
    }
    cout<<endl;
}