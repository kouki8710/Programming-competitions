//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define INFL 
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
    ll a,b,x,y;cin>>a>>b>>x>>y;
    if (a>b){
        cout<<min(x*((a-b-1)*2+1),x + y*(a-b-1))<<endl;
    }else if(a == b){
        cout<<x<<endl;
    }else{
        cout<<min(x + y*(b-a),x*(2*b-2*a+1))<<endl;
    }
}