#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e5 + 10;
const ll mod=1e9+7;

int n, v[MAXN], used[MAXN];

int32_t main(){
	fastio;
	cin>>n;

	frr(i, n - 1)
		cin>>v[i];	

	cout<<v[1]<<endl; // Raiz

	int lst = n; // Cara mais pesado não utilizado
	frr(i, n - 1){
		used[v[i]] = 1;
		while (used[lst])
			lst--;

		if (i == n - 1 or used[v[i + 1]]){ // Fim de uma cadeia 
			cout<<v[i]<<' '<<lst<<endl;
			used[lst] = 1;
		}
		else
			cout<<v[i]<<' '<<v[i + 1]<<endl;
	}
}