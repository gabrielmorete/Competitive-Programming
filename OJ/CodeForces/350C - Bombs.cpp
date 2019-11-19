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
vii pnt;

bool comparator(pii a, pii b){
	if ((abs(a.fst) + abs(a.snd)) < (abs(b.fst) + abs(b.snd)))
		return true;
	return false;
}

int main(){
	scanf("%d", &n);

	int a, b, ans;

	ans = 0;
	fr(i,n){
		scanf("%d %d", &a, &b);
		ans += (a ? 1 : 0) + (b ? 1 : 0);
		pnt.pb({a, b});
	}
	sort(all(pnt), comparator);

	cout<<2*ans + 2*n<<endl;

	for(auto x : pnt) {
		if (x.fst != 0)
			printf("1 %d %c\n", abs(x.fst), (x.fst > 0 ? 'R' : 'L'));
		if (x.snd != 0)
			printf("1 %d %c\n", abs(x.snd), (x.snd > 0 ? 'U' : 'D'));
		printf("2\n");
		if (x.fst != 0)
			printf("1 %d %c\n", abs(x.fst), (x.fst < 0 ? 'R' : 'L'));
		if (x.snd != 0)
			printf("1 %d %c\n", abs(x.snd), (x.snd < 0 ? 'U' : 'D'));
		printf("3\n");
	}

}