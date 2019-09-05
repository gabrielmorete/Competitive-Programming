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
	int n,k,num; 
	cin>>n>>k; 
	num=n/(2*k+1);
	if(n%(2*k+1))
		num++; 
	int ok=0,sub=0,p1;
	vi pos; 
	p1=k+1;
	pos.pb(k+1);
	while(!ok){
		if(pos.back() <= n && pos.back() + k >= n )
			ok = 1;
		//dbg(pos.back());

		while(p1 <= n && !ok){
			//chapa;
			// dbg(p1);
			// dbg(n);
			p1+=2*k+1;
			pos.pb(p1);
			if(pos.back()<= n && pos.back() + k >= n )
				ok = 1;
		}
		//dbg(ok);

		if(p1>n && !ok){
			sub=pos.back()-n;
			ok=1;
		}
	}
	cout<<num<<endl; 
	fr(i,num){
		cout<<pos[i]-sub<<' ';
	}
	gnl;
	return 0;
}