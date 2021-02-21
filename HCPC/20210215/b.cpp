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
    ll n;cin>>n;
    vector<ll> a(2*n+1),b(2*n+1);
    rep(i,0,n){
        ll k;cin>>k;
        a[k] = 1;
    }
    rep(i,1,2*n+1){
        b[i] = 1 - a[i];
    }

    ll f = 0;
    ll i = 1, j = 1;
    ll sum1 = n, sum2 = n;
    while (1){
        if (sum1==0 || sum2==0) break;
        if (f==0){
            while (1){
                if (i>2*n){
                    f = 1;
                    i = 1;
                    j = 1;
                    break;
                }

                if (a[i]==1){
                    
                    a[i] = 0;
                    f = 1;
                    j = i+1;
                    sum1--;
                    break;
                }
                i++;
            }
        }else{
            while (1){
                if (j>2*n){
                    f = 0;
                    i = 1;
                    j = 1;
                    break;
                }

                if (b[j]==1){
                    
                    b[j] = 0;
                    f = 0;
                    i = j+1;
                    sum2--;
                    break;
                }
                j++;
            }
        }
    }
    cout<<sum2<<endl;
    cout<<sum1<<endl;
}