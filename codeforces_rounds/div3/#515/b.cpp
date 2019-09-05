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
	fastio; 
	int n,r; 
	vi v; 
	cin>>n>>r; 
	frr(i,n){
		int x; 
		cin>>x; 
		if(x)
			v.pb(i);
	}
	
	if(v.size()==0){
		cout<<-1<<endl; 
		return 0;
	}

	int at,tot,pos,nxt;
	bool ok=1;
	at=1;tot=0;pos=0;
	
	while(v[pos]<=at+r-1 && pos<v.size())
		pos++;

	if(pos==0){
			cout<<-1<<endl; 
			return 0;
	}

	pos--; 
	at=v[pos];
	tot++;
	
	while(at+r-1<n && pos<v.size() && ok){
		nxt=at+2*r-1;

		while(v[pos+1]<=nxt && pos+1<v.size())
			pos++;
		if(v[pos]==at)
			ok=0; 
		else{
			tot++;
			at=v[pos];
		}
	
	}
	if(at+r-1<n)
		ok=0;
	cout<<(ok?tot:-1)<<endl;
}