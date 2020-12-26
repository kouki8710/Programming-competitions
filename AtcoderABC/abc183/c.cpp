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
    int n,k;cin>>n>>k;
    vector<vector<int>> time(n,vector<int>(n));
    vector<int> index(n);

    rep(i,0,n){
        index[i] = i;
    }
    rep(i,0,n){
        rep(j,0,n){
            cin>>time[i][j];
        }
    }

    ll ans = 0;
    do{
        ll num = 0;
        if (index[0]!=0){
            continue;
        }
        for(int i=0; i<n-1; i++){
            num += time[index[i+1]][index[i]];
        }
        num += time[index[n-1]][0];
        if (num==k) ans++;
    }while(next_permutation(index.begin(),index.end()));
    cout<<ans<<endl;
}