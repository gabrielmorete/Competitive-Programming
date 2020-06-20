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


int n, k;
int v[MAXN];

bool test(int val){
	int tot = 0, p;
	p = 0;
	for (int i = 0; i < n; i++){
		if (p % 2){
			tot++;
			p = 0;
			continue;
		}

		if (v[i] <= val){
			tot++;
			p = 1;
		}
	}	

	if (tot >= k)
		return true;	

	tot = 0;
	p = 1;

	for (int i = 0; i < n; i++){
		if (p % 2){
			tot++;
			p = 0;
			continue;
		}

		if (v[i] <= val){
			tot++;
			p = 1;
		}
	}	

	return tot >= k;
}


int32_t main(){
	fastio;

	cin>>n>>k;

	int a;
	fr(i, n){
		cin >> v[i];
	}

	int ini, fim, bst, meio;
	ini = 1;
	bst = fim = 1e9;

	while (ini <= fim){
		meio = (ini + fim)/2;

		if (test(meio)){
			bst = meio;
			fim = meio - 1;
		}
		else
			ini = meio + 1;
	}

	cout<<bst<<endl;
}