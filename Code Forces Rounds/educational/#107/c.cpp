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
const int MAXN = 3e5 + 10;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q, pos[55];

	cin>>n>>q;

	fr(i, 55)
		pos[i] = n + 1;

	int x;
	frr(i, n){
		cin>>x;
		pos[x] = min(pos[x], i); // só a primeira aparição
	}

	while (q--){
		cin>>x;
		cout<<pos[x]<<' ';

		fr(i, 55)
			if (pos[i] < pos[x])
				pos[i]++;
		pos[x] = 1;	
	}
	gnl;
}