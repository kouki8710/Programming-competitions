#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
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
#define NUM_MAX   100001
bool flag[NUM_MAX];
vector< int >prm;
ll N;
int ans = 0;
int K;
void eratosthenes(){
    if( N < 2 ) return;
    fill( flag, flag+NUM_MAX, 0 );
    int idx = 2;
    while( idx <= K ){
        while( flag[idx] ) idx++;
        if( idx > N ) break;
        prm.push_back( idx );
        for( int i = idx; i <= N; i += idx ) flag[i] = 1;
    }
    while( idx < N ){
        idx++;
        if( !flag[idx] ){
            prm.push_back( idx );
        }
    }
}
int l, r;
int main(){
    cin>>l>>r;
    N = sqrt(r)+2;// N 右のルート
    K = sqrt( N );// K Nのルート
    K++;
    eratosthenes();
    FOR( i, l, r+1 ){
        int X = i;
        int cnt = 0;
        REP( j, prm.size() ){
            while( X % prm[j] == 0 ){
                X /= prm[j];
                cnt++;
            }
        }
        if( X != 1 ) cnt++;
        REP( j, prm.size() ){
            if( cnt < prm[j] ) break;
            if( cnt == prm[j] ) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}