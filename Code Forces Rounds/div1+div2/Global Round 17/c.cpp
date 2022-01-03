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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e5 + 10;

int n, a[MAXN], b[MAXN];

bool test(int val){

	int p = 1;

	for(int i = 0; i < n; i++){
		if ((a[i] >= val - p) and (b[i] >= p - 1))
			p++;
	}

	return p > val;
}

void solve(){
	cin>>n;

	fr(i, n)
		cin>>a[i]>>b[i];

	int ini = 1, bst = 1, fim = n;
		
	while (ini <= fim){
		int meio = (ini + fim)/2;
	
		if (test(meio)){
			bst = meio;
			ini = meio + 1;
		}
		else
			fim = meio - 1;
	}	

	cout<<bst<<endl;

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}