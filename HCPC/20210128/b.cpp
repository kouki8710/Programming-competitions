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
ll mod = 1000000007;
ll mod2 = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<ll> a(2*n+1), b(2*n+1);
    rep(i,0,n){
        int num;cin>>num;
        a[num] = 1;
    }
    rep(i,1,2*n+1){
        b[i] = 1 - a[i];
    }

    int j1 = 1, j2=1;
    int num = 0, p=0;// 0 太郎
    int n1 = n, n2 = n;
    while (true){

        if (n1==0 || n2==0) break;
        
        if (p==0){
            
            while (1){
                if (j1>2*n){
                    num = 0;
                    j1 = 1;
                    j2 = 1;
                    break;
                }
                if (num<j1 && a[j1]){
                    num = j1;
                    a[j1] = 0;
                    j1++;
                    n1--;
                    break;
                }
                j1++;
            }
            p = 1;

        }else{

            while (1){
                if (j2>2*n){
                    num = 0;
                    j1 = 1;
                    j2 = 1;
                    break;
                }
                if (num<j2 && b[j2]){
                    num = j2;
                    b[j2] = 0;
                    j2++;
                    n2--;
                    break;
                }
                j2++;
            }
            p = 0;
        }
    }

    cout<<n2<<endl;
    cout<<n1<<endl;
}