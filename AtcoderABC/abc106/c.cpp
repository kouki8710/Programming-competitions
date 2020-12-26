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
    string s;cin>>s;
    int k;cin>>k;
    int num =0, num2=0;
    rep(i,0,s.size()){
        if (s[i]=='1'){
            num++;
        }else{
            num2=s[i]-'0';
            break;
        }
    }
    if (k<=num){
        cout<<1<<endl;
    }else{
        cout<<num2<<endl;
    }
}