#include <iostream>

using namespace std;

int main(int args, char * argv[]) {
	int score;
	cin >> score;
	
	int grade;
	grade = score / 10;
	switch(grade) {
	case 10:
		cout << 'A';
		break;
	case 9:
		cout << 'A';
		break;
	case 8:
		cout << 'B';
		break;
	case 7:
		cout << 'C';
		break;
	case 6:
		cout << 'D';
		break;
	default:
		cout << 'F';
		break;
	}
}