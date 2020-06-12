#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

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

int a[MAXN], b[MAXN], ansa[MAXN], ansb[MAXN];

int32_t main(){
	fastio;

	int n;
	cin>>n;
	fr(i, n)
		cin>>a[i]>>b[i];

	// best
	int cnt = 0, p = 0, q = 0;
	while (cnt < n){
		if (a[p] < b[q])
			ansa[p++] = 1;
		else
			ansb[q++] = 1;
		cnt++;
	}

	fr(i, n/2)
		ansa[i] = ansb[i] = 1;	

	fr(i, n)
		cout<<ansa[i];
	gnl;
	
	fr(i, n)
		cout<<ansb[i];
	gnl;		


}