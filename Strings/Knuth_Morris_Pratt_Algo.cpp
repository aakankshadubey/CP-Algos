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

	int T; cin>>T; while(T--) 
	{
		
		
		string t, p;
		cin>>t>>p;


		int n = t.length(), m = p.length();

		string s = p + '#' + t;

		vi pf(n+m+1, 0);
		vi answer;

		for (int i = 1; i < n+m+1; i++) {

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

			if(pf[i] == m) {

				answer.P_B(i-m - (m+1) +1);
			}
		}	

		if(answer.size() == 0) {
			cout<<"Not Found"<<endl<<endl;
			continue;
		}

		cout<<answer.size()<<endl;
		for (auto ele : answer) cout<<ele+1<<" ";
		cout<<endl<<endl;
		
	}	
	
	return 0;
}   
