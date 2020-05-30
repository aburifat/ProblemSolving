#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=4294967300;

vector<ll>F,M;

void inis()
{
    F.push_back(1);
    F.push_back(1);
    M.push_back(0);
    M.push_back(1);
    for(int i=2;F[i-1]<MX;i++){
        F.push_back(F[i-1]+F[i-2]);
        M.push_back(M[i-1]+F[i-1]);
    }
}

int main()
{
    inis();
    int n;
    while(cin>>n){
        if(n==(-1))break;
        cout<<M[n]<<" "<<(M[n]+F[n])<<endl;
    }
    return 0;
}

