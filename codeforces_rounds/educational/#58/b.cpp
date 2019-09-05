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

string s,b,c;


int main(){
	fastio;
	cin>>s;
	if(s.size()<3){
		cout<<-1<<endl;
		return 0;
	}


	for(auto x:s){
		if(x==':' or x=='|' or x=='[' or x==']')
			b.pb(x);
	}

	for(int i=b.size()-1;i>=0;i--){
		if(b[i]==']')
			break;
		b.pop_back();
	}
	reverse(all(b));

	for(int i=b.size()-1;i>=0;i--){
		if(b[i]=='[')
			break;
		b.pop_back();
	}
	reverse(all(b));

	if(b.size()==0 || b[0]!='[' || b[b.size()-1]!=']'){
		cout<<-1<<endl;
		return 0;
	}


	bool co,cc;
	co=cc=0;
	c.pb('[');
	frr(i,b.size()-1){
		if(co==0){
			if(b[i]==':'){
				c.pb(':');
				co=1;
			}
		}
		else{
			if(b[i]==':')
				cc=1;
			if(b[i]==':' or b[i]=='|')
				c.pb(b[i]);
		}
	}

	if(co==0 || cc==0){
		cout<<-1<<endl;
		return 0;
	}

	bool foi;
	foi=0;

	c.pb(']');
	ll ans=c.size();
	
	for(int i=c.size()-2;i>1;i--){
		if(foi==0 && c[i]!=':'){
			ans--;
			continue;
		}
		if(foi==0 && c[i]==':'){
			foi=1;
			continue;
		}
		if(foi==1 && c[i]==':'){
			ans--;
			continue;
		}

	}
	cout<<ans<<endl;

}