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
    map<ll,ll> a1,a2;
    rep(i,0,n){
        ll v;cin>>v;
        if (i%2==0){
            a1[v]++;
        }else{
            a2[v]++;
        }
    }

    ll max1=0,index1=0,max2=0,index2=0;

    for (auto p : a1){
        if (max1<p.second){
            max1 = p.second;
            index1 = p.first;
        }
    }

    for (auto p : a2){
        if (max2<p.second){
            max2 = p.second;
            index2 = p.first;
        }
    }

    if (index1!=index2){

        cout<<n-max1-max2<<endl;
        
    }else{

        ll m1 = 0, m2 = 0;

        for (auto p : a2){
            if (m2<p.second && p.first!=index2){
                m2 = p.second;
            }
        }

        for (auto p : a1){
            if (m1<p.second && p.first!=index1){
                m1 = p.second;
            }
        }

        cout<<min(n-max1-m2,n-max2-m1)<<endl;

    }
}