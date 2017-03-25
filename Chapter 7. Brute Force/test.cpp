#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstring>
using namespace std;

int T=100;
int i,j;

int main(){
//	freopen("test.in","r",stdin);
	freopen("test.in","w",stdout);
	
	ios::sync_with_stdio(false);
	srand(time(NULL));
	while(T--){
		cout<<rand()%6+1<<' '<<rand()%4+1<<'\n';
		for(i=0;i<4;++i){
			for(j=0;j<6;++j)
				cout<<rand()%15+1<<' ';
			cout<<'\n';
		}
	}
	return 0;
}
