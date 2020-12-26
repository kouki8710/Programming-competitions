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
    string s;cin>>s;
    ll bignum = pow(10,10);

    if (n==1){
        if (s[0]=='1'){
            cout<<bignum*2<<endl;
        }else{
            cout<<bignum<<endl;
        }
        return 0;
    }

    int a1[] = {'1','1','0'};
    int a2[] = {'1', '0', '1'};
    int a3[] = {'0', '1', '1'};
    ll num = 0, k = 0;
    rep(i,0,n){
        if (a1[i%3]!=s[i]){
            break;
        }
        if (i==n-1){
            num = 1;
            k = (n+2)/3;
        }
    }

    rep(i,0,n){
        if (a2[i%3]!=s[i]){
            break;
        }
        if (i==n-1){
            num = 2;
            k = (n+3)/3;
        }
    }

    rep(i,0,n){
        if (a3[i%3]!=s[i]){
            break;
        }
        if (i==n-1){
            num = 3;
            k = (n+4)/3;
        }
    }

    if (num==0){
        cout<<0<<endl;
        return 0;
    }

    cout<< bignum - (k-1) << endl;

}