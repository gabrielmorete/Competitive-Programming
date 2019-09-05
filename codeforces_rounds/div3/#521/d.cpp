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

int x,n,k;
int q[1123456];
set<pii> freq;
bool test(int meio){
	int tot=0;
	for(auto it=freq.begin();it!=freq.end();it++){
		tot+=(it->fst)/meio;
	}	
	return(tot>=k);
}


int main(){
	fastio;
	cin>>n>>k; 
	fr(i,n){
		cin>>x;
		q[x]++; 
	} 
	fr(i,1123456){
		if(q[i]!=0)
			freq.insert({q[i],i});
	}
	
	int ini,fim,meio,best=1; 
	ini=1;fim=n; 
	while(ini<=fim){
		meio=(ini+fim)/2;
		if(test(meio)){
			if(meio>best)
				best=meio;
			ini=meio+1;
		}
		else{
			fim=meio-1;
		}
	}
//	dbg(best);dbg(k);dbg(freq.begin()->fst);dbg(n);
	int ans=0;
	for(auto it=freq.begin();it!=freq.end() && ans<k ;it++){
		int aux=it->fst;
		while(aux-best>=0 && ans<k){
			cout<<it->snd<<' ';	
			aux-=best;
			ans++;
		}
	}	
	
	gnl;	
	


	
}