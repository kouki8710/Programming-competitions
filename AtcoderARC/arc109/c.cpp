//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define INFL 
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

char retu(int i){
    if (i==0){
        return 'R';
    }else if(i==1){
        return 'S';
    }else{
        return 'P';
    }
}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;cin>>n>>k;
    string s;cin>>s;
    vector<vector<int>> win(k,vector<int>(n));
    // 0 gu 1 tyoki 2 pa
    rep(j2,0,n){
        char zjan = s[j2];
        if (s[j2]=='R' && s[(j2+1)%s.size()]=='S'){
            win[0][j2] = 0;
        }else if(s[j2]=='R' && s[(j2+1)%s.size()]=='P'){
            win[0][j2] = 2;
        }else if(s[j2]=='S' && s[(j2+1)%s.size()]=='R'){
            win[0][j2] = 0;
        }else if(s[j2]=='S' && s[(j2+1)%s.size()]=='P'){
            win[0][j2] = 1;
        }else if(s[j2]=='P' && s[(j2+1)%s.size()]=='R'){
            win[0][j2] = 2;
        }else if(s[j2]=='P' && s[(j2+1)%s.size()]=='S'){
            win[0][j2] = 1;
        }else{
            if (s[j2]=='R'){
                win[0][j2] = 0;
            }else if(s[j2]=='S'){
                win[0][j2] = 1;
            }else{
                win[0][j2] = 2;
            }
            
        }
    }

    rep(i,1,k){
        rep(j,0,n){
            char before = s[j];
            char midium = s[(modpow(2,i,n)+j)%n];
            char s1 = retu(win[i-1][j]) ;
            char s2 = retu(win[i-1][(modpow(2,i,n)+j)%n]);
            
            if (s1=='R' && s2=='S'){
                win[i][j] = 0;
            }else if(s1=='R' && s2=='P'){
                win[i][j] = 2;
            }else if(s1=='S' && s2=='R'){
                win[i][j] = 0;
            }else if(s1=='S' && s2=='P'){
                win[i][j] = 1;
            }else if(s1=='P' && s2=='R'){
                win[i][j] = 2;
            }else if(s1=='P' && s2=='S'){
                win[i][j] = 1;
            }else{
                if (s1=='R'){
                    win[i][j] = 0;
                }else if(s1=='S'){
                    win[i][j] = 1;
                }else{
                    win[i][j] = 2;
                }
                
            }

        }
    }
    cout<<retu(win[k-1][0])<<endl;
}