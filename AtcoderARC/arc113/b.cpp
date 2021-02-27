//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 1000000000
#define INFL 1000000000000000000
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
#define tp make_tuple
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef tuple<int,int,int> T;
typedef tuple<ll,ll,ll> TL;

ll modpow(ll a, ll b, ll mod) {
    ll r = 1;
    while (b) {
        r = r * ((b % 2) ? a : 1) % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b,c;cin>>a>>b>>c;
    ll first = a%10;
    vector<ll> nums;
    nums.push_back(first);
    ll num = first;
    while(1){
        num = num*first%10;
        ll f = 0;
        rep(i,0,nums.size()){
            if (nums[i]==num){
                f = 1;
                break;
            }
        }
        if (f) break;
        nums.push_back(num);
    }
    
    ll num2 = modpow(b,c,nums.size());
    num2 = (num2-1+nums.size())%nums.size();
    cout<<nums[num2]<<endl;
}