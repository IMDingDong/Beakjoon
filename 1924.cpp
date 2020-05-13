#include <iostream>

using namespace std;

int main() {
	int x, y;	// 1
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31 };	// 1
	cin >> x >> y;	// 1

	int sum = 0;	// 1
	for (int i = 0; i < x - 1; i++) {	// n
		sum += month[i];
	}

	sum += y;

	switch(sum % 7) {
		case 1:
			cout << "MON";
			break;
		case 2:
			cout << "TUE";
			break;
		case 3:
			cout << "WED";
			break;
		case 4:
			cout << "THU";
			break;
		case 5:
			cout << "FRI";
			break;
		case 6:
			cout << "SAT";
			break;
		case 0:
			cout << "SUN";
			break;
	}

	return 0;
}