#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int v[MAXN];


int query(int pos){
	fr(i, 3)
		if (v[pos - 1 + i] == 0){
			cout<<"? "<<pos - 1 + i<<endl;
			cin>>v[pos - 1 + i];
		}

	// formato
	if (v[pos] < v[pos - 1] and v[pos] < v[pos + 1]){ // achei	
		cout<<"! "<<pos<<endl;
		exit(0);
	}

	if (v[pos] > v[pos - 1] and v[pos] > v[pos + 1]) // vai para esquerda
		return 0;
	if (v[pos] > v[pos - 1] and v[pos] < v[pos + 1])
		return 0;
	return 1;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin>>n;

	v[0] = v[n + 1] = INF;

	if (n <= 100){
		for (int i = 1; i <= n; i++){
			cout<<"? "<<i<<endl;
			cin>>v[i];
		}

		for (int i = 1; i <= n; i++)
			if (v[i - 1] > v[i] and v[i + 1] > v[i]){
				cout<<"! "<<i<<endl;
				return 0;
			}
	}

	cout<<"? 1"<<endl;
	cin>>v[1];
	cout<<"? 2"<<endl;
	cin>>v[2];

	cout<<"? "<<n<<endl;
	cin>>v[n];
	cout<<"? "<<n - 1<<endl;
	cin>>v[n - 1];

	if (v[1] < v[2]){
		cout<<"! 1"<<endl;
		return 0;
	}
	if (v[n] < v[n - 1]){
		cout<<"! "<<n<<endl;
		return 0;
	}

	int esq, dir, meio;

	esq = 2;
	dir = n - 1;

	while (esq <= dir){
		int meio = (esq + dir)/2;

		if (query(meio) == 0)
			dir = meio;
		else
			esq = meio;
	}

}