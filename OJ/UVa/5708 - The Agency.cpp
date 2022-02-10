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

ll n, c[MAXN], sout[MAXN], ssin[MAXN];
string a, b;
vector<ll> out, in, stay;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int cnt = 1;
	while (cin>>n and n > 0){
		fr(i, n + 100)
			sout[i] = ssin[i] = 0;



		out.clear();
		in.clear();
		stay.clear();

		cin>>a>>b;

		fr(i, n)
			cin>>c[i];

		fr(i, n){
			if (a[i] == '1' and b[i] == '0')
				out.pb(c[i]);
			if (a[i] == '0' and b[i] == '1')
				in.pb(c[i]);
			if (a[i] == '1' and b[i] == '1')
				stay.pb(c[i]);
		}
	
		sort(all(out));
		sort(all(stay));
		sort(all(in));

		reverse(all(out));
		reverse(all(in));

		ll op = out.size() + in.size(); // # de operações
		ll sstay = 0;
		for (auto x : stay)
			sstay += x;

		ll cstout = 0, cstin = 0;	
		
		ll sz_out = out.size();
		ll sz_in = in.size();

		fr(i, out.size()){
			cstout += (ll)(i) * out[i];

			sout[i] += out[i];
			sout[i + 1] = sout[i]; 
		}

		fr(i, in.size()){
			cstin += (ll)(i + 1) * in[i];

			ssin[i] += in[i];
			ssin[i + 1] = ssin[i];
		}

		ll ans = op * sstay + cstin + cstout;
		ll fstay = 0, pout = -1, pin = -1;

		while (!stay.empty()){
			ll x = stay.back();
			stay.pop_back();

			op += 2; // go out and go in
			sstay -= x;

			while (pout < sz_out - 1 and out[pout + 1] > x)
				pout++; // pou is the greatest positin with higer value,
			// I will only pay tohe and the ones that came before

			cstout += x * fstay; // go out after
			cstout += (pout + 1) * x; // grater than me has to pay me to go out

			cstout += sout[sz_out - 1];
			if (pout >= 0)
				cstout -= sout[pout];
			

			while (pin < sz_in - 1 and in[pin + 1] > x)
				pin++;

			cstin += (fstay + 1) * x; // I have to pay me
			cstin += (pin + 1) * x;

			cstin += ssin[sz_in - 1];
			if (pin >= 0)
				cstin -= ssin[pin];

			ll aux = op * sstay + cstin + cstout;
			ans = min(ans, aux);

			fstay++;
		}

		cout<<"Case "<<cnt++<<": "<<ans<<endl;
	}

}