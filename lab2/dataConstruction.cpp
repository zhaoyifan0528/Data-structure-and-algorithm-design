#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n;cin>>n;
	freopen("data.in","w",stdout);
	cout<<n<<endl;
	for(int i = 1;i <= n;++i){
		printf("%lld ",(long long)rand()*(long long)rand()/2);
	}
	return 0;
}
