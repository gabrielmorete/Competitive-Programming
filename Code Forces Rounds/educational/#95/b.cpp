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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e2 + 10;

int n, l[MAXN], v[MAXN], aux[MAXN];
vi fr;

void solve(){
	cin>>n;
	frr(i, n)
		cin>>v[i];
	frr(i, n)	
		cin>>l[i];

	fr.clear();	

	frr(i, n)
		if (!l[i])
			fr.pb(v[i]);

	sort(all(fr));	
	int p = fr.size();
	p--;

	frr(i, n){
		if (!l[i])
			aux[i] = fr[p--];
		else
			aux[i] = v[i];
	}

	// bool ok = 0;
	// int sum = 0;
	// frr(i, n){
	// 	sum += aux[i];
	// 	if (sum < 0)
	// 		ok = 1;
	// }

	// if (!ok){
	// 	frr(i, n)
	// 		cout<<aux[i]<<' ';
	// 	gnl;
	// 	return;	
	// }

	// reverse(all(fr));

	// p = fr.size();
	// p--;
	// frr(i, n){
	// 	if (!l[i])
	// 		aux[i] = fr[p--];
	// 	else
	// 		aux[i] = v[i];
	// }

	frr(i, n)
			cout<<aux[i]<<' ';
		gnl;

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}