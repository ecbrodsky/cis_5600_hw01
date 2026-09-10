#include "vec4.h"
#include "mat4.h"
#include <math.h>
#include <cmath>

/**
 * @brief mat4::mat4 Default constructor. Initializes to identity matrix.
 */
mat4::mat4() : mat4(1.0f) {}

/**
 * @brief mat4::mat4 Initializes diagonal values to diag. All other values are 0.
 * @param diag
 */
mat4::mat4(float diag) : mat4(vec4(diag, 0, 0, 0), vec4(0, diag, 0, 0), vec4(0, 0, diag, 0), vec4(0, 0, 0, diag)) {}

/**
 * @brief mat4::mat4 Initializes matrix with each vector representing a column.
 * @param col0
 * @param col1
 * @param col2
 * @param col3
 */
mat4::mat4(const vec4 &col0, const vec4 &col1, const vec4 &col2, const vec4 &col3)
    : data{col0, col1, col2, col3} {}

/**
 * @brief mat4::mat4 Copy constructor.
 * @param m2
 */
mat4::mat4(const mat4 &m2) : mat4(m2.data[0], m2.data[1], m2.data[2], m2.data[3]) {}

/**
 * @brief mat4::operator[] Returns the values of the column at the index.
 * @param index
 * @return the values of the column at the index
 */
vec4 mat4::operator[](unsigned int index) const {
    if (index > 3) throw std::out_of_range("Index out of range.");
    return data[index];
}

/**
 * @brief mat4::operator[] Returns a reference to the column at the index.
 * @param index
 * @return reference to the column at the index
 */
vec4& mat4::operator[](unsigned int index) {
    if (index > 3) throw std::out_of_range("Index out of range.");
    return data[index];
}

/**
 * @brief mat4::identity Generates a 4x4 identity matrix.
 * @return a 4x4 identity matrix
 */
mat4 mat4::identity() { return mat4(1.0f); }

/**
 * @brief mat4::translate Takes an xyz displacement and outputs a 4x4 translation matrix.
 * @param x
 * @param y
 * @param z
 * @return a 4x4 translation matrix
 */
mat4 mat4::translate(float x, float y, float z) {
    mat4 m(1.0f);
    m.data[3] = vec4(x, y, z, 1);
    return m;
}

/**
 * @brief mat4::scale Takes an xyz scale and outputs a 4x4 scale matrix.
 * @param x
 * @param y
 * @param z
 * @return a 4x4 scale matrix
 */
mat4 mat4::scale(float x, float y, float z) {
    return mat4(
        vec4(x, 0, 0, 0),
        vec4(0, y, 0, 0),
        vec4(0, 0, z, 0),
        vec4(0, 0, 0, 1)
        );
}

/**
 * @brief mat4::rotate Creates a 3D rotation matrix using Rodrigues' formula.
 * @param angle
 * @param x
 * @param y
 * @param z
 * @return a 4x4 rotation matrix
 */
mat4 mat4::rotate(float angle, float x, float y, float z) {
    float r = angle * M_PI / 180.0f;
    float c = std::cos(r), s = std::sin(r), t = 1 - c;
    float len = std::sqrt(x*x + y*y + z*z);
    x /= len; y /= len; z /= len;
    return mat4(
        vec4(t*x*x + c,   t*x*y + s*z, t*x*z - s*y, 0),
        vec4(t*x*y - s*z, t*y*y + c,   t*y*z + s*x, 0),
        vec4(t*x*z + s*y, t*y*z - s*x, t*z*z + c,   0),
        vec4(0,           0,            0,            1)
        );
}

/**
 * @brief mat4::operator= Assigns m2's data to this and returns this.
 * @param m2
 * @return this
 */
mat4& mat4::operator=(const mat4 &m2) {
    data[0] = m2.data[0]; data[1] = m2.data[1];
    data[2] = m2.data[2]; data[3] = m2.data[3];
    return *this;
}

/**
 * @brief mat4::operator== Tests for equality.
 * @param m2
 * @return true if matrices are equal
 */
bool mat4::operator==(const mat4 &m2) const {
    return data[0] == m2.data[0] && data[1] == m2.data[1] && data[2] == m2.data[2] && data[3] == m2.data[3];
}

/**
 * @brief mat4::operator!= Tests for inequality.
 * @param m2
 * @return true if matrices are not equal
 */
bool mat4::operator!=(const mat4 &m2) const { return !(*this == m2); }

/**
 * @brief mat4::operator+= Adds elements of m2 to this and returns this.
 * @param m2
 * @return this
 */
mat4& mat4::operator+=(const mat4 &m2) {
    data[0] += m2.data[0]; data[1] += m2.data[1];
    data[2] += m2.data[2]; data[3] += m2.data[3];
    return *this;
}

/**
 * @brief mat4::operator-= Subtracts elements of m2 from this and returns this.
 * @param m2
 * @return this
 */
mat4& mat4::operator-=(const mat4 &m2) {
    data[0] -= m2.data[0]; data[1] -= m2.data[1];
    data[2] -= m2.data[2]; data[3] -= m2.data[3];
    return *this;
}

/**
 * @brief mat4::operator*= Multiplies this by scalar c and returns this.
 * @param c
 * @return this
 */
mat4& mat4::operator*=(float c) {
    data[0] *= c; data[1] *= c; data[2] *= c; data[3] *= c;
    return *this;
}

/**
 * @brief mat4::operator/= Divides this by scalar c and returns this.
 * @param c
 * @return this
 */
mat4& mat4::operator/=(float c) {
    data[0] /= c; data[1] /= c; data[2] /= c; data[3] /= c;
    return *this;
}

/**
 * @brief mat4::operator+ Returns a new matrix that is the sum of this and m2.
 * @param m2
 * @return a new matrix that is the sum of this and m2
 */
mat4 mat4::operator+(const mat4 &m2) const { mat4 r(*this); r += m2; return r; }

/**
 * @brief mat4::operator- Returns a new matrix that is the difference of this and m2.
 * @param m2
 * @return a new matrix that is the difference of this and m2
 */
mat4 mat4::operator-(const mat4 &m2) const { mat4 r(*this); r -= m2; return r; }

/**
 * @brief mat4::operator* Returns a new matrix that is this multiplied by scalar c.
 * @param c
 * @return a new matrix multiplied by c
 */
mat4 mat4::operator*(float c) const { mat4 r(*this); r *= c; return r; }

/**
 * @brief mat4::operator/ Returns a new matrix that is this divided by scalar c.
 * @param c
 * @return a new matrix divided by c
 */
mat4 mat4::operator/(float c) const { mat4 r(*this); r /= c; return r; }

/**
 * @brief mat4::operator* Matrix multiplication.
 * @param m2
 * @return a new matrix that is the product of this and m2
 */
mat4 mat4::operator*(const mat4 &m2) const {
    vec4 r0 = row(*this, 0), r1 = row(*this, 1), r2 = row(*this, 2), r3 = row(*this, 3);
    return mat4(
        vec4(dot(r0,m2.data[0]), dot(r1,m2.data[0]), dot(r2,m2.data[0]), dot(r3,m2.data[0])),
        vec4(dot(r0,m2.data[1]), dot(r1,m2.data[1]), dot(r2,m2.data[1]), dot(r3,m2.data[1])),
        vec4(dot(r0,m2.data[2]), dot(r1,m2.data[2]), dot(r2,m2.data[2]), dot(r3,m2.data[2])),
        vec4(dot(r0,m2.data[3]), dot(r1,m2.data[3]), dot(r2,m2.data[3]), dot(r3,m2.data[3]))
    );
}

/**
 * @brief mat4::operator* Matrix/vector multiplication, assumes v is a column vector.
 * @param v
 * @return the resulting vec4
 */
vec4 mat4::operator*(const vec4 &v) const {
    vec4 r0 = row(*this, 0), r1 = row(*this, 1), r2 = row(*this, 2), r3 = row(*this, 3);
    return vec4(dot(r0, v), dot(r1, v), dot(r2, v), dot(r3, v));
}

/**
 * @brief transpose Returns the transpose of the input matrix.
 * @param m
 * @return the transposed matrix
 */
mat4 transpose(const mat4 &m) {
    return mat4(row(m, 0), row(m, 1), row(m, 2), row(m, 3));
}

/**
 * @brief row Returns the ith row of the input matrix.
 * @param m
 * @param index
 * @return the ith row as a vec4
 */
vec4 row(const mat4 &m, unsigned int index) {
    if (index > 3) throw std::out_of_range("Index out of range.");
    return vec4(m[0][index], m[1][index], m[2][index], m[3][index]);
}

/**
 * @brief operator* Scalar multiplication.
 * @param c
 * @param m
 * @return a new matrix multiplied by c
 */
mat4 operator*(float c, const mat4 &m) { return m * c; }

/**
 * @brief operator* Vector/matrix multiplication, assumes v is a row vector.
 * @param v
 * @param m
 * @return the resulting vec4
 */
vec4 operator*(const vec4 &v, const mat4 &m) {
    return vec4(dot(v, m[0]), dot(v, m[1]), dot(v, m[2]), dot(v, m[3]));
}

/**
 * @brief operator<< Prints formatted matrix to stream.
 * @param o
 * @param m
 * @return the output stream
 */
std::ostream &operator<<(std::ostream &o, const mat4 &m) {
    for (int i = 0; i < 4; i++) {
        o << row(m, i) << "\n";
    }
    return o;
}