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
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;
const int LMAXN = 20;

int main(){
	fastio; 
	int n,sum,gr[512];
	bool um[512];
	ms(um,0);

	cin>>n;

	sum=0;
	frr(i,n){
		cin>>gr[i];
		sum+=gr[i];

		if(gr[i]==1)
			um[i]=1;
	}

	if(sum<(2*n-2)){
		cout<<"NO"<<endl;
		return 0;
	}
	
	vii edj;
	int dim=0;

	int last=-1;
	int first;

	frr(i,n){
		if(um[i])
			continue;
		else{
			if(last==-1){
				first=i;
				last=i;
			}

			else{
				edj.pb({last,i});
				
				gr[last]--;
				gr[i]--;

				last=i;
				dim++;
			}
		}
	}

	int j=0;

	frr(i,n)
		if(um[i]){
			if(first!=-1){
				edj.pb({first,i});
				gr[first]--;
				dim++;
				first=-1;
				continue;
			}
			if(last!=-1){
				gr[last]--;
				edj.pb({last,i});
				dim++;
				last=-1;
				continue;
			}	

			while(um[j] || gr[j]<1)
				j++;
			
			gr[j]--;
			edj.pb({i,j});

		}

	cout<<"YES "<<dim<<endl;
	cout<<edj.size()<<endl;
	for(auto x:edj)
		cout<<x.fst<<' '<<x.snd<<endl;	
	

}