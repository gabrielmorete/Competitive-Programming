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

int s[121];

int main(){
	fastio;

	int n, bst = 0;
	cin>>n;
	frr(i,n){
		cin>>s[i];	
		bst += s[i];
		s[i] +=s[i-1];
	}

	if(bst == n){
		cout<<n-1<<endl;
		return 0;
	}
	


	int aux;

	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++){


			aux = s[i-1] + s[n] - s[j];
			aux += (j-i+1) - (s[j] - s[i-1]);
			bst = max(bst,aux);
		}

	cout<<bst<<endl;	

}