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
const int MAXN = 5e2 + 25;

int n, val[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	memset(val, -1, sizeof val);
	val[0] = 0;


	int x;
	fr(i, n){
		cin>>x;

		fr(j, MAXN)
			if (val[j] != -1 and val[j] < x){
				if (val[j^x] == -1)
					val[j^x] = x;
				else
					val[j^x] = min(val[j^x], x);
			}
	}

	int k = 0;
	fr(i, MAXN)
		k += val[i] >= 0;

	cout<<k<<endl;
	fr(i, MAXN)
		if (val[i] >= 0)
			cout<<i<<' ';
	gnl;			
}