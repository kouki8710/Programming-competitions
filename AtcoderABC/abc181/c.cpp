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
    int n;cin>>n;
    vector<int> x(n),y(n);
    rep(i,0,n){
        cin>>x[i]>>y[i];
    }
    rep(i,0,n){
        rep(j,0,n){
            rep(k,0,n){
                if (i==j || i==k || j==k) continue;
                if (x[j]==x[i]){
                    if (x[j]==x[k]){
                        cout<<"Yes"<<endl;
                        return 0;
                    }else{
                        continue;
                    }
                }
                ll a1 = (y[k]-y[j])*(x[j]-x[i]);
                ll a2 = (y[j]-y[i])*(x[k]-x[j]);
                if (a1==a2){
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;
}