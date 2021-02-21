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
    ll n,m;cin>>n>>m;

    if (n==1 && m==0){
        cout<<1<<" "<<2<<endl;
        return 0;
    } 

    if (abs(m)>=n-1){
        cout<<-1<<endl;
        return 0;
    }
    if (m==0){
        rep(i,0,n){
            cout<<2*i+1<<" "<<2*i+2<<endl;
        }
    }
    if (m>0){
        rep(i,0,n-1){
            cout<<3*i+1+1<<" "<<3*i+2+1<<endl;
        }
        cout<<3*(n-2-m)+1<<" "<<3*(n-1)+2+1<<endl;
    }else if(m<0){
        cout<<-1<<endl;
    }
}