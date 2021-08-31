#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin>>n;
	ll a[n+1];
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll msf=a[0],meh=0;
	ll s=0,start=0,end=0;
	for(int i=0;i<n;i++)
	{
		meh+=(meh+a[i]);
		if(msf<meh){
			msf = meh;
			start = s;
			end = i;
		}
		if(meh<0){
			meh=0;
			s=i+1;
		}
	}
	cout<<msf;
	return 0 ;

}