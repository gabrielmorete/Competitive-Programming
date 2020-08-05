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
const int MAXN = 1e5 + 10;

int32_t main(){
	fastio;
	int n, v[MAXN];

	bool ok = 1;
	cin>>n;
	frr(i, n){
		cin>>v[i];
		if (v[i] > i)
			ok = 0;
	}

	if (!ok){
		cout<<-1<<endl;
		return 0;
	}

	bool check[MAXN];
	fill(check, check + MAXN, 0);
	frr(i, n)
		check[v[i]] = 1;
	
	vi falta;
	for (int i = n; i > 0; i--)
		if (!check[i])
			falta.pb(i);	

	fill(check, check + MAXN, 0);	

	int lst = 0, aux;
	vi ans;
	for (int i = 1; i <= n; i++){
		if (v[i] <= lst){
			aux = falta.back();
			falta.pop_back();
			check[aux] = 1;
			ans.pb(aux);
		}
		else{
			check[lst] = 1;
			ans.pb(lst);
		}
		while (check[lst])
			lst++;
	}

	for (int x : ans)
		cout<<x<<' ';
	gnl;

}