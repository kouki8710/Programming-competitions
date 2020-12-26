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
    ld s1,s2,g1,g2;;cin>>s1>>s2>>g1>>g2;
    ld x = s1 + s2*((g1-s1)/(g2+s2));
    cout<<std::fixed << std::setprecision(15)<<x<<endl;
}