#include<iostream>
#include<cstring>
#define N 401
#define M 100000
using namespace std;

int n;
bool b[1000];

void DFS(int n){
	if(n0000)
		DFS(n+1);
	cout<<n<<endl;
}

int main(){
//	freopen("test.out","r",stdin);
//	freopen("test.in","w",stdout);

	ios::sync_with_stdio(false);
	DFS(1);
/*	
	memset(b,0,sizeof(b));
	cin>>n;
	while(cin>>n)
		if(!b[n])
			b[n]=1;
		else
			cout<<"Wrong!\n";
/*	cout<<N<<' '<<(N+1)*N/2<<'\n';
	for(int i=1;i<=N;++i)
		for(int j=i+1;j<=N;++j)
			cout<<i<<' '<<j<<'\n';*/
	return 0;
}

