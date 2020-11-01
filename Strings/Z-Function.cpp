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


int32_t main() {
	
	// file_io();
	
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	// int T; cin>>T; while(T--) 
	{
		
		string s;
		cin>>s;

		int n = s.length();
		vi Z(n, 0);
		int l = 0, r = 0;

		for (int i = 1; i < n; i++) {

			if(i <= r) Z[i] = min(Z[i-l], r-i+1);

			while(i + Z[i] < n && s[Z[i]] == s[Z[i] + i]) Z[i]++;
			if(i+Z[i] - 1 > r) {
				l = i, r = i+Z[i]-1;
			}

		}

		for (auto ele : Z) cout<<ele<<" ";
 
	}	
	
	return 0;
}   
