#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 100009

int arr[MX];
vector<ll>P(MX,-1); ///parent of i is P[i]
stack<ll>st;

void CarTree(ll n)
{
    for(ll i=0; i<n; i++){
        ll last=-1;
        while(!st.empty()&&arr[st.top()]>=arr[i]){
            last=st.top();
            st.pop();
        }
        if(!st.empty()){
            P[i]=st.top();
        }if(last>=0){
            P[last]=i;
        }
        st.push(i);

    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    CarTree(n);
    for(int i=0; i<n;i++){
        cout<<"Parent of "<<arr[i]<<" is : "<<arr[P[i]]<<endl;
    }
    return 0;
}

/* input:

10
2 4 3 1 2 5 6 7 4 3

*/

/* output:

Parent of 2 is : 1
Parent of 4 is : 3
Parent of 3 is : 2
Parent of 1 is : 0
Parent of 2 is : 1
Parent of 5 is : 4
Parent of 6 is : 5
Parent of 7 is : 6
Parent of 4 is : 3
Parent of 3 is : 2

*/
