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

int n, q;
string s;

int conta(int l, int r){
	int cnt = 0;
	for (int i = l; i + 2 < r; i++){
		if (s[i] == 'a' and s[i + 1] == 'b' and s[i + 2] == 'c')
			cnt++;
	}

	return cnt;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>q>>s;

	int tot = conta(0, n);


	int x;
	char c;
	while (q--){
		cin>>x>>c;

		int velho = conta(max(0, x - 4), min(n, x + 4));
		s[x - 1] = c;
		int novo =  conta(max(0, x - 4), min(n, x + 4));

		tot = tot + novo - velho;

		cout<<tot<<endl;
	}
}