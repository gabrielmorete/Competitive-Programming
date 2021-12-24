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
const int MAXN = 4e5 + 10;

int sum[MAXN][30];


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i < 212345; i++){
		for (int j = 0; j < 26; j++)
			if (i&(1<<j))
				sum[i][j]++;
	
		for (int j = 0; j < 26; j++)
			sum[i][j] += sum[i - 1][j];	
	}

	int t;
	cin>>t;

	while (t--){
		int l, r, ans = 0;

		cin>>l>>r;

		fr(j, 26)
			ans = max(ans, sum[r][j] - sum[l - 1][j]);

		cout<<(r - l + 1 - ans)<<endl;
	}

}