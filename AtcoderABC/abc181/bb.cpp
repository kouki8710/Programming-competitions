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
vector< ll > num;
ll p;
void yakusu( ll N ){
    ll K = sqrt( N )+1;
    FOR( i, 1, K ){
        if( N % i == 0 ){
            num.push_back( i );
            num.push_back( N/i );
        }
    }
}
int main(){
    while( 1 ){
        cin>>p;
        if( p == 0 ) break;
        ll ans = mod*mod;
        num.clear();
        yakusu( p );
        sort( num.begin(), num.end() );
        REP( i, num.size() ){
            ll X = p/num[i];
            REP( j, num.size() ){
                if( X < num[j] ) break;
                if( X % num[j] == 0 ){
                    ll Y = X/num[j];
                    //printf("%lld %lld %lld\n", num[i], num[j], Y);
                    ans = min( ans, num[i]+num[j]+Y );
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}