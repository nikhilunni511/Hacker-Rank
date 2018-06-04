#include <bits/stdc++.h>
using namespace std;


int main()
{
	int g,n,sum;
	cin>>g;
	for(int i=0;i<g;i++){
		cin>>n;
		int p[n];
		sum=0;
		for(int j=0;j<n;j++){
			cin>>p[j];
			if(p[j]%2==0)
				p[j]--;
			else
				p[j]++;
			sum=sum^p[j];

		}
		if(sum==0)
			cout<<"L\n";
		else
			cout<<"W\n";
	}
}
