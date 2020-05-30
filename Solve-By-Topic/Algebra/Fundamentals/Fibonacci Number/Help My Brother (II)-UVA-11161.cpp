#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl printf("\n")

const int base=1e9;
typedef vector<int>bigInt;

void Set(bigInt &a)
{
    while(a.size()>1&&a.back()==0)
        a.pop_back();
}
void Print(bigInt a) {
    Set(a);
    printf("%d", (a.size()==0) ? 0 : a.back());
    for(int i=(a.size()-2); i>=0; i--){
        cout<<" : WTF :"<<i<<"-> : ";
        printf("%09d",a[i]);
    }
}
bigInt toBigInt(string st) {
    bigInt ans;
    if(st.size()==0) {
        ans.push_back(0);
        return ans;
    }
    if(st[0]=='-') {
        ans.push_back(0);
        return ans;
    }
    while(st.size()%9!=0)
        st='0'+st;
    for(int i=0; i<st.size(); i+=9) {
        int num=0;
        for(int j=i; j<i+9; j++)
            num=(num*10)+(st[j]-'0');
        ans.insert(ans.begin(),num);
    }
    Set(ans);
    return ans;
}
bigInt toBigInt(ll x) {
    string s="";
    if(x<0) {
        s="0";
        return toBigInt(s);
    }
    while(x>0) {
        s=char(x%10+'0')+s;
        x/=10;
    }
    return toBigInt(s);
}
bigInt toBigInt(int x) {
    return toBigInt((ll)x);
}
bool operator < (bigInt a, bigInt b) {
    if(a.size()!=b.size())
        return (a.size()<b.size());
    for(ll i=(a.size()-1); i>=0; i--) {
        if(a[i]!=b[i]) {
            return (a[i]<b[i]);
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
bigInt operator + (bigInt a, bigInt b) {
    bigInt ans;
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
    Set(ans);
    return ans;
}
bigInt operator - (bigInt a, bigInt b) {
    bigInt ans;
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
    Set(ans);
    return ans;
}
bigInt operator * (bigInt a, bigInt b) {
    bigInt ans;
    ans.assign(a.size()+b.size(),0);
    for(int i=0; i<a.size(); i++) {
        ll carry= 0ll; ///(Zero-L-L)
        for(int j=0; j<b.size()||carry>0; j++) {
            ll sum=ans[i+j]+carry+(ll)a[i]*(j<b.size()?(ll)b[j]:0ll); ///(Zero-L-L)
            ans[i+j]=sum%base;
            carry=sum/base;
        }
    }
    Set(ans);
    return ans;
}
bigInt operator / (bigInt a, bigInt b) {
    if(b==toBigInt(0)) {
        return b;
    }
    bigInt ans,cur;
    for(int i=(a.size()-1); i>=0; i--) {
        cur.insert(cur.begin(),a[i]);
        int x=0,L=0,R=base;
        while(L<=R) {
            int mid=(L+R)>>1;
            if(b*toBigInt(mid)>cur) {
                x=mid;
                R=mid-1;
            } else {
                L=mid+1;
            }
        }
        cur=cur-toBigInt(x-1)*b;
        ans.insert(ans.begin(),x-1);
    }
    Set(ans);
    return ans;
}


const int MX=1509;

bigInt fib[MX],sum[MX];

void inis()
{
    fib[0]=toBigInt(0);
    fib[1]=toBigInt(1);
    for(int i=2;i<=MX;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    sum[0]=fib[0];
    for(int i=1;i<=MX;i++){
        sum[i]=sum[i-1]+fib[i];
    }
}

int main()
{
    inis();
    int n;
    ll t=1;
    while(cin>>n)
    {
        if(n==0)break;
        bigInt ans=sum[n]+sum[n-1];
        ans=ans-toBigInt(1);
        ans=(ans/toBigInt(2));
        cout<<"Set "<<t++<<":\n";
        Print(ans);nl;
    }
    return 0;
}

