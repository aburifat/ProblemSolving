/*** Bismillahir Rahmanir Rahim ***/

#include<bits/stdc++.h>
using namespace std;

/*** Team_Excalibur ***/
/*** A.R.M.Al.Hasib - elvengard ***/

#define     ins              insert
#define     pub              push_back
#define     pob              pop_back
#define     ll               long long int
#define     ull              unsigned long long int
#define     max3(a,b,c)      max(a,max(b,c))
#define     max4(a,b,c,d)    max(max3(a,b,c),d)
#define     min3(a,b,c)      min(a,min(b,c))
#define     min4(a,b,c,d)    min(a,min3(b,c,d))
#define     MOD              1000000007
#define     MAX              1000000000000014
#define     MIN              -100000000000014
#define     INF              1e5 //1e5==10000
#define     EPS              1e-8
#define     PI               (2*acos(0.0))
#define     all(v)           v.begin(),v.end()
#define     mii              map<int,int>
#define     mll              map<ll,ll>
#define     pii              pair<int,int>
#define     pll              pair<ll,ll>
#define     mpii             map<pii,int>
#define     mpll             map<pll,ll>
#define     vi               vector<int>
#define     vl               vector<ll>
#define     vpi              vector<pii>
#define     vpl              vector<pll>
#define     si               set<int>
#define     sl               set<ll>
#define     siit             set<int>::iterator
#define     slit             set<long long>::iterator
#define     msi              multiset<int>
#define     msl              multiset<ll>
#define     msiit            multiset<int>::iterator
#define     mslit            multiset<long long>::iterator
#define     frsit(it,myset)  for (it=myset.begin(); it!=myset.end(); ++it)
///         use *it as the loop variable for set iteration..
#define     fast             ios_base::sync_with_stdio(0);cin.tie(0)
#define     F                first
#define     S                second
#define     mem(a,v)         memset(a,v,sizeof(a))
#define     mp               make_pair
#define     sq(x)           (x)*(x)
#define     dis(x1, y1, x2, y2) sqrt(sq(x1-x2)+sq(y1-y2))
#define     foi              freopen("input.txt","r",stdin);
#define     foo              freopen("output.txt","w",stdout);
#define     check            printf("check")
#define     nl               printf("\n")
#define     left(x)          ((x) << 1)
#define     right(x)         (((x) << 1) + 1)
#define     dbg(x)           cout << #x << " = " << x << endl
#define     gcd(a,b)         __gcd(a,b)
#define     lcm(a,b)         (a/gcd(a,b))*b
#define     fri(i,n)         for(int i=0;i<n;i++)
#define     frl(i,n)         for(ll i=0;i<n;i++)
#define     frir(i,n)        for(int i=n-1;i>=0;i--)
#define     frlr(i,n)        for(ll i=n-1;i>=0;i--)
#define     wh(n)            while(n--)
#define     fxd(i,x)         std::fixed <<std::setprecision(i)<<(x)
#define     onesi(n)         __builtin_popcount(n)
#define     onesll(n)        __builtin_popcountll(n)

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
///in 10^7, there are 22 pprimes and in 10^20, there are one more.
ll pprime[] = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991, 1111111111111111111};

#define bug printf("debug\n");
#define br puts("");

template<typename t>
t abs(t a)
{
    if(a>=0)
        return a;
    return -a;
}
template<typename t>
t dgtsum(t n)
{
    return n? dgtsum(n/10) + n%10 : 0;
}

/*** End Of Template ***/

/*** Start of Math Functions ***/

///sieve method to generate primes

bitset<10000010>bs;
ll ss;
vl primes;

void sieve(ll ub)
{
    ss=ub+1;
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2; i<=ss; i++){
        if(bs[i]){
            for(ll j=i*i; j<=ss; j+=i){
                bs[j]=0;
            }
            primes.pub(i);
        }
    }
}

bool isPrime(ll n)
{
    if(n<=ss)return bs[n];
    for(ll i=0; i<primes.size(); i++)
        if(n%primes[i]==0)return false;
    return true;
}

///end

///the list of prime factors of a number return in a vector

vl primeFactors(ll n)
{
    vl factors;
    ll PF_idx=0, PF=primes[PF_idx];
    while(PF*PF<=n){
        while(n%PF==0){
            n/=PF;
            factors.pub(PF);
        }
        PF=primes[++PF_idx];
    }
    if(n!=1)factors.pub(n);
    return factors;
}

///end

///finding the number of prime factors of number n

ll numPF(ll n)
{
    ll PF_idx=0, PF=primes[PF_idx], ans=0;
    while(PF*PF<=n){
        while(n%PF==0){
            n/=PF;
            ans++;
        }
        PF=primes[++PF_idx];
    }
    if(n!=1)ans++;
    return ans;
}

///end

///finding number of different prime factors of number n

ll numDiffPF(ll n)
{
    ll PF_idx=0, PF = primes[PF_idx], ans=0;
    while(PF*PF<=n){
        if(n%PF==0)ans++;
        while(n%PF==0)n/=PF;
        PF=primes[++PF_idx];
    }
    if(n!=1)ans++;
    return ans;
}

///end

///finding sum of prime factors of number n

ll sumPF(ll n)
{
    ll PF_idx=0, PF=primes[PF_idx], ans=0;
    while(PF*PF<=n){
        while(n%PF==0){
            n/=PF;
            ans+=PF;
        }
        PF=primes[++PF_idx];
    }
    if(n!=1)ans+=n;
    return ans;
}

///end

///finding number of divisors of number n

ll numDiv(ll n)
{
    ll PF_idx=0, PF=primes[PF_idx], ans=1;
    while(PF*PF<=n){
        ll power=0;
        while(n%PF==0){
            n/=PF;
            power++;
        }
        ans*=(power+1);
        PF=primes[++PF_idx];
    }
    if(n!=1)ans*=2;
    return ans;
}

///end

///finding the sum of divisors of number n

ll sumDiv(ll n)
{
    ll ans=1;
    for(ll i=0;primes[i]<=n;i++)
    {
        if(n%primes[i]==0)
        {
            ll power=1;
            while(n%primes[i]==0)
            {
                n/=primes[i];
                power++;
            }
            ans*=(pow(primes[i],power)-1)/(primes[i]-1);
        }
    }
    return ans;
}

///end

///finding number of relative primes with in range n

ll EulerPhi(ll n)
{
    ll PF_idx=0, PF=primes[PF_idx], ans=n;
    while(PF*PF<=n){
        if(n%PF==0)ans-=(ans/PF);
        while(n%PF==0)n/=PF;
        PF=primes[++PF_idx];
    }
    if(n!=1)ans-=(ans/n);
    return ans;
}

///end

///solving linear equation

ll lin_x, lin_y, lin_d;

void extEuclid(ll lin_a, ll lin_b)
{
    if(lin_b==0){
        lin_x=1; lin_y=0; lin_d=lin_a; return;
    }
    extEuclid(lin_b, lin_a%lin_b);
    ll lin_x1=lin_y;
    ll lin_y1=lin_x-(lin_a/lin_b)*lin_y;
    lin_x=lin_x1;
    lin_y=lin_y1;
}

void linEqn(ll lin_a,ll lin_b,ll lin_c)
{
    extEuclid(lin_a,lin_b);
    ll lin_v=lin_c/gcd(lin_a,lin_b);
    ll lin_xt=(lin_b/lin_d);
    ll lin_yt=(lin_a/lin_d);
    lin_x*=lin_v;
    lin_y*=lin_v;
    lin_d*=lin_v;
    if(lin_x>lin_y){
        while(lin_y<0){
            lin_x-=lin_xt;
            lin_y+=lin_yt;
        }
    }
    else{
        while(lin_x<0){
            lin_x+=lin_xt;
            lin_y-=lin_yt;
        }
    }
}

///end

///finding numDiffPF of a lot of numbers within range n

ll numDiffPFs[10000010];
void modSieve(ll n)
{
    memset(numDiffPFs, 0, n);
    for(ll i=2; i<n; i++){
        if(numDiffPFs[i]==0)
        {
            for(ll j=i; j<n; j+=i){
                numDiffPFs[j]++;
            }
        }
    }
}

///end

///(a+b-c)%s=((a%s)+(b%s)-(c%s)+s)%s
///(a*b)%s=((a%s)*(b*s))%s
///(a^b)%s=(((a^(b/2))%s)*((a^(b/2))%s))%s //here b is positive

/*** End of math functions ***/

int main()
{
    fast;

    return 0;
}

/*** Alhamdulillah ***/
/*** Team_Excalibur ***/
/*** University of Barisal, Bangladesh ***/
