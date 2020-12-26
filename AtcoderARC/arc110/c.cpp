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
    vector<ll> p(n),used(n-1);
    map<ll,ll> keep;
    rep(i,0,n){
        cin>>p[i];
        keep[p[i]] = i;
    }

    int i = 1;
    vector<ll> ans;
    while(i<=n){
        int now_i = keep[i];//index
        if (now_i==i-1){
            i++;
            continue;
        }

        if (used[now_i-1] == 1){
            break;
        }

        used[now_i-1] = 1;
        ans.push_back(now_i);
        swap(p[now_i], p[now_i-1]);
        keep[i] = now_i-1;
        keep[p[now_i]] = now_i;
    }  

    rep(i,0,n){
        if (p[i]!=i+1){
            cout<<-1<<endl;
            return 0;
        }
    }

    rep(i,0,n-1){
        if (used[i]==0){
            cout<<-1<<endl;
            return 0;
        }
    }

    rep(i,0,ans.size()){
        cout<<ans[i]<<endl;
    }
}