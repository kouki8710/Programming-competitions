#define _GLIBCXX_DEBUG
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
    ll n,m;cin>>n>>m;
    vector<PL> x_sort(m),y_sort(m);
    rep(i,0,m){
        ll x,y;cin>>x>>y;
        x_sort[i] = mp(x,y);
        y_sort[i] = mp(y,x);
    }

    sort(x_sort.begin(), x_sort.end());
    sort(y_sort.begin(), y_sort.end());



    ll ng = -1, ok = INF+10;

    while ((ok-ng)>1){
        ll mid = (ok+ng)/2;

        ll cnt = 1;
        ll num = x_sort[0].first + mid;
        rep(i,1,m){
            if (x_sort[i].first > num){
                cnt++;
                num = x_sort[i].first + mid;
            }
        }

        cnt ++;
        num = y_sort[0].first + mid;
        rep(i,1,m){
            if (y_sort[i].first > num){
                cnt++;
                num = y_sort[i].first + mid;
            }
        }

        if (cnt > n){
            ng = mid;
        }else{
            ok = mid;
        }
    }
    cout<<ok<<endl;
}