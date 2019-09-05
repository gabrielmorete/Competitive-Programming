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
	ll n,m,k; 
	cin>>n>>m>>k; 
	
	ll a,N;
	N=n;
	a=__gcd(n,k); 
	
	n=n/a;
	k=k/a;
	a=__gcd(m,k);
	
	m=m/a;
	k=k/a;
	if(k>2){
		cout<<"NO"<<endl; 
		return 0;
	}
	if(k==2){
		cout<<"YES"<<endl;
		cout<<"0 0"<<endl;
		cout<<n<<" 0"<<endl; 
		cout<<"0 "<<m<<endl;
	} 
	else{
		cout<<"YES"<<endl;
		cout<<"0 0"<<endl;
		if(2*n<=N){
			cout<<2*n<<" 0"<<endl; 
			cout<<"0 "<<m<<endl;
		}
		else{
			cout<<n<<" 0"<<endl; 
			cout<<"0 "<<2*m<<endl;
		}

	}
	

}