#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)

int main(){
    while (1){
        string s;cin>>s;
        if (s=="#") break;
        int i=0,f=0, left=0,right=0;
        int ans = 0;
        int si = s.size();
        while (i<si){
            if (f==0){
                if (s[i]=='('){
                    left++;
                }else{
                    f=1;
                    right++;
                }
            }else{
                if (s[i]==')'){
                    right++;
                }else{
                    f=0;
                    int a = max(left,right);
                    int b = min(left,right);
                    if (a<=2*b){

                    }else{
                        ans += ceil(((double)a-(double)b*2)/2);
                    }
                    left=1;
                    right=0;
                }
            }
            i++;
        }
        int a = max(left,right);
        int b = min(left,right);
        if (a<=2*b){

        }else{
            ans += ceil(((double)a-(double)b*2)/2);
        }
        cout<<ans<<endl;
    }
}