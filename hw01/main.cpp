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

/**
 * @brief vec4ConstructorTest Tests vec4()
 */
void vec4ConstructorTest() {
    vec4 a;
    vec4 b(1.f, 2.f, 3.f, 4.f);
    vec4 c(b);
    cout << "vec4 default constructor expected: (0, 0, 0, 0) actual: " << a << endl;
    cout << "vec4 value constructor expected: (1, 2, 3, 4) actual: " << b << endl;
    cout << "vec4 copy constructor expected: (1, 2, 3, 4) actual: " << c << endl;
}

/**
 * @brief vec4AssignTest Tests operator=
 */
void vec4AssignTest() {
    vec4 a(1.f, 2.f, 3.f, 4.f);
    vec4 b;
    b = a;
    cout << "vec4 operator= expected: (1, 2, 3, 4) actual: " << b << endl;
}

/**
 * @brief vec4EqualityTest Tests operator== and operator!=
 */
void vec4EqualityTest() {
    vec4 a(1.f, 2.f, 3.f, 4.f);
    vec4 b(1.f, 2.f, 3.f, 4.f);
    vec4 c(0.f, 0.f, 0.f, 0.f);
    cout << "vec4 == expected: 1 actual: " << (a == b) << endl;
    cout << "vec4 != expected: 1 actual: " << (a != c) << endl;
}

/**
 * @brief vec4DotTest Tests dot()
 */
void vec4DotTest() {
    vec4 a(1.f, 2.f, 3.f, 4.f);
    vec4 b(2.f, 4.f, 6.f, 8.f);
    cout << "vec4 dot expected: 60 actual: " << dot(a, b) << endl;
}

/**
 * @brief vec4CrossTest Tests cross()
 */
void vec4CrossTest() {
    vec4 a(1.f, 0.f, 0.f, 0.f);
    vec4 b(0.f, 1.f, 0.f, 0.f);
    cout << "vec4 cross expected: (0, 0, 1, 0) actual: " << cross(a, b) << endl;
}

/**
 * @brief vec4NormalizeTest Tests normalize()
 */
void vec4NormalizeTest() {
    vec4 a(0.f, 3.f, 0.f, 0.f);
    cout << "vec4 normalize expected: (0, 1, 0, 0) actual: " << normalize(a) << endl;
}

/**
 * @brief mat4ConstructorTest Tests mat4()
 */
void mat4ConstructorTest() {
    mat4 a;
    mat4 b(2.f);
    mat4 c(vec4(1,0,0,0), vec4(0,1,0,0), vec4(0,0,1,0), vec4(0,0,0,1));
    mat4 d(a);
    cout << "mat4 default constructor expected:" << endl;
    cout << "(1,0,0,0)\n(0,1,0,0)\n(0,0,1,0)\n(0,0,0,1)" << endl;
    cout << "actual:" << endl << a << endl;
    cout << "mat4 diagonal constructor expected diagonal 2:" << endl << b << endl;
    cout << "mat4 column constructor expected identity:" << endl << c << endl;
    cout << "mat4 copy constructor expected identity:" << endl << d << endl;
}

/**
 * @brief mat4AssignTest Tests operator=
 */
void mat4AssignTest() {
    mat4 a(2.f);
    mat4 b;
    b = a;
    cout << "mat4 operator= expected diagonal 2:" << endl << b << endl;
}

/**
 * @brief mat4EqualityTest Tests operator== and operator!=
 */
void mat4EqualityTest() {
    mat4 a(1.f);
    mat4 b(1.f);
    mat4 c(2.f);
    cout << "mat4 == expected: 1 actual: " << (a == b) << endl;
    cout << "mat4 != expected: 1 actual: " << (a != c) << endl;
}

/**
 * @brief mat4RotateTest Tests mat4::rotate()
 */
void mat4RotateTest() {
    mat4 r90 = mat4::rotate(90.f, 0.f, 0.f, 1.f);
    mat4 r180 = mat4::rotate(180.f, 0.f, 0.f, 1.f);
    vec4 v(1.f, 0.f, 0.f, 1.f);
    cout << "mat4 rotate 90 around Z * (1,0,0,1) expected: (0, 1, 0, 1) actual: " << (r90 * v) << endl;
    cout << "mat4 rotate 180 around Z * (1,0,0,1) expected: (-1, 0, 0, 1) actual: " << (r180 * v) << endl;
}

/**
 * @brief mat4MultiplyTest Tests operator*
 */
void mat4MultiplyTest() {
    mat4 a = mat4::translate(1.f, 2.f, 3.f);
    mat4 b = mat4::scale(2.f, 2.f, 2.f);
    vec4 v(1.f, 0.f, 0.f, 1.f);
    cout << "mat4 * mat4 expected:" << endl;
    cout << "(2,0,0,1)\n(0,2,0,2)\n(0,0,2,3)\n(0,0,0,1)" << endl;
    cout << "actual:" << endl << (a * b) << endl;
    cout << "mat4 * vec4 expected: (2, 2, 3, 1) actual: " << (a * v) << endl;
    cout << "vec4 * mat4 expected: (1, 0, 0, 2) actual: " << (v * a) << endl;
}

int main() {
	// Example test (won't work until you implement vec4's operator+ and operator<<)
	vec4AddTest();
	// Add your own tests here
    vec4ConstructorTest();
    vec4AssignTest();
    vec4EqualityTest();
    vec4DotTest();
    vec4CrossTest();
    vec4NormalizeTest();
    mat4ConstructorTest();
    mat4AssignTest();
    mat4EqualityTest();
    mat4RotateTest();
    mat4MultiplyTest();

}
