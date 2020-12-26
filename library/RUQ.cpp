//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)


template <typename T>
struct RUQ {
    const T INF_SEG = numeric_limits<T>::max();
    int n; //葉の数
    vector<T> dat, lazy; //ノード
    RUQ(int n_) : n(), dat(n_ * 4, INF_SEG), lazy(n_ * 4, INF_SEG){
        int x = 1;
        while (n_ > x){
            x *= 2;
        }
        n = x;
    }

    void set(int i, T x) { dat[i + n - 1] = x; }
    
    void build() {
        for (int k = n - 2; k >= 0; k--){
            dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }

    void eval(int k){
        if (lazy[k]==INF_SEG) return;
        if (k<n-1){
            lazy[k * 2 + 1] = min(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = min(lazy[k * 2 + 2], lazy[k]);
        }
        dat[k] = min(dat[k],lazy[k]);
        lazy[k] = INF_SEG;
    }

    void update(int a, int b, T x){
        update_sub(a, b, x, 0, 0, n);
    }

    void update_sub(int a, int b, T x, int k, int l, int r){
        eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = x;
            eval(k);
        } else if (a < r && l < b) {                    // 一部区間が被る時
            update_sub(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update_sub(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    // the minumum element of [a,b)
    T query(int a, int b){
        return query_sub(a, b, 0, 0, n);
    }
    // k : 現在見ているノードの位置
    T query_sub(int a, int b, int k, int l, int r){
        eval(k);
        if (r<=a || b<=l){
            return INF_SEG;
        } else if (a <= l && r <= b){
            return dat[k];
        } else {
            int vl = query_sub(a, b, 2*k+1, l, (l+r)/2);
            int vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }

    }
};