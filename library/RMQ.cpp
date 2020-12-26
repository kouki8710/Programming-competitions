//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)

template <typename T>
struct RMQ {
    const T INF = numeric_limits<T>::max();
    int n; //葉の数
    vector<T> dat; //ノード
    RMQ(int n_) : n(), dat(n_ * 4, INF){
        int x = 1;
        while (n_ > x){
            x *= 2;
        }
        n = x;
    }

    void update(int i,T x){
        i += n - 1;
        dat[i] = x;
        while (i > 0){
            i = (i-1)/2; //parent
            dat[i] = min(dat[2*i+1],dat[2+i+2]);
        }
    }

    // the minumum element of [a,b)
    T query(int a, int b){
        return query_sub(a, b, 0, 0, n);
    }
    // k : 現在見ているノードの位置
    T query_sub(int a, int b, int k, int l, int r){
        if (r<=a || b<=l){
            return INF;
        } else if (a <= l && r <= b){
            return dat[k];
        } else {
            int vl = query_sub(a, b, 2*k+1, l, (l+r)/2);
            int vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }

    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}