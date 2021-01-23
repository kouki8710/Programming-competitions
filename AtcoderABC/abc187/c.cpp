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
    map<string,int> k1,k2;
    rep(i,0,n){
        string a;cin>>a;
        if (a[0]=='!'){
            a = a.substr(1);
            k2[a] = 1;
        }else{
            k1[a] = 1;
        }
        
    }

    string ans = "satisfiable";

    for (auto s : k1){
        string l = s.first;
        if (k2[l]==1){
            ans = l;
            break;
        }
    }
    cout<<ans<<endl;
}