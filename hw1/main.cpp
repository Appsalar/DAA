#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	auto compare = [](const string& str1, const string& str2)->bool
	{
		bool lel = str1.size()< str2.size() ? true : false;

		int minsize = lel ? str1.size() : str2.size();

		//int comp = str1.compare(0, minsize, str2);

		for (int i = 0; i < minsize; ++i)
		{
			if (str1[i] != str2[i])
			{
				if (str1[i] < str2[i])
					return false;
				return true;
			}
		}

		if (lel)
		{
			int i = minsize;
			while (str2[i] == str1[0])
				++i;

			if (str2[i] < str1[0] && str2[i] != '\n')
				return true;
			return false;
		}
		int i = minsize;
		while (str1[i] == str2[0])
			++i;
		if (str1[i] < str2[0] && str1[i] != '\n')
			return false;
		return true;
	};

	vector<string> arr;

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	make_heap(arr.begin(), arr.end(), compare);

	string out;
	for (int i = 0; i < n; ++i)
	{
		out += arr[0];
		pop_heap(arr.begin(), arr.end(), compare);
		arr.pop_back();
	}

	cout << out << "\n";

	return 0;
}