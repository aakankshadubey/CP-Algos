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

		int n  =s.length();

		vi pf(n, 0);

		for (int i = 1; i < n; i++) {

			int j = pf[i-1];

			while(j >= 0) {

				if(s[j] == s[i]) {
					pf[i] = j+1;
					break;
				}

				j = pf[j-1];
				if(j == 0) {
					if(s[j] == s[i]) pf[i] = j+1;
					break;
				}
			}
		}	


		for (auto ele : pf) cout<<ele<<" ";
	}	
	
	return 0;
}   
