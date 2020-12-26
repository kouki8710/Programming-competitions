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
    ll n,k;cin>>n>>k;
    vector<ll> p(n),c(n);
    rep(i,0,n){
        cin>>p[i];// next pos
        p[i]--;
    }

    rep(i,0,n){
        cin>>c[i];// score
    }

    ll ans = ll(-2e63);
    rep(i,0,n){
        vector<ll> seen(n), used;
        ll index = i;
        ll num = 0;
        
        
        while ((ll)used.size() < k){
            index = p[index];
            if (seen[index]==1) break;// indexは2回目の位置
            num += c[index];
            ans = max(num,ans);
            used.push_back(index);
            seen[index] = 1;
            
        }
        if ((ll)used.size()==k){
            continue;
        }
        ll bi = 0;
        rep(j,0,used.size()){
            if (used[j]==index){
                bi = j;
                break;
            }
        }
        
        ll sum = 0;
        ll cha = used.size() - bi;
        
        rep(j, bi, used.size()){
            sum += c[used[j]];
        }

        ll ss = (k - used.size()) / cha;
        if (ss==0){
            rep(j,bi, bi + (k - used.size() - ss*cha) ){
                num += c[used[j]];
                ans = max(ans,num);
            }
        }else{
            if (sum<=0){
                rep(j,bi, used.size() ){
                    num += c[used[j]];
                    ans = max(ans,num);
                }
            }else{
                num += sum*ss;
                ans = max(num,ans);
                rep(j, bi, bi + (k - used.size() - ss*cha) ){
                    num += c[used[j]];
                    ans = max(ans,num);
                }
            }

            
        }
        
        ans = max(num,ans);
    }
    cout<<ans<<endl;
}