//: T02:Rational.h {-xo}
// Complete the pre-condition, post-condition, and exception specification
// for class Rational.
#ifndef RATIONAL_H
#define RATIONAL_H
#include <ios>
#include <iosfwd>
#include <stdexcept>
using namespace std;

class Rational {
public:
  /*
   * Prefix:
   *  denominator != 0
   */
  Rational(int numerator = 0, int denominator = 1) throw (invalid_argument);
  /*
   * revert the sign of numerator
   */
  Rational operator-() const;
  /*
   * Postfix:
   *  return Rational.numerator = left.numerator * right.denominator
   *                            + left.denominator * right.numerator;
   *         Rational.denominator = left.denominator * right.denominator;
   */
  friend Rational operator+(const Rational&,
                            const Rational&);
  /*
   * Postfix:
   *  return Rational.numerator = left.numerator * right.denominator
   *                            - left.denominator * right.numerator;
   *         Rational.denominator = left.denominator * right.denominator;
   */
  friend Rational operator-(const Rational&,
                            const Rational&);
  /*
   * Postfix:
   *  return Rational.numerator = left.numerator * right.numerator;
   *         Rational.denominator = left.denominator * right.denominator;
   */
  friend Rational operator*(const Rational&,
                            const Rational&);
  /*
   * Prefix:
   * right.numerator  != 0
   *
   * Postfix:
   *  return Rational.numerator = left.numerator * right.denominator;
   *         Rational.denominator = left.denominator * right.numerator;
   */
  friend Rational operator/(const Rational&,
                            const Rational&) throw (overflow_error);
  /*
   * insert Rational.numerator/Rational.denominator to the ostream
   * and return the ostream reference.
   */
  friend std::ostream&
    operator<<(std::ostream&, const Rational&);
  /*
   * retrive Rational.numerator/Rational.denominator from the istream
   * and return the istream reference.
   */
  friend std::istream&
    operator>>(std::istream&, Rational&) throw (ios_base::failure);
  /*
   * Postfix:
   *  return Rational.numerator = left.numerator * right.denominator
   *                            + left.denominator * right.numerator;
   *         Rational.denominator = left.denominator * right.denominator;
   */
  Rational& operator+=(const Rational&);
  /*
   * Postfix:
   *  return Rational.numerator = left.numerator * right.denominator
   *                            - left.denominator * right.numerator;
   *         Rational.denominator = left.denominator * right.denominator;
   */
  Rational& operator-=(const Rational&);
  /*
   * Postfix:
   *  return Rational.numerator = left.numerator * right.numerator;
   *         Rational.denominator = left.denominator * right.denominator;
   */
  Rational& operator*=(const Rational&);
  /*
   * Prefix:
   * right.numerator  != 0
   *
   * Postfix:
   *  return Rational.numerator = left.numerator * right.denominator;
   *         Rational.denominator = left.denominator * right.numerator;
   */
  Rational& operator/=(const Rational&) throw (overflow_error);
  /*
   * Postfix:
   *  return true if left.numerator   * right.denominator
   *               < left.denominator * right.numerator;
   *     else false
   */
  friend bool operator<(const Rational&,
                        const Rational&);
  /*
   * Postfix:
   *  return true if left.numerator   * right.denominator
   *               > left.denominator * right.numerator;
   *     else false
   */
  friend bool operator>(const Rational&,
                        const Rational&);
  /*
   * Postfix:
   *  return true if left.numerator   * right.denominator
   *              <= left.denominator * right.numerator;
   *     else false
   */
  friend bool operator<=(const Rational&,
                         const Rational&);
  /*
   * Postfix:
   *  return true if left.numerator   * right.denominator
   *              >= left.denominator * right.numerator;
   *     else false
   */
  friend bool operator>=(const Rational&,
                         const Rational&);
  /*
   * Postfix:
   *  return true if left.numerator   * right.denominator
   *              == left.denominator * right.numerator;
   *     else false
   */
  friend bool operator==(const Rational&,
                         const Rational&);
  /*
   * Postfix:
   *  return true if left.numerator   * right.denominator
   *              != left.denominator * right.numerator;
   *     else false
   */
  friend bool operator!=(const Rational&,
                         const Rational&);

protected:
  int gcd(int a, int b);
  Rational& format();

private:
  int num;
  int denom;
};
#endif // RATIONAL_H ///:~
