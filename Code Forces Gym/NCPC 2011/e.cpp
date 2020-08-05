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
//cout << setprecision(9)<<fixed;
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;
 
string pat;
string cara;
 
int memo[110][110];
 
bool pd(int indpat, int indcara){
 
	if(indpat==pat.size())
		return indcara==cara.size() || pat[pat.size()-1]=='*';
 
	if(indcara == cara.size())
		return indpat == pat.size();
 
	int &pdm = memo[indpat][indcara];
 
	if(pdm!=-1)	return pdm;
 
	pdm=0;
 
	if(pat[indpat]=='*'){
		pdm|=pd(indpat,indcara+1);
		pdm|=pd(indpat+1,indcara);
	}
	else{
		if(pat[indpat]!=cara[indcara])
			return pdm=0;
		pdm|=pd(indpat+1,indcara+1);
	}
 
	return pdm;
}
 
int main(){
 
	fastio;
	
	getline(cin,pat);
	int n;
	cin >> n;
	
	getline(cin,cara);
	
	fr(i,n){
	
		getline(cin,cara);
	
		ms(memo,-1);
	
		if(pd(0,0))
			cout << cara << endl;
	
	}
}