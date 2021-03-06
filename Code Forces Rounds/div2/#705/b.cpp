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

int valid[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

void print(int a, int b){
	string s = "00:00";
	s[1] = '0' + a % 10;
	a /= 10;
	s[0] = '0' + a % 10;
	s[4] = '0' + b % 10;
	b /= 10;
	s[3] = '0' + b % 10;

	cout<<s<<endl;
}

bool test(int a, int b){
	int aux;
	if (valid[a % 10] == -1)
		return 0;
	aux = 10 * valid[a % 10];
	a /= 10;
	if (valid[a % 10] == -1)
		return 0;
	aux += valid[a % 10];

	return aux < b;
}


void solve(){
	int h, m, a, b;
	string s;
	cin>>h>>m;

	cin>>s;
	a = 10 * (s[0] - '0') + (s[1] - '0');
	b = 10 * (s[3] - '0') + (s[4] - '0');

	for (int i = a; i < h; i++){
		int j = 0;
		if (i == a)
			j = b;

		while (j < m){
			if (test(i, m) and test(j, h)){
				print(i, j);
				return;
			}
			j++;
		}
	}

	cout<<"00:00"<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}