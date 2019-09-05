#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;

int main(){
	int n,a,b,roupa[20],low; 
	cin>>n>>a>>b; 
	low=min(a,b);
	fr(i,n)
		cin>>roupa[i]; 
	int i,j;
	int sum=0,ok=1;
	if(n==1){
		if(roupa[0]==2)
			cout<<low<<endl; 
		else 
			cout<<"0"<<endl;
	}
	else{
		for(i=0,j=n-1; i<=j && ok==1 ;i++,j--){
			if(roupa[i]==2 && roupa[j]==2 ){
				if(i!=j)
					sum+=2*low;
				else
					sum+=low;
			}
			else if((roupa[i]==2 && roupa[j]!=2) || (roupa[j]==2 && roupa[i]!=2)){
				if(roupa[i]==0 || roupa[j]==0)
					sum+=a; 
				else 
					sum+=b;
			}
			else if((roupa[i]==0 && roupa[j]==1) ||(roupa[i]==1 && roupa[j]==0) )
				ok=0; 
			else
				continue;
		}	
		if(ok)
			cout<<sum<<endl; 
		else
			cout<<"-1"<<endl;
	}	

	return 0;
}