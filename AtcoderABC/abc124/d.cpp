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
    string s;cin>>s;
    vector<ll> num;
    int i = 1,cnt=1;
    char mozi = s[0];
    if (mozi=='0') num.push_back(0);
    while (true){
        if (i==n){
            if (cnt!=0){
                num.push_back(cnt);
            }
            break;
        }
        if (s[i]==mozi){
            cnt++;
        }else{
            num.push_back(cnt);
            cnt = 1;
            mozi = s[i];
        }
        i++;
    }
    if (mozi=='0') num.push_back(0);
    ll size = num.size();
    
    if (size/2<=k){
        cout<<n<<endl;
        return 0;
    }
    ll ans = 0;
    
    for (int i=0;i<=size-(2*k+1);i+=2){
        ll num2 = 0;
        rep(j,i,i+2*k+1){
            num2 += num[j];
        }
        ans = max(ans,num2);
    }
    cout<<ans<<endl;
}