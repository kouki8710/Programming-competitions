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
    vector<ll> a(n), b(n);
    ll k = -1;
    rep(i,0,n){
        cin>>a[i];
        if (k==-1){
            if (a[i]==0){
                k = i;
                b[k]+=1;
            }
        }else{
            if (a[i]==0){
                b[k]+=1;
            }else{
                k = -1;
            }
        }
    }
    ll ans = 0;

    rep(i,0,n-1){
        if (b[i]>0){
            b[i+1] = b[i] - 1;
        }
    }

    rep(i,0,n){
        ll num = a[i];
        ans++;
        ll j = i+1;
        if (b[i]>0){
            j += b[i]-1;
            ans += b[i]-1;
        }
        
        while(j<n){

            if (b[j]>0){
                ans += b[j];
                j += b[j];
                continue;
            }

            if ((num ^ a[j]) == (num + a[j]) ){
                ans++;
                num ^= a[j];
            }else{
                break;
            }
            j++;
        }
    }
    cout<<ans<<endl;
}