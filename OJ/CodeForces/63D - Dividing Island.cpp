#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;
int a, b, c, d, n;
char ans[100][100];
string s;


int main(){
	fastio;
	
	cin>>a>>b>>c>>d>>n;

	int aux;
	int f = 'a';
	fr(i,n){
		cin>>aux;
		while (aux--)
			s.pb(f);
		f++;

	}

	fr(i,100)
		fr(j,100)
			ans[i][j] = '.';

	bool side = d%2;

	for(int i = d - 1; i >= 0; i--){
		if (side) {
			for (int j = a + c - 1; j >= a ; j--) {
				ans[i][j] = s.back();
				s.pop_back();
			}	
		}
		else {
			for (int j = a; j < a + c; j++){
				ans[i][j] = s.back();
				s.pop_back();
			}
		}

		side = !side;
	}			

	side = 1;

	for(int i = 0; i < b; i++){
		if (side) {
			for (int j = a - 1; j >= 0; j--) {
				ans[i][j] = s.back();
				s.pop_back();
			}
		}
		else {
			for (int j = 0; j < a ; j++) {
				ans[i][j] = s.back();
				s.pop_back();
			}
		}

		side = !side;
	}

	cout<<"YES"<<endl;
	fr(i, max( b, d)) {
		fr(j, a + c)
			cout<<ans[i][j];
		gnl;	
	}



}