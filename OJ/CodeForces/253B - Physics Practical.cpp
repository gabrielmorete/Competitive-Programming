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
int n;
int v[112345];

bool test( int tam) {
	int p1,p2;
	p1 = 0;
	p2 = tam - 1;

	while (p2 < n){
		if (v[p2] <= 2*v[p1])
			return true;
		p1++;
		p2++;
	}
	return false;
}


int main(){
	fastio;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>n;

	fr(i,n)
		cin>>v[i];

	sort( v, v + n);	

	int aux, fst, lst, bst, mid;
	bst = 1;
	fst = 1;
	lst = n;

	while (fst <= lst) {
		mid = (fst + lst)/2;
		
		if (test(mid)) {
			bst = mid;
			fst = mid + 1;
		}
		else
			lst = mid - 1; 
	}

	cout<<n - bst<<endl;
}