#define _GLIBCXX_DEBUG
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
    string s;cin>>s;
    string a = "";
    rep(i,0,n){
        a += s[i];
        int size = a.size();
        if (size>=3){
            string fox = "";
            repp(j,size-1,size-3){
                fox += a[j];
            }
            if (fox=="xof"){
                a = a.erase(a.size()-3);
            }
        }
    }
    cout<<a.size()<<endl;
}