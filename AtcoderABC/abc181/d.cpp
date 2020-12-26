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
    string s;cin>>s;
    vector<int> num(10);
    rep(i,0,s.size()){
        num[s[i]-'0']++;
    }
    int start = 0,end=0;
    if (s.size()==1){
        start = 1;
        end = 10;
    }else if(s.size()==2){
        start = 10;
        end = 100;
    }else if(s.size()>=3){
        start = 100;
        end = 1000;
    }
    rep(i,start,end){
        int k = i;
        if (i%8!=0) continue;
        vector<int> b(10);
        while (k>0){
            int a = k%10;
            b[a]++;
            k/=10;
        }
        int f = 1;
        rep(i,0,10){
            if (b[i]>num[i]){
                f = 0;
                break;
            }
        }
        if (f==1){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}