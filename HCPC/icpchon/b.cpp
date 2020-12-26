#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define FOR(i,a,b)   for(ll i = (a); i < (b); i++ )
#define REP(i, n)    FOR(i,0,n)
typedef pair< int, int >   cp2;
typedef pair< int, cp2 >   cp3;
#define fi first
#define se second
#define sec  se.fi
#define thr  se.se
const ll mod = 1000000007;
//              123456789
///////////////////////////////////////////////
//
//
///////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////
#define NUM_MAX   32000000
//                 1234567
bool *flag;
vector< int >prm;
ll p;
ll N;
ll S = 0;
ll K;
ll X;
void eratosthenes(){
    if( N < 2 ) return;
    fill( flag, flag+NUM_MAX, 0 );
    int idx = 2;
    while( idx <= K ){
        while( flag[idx] ) idx++;
        if( idx > N ) break;
        prm.push_back( idx );
        for( int i = idx; i <= N; i += idx ) flag[i] = 1;
        S++;
    }
    while( idx < N ){
        idx++;
        if( !flag[idx] ){
            prm.push_back( idx );
            S++;
        }
    }
}

vector<ll> yakusuu(ll n ){
    vector<ll> yaku;
    FOR(i,1,sqrt(n)+2){
        if (n%i==0){
            if (i<n/i){
                yaku.push_back(n/i);
                yaku.push_back(i);
            }else if(i==n/i){
                yaku.push_back(i);
            }
        }
    }
    return yaku;
}

int main(){
    flag = (bool*)malloc(sizeof(bool)*NUM_MAX);
    N = NUM_MAX;
    K = sqrt( N )+1;
    while( 1 ){
        ll dist[3];
        vector< ll >q;
        vector< ll >num;
        set<ll>s;
        cin>>p;
        ll kkk = p;
        kkk++;
        X = p;
        if( p == 0 ) break;
        
        // q.push_back( 1 );
        // REP( i, S ){
        //     while( p % prm[i] == 0 ){
        //         q.push_back( prm[i] );
        //         p /= prm[i];
        //     }
        // }
        // if( p != 1 ) q.push_back( p );
        // num.push_back( 1 );
        // ll ans = mod*mod;
        // REP( i, q.size() ){
        //     ll idx_num = num.size();
        //     REP( j, idx_num ){
        //         ll temp = q[i]*num[j];
        //         if( s.find(temp) == s.end() ){
        //             s.insert( temp );
        //             num.push_back( temp );
        //         }
        //     }
        // }
        // REP( i, num.size() ){
        //     dist[0] = num[i];
        //     ll temp = X / dist[0];
        //     REP( j, num.size() ){
        //         if( temp < num[j] ) break;
        //         if( temp % num[j] == 0){
        //             dist[1] = num[j];
        //             dist[2] = temp/num[j];
        //         }
        //         ans = min( ans, dist[0]+dist[1]+dist[2] );
        //         //printf("***%lld %lld %lld\n",dist[0], dist[1], dist[2]);
        //     }
        // }
        vector<ll> b = yakusuu(kkk-1);
        ll n1=0,n2=0,n3=0;
        ll ans2 = mod*mod;
        FOR(i,0,b.size()){
            FOR(j,0,b.size()){
                if (i<=j && kkk-1>=b[i]*b[j] && (kkk-1)%b[i]==0 &&(kkk-1)/b[i]%b[j]==0){
                    if (ans2<(kkk-1)/b[i]/b[j]+b[i]+b[j]){
                        ans2 = (kkk-1)/b[i]/b[j]+b[i]+b[j];
                    }
                    ans2 = min(ans2,(ll)();
                }
            }
        }
        cout<<ans2<<endl;    
    }
    return 0;
}
