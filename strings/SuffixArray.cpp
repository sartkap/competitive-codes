#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
vector<vector<int>> _rank;

int lcp(int i, int j)
{
	int ret = 0;
	int mx = (int)_rank.size() - 1;

	for(int k = mx; k >= 0; k--)
	{
		if(_rank[k][i] == _rank[k][j])
		{
			ret += 1 << k;
			i += 1 << k;
			j += 1 << k;
		}
	}

	return ret;
}

void suffix_array(string str)
{
	str += '$';

	int n = str.length();
	vector<int> p(n), c(n);

	{
		vector<pair<char, int>> a(n);
		for(int i = 0; i < n; i++)
			a[i] = {str[i], i};

		sort(a.begin(), a.end());

		for(int i = 0; i < n; i++)
			p[i] = a[i].second;

		c[p[0]] = 0;
		for(int i = 1; i < n; i++)
		{
			if(a[i].first == a[i - 1].first)
				c[p[i]] = c[p[i - 1]];
			else
				c[p[i]] = c[p[i - 1]] + 1;
		}

		_rank.push_back(c);
	}

	int k = 0;
	while( (1 << k) < n)
	{
		vector<pair<pii, int>> a(n);
		for(int i = 0; i < n; i++)
			a[i] = {{c[i], c[(i + (1 << k))%n]}, i};

		sort(a.begin(), a.end());

		for(int i = 0; i < n; i++)
			p[i] = a[i].second;

		c[p[0]] = 0;
		for(int i = 1; i < n; i++)
		{
			if(a[i].first == a[i - 1].first)
				c[p[i]] = c[p[i - 1]];
			else
				c[p[i]] = c[p[i - 1]] + 1;
		}

		_rank.push_back(c);
		k++;
	}

	long long ret = 0;
	for(int i = 1; i < n; i++)
	{
		int len = n - p[i];
		
		ret += len - lcp(p[i], p[i - 1]);
	}

	/* Subtract substrings ending at $ */
	ret -= (n - 1);

	cout << ret << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	suffix_array(str);
	return 0;
}