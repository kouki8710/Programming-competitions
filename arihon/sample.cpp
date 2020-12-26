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

int fact(int i){
    if (i==1){
        return 1;
    }
    return fact(i-1)*i;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string a = "abc",b = "bcd";
    int i = a<b;
    cout<< i <<endl;
}