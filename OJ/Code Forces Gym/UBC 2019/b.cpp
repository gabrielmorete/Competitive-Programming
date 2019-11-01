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
 
string names[110];
int hp[110], at[110], df[110];
int battle[110][110];
int vis[110][110][110];
 
int win(int i, int j){
 
	int hpi = hp[i];
	int hpj = hp[j];
 
	while(hpi>0 && hpj>0){
		int delta1 = max(0,at[j]-df[i]);
		int delta2 = max(0,at[i]-df[j]);
		if(!delta1 && !delta2)	break;
		hpi-=delta1;
		hpj-=delta2;
	}
 
	return hpi>0 && hpj<=0;
 
}
 
int main(){
	
	fastio;
 
	int n; cin >> n;
 
	fr(i,n){
		cin >> names[i];
		//dbg(names[i]);
		cin >> hp[i] >> at[i] >> df[i];
	}
 
	fr(i,n){
		fr(j,n){
			battle[i][j]=win(i,j);
		}
	}
 
	set<tuple<int,int,int>> cands;
 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(battle[i][j] && battle[j][k] && battle[k][i] && i!=j && j!=k && i!=k){
					if(!vis[i][j][k] && !vis[k][i][j] && !vis[j][k][i]){
						vis[i][j][k]=1;
						cands.insert(make_tuple(i,j,k));
					}
				}
			}
		}
	}
 
	cout << cands.size() << endl;
	
	for(auto x : cands) {
		cout << names[get<0>(x)] << " " << names[get<1>(x)] << " " << names[get<2>(x)] << endl;
	}
	
}