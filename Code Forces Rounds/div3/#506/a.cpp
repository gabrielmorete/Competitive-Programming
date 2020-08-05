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
	int n,k,mxs,j; 
	string l;
	cin>>n>>k;
	getchar();
	getline(cin,l);
	int ok;
	mxs=0; 
	if(n>1){
		for(int i=n-1;i>0;i--){
			if(l[i]==l[0]){
				j=i;
				ok=1;
				int p=1;
				while(j+p<n){
					if(l[p]!=l[p+j])
						ok=0;
					p++;
				}
				if(ok){
					mxs=i;
				}
			}	
		}
		if(mxs==0){
			fr(i,k)
				cout<<l; 
			gnl;	
		} 
		else{
			cout<<l; 
			fr(i,k-1){
				for(j=n-mxs;j<n;j++)
					cout<<l[j];
			}
			gnl;
		}
	} 
	else{
		fr(i,k)
			cout<<l[0]; 
		gnl;
	}	

	
	
	
	return 0;
}