#include "vec4.h"
#include <cmath>
#include <iomanip>

/**
 * @brief vec4::vec4 Default constructor. Initializes all elements to 0.
 */
vec4::vec4() : vec4(0,0,0,0) {}

/**
 * @brief vec4::vec4 vec4 Constructor. Creates a 4D vector with values x, y, z, and w.
 * @param x
 * @param y
 * @param z
 * @param w
 */
vec4::vec4(float x, float y, float z, float w) : data{x, y, z, w} {}

/**
 * @brief vec4::vec4 Copy constructor. Sets each element of this->data to v2's corresponding data.
 * @param v2 the vec4 object to copy
 */
vec4::vec4(const vec4 &v2) : vec4(v2.data[0], v2.data[1], v2.data[2], v2.data[3]) {}

/**
 * @brief vec4::operator [] Returns the value at index.
 * @param index
 * @return the value at index
 */
float vec4::operator[](unsigned int index) const {
    if (index > 3) {
        throw std::out_of_range("Index out of range.");
    }
    return data[index];
}

/**
 * @brief vec4::operator [] Returns a reference to the value at index.
 * @param index
 * @return a reference to the value at index
 */
float& vec4::operator[](unsigned int index) {
    if (index > 3) {
        throw std::out_of_range("Index out of range.");
    }
    return data[index];
}

/**
 * @brief vec4::operator = Sets each element of this->data to v2's corresponding data, then returns this.
 * @param v2 the vec4 object to set this equal to
 * @return this
 */
vec4& vec4::operator=(const vec4 &v2) {
    data[0] = v2.data[0];
    data[1] = v2.data[1];
    data[2] = v2.data[2];
    data[3] = v2.data[3];

    return *this;
};

/**
 * @brief vec4::operator == Test for equality.
 * @param v2 a reference to the vec4 object to compare the equality of this to
 * @return true if the two vec4s are equal
 */
bool vec4::operator==(const vec4 &v2) const {
    if (data[0] == v2.data[0] && data[1] == v2.data[1] && data[2] == v2.data[2] && data[3] == v2.data[3]) {
        return true;
    }
    return false;
}

/**
 * @brief vec4::operator != Test for inequality.
 * @param v2 a reference to the vec4 object to compare the equality of this to
 * @return true if the two vec4s are not equal
 */
bool vec4::operator!=(const vec4 &v2) const {
    if (*this == v2) {
        return false;
    }
    return true;
}

/**
 * @brief vec4::operator += Add v2 to this and return this.
 * @param v2 the vec4 object to add to this
 * @return this
 */
vec4& vec4::operator+=(const vec4 &v2) {
    data[0] += v2.data[0];
    data[1] += v2.data[1];
    data[2] += v2.data[2];
    data[3] += v2.data[3];
    return *this;
}

/**
 * @brief vec4::operator -= Subtract v2 from this and return this.
 * @param v2 the vec4 object to subtract from this
 * @return this
 */
vec4& vec4::operator-=(const vec4 &v2) {
    data[0] -= v2.data[0];
    data[1] -= v2.data[1];
    data[2] -= v2.data[2];
    data[3] -= v2.data[3];
    return *this;
}

/**
 * @brief vec4::operator *= Multiply this by c and return this.
 * @param c the scalar to multiply this by
 * @return this
 */
vec4& vec4::operator*=(float c) {
    data[0] *= c;
    data[1] *= c;
    data[2] *= c;
    data[3] *= c;
    return *this;
}

/**
 * @brief vec4::operator /= Divide this by c and return this.
 * @param c the scale to divide this by
 * @return this
 */
vec4& vec4::operator/=(float c) {
    data[0] /= c;
    data[1] /= c;
    data[2] /= c;
    data[3] /= c;
    return *this;
}

/**
 * @brief vec4::operator + Returns a new vector that is the sum of this and v2.
 * @param v2
 * @return a new vec4 that is the sum of this and v2
 */
vec4  vec4::operator+(const vec4 &v2) const {
    float x = data[0] + v2.data[0];
    float y = data[1] + v2.data[1];
    float z = data[2] + v2.data[2];
    float w = data[3] + v2.data[3];

    vec4 temp = vec4(x, y, z, w);
    return temp;
}

/**
 * @brief vec4::operator - Returns a new vector that is the difference of this and v2.
 * @param v2
 * @return a new vec4 that is the difference of this and v2
 */
vec4  vec4::operator-(const vec4 &v2) const {
    float x = data[0] - v2.data[0];
    float y = data[1] - v2.data[1];
    float z = data[2] - v2.data[2];
    float w = data[3] - v2.data[3];

    vec4 temp = vec4(x, y, z, w);
    return temp;
}

/**
 * @brief vec4::operator * Returns a new vector that is this multiplied by scalar c.
 * @param c
 * @return a new vec4 that is this multiplied by scalar c
 */
vec4  vec4::operator*(float c) const {
    float x = data[0] * c;
    float y = data[1] * c;
    float z = data[2] * c;
    float w = data[3] * c;

    vec4 temp = vec4(x, y, z, w);
    return temp;
}

/**
 * @brief vec4::operator / Returns a new vector that is this divided by scalar c.
 * @param c
 * @return a new vec4 that is this divided by scalar c
 */
vec4  vec4::operator/(float c) const{
    float x = data[0] / c;
    float y = data[1] / c;
    float z = data[2] / c;
    float w = data[3] / c;

    vec4 temp = vec4(x, y, z, w);
    return temp;
}

/**
 * @brief dot Computes the dot product of v1 and v2.
 * @param v1
 * @param v2
 * @return the dot product of v1 and v2
 */
float dot(const vec4 &v1, const vec4 &v2) {
    return (v1[0] * v2[0]) + (v1[1] * v2[1]) + (v1[2] * v2[2]) + (v1[3] * v2[3]);
}

/**
 * @brief cross Computes the cross product of v1 and v2 using only their xyz elements.
 * @param v1
 * @param v2
 * @return the cross product of v1 and v2 as a vec4 with w = 0
 */
vec4 cross(const vec4 &v1, const vec4 &v2) {
    float x = v1[1]*v2[2] - v1[2]*v2[1];
    float y = v1[2]*v2[0] - v1[0]*v2[2];
    float z = v1[0]*v2[1] - v1[1]*v2[0];

    return vec4(x, y, z, 0);
}

/**
 * @brief length Returns the geometric length of the input vector.
 * @param v
 * @return the geometric length of v
 */
float length(const vec4 &v) {
    float temp = std::pow(v[0], 2) + std::pow(v[1], 2) + std::pow(v[2], 2) + std::pow(v[3], 2);
    return std::sqrt(temp);
}

/**
 * @brief operator * Scalar multiplication.
 * @param c
 * @param v
 * @return a new vec4 that is v multiplied by scalar c
 */
vec4 operator*(float c, const vec4 &v) {
    return v*c;
}

/**
 * @brief normalize Returns a normalized copy of v with length 1.
 * @param v
 * @return a normalized copy of v
 */
vec4 normalize(const vec4& v) {
    return v/length(v);
}

/**
 * @brief operator << Prints the vector to a stream in a nice format.
 * @param o
 * @param v
 * @return the output stream
 */
std::ostream &operator<<(std::ostream &o, const vec4 &v) {
    o << std::fixed << std::setprecision(4);
    o << "(" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << ")";
    return o;
}
