class Solution {
public:
	static bool compare(int a, int b)
	{
		string str1, str2;
		str1.append(to_string(a));
		str1.append(to_string(b));
		str2.append(to_string(b));
		str2.append(to_string(a));
		return str1 < str2;
	};
	string PrintMinNumber(vector<int> numbers) {
		string output;
		sort(numbers.begin(), numbers.end(), &Solution::compare);
		for (auto it = numbers.begin(); it != numbers.end(); it++){
			output.append(to_string(*it));
		}
		return output;
	}
};
