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
    ll r1,c1,r2,c2;cin>>r1>>c1>>r2>>c2;

    if (r1==r2 && c2==c1){
        cout<<0<<endl;
        return 0;
    }

    if (r1+c1==r2+c2 || r1-c1==r2-c2){
        cout<<1<<endl;
        return 0;
    }else if(abs(r1-r2)+abs(c1-c2)<=3){
        cout<<1<<endl;
        return 0;
    }else if((r1+c1)%2==(r2+c2)%2){
        cout<<2<<endl;
        return 0;
    }

    rep(i,0,4){
        rep(j,0,2*i+1){
            ll x = r2+(j-i);
            ll y1 = c2+(3-i);
            ll y2 = c2-(3-i);
            if (r1+c1==x+y1 || r1-c1==x-y1 || r1+c1==x+y2 || r1-c1==x-y2){
                cout<<2<<endl;
                return 0;
            }
        }
    }
    cout<<3<<endl;
    return 0;
}