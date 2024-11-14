// قال رسول الله صلى الله عليه وسلم: "مَن تواضَعَ للهِ رَفَعَهُ".

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;
using namespace chrono;

#define endl '\n'
#define ll long long

template<typename data_type>
using ordered_set = tree<data_type, null_type, less<data_type>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(high_resolution_clock::now().time_since_epoch().count());

int dx[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };
int dy[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };

const int MOD = 1e9 + 7;
ll prime = 786433;

ll power(int n, int p)
{
	ll ans = 1, a = n;
	while (p)
	{
		if (p & 1)
			ans = ans * a % MOD;
		a = a * a % MOD;
		p >>= 1;
	}

	return ans;
}

int Rolling_Hash(string s)
{
	// s[0] * power(prime, 1) + s[1] * power(prime, 2) + ....... + s[n - 1] * power(prime, n).

	int n = s.size();
	ll ans = 0, prime_power = prime;
	for (int i = 0; i < n; ++i)
	{
		ans = (ans + (s[i] - 'a' + 1) * prime_power) % MOD;
		prime_power = prime_power * prime % MOD;
	}

	return ans;
}

void Solve()
{
	string a, b;
	cin >> a >> b;

	int n = a.size(), m = b.size();

	if (m > n)
		cout << 0 << endl;

	else
	{
		ll text_hash = Rolling_Hash(a.substr(0, m)), pattern_hash = Rolling_Hash(b);
		int ans = (text_hash == pattern_hash);
		for (int i = 1; i + m - 1 < n; ++i)
		{
			// 1. Remove the first current character in text_hash.
			text_hash = (text_hash - (a[i - 1] - 'a' + 1) * prime + MOD) % MOD;

			// 2. Divide text_hash by prime.
			text_hash = text_hash * power(prime, MOD - 2) % MOD;

			// 3. Add the last current character in text_hash.
			text_hash = (text_hash + (a[i + m - 1] - 'a' + 1) * power(prime, m)) % MOD;

			// If text_hash equals pattern_hash, add 1 to the answer.
			ans += (text_hash == pattern_hash);
		}

		cout << ans << endl;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("C:\\Sublime\\input.txt", "r", stdin);
	freopen("C:\\Sublime\\output.txt", "w", stdout);
#endif

	Solve();

	cerr << "Basel Al-Jabari." << endl;

	return 0;
}
