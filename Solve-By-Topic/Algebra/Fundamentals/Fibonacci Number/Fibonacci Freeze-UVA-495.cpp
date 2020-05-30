#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl printf("\n")

///big integer template start
const int base = 1e9;
struct bigInt {
    vector<int>v;
    char s='+';
};
void Set(bigInt &a) {
    while(a.v.size()>1&&a.v.back()==0)
        a.v.pop_back();
    if(a.v.size()==1&&a.v[0]==0)
        a.s='+';
}
void Print(bigInt a) {
    Set(a);
    if(a.s=='-'&&!(a.v.size()==1&&a.v[0]==0))
        printf("-");
    printf("%d", (a.v.size()==0) ? 0 : a.v.back());
    for(int i=(a.v.size()-2); i>=0; i--)
        printf("%09d",a.v[i]);
}
bigInt toBigInt(string st) {
    bigInt ans;
    if(st[0]=='-') {
        ans.s='-';
        st.erase(st.begin());
    }
    if(st.size()==0) {
        ans.v.push_back(0);
        return ans;
    }
    while(st.size()%9!=0)
        st='0'+st;
    for(int i=0; i<st.size(); i+=9) {
        int num=0;
        for(int j=i; j<i+9; j++)
            num=(num*10)+(st[j]-'0');
        ans.v.insert(ans.v.begin(),num);
    }
    Set(ans);
    return ans;
}
bigInt toBigInt(char c[]) {
    string s="";
    for(int i=0; i<strlen(c); i++)
        s=s+c[i];
    return toBigInt(s);
}
bigInt toBigInt(ll x) {
    string s="";
    bool ck=false;
    if(x<0) {
        ck=true;
        x=(-1)*x;
    }
    while(x>0) {
        s=char(x%10+'0')+s;
        x/=10;
    }
    if(ck)
        s='-'+s;
    return toBigInt(s);
}
bigInt toBigInt(int x) {
    return toBigInt((ll)x);
}
bool operator < (bigInt a, bigInt b) {
    if(a.s!=b.s) {
        if(a.s=='-') {
            return true;
        } else
            return false;
    }
    if(a.v.size()!=b.v.size())
        return (a.v.size()<b.v.size());
    for(ll i=(a.v.size()-1); i>=0; i--) {
        if(a.v[i]!=b.v[i]) {
            return (a.v[i]<b.v[i]);
        }
    }
    return false;
}
bool operator > (bigInt a, bigInt b) {
    return b<a;
}
bool operator == (bigInt a, bigInt b) {
    return (!(a<b)&&!(b<a));
}
bool operator <= (bigInt a, bigInt b) {
    return (a<b||a==b);
}
bool operator >= (bigInt a, bigInt b) {
    return (b<a||a==b);
}
bigInt max(bigInt a, bigInt b) {
    if(a>b)
        return a;
    return b;
}
bigInt min(bigInt a, bigInt b) {
    if(a<b)
        return a;
    return b;
}
vector<int> Plus(vector<int> a, vector<int> b) {
    vector<int>ans;
    int carry=0;
    for(int i=0; i<max(a.size(),b.size()); i++) {
        if(i<a.size())
            carry+=a[i];
        if(i<b.size())
            carry+=b[i];
        ans.push_back(carry%base);
        carry/=base;
    }
    if(carry)
        ans.push_back(carry);
    return ans;
}
vector<int> Minus(vector<int> a, vector<int> b) {
    vector<int>ans;
    int carry=0;
    for(int i=0; i<a.size(); i++) {
        carry+=a[i]-(i<b.size()?b[i]:0);
        if(carry<0) {
            ans.push_back(carry+base);
            carry=-1;
        } else {
            ans.push_back(carry);
            carry=0;
        }
    }
    return ans;
}
bigInt operator + (bigInt a, bigInt b) {
    bigInt ans;
    if(a.s==b.s) {
        ans.s=a.s;
        ans.v=Plus(a.v,b.v);
    } else {
        bigInt c;
        c.s=a.s;
        c.v=b.v;
        if(a<c) {
            ans.s=b.s;
            ans.v=Minus(b.v,a.v);
        } else {
            ans.s=a.s;
            ans.v=Minus(a.v,b.v);
        }
    }
    Set(ans);
    return ans;
}


bigInt fib[5009];

void inis()
{
    fib[0]=toBigInt(0);
    fib[1]=toBigInt(1);
    for(int i=2;i<=5000;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
}

int main() {
    inis();
    int n;
    while(cin>>n)
    {
        cout<<"The Fibonacci number for "<<n<<" is ";
        Print(fib[n]);nl;
    }
    return 0;
}

