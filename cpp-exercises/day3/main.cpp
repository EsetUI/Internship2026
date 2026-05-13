#include <iostream>
using namespace std;

double c_to_f(double);

int main() {
	double degrees;
	cout << "Enter a temperature to convert (celsius to fahrenheit): ";
	cin >> degrees;

	cout << "Your temperature in fahrenheit is " << c_to_f(degrees) << " degrees\n";
}

double c_to_f(double c) {
	return c * 9.0 / 5.0 + 32.0;
}
