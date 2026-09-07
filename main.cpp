// Base code written by Jan Allbeck, Chris Czyzewicz, Cory Boatright, Tiantian Liu, Benedict Brown, and Adam Mally
// University of Pennsylvania

// At least some C++ compilers do funny things
// to C's math.h header if you don't define this
#define _USE_MATH_DEFINES

#include "vec4.h"
#include "mat4.h"
#include <iostream>
#include <math.h>
using namespace std;

void vec4AddTest() {
	vec4 a = vec4(1.f, 2.f, 3.f, 4.f);
	vec4 b = vec4(2.f, 4.f, 6.f, 8.f);
	std::cout << "vec4 + vec4 expected value: (3.0, 6.0, 9.0, 12.0)" << std::endl;
	std::cout << "vec4 + vec4 actual value: " << (a + b) << std::endl;
}

int main() {
	// Example test (won't work until you implement vec4's operator+ and operator<<)
	vec4AddTest();
	// Add your own tests here
}
