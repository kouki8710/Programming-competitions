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
    vector<ll> x(n),y(n);
    rep(i,0,n){
        cin>>x[i]>>y[i];
    }
    int m;cin>>m;
    vector<ll> px(m+1), py(m+1), opx(m+1), opy(m+1), is_x(m+1),is_y(m+1); // 0 -> + / 1 -> -
    ll a1 = 1, a2=2;
    is_x[0] = 1;
    is_y[0] = 1;
    rep(i,0,m){
        int op;cin>>op;
        if (op==1){
            swap(a1,a2);
            px[i+1] = py[i];
            py[i+1] = -px[i];
            a2 *= (-1);
        }else if(op==2){
            swap(a1,a2);
            px[i+1] = -py[i];
            py[i+1] = px[i];
            a1 *= (-1);
        }else if(op==3){
            ll p;cin>>p;
            px[i+1] += 2*p - px[i];
            py[i+1] = py[i];
            a1 *= (-1);
        }else{
            ll p;cin>>p;
            a2 *= (-1);
            px[i+1] = px[i];
            py[i+1] += 2*p - py[i];
        }

        if (a1<0){
            opx[i+1] = 1; 
        }
        if (a2<0){
            opy[i+1] = 1;
        }
        if (abs(a1)==1) is_x[i+1] = 1;
        if (abs(a2)==2) is_y[i+1] = 1;
    }

    ll q;cin>>q;
    vector<ll> ansx(q),ansy(q);
    rep(i,0,q){
        ll k,l;cin>>k>>l; // k ... 何番目の後か l ... 駒
        l--;
        if (opx[k]==0){
            if (is_x[k]==1){
                ansx[i] = x[l] + px[k]; 
            }else{
                ansx[i] = y[l] + px[k]; 
            }
        }else{
            if (is_x[k]==1){
                ansx[i] = -x[l] + px[k];
            }else{
                ansx[i] = -y[l] + px[k]; 
            }
            
        }

        if (opy[k]==0){
            if (is_y[k]==1){
                ansy[i] = y[l] + py[k];
            }else{
                ansy[i] = x[l] + py[k];
            }
            
        }else{
            if (is_y[k]==1){
                ansy[i] = -y[l] + py[k];
            }else{
                ansy[i] = -x[l] + py[k];
            }
            
        }
    }
    rep(i,0,q){
        cout<<ansx[i]<<" "<<ansy[i]<<endl;
    }
}