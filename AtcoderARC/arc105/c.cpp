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
    int n,m;cin>>n>>m;
    vector<ll> w(n), l(m), v(m), array_n;
    rep(i,0,n) cin>>w[i];
    rep(i,0,m){
        ll l1,v1;cin>>l1>>v1;
        l[i] = l1;
        v[i] = v1;
    }
    ll max_w = *max_element(w.begin(), w.end());
    ll min_v = *min_element(v.begin(), v.end());
    ll max_l = *max_element(l.begin(), l.end());

    if (max_w > min_v){
        cout<<-1<<endl;
        return 0;
    }

    rep(i,0,n){
        array_n.push_back(i);
    }

    ll ans = (ll)2e61;

    do{
        rep(i, 0, 1<<n){
            vector<ll> seq(n);
            ll num = w[array_n[0]];
            ll f = 1 & (i>>0);
            int k = 0;
            rep(j, 1, n){
                if (f == (1 & (i>>j)) ){
                    num += w[array_n[j]];
                }else{
                    f = (1 & (i>>j));
                    seq[k++] = num;
                    num = w[array_n[j]];
                }
            }

            seq[k] = num;

            ll max_seq = *max_element(seq.begin(), seq.end());
            if (min_v < max_seq) continue;

            ll size = 0;
            rep(j,0,n){
                if (seq[j]!=0) size++;
            }

            ans = min(ans, ll(max_l * (size - 1) ) );

        }
    }while(next_permutation(array_n.begin(),array_n.end()));

    cout<<ans<<endl;

    rep(i,1,20){
        cout<< double(3802)/double(i) <<endl;
    }
}