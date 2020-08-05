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

bool check(string s){
	int i,j; 
	i=0;
	j=s.size()-1;
	while(i<=j){
		if(s[i]!=s[j])
			return false;
		i++;
		j--;
	}
	
	return true;	
}

int main(){
	fastio; 
	int t; 
	cin>>t; 
	while(t--){
		string s; 
		cin>>s; 
//		dbg(s);
		sort(all(s)); 
//		chapa;
		if(check(s))
			cout<<-1<<endl;
		else 
			cout<<s<<endl;

	}
	
}