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

// a + b がオーバーフローするならtrueを返す
template <class T> bool overflow_if_add(T a, T b) {
    return (std::numeric_limits<T>::max() - a) < b;
}

// a * b がオーバーフローするならtrueを返す
template <class T> bool overflow_if_mul(T a, T b) {
    return (std::numeric_limits<T>::max() / a) < b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string x;cin>>x;
    ll m;cin>>m;
    ll max_d = 0;
    if (x.size() == 1) {
        if (x[0] - '0' <= m)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        return 0;
    }

    rep(i,0,x.size()){
        max_d = max(max_d, ll(x[i]-'0'));
    }
    max_d++;
    
    ll ng = max_d - 1, ok = INFL+10;
    while ((ok-ng)>1){
        ll mid = (ng+ok)/2;
        ll tmp = 0;ll k = 1;

        for (ll i = x.size() - 1; 0 <= i && tmp <= m; i--) {
            tmp += (x[i] - '0') * k;
            if ((ll) 1e18 / k < (x[i] - '0') || (i != 0 && (ll) 1e18/ k < mid)) {
                tmp = m + 1;
                break;
            }
            k *= mid;
        }
        if (m < tmp)
            ng = mid;
        else
            ok = mid;
    }

    cout<<ng-max_d+1<<endl;
}