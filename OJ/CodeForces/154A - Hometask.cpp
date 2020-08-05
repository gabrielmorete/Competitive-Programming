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
int k, pa[300];
string s;
int memo[112345][300];

int pd(int pos, int ant){
	if (pos >= s.size())
		return 0;

	int &pdm = memo[pos][ant];
	if (pdm != -1)
		return pdm;

	pdm = 0;
	//dbg(s[pos]);
	if(pa[s[pos]] != ant)
		pdm = pd(pos + 1, s[pos]) + 1;

	pdm = max(pdm, pd(pos + 1, ant));

	return pdm;
}

int main() {
	fastio;
	cin>>s;
	cin>>k;
	
	string t;
	fr(i,k){
		cin>>t;
		pa[t[0]] = t[1];
		pa[t[1]] = t[0];
	}	
	ms(memo,-1);
	int tam = s.size();
	cout<<tam - pd(0,2)<<endl;
}