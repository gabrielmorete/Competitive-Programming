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

int main(){
	fastio;
	int n, k, d;
	cin>>n>>k>>d;

	if (n == 1 and k == 1){
		fr(i,d)
			cout<<1<<endl;
		return 0;	
	}
	else if (k == 1){
		cout<<-1<<endl;
		return 0;
	}

	int aux = 1;

	fr(i,d){
		if(aux >= n)
			break;
		aux *= k;
	}

	if (aux < n){
		cout<<-1<<endl;
		return 0;
	}

	int v[1111][1111];
	int ans[1111];
	fr(i,d)
		ans[i] = 1;

	fr(i,n){
		fr(j,d)
			v[j][i] = ans[j];
		int j = 0;
		ans[0]++;
		while ( j < d and ans[j] > k){
			ans[j] = 1;
			j++;
			ans[j]++;
		}
	}	
	fr(i,d){
		fr(j,n)
			cout<<v[i][j]<<' ';
		gnl;	
	}
}