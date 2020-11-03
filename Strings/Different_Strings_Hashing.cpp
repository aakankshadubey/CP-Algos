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
int  p = 31;
int m = 1e9 + 9;

vi hashset;
vi p_power;

void computeHash(string s) {

	int n = s.length();
	int power = 1;
	hashset.P_B(0);
	p_power.P_B(1);


	for (int i = 0; i < n; i++) {

		hashset.P_B(hashset.back() + power*(s[i] - 'a'+1)%m);
		power = (power * p)%m;
		p_power.P_B(power);
	}


}

int32_t main() {
	
	// file_io();
	
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	// int T; cin>>T; while(T--) 
	{
		
			
		int n;
		cin>>n;
		string s;
		cin>>s;

		computeHash(s);

		set<int> hashes;

		for (int len = 1; len <= n; len++) {

			for (int i = 0; i < n; i++) {

				if(i+len > n) break;

				int cur_hash = (hashset[i+len] - hashset[i] + m)%m;
				cur_hash = (cur_hash * p_power[n-i-1])%m;
				 /*It is done bcoz hash difference is multiplied by i 
					To make all even we multiply by remaining n-i
				*/

				if(hashes.find(cur_hash) == hashes.end()) hashes.insert(cur_hash);
			}
		}

		cout<<hashes.size();

	}	
	
	return 0;
}   


/*
aabcd
a
b
c
d

aa
ab
bc
cd

aab
abc
bcd

aabc
abcd
aabcd

*/