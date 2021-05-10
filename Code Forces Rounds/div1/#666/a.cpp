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

ll n, a[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	fr(i, n)
		cin>>a[i];

	if (n == 1){
		cout<<"1 1"<<endl;
		cout<<-a[0]<<endl;
		a[0] = 0;
		cout<<"1 1"<<endl;
		cout<<-a[0]<<endl;
		cout<<"1 1"<<endl;
		cout<<-a[0]<<endl;
		return 0;
	}	


	cout<<"1 1"<<endl;
	cout<<-a[0]<<endl;
	a[0] = 0;

	cout<<"2 "<<n<<endl;
	for (int i = 1; i < n; i++){
		ll b = a[i] * (n - 1);
		cout<<b<<' ';
		a[i] += b;
	}
	gnl;

	cout<<"1 "<<n<<endl;

	for (int i = 0; i < n; i++){
		cout<<-a[i]<<' ';
	}
	gnl;

}