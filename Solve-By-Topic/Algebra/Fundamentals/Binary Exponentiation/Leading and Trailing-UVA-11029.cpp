#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int binExp(int base,int power) {
    int mod=1000;
    base%=mod;
    int result=1;
    while(power>0) {
        if(power&1)
            result=(result*base)%mod;
        base=(base*base)%mod;
        power>>=1;
    }
    return result;
}

int main() {
    int t;
    cin>>t;
    int base,power;
    while(t--) {
        cin>>base>>power;
        int tails=binExp(base,power);
        double p=(double)power*log10(base);
        p=p-floor(p);
        double lead=pow(10,p)*100.0;
        printf("%03d...%03d\n",(int)lead,tails);
    }
    return 0;
}
