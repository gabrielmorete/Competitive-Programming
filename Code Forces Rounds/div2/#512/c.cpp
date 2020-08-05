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

int n;
vi sum; 
bool check(int k){
	int i,j;
	i=j=k+1; 
	while(i<=n && j<=n){
	
		while(sum[j+1]-sum[i-1]<=sum[k] && j+1<=n)
			j++;

		if(sum[k]!=sum[j]-sum[i-1])
			return false; 
		j++;
		i=j;
	}
	return true;

}


int main(){
	fastio;
	
	string s;
	cin>>n; 
	getline(cin,s);
	getline(cin,s);
	sum.pb(0);
	fr(i,s.size()){
		sum.pb(sum.back()+s[i]-'0');
	}
	int ok=0;
	frr(i,n-1)
		if(check(i)){
			ok=1; 
		}
	if(ok)
		cout<<"YES"<<endl; 
	else 
		cout<<"NO"<<endl;		
			

}