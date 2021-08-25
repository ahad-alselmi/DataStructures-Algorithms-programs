//lecture22 dynamic programming
#include<iostream>
#include<map>
#include<vector>
using namespace std;
/*map<int, int> fibnum;
int fibo(int n) {
	if (fibnum.find(n) != fibnum.end()) {//if it is the fibonacci of number found
		return fibnum[n];

	 }
	if (n == 0 || n == 1) { return n; }
		
	
		int res=	fibo(n - 1) + fibo(n - 2);
	fibnum[n] = res;
	return res;
}
int fibloop(int n) {
	if (n == 0 || n == 1)
		return n;

	int fib1 = 1;
	int fib0 = 0;
	int res = 0;

	for (int i = 2; i <= n; i++) {
		res = fib0+fib1;
		fib0 = fib1;
		fib1 = res;

	}
	return fib1;

}*/
/*class Solution {
public:
	vector<int> arr;
	int i ;
	vector<int> runningSum(vector<int>& nums) {
		for ( i = 0; i < nums.size(); i++) {
			if (i == 0)
			arr[0] =nums[0];
			arr[i]= nums[i]+nums[i+1];
			
		}
		return arr;
	}
};*/
/*حل ايناس
vector<int>sol;
for (int i = 0, j = n; i < n, j < n * 2; i++, j++) {
	sol.push_back(nums[i]);
	sol.push_back(nums[j]);
}
return sol;‏*/

class Solution {
public:
	int maximumWealth(vector<vector<int>>& accounts) {
		int sum1=0;
		int sum2=0;
		for (int i = 0; i < accounts.size(); i++) {
			for (int j =0; j < accounts[i].size(); j++) {
				 sum1 += accounts[i][j++];
				 sum2 += accounts[i++][j++];
				 

			}
		
		}if (sum1>=sum2)
		return sum1;
	}
};

/*class Solution {حل المهندس
public:
	int maximumWealth(vector<vector<int>>& accounts) {
		int max = INT_MIN; int current = 0;
		for (int i = 0; i < accounts.size(); i++) {
			for (int j = 0; j < accounts[i].size(); j++) {

				current += accounts[i][j];

			}
		}
		if (current > max)
			return current;
	}
};*/
int main() {

	vector < vector<int>> accounts = { { 1,2,3},{3,2,1} };
	Solution  s;
	cout << s.maximumWealth(accounts);
}
	/*int n = 6;
	 cout<<fibloop(n);*/
	
