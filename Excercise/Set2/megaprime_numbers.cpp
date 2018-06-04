#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define END 10000000
#define START 2222222
#define STOP 7777777
#define MID 777777

ll MAX = (ll)sqrt(1e15);
vector<ll> primearray;
void sieve(){
    vector<bool> prime(MAX+1,true);
    for(ll i=2;i*i<=MAX;i++)
        if(prime[i])
            for(ll j=i*i;j<=MAX;j+=i)
                prime[j]=false;
    for(ll i=2;i<=MAX;i++)
        if(prime[i])
            primearray.push_back(i);
}
bool megaprime(ll N){
    ll dig = N%10;
    if(dig != 2 && dig != 3 && dig != 5 && dig != 7 )
        return false;
  return (N>10)?megaprime(N/10):true;
}
ll cmega(ll first,ll last,ll count=0){
    if(first>last) 
        return 0;
    vector<int> prime(last-first+1,true);
    for(ll i=0;i<primearray.size();i++){
        ll p = primearray[i];
        if(p*p>last) 
            break;
        for(ll j=max(p,(first+p-1)/p)*p;j<=last;j+=p)
                prime[j-first]=false;
    }
    for(ll i=first;i<=last;i++)
        if(prime[i-first] && megaprime(i))
            ++count;
    return count;
}
int main(){
 
    sieve();
    ll L,R,ans=0;
    cin >> L >> R;
    if(R<=MID){
        
        ans+=cmega(L,R);
    }else{
        if(L<=MID){
            
            ans+=cmega(L,MID);
            L=MID+1;
        }
        for( ll start=(L/END)*END+START,stop;start<=R;start+=END){
            if(megaprime(start)){
                stop  = start-START+STOP;
                
                ans+=cmega(max(L,start),min(R,stop));
            }
        }
    }
    cout<<ans<<endl;
}
