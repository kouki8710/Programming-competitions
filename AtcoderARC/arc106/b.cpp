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

vector<vector<ll>> ma;
vector<ll> a,b,seen;

int dfs(int index,vector<ll>& sum){
    if (seen[index]==1){
        return 0;
    }
    seen[index] = 1;
    sum.push_back(index);
    for (auto i : ma[index]){
        dfs(i,sum);
    }
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    a.resize(n);
    b.resize(n);
    ma.resize(n);
    seen.resize(n);
    rep(i,0,n) cin>>a[i];
    rep(i,0,n) cin>>b[i];
    rep(i,0,m){
        int s,k;cin>>s>>k;
        s--;k--;
        ma[s].push_back(k);
        ma[k].push_back(s);
    }
    rep(i,0,n){
        vector<ll> sum;
        dfs(i,sum);
        ll sum_a=0;ll sum_b=0;
        for (auto j:sum){
            sum_a+=a[j];
            sum_b+=b[j];
        }
        if (sum_a!=sum_b ){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}