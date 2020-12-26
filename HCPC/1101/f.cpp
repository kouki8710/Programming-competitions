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
int N;
int x,y,z;
cp3 box[112];
int ans;
bool inside[112];
priority_queue< cp3 >pq;

int dfs( int idx, int sum ){
    if( idx == N ) return sum;
    int size = box[idx].fi*box[idx].sec*box[idx].thr;
    int res = mod;
    //外置きパターン
    if( sum + size < ans ){
        inside[idx] = true;
        res = min( res, dfs( idx+1, sum+size ) );
        inside[idx] = false;
    }
    //入れるパターン
    for( ll j = idx-1; j >= 0; j-- ){
        if( inside[j] ){
            if( box[idx].fi < box[j].fi && box[idx].sec < box[j].sec && box[idx].thr < box[j].thr ){
                inside[idx] = true;
                inside[j] = false;
                res = min( res, dfs( idx+1, sum ) );
                inside[idx] = false;
                inside[j] = true;
            }
        }
    }
    //cout<<"***"<<res<<endl;
    return res;
}

int main(){
    while( 1 ){
        fill( inside, inside+112, false );
        ans = 0;
        cin>>N;
        if( N == 0 ) break;
        REP( i, N ){
            cin>>x>>y>>z;
            if( y > x ) swap( x, y );
            if( z > y ) swap( y, z );
            if( y > x ) swap( x, y );
            box[i] = cp3( x, cp2(y, z) );
        }
        sort( box, box+N, greater<cp3>() );
        REP( i, N ){
            for( ll j = i-1; j >= 0; j-- ){
                if( inside[j] ){
                    if( box[i].fi < box[j].fi && box[i].sec < box[j].sec && box[i].thr < box[j].thr ){
                        inside[i] = true;
                        inside[j] = false;
                        break;
                    }
                }
            }
            if( !inside[i] ){
                ans += box[i].fi*box[i].sec*box[i].thr;
                inside[i] = true;
            }
        }
        fill( inside, inside+112, false );
        ans = min( ans, dfs( 0 , 0 ) );
        cout<<ans<<endl;
    }
    return 0;
}