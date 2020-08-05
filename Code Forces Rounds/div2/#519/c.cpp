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

string s,aux;
vi v;

int main(){
	fastio; 
	getline(cin,s); 
	int pon=s[0]-'a'; 
	aux=s; 
	for(int i=0;i<s.size()-1;i++){
		if(pon==0 && (s[i]=='b' && s[i+1]=='a' ) ){
			v.pb(1); 
			pon=1;
			continue;
		}
		if(pon==1 && (s[i]=='a' && s[i+1]=='b' ) ){
			v.pb(1); 
			pon=0;
			continue;
		} 

		v.pb(0);
	}

	if(pon==1)
		v.pb(1);  
	else 
		v.pb(0);

	for(int i=0;i<v.size();i++)
		cout<<v[i]<<' '; 
	gnl;		 


}