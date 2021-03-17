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
const int MAXN = 1e5 + 10;

int n;
vi v, ans;

bool test(int val){
	ans.clear();

	int p = 0;
	int q = n - val - 1;

	if (q < val)
		return 0;

	ans.pb(v[q++]);	
	
	while (p < val){
		ans.pb(v[p++]);
		ans.pb(v[q++]);		
	}

	while (p < n - val - 1)
		ans.pb(v[p++]);

	int sum = 0;

	for (int i = 1; i < n - 1; i++)
		if (ans[i] < ans[i - 1] and ans[i] < ans[i + 1])
			sum++;

	return sum >= val;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	int x;
	fr(i, n){
		cin>>x;
		v.pb(x);
	}

	sort(all(v));

	int ini, fim, bst, meio;
	ini = bst = 0;
	fim = n;

	while (ini <= fim){
		meio = (ini + fim)/2;
		if (test(meio)){
			ini = meio + 1;
			bst = meio;
		}
		else
			fim = meio - 1;
	}

	test(bst);
	cout<<bst<<endl;
	for (auto x : ans)
		cout<<x<<' ';
	gnl;
}