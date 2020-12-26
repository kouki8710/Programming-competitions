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
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) {
        int k;
        cin >> k;
        a[i] = abs(k);
    }
    ll ans = 0;
    rep(i, 0, n) {
        ans += a[i];
    }
    cout << ans << endl;
    ans = 0;
    rep(i, 0, n) {
        ans += a[i] * a[i];
    }
    cout << fixed << setprecision(15) << sqrt(ans) << endl;
    cout << *max_element(a.begin(), a.end()) << endl;
}