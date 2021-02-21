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
    ll b,c;cin>>b>>c;
    ll ans = 1;
    if (c==1){
        if (b==0){
            cout<<1<<endl;
            return 0;
        }else{
            cout<<2<<endl;
            return 0;
        }
    }
    if (b==0){
        ans += (c-1)/2; // +1
        ans += c/2;
        cout<<ans<<endl;
        return 0;
    }

    if (b<0){
        ans += c/2;
        ans += (c-1)/2;
        b = abs(b);
        c--;
        ans++;
        if (b-c/2>-b){
            if (b-c/2>0){
                ans+=c/2;
                ans+=(c-1)/2;
            }else if (b-c/2<=0){
                ans += (b-1)*2+1;
            }
        }else{
            ans += (b-1)*2+1;
        }
        cout<<ans<<endl;
    }else if (b>0){
        ans += (c-1-1)/2;
        ans += (c-1)/2+1;
        if (b-c/2>-b){
            if (b-c/2>0){
                ans+=c/2;
                ans+=(c-1)/2;
            }else if (b-c/2<=0){
                ans += (b-1)*2+1;
            }
        }else{
            ans += (b-1)*2+1;
        }
        cout<<ans<<endl;
    }
}