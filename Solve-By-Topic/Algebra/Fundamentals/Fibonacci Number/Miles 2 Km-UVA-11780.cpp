#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=1009;
float ans[MX];
bool visited[MX];
vector<int>fib;

void inis()
{
    fib.push_back(1);
    fib.push_back(2);
    for(ll i=2;fib[i-1]<=MX;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
}

int main()
{
    inis();
    int n;
    while(cin>>n){
        if(n==0)break;
        float real=(float)n*1.6;
        if(visited[n]==false){
            visited[n]=true;
            int idx=upper_bound(fib.begin(),fib.end(),n)-fib.begin();
            if(fib[idx]>n)idx--;
            int fake=0;
            for(ll i=idx;i>=0;i--){
                if(fib[i]<=n){
                    fake+=fib[i+1];
                    n-=fib[i];
                }
            }
            float diff=abs(real-(float)fake);
            ans[n]=diff;
        }
        printf("%.2f\n",ans[n]);
    }
    return 0;
}
