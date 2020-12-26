#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)

int main() {
    ll n, k, t, u, v, l;
    cin >> n >> k >> t >> u >> v >> l;
    vector<ll> d(n);
    rep(i, 0, n) {
        cin >> d[i];
    }
    ll l1 = 0, l2 = 0, pos=0;
    ll f = 0;  //加速中かどうか 1が加速中
    rep(i, 0, n) {
        if (f = 0) {
            l1 += d[i]-pos;
            pos = d[i];
        }else if(){
            
        }
    }
}