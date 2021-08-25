#include <iostream>
using namespace std;
int factorial(int num) {
	if (num <= 1)
		return 1;
	else return num * factorial(num - 1);


}
int main() {
	int num = 10;
	for(int i=0;i<=num;i++)
	cout << i<<"!"<<'='<<factorial(i)<<endl;
 }