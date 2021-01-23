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
    string n;cin>>n;
    string k;cin>>k;
    int a1=0,a2=0;
    a1 += (n[2]-'0') + (n[1]-'0') + (n[0]-'0');
    a2 += (k[2]-'0') + (k[1]-'0') + (k[0]-'0');
    if (a1<a2){
        cout<<a2<<endl;
    }else{
        cout<<a1<<endl;
    }
}