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
	int n;
	string s;
	cin>>n;
	cin>>s;

	bool ok=0;

	fr(i,s.size()){
		if(ok){
			cout<<s[i];
			continue;
		}

		if(ok==0 && s[i+1]<s[i]){
			ok=1;
			continue;
		}
		else if(ok==0 && i==(s.size()-1)){
			continue;
		}

		else
			cout<<s[i];

	}

	gnl;


}