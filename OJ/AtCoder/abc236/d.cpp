#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
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
const int MAXN = 4e5 + 10;

int n, a[20][20], ans, now, used[16];

void backtraking(){
	int p = -1;
	fr(i, n)
		if (used[i] == 0){
			p = i;
			break;
		}

	if (p == -1){
		ans = max(ans, now);
		return;
	}	

	used[p] = 1;
	fr(j, n)
		if (!used[j]){
			used[j] = 1;
			now ^= a[p][j];
			backtraking();
			now ^= a[p][j];
			used[j] = 0;
		}

	used[p] = 0;		
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	n *= 2;

	fr(i, n)
		for (int j = i + 1; j < n; j++){
			cin>>a[i][j];
			a[j][i] = a[i][j];
		}

	backtraking();
	
	cout<<ans<<endl;
}