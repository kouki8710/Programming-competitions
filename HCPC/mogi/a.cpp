
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)

int main(){
    while (true)
{
    int n,m;cin>>n>>m;
    if (n==0 && m==0){
        break;
    }
    vector<ll> a(n),b(m),ans(10);
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,m){
        cin>>b[i];
    }
    rep(i,0,n){
        rep(j,0,m){
            int k = a[i]*b[j];
            string s = to_string(k);
            rep(l,0,s.size()){
                ans[s[l]-'0']++;
            }
        }
    }
    rep(i,0,10){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
}