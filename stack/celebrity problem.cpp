#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
 
using namespace std;
#define set_precision cout << fixed << setprecision(10)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repb(i, a, b) for (int i = a; i >= b; i--)
#define replb(i, a, b) for (ll i = a; i >= b; i--)
#define repl(i, a, b) for (ll i = a; i < b; i++)
#define repit(arr) for (auto it = arr.begin(); it != arr.end(); 
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vl vector<long long int>
#define Vi vector<vector<int>>
#define vpi vector<pair<int,int> >
#define seti set<int>
#define setl set<ll>
#define dseti set<int, greater<int>>
#define dsetl set<ll, greater<ll>>
#define mseti multiset<int>
#define msetl multiset<ll>
#define dmseti multiset<int, greater<int>>
#define dmsetl multiset<ll, greater<ll>>
#define sortA(arr) sort(arr.begin(), arr.end())
#define dsortA(arr) sort(arr.begin(), arr.end(), greater<int>())
#define ssort(arr) stable_sort(arr.begin(), arr.end())
#define search(arr, c) binary_search(arr.begin(), arr.end(), c)
#define pb push_back
#define ll long long
#define cl_bf cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define castl static_cast<ll>
#define BRAHAMASTRA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ull unsigned long long int

/*
brute force

int celebrity(vector<vector<int> >& M, int n) 
{
	vector<int> res;
	for(int i=0;i<n;++i)
	{
		int aux=0;
		for(int j=0;j<n;++j)
		{
			if(M[i][j]==0)
				aux++;
		}
		if(aux==n)
			res.push_back(i);
	}
	if(res.size()==1)
		return res[0];
	else
		return -1;
}*/

int celebrity(vector<vector<int> >& M, int n) 
{
	stack<int> s;
	for(int i=0;i<n;++i)
		s.push(i);
	while(s.size()>1)
	{
		int x=s.top();
		s.pop();
		int y=s.top();
		s.pop();
		if(M[x][y])
			s.push(y);
		else
			s.push(x);
	}
	int x=s.top();
	int i;
	for(i=0;i<n;++i)
	{
		if(i==x)
			continue;
		if(M[i][x]==1 && M[x][i]==0)
			continue;
		else
			break;
	}
	if(i==n)
		return x;
	else
		return -1;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../output.txt","w",stdout);
	#endif

	BRAHAMASTRA

	int n;
	cin>>n;
	vector<vector<int> > v(n,vector<int>(n));
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			cin>>v[i][j];
	}
	cout<<celebrity(v,n);
}
