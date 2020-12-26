
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)

int h,w,n;

int erase(vector<string>& mc){
    vector<vector<int>> me(h,vector<int>(w,0));
    //横
    rep(i,0,h){
        char color = '@';
        int num = 0;
        rep(j,0,w){
            if (mc[i][j]=='.') continue;
            if (color==mc[i][j]){
                num++;
            }else{
                if (num>=n){
                    rep(s,0,num){
                        me[i][j-s-1] = 1;
                    }
                }
                color = mc[i][j];
                num=1;
            }
        }
        if (num>=n){
            rep(s,0,num){
                me[i][w-1-s] = 1;
            }
        }
    }
    //縦
    rep(i,0,w){
        char color = '@';
        int num = 0;
        rep(j,0,h){
            if (mc[j][i]=='.') continue;
            if (color==mc[j][i]){
                num++;
            }else{
                if (num>=n){
                    rep(s,0,num){
                        me[j-s-1][i] = 1;
                    }
                }
                color = mc[j][i];
                num=1;
            }
        }
        if (num>=n){
            rep(s,0,num){
                me[h-1-s][i] = 1;
            }
        }
    }
    int num=0,num2 = 0;
    rep(i,0,h){
        rep(j,0,w){
            if (me[i][j]==1){
                mc[i][j]='.';
                num=1;
            }
            if (mc[i][j]=='.') num2++;
        }
    }
    if (num2==h*w){
        return 1;
    }
    if (num==0){
        return 0;
    }
    return 2;
}

void fall(vector<string>& mc){
    rep(i,0,w){
        if (mc[h-1][i]=='.'){
            int k = 0;
            rep(j,1,h){
                if (mc[h-1-j][i]!='.'){
                    mc[k++][i] = mc[h-1-j][i];
                    mc[h-1-j][i] = '.';
                }
            }
        }
    }
}





int main(){
    cin>>h>>w>>n;
    vector<string> m(h);
    rep(i,0,h){
        cin>>m[i];
    }
    vector<string> mc(h);
    rep(j,0,w){
        rep(i,0,h-1){
            if (m[i][j]=='.' && m[i+1][j]=='.') continue;
            rep(s,0,h){
                mc[s] = m[s];
            }
            swap(mc[i][j],mc[i+1][j]);
            
            fall(mc);
            while (1){
                int num = erase(mc);
                if (num==1){
                    cout<<"YES"<<endl;
                    return 0;
                }else if(num==0){
                    break;
                }
                fall(mc);
            }
        }
    }
    rep(j,0,h){
        rep(i,0,w-1){
            if (m[j][i]=='.' && m[j][i+1]=='.') continue;
            copy(m.begin(),m.end(),mc.begin());
            swap(mc[j][i],mc[j][i+1]);
            fall(mc);
            while (1){
                int num = erase(mc);
                if (num==1){
                    cout<<"YES"<<endl;
                    return 0;
                }else if(num==0){
                    break;
                }
                fall(mc);
            }
        }
    }
    cout<<"NO"<<endl;
}