#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for (ll i=(ll)(s);i<(ll)(n);i++)

int main(){
    ll l,r;cin>>l>>r;
    vector<ll> is_prime(100000,1),num_lr(r-l+10),num2(100000),num_lr_prime(r-l+10),num22(100000);//num22 1~100000の素因数の個数 num2 値 
    rep(i,0,r-l+1){
        num_lr[i] = l+i;
    }
    rep(i,0,100000){
        num2[i] = i;
    }
    is_prime[0]=0;is_prime[1]=0;
    rep(i,2,100000){
        if (is_prime[i]==0){
            if (num2[i]!=1){
                num22[i] += num22[num2[i]];
                num2[i] = 1;
            }
            continue;
        }
        num22[i] = 1;
        for (int j=i*2;j<100000;j+=i){
            is_prime[j] = 0;
            num2[j]/=i;
            num22[j]++;
        }
        for (int j=(i+l-1)/i*i;j<=r;j+=i){
            num_lr[j-l]/=i;
            num_lr_prime[j-l]++;
        }
    }
    rep(i,0,r-l+1){
        if (num_lr[i]!=1){
            num_lr_prime[i]+=num_lr_prime[num_lr[i]];
        }
    }
    
    ll ans = 0;
    rep(i,0,r-l+1){
        if (is_prime[num_lr_prime[i]]==1){
            ans++;
        }
    }
    cout<<ans<<endl;
}