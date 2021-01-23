// #define _GLIBCXX_DEBUG
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
ll mod = 1000000007;
ll mod2 = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<ll> a(3*n), num(n+1), num2(n+1);
    rep(i,0,3*n){
        cin>>a[i];
    }

    priority_queue<ll, vector<ll>, greater<ll>> que;
    ll a_former_sum = 0;
    rep(i,0,n){
        que.push(a[i]);
        a_former_sum += a[i];
    }
    ll min_sum = 0;
    num[0] = a_former_sum; 
    rep(i,n,2*n){
        a_former_sum += a[i];
        if (a[i]>que.top()){
            min_sum += que.top();
            que.pop();
            que.push(a[i]);
            num[i-n+1] =  a_former_sum - min_sum;
        }else{
            min_sum += a[i];
            num[i-n+1] =  a_former_sum - min_sum;
        }
    }

    ll max_sum = 0;
    priority_queue<ll> que2;
    ll a_latter_sum = 0;
    rep(i,2*n,3*n){
        que2.push(a[i]);
        a_latter_sum += a[i];
    }

    num2[0] = a_latter_sum;
    repp(i,2*n-1,n){
        a_latter_sum += a[i];
        if (a[i]<que2.top()){
            max_sum += que2.top();
            que2.pop();
            que2.push(a[i]);
            num2[2*n-1-i+1] = a_latter_sum - max_sum;
        }else{
            max_sum += a[i];
            num2[2*n-1-i+1] = a_latter_sum - max_sum;
        }
    }

    ll ans = -pow(10,18);
    rep(i,0,n+1){
        ans = max(ans, num[i]-num2[n-i]);
    }

    cout<<ans<<endl;
}