#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl printf("\n");

struct fibNum{
    vector<int>val;
    int siz;
};

void Set(fibNum &a)
{
    int len=a.siz;
    while(a.val.size()>1&&a.val[0]==0){
        a.val.erase(a.val.begin());
        a.siz--;
    }
}

fibNum toFibNum(string s)
{
    fibNum a;
    a.siz=s.size();
    for(int i=0;i<a.siz;i++){
        a.val.push_back((s[i]-'0'));
    }
    Set(a);
    return a;
}

void Print(fibNum a)
{
    for(int i=0;i<a.siz;i++){
        cout<<a.val[i];
    }
}

fibNum operator + (fibNum a, fibNum b)
{
    fibNum ans;
    int carry=0;
    if(a.siz<b.siz){
        int p=b.siz-a.siz;
        while(p--){
            a.val.insert(a.val.begin(),0);
            a.siz++;
        }
    }else if(b.siz<a.siz){
        int p=a.siz-b.siz;
        while(p--){
            b.val.insert(b.val.begin(),0);
            b.siz++;
        }
    }
    for(int i=0;i<max(a.siz,b.siz);i++){
        if(i<a.siz)
            carry+=a.val[i];
        if(i<b.siz)
            carry+=b.val[i];
        ans.val.push_back(carry);
        carry=0;
    }
    ans.siz=ans.val.size();
    Set(ans);
    return ans;
}

void relax(fibNum &a)
{
    bool ct=false;
    for(int i=(a.siz-1);i>=0;i--){
        if(a.val[i]>0){
            if(ct){
                ct=false;
                int trans=min(a.val[i],a.val[i+1]);
                a.val[i]-=trans;
                a.val[i+1]-=trans;
                if(i==0){
                    a.val.insert(a.val.begin(),trans);
                    a.siz++;
                    i++;
                }else{
                    a.val[i-1]+=trans;
                }
            }else{
                if(a.val[i]>1){
                    int v=a.val[i];
                    if(v%2==0){
                        a.val[i]=0;
                    }else{
                        a.val[i]=1;
                        ct=true;
                    }
                    if(i==0){
                        a.val.insert(a.val.begin(),(v/2));
                        a.siz++;
                        i++;
                    }else{
                        a.val[i-1]+=(v/2);
                    }
                    if(i<(a.siz-2)){
                        a.val[i+2]+=(v/2);
                    }else if(i<(a.siz-1)){
                        a.val[i+1]+=(v/2);
                    }
                }else{
                    ct=true;
                }
            }
        }else{
            ct=false;
        }
    }
    Set(a);
}

bool what(fibNum a)
{
    int len=a.siz;
    bool ck=false;
    for(int i=0;i<len;i++){
        if(a.val[i]>1)return true;
        if(a.val[i]>0){
            if(ck)return true;
            else{
                ck=true;
            }
        }else{
            ck=false;
        }
    }
    return false;
}

int main()
{
    string s;
    int c=0;
    while(cin>>s){
        fibNum a,b;
        a=toFibNum(s);
        cin>>s;
        b=toFibNum(s);
        a=a+b;
        bool ck=true;
        while(ck){
            relax(a);
            ck=what(a);
        }
        if(c){
            nl;
        }
        else c++;
        Print(a);nl;
    }
}
