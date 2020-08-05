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
const ll mod = 1e9+7;

int32_t main(){
	fastio;
	int a, b;

	cin>>a>>b;
	int ans = 0;

	int x, y, aux;

	x = y = 0;

	while (a % 2 == 0){
		x++;
		a /= 2;
	}

	while (b % 2 == 0){
		y++;
		b /= 2;
	}

	ans += abs(x - y);

	x = y = 0;

	while (a % 3 == 0){
		x++;
		a /= 3;
	}

	while (b % 3 == 0){
		y++;
		b /= 3;
	}

	ans += abs(x - y);
	
	x = y = 0;

	while (a % 5 == 0){
		x++;
		a /= 5;
	}

	while (b % 5 == 0){
		y++;
		b /= 5;
	}

	ans += abs(x - y);

	if (a == b)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
}