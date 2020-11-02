#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define F first
#define S second
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define P_B push_back
#define M_P make_pair
#define endl "\n"

#define MOD 1000000007
#define pi 3.141592653589793238


// void file_io()
// {
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// }


const int N = 1e5 + 5;
int p = 31;
int m = 1e9 + 9;

int computeHash(string s) {

	int hash = 0;
	int power = 1;

	for (auto c : s) {

		hash = hash + ((c-'a'+1) * power)%m;
		power = (p*power)%m;
	}

	return hash;
}


int32_t main() {
	
	// file_io();
	
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	// int T; cin>>T; while(T--) 
	{
		
		int n;
		cin>>n;

		vector<string> v(n);
		for (int i = 0; i < n; i++) cin>>v[i];

		vi hashes;
		for (auto s : v) hashes.P_B(computeHash(s));
		sort(hashes.begin(), hashes.end());

		int answer = 1, i = 0, j = 0;

		while(i < n && j < n) {

			j = i;
			while(j < n && hashes[j] == hashes[i]) j++;
			i = j;

			if(i < n) answer++;
		}

		cout<<answer<<endl;

	}	
	
	return 0;
}   
