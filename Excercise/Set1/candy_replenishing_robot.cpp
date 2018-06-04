#include <bits/stdc++.h>

using namespace std;

int main(){
    int m,n;
    int t;
    int c[100],s=0;
    cin >> n >> t;
    m=n;
    for(int i=1;i<t;i++)
    {
        cin>>c[i];
        m-=c[i];
        if(m<5)
        {
            s+=n-m;
            m=n;
            
        }
    
    }
    cout<<s;
    // your code goes here
    return 0;
}
