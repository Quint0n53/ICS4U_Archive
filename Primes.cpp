#include <iostream>
#include <vector>

using namespace std;
vector <int> primes; //prime list
bool prime = true;

void isprime(int num) {//check each numberfor divisibilty
	for (int i = 2; i < num; i++ ) {//try to divide by each num below it, starting at 2
		if (num % i != 0) {//if it doesnt go clean. Continue with true
			prime = true;
		}
		else {//if it comes clean not prime, stop and check next num
			prime = false;
			break;
		}
	}
	if (prime) {//if it remained true all the way, must be prime
		cout << num << " ";//output
		primes.push_back(num);//add to counter
	}
}
int main() {
	cout << "These will be the first 1000 primes\n";
	for (int i = 1; primes.size() <= 1000; i++) {//loop until primes = 1000
		isprime(i);//check with function
	}
	system("pause");//sorry
	return 0;
}
