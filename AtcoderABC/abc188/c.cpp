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
    ll n;cin>>n;
    vector<ll> a(1<<n),b(1<<(n+1)), c(1<<(n+1));
    rep(i,0,1<<n){
        cin>>a[i];
        b[(1<<n)+i-1] = a[i];
        c[(1<<n)+i-1] = i+1;
    }

    repp(i,(1<<(n+1))-2,0){
        if ((i+1)%2==0){
            if (b[i]<b[i+1]){
                b[(i-1)/2] = max(b[i],b[i+1]);
                c[(i-1)/2] = c[i+1];
            }else{
                b[(i-1)/2] = max(b[i],b[i+1]);
                c[(i-1)/2] = c[i];
            }
        }
    }
    if (b[1]<b[2]){
        cout<<c[1]<<endl;
    }else{
        cout<<c[2]<<endl;
    }
}
