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

int32_t main() {
	
	// file_io();
	
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int T; cin>>T; while(T--) 
	{
		
		string text, s;
		cin>>text>>s;

		int t = text.length(), n = s.length();

		vi p_power, hash_text;

		hash_text.P_B(0);
		int hash_string = 0;
		p_power.P_B(1);


		for (int i = 0; i < max(n, t)+1; i++) p_power.P_B((p_power.back()*p)%m);

		for (int i = 0; i < t; i++) hash_text.P_B(hash_text.back() + (p_power[i]*(text[i] - 'a'+1))%m);	

		for (int i = 0; i < n; i++) hash_string = hash_string + (p_power[i]*(s[i] - 'a'+1))%m;	

		vi answer;

		for (int i = 0; i < t; i++) {

			if(i+n > t) break;

			int cur_hash_text = (hash_text[i+n] - hash_text[i] + m)%m;

			if(cur_hash_text == (hash_string*p_power[i])%m) {
				answer.P_B(i+1);
			}

		}
		

		if(answer.size() == 0) {
			cout<<"Not Found"<<endl<<endl;
			continue;
		}

		cout<<answer.size()<<endl;
		for (auto ele : answer) cout<<ele<<" ";
		cout<<endl;
		cout<<endl;
	}	
	
	return 0;
}   
