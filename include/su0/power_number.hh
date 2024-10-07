#ifndef SU0_POWER_NUMBER_HH_
#define SU0_POWER_NUMBER_HH_

#include <cmath>
#include <concepts>
#include <type_traits>

namespace su0 {

/*!
 * @brief struct representing power of 10 numbers
 *     number = stored_value * 10 ^ exponent
 * @tparam Exponent is the value of an exponent
 *     @example 0, 1, -1, 3ul. -3ll
 * @tparam Container is the container type used internally for storing a number
 *     @note reflects the precision capacity of a number
 *     @note signed types allow to store signed values but unsigned types do not
 *     @example int, unsigned, long
 */
template <
    auto Exponent,
    class Container = decltype(Exponent)
> class PowerOf10 {
public:
  using container_type = Container;
  //! value representing exponentiation base
  constexpr static container_type BASE = 10;
  constexpr PowerOf10() = default;
  /*!
   * @brief constructs an instance using a value
   * @param value is the value to be stored in the container
   */
  constexpr PowerOf10(Container value);
  /*!
   * @brief compares two instances
   * @return
   *     if the two instance are equal -> true
   *     else -> false
   */
  constexpr bool operator==(const PowerOf10& o) const = default;
  /*!
   * @brief compares two instances
   * @return
   *     if the two instance are not equal -> true
   *     else -> false
   */
  constexpr bool operator!=(const PowerOf10& o) const = default;
  /*!
   * @brief compares two instances
   * @param o is the other instance
   * @return
   *     if *this < o -> value < 0
   *     if *this > o -> value > 0
   *     if *this == o -> 0
   */
  constexpr auto operator<=>(const PowerOf10& o) const = default;
  /*!
   * @brief compares two instances
   * @param o is the other instance
   * @return
   *     if *this < o -> true
   *     else -> false
   */
  constexpr bool operator<(const PowerOf10& o) const = default;
  /*!
   * @brief compares two instances
   * @param o is the other instance
   * @return
   *     if *this <= o -> true
   *     else -> false
   */
  constexpr bool operator<=(const PowerOf10& o) const = default;
  /*!
   * @brief compares two instances
   * @param o is the other instance
   * @return
   *     if *this > o -> true
   *     else -> false
   */
  constexpr bool operator>(const PowerOf10& o) const = default;
  /*!
   * @brief compares two instances
   * @param o is the other instance
   * @return
   *     if *this >= o -> true
   *     else -> false
   */
  constexpr bool operator>=(const PowerOf10& o) const = default;
  /*!
   * @brief applies + sign to stored value
   * @return copy of *this with applied + sign
   */
  constexpr PowerOf10 operator+() const;
  /*!
   * @brief applies - sign to stored value
   * @return copy of *this with applied - sign
   */
  constexpr PowerOf10 operator-() const;
  /*!
   * @brief adds instance to *this instance
   * @param o is the other instance to be added from right
   * @return copy of *this + o
   */
  constexpr PowerOf10 operator+(const PowerOf10& o) const;
  /*!
   * @brief substracts instance from *this instance
   * @param o is the other instance to be substracted from right
   * @return copy of *this - o
   */
  constexpr PowerOf10 operator-(const PowerOf10& o) const;
  /*!
   * @brief multiplies *this instance with other instance
   * @param o is the other instance to be multiplied with from right
   * @return copy of *this * o
   */
  constexpr PowerOf10 operator*(const PowerOf10& o) const;
  /*!
   * @brief divides *this instance by other instance
   * @param o is the other instance to be divided by
   * @return copy of *this / o
   */
  constexpr PowerOf10 operator/(const PowerOf10& o) const;
  /*!
   * @brief calculates remainder of dividing *this instance by other instance
   * @param o is the other instance to be divided by
   * @return copy of *this % o
   */
  constexpr PowerOf10 operator%(const PowerOf10& o) const;
  /*!
   * @brief adds instance to *this instance
   * @param o is the other instance to be added from right
   * @return *this + o
   */
  constexpr PowerOf10& operator+=(const PowerOf10& o);
  /*!
   * @brief substracts instance from *this instance
   * @param o is the other instance to be substracted from right
   * @return *this - o
   */
  constexpr PowerOf10& operator-=(const PowerOf10& o);
  /*!
   * @brief multiplies *this instance with other instance
   * @param o is the other instance to be multiplied with from right
   * @return *this * o
   */
  constexpr PowerOf10& operator*=(const PowerOf10& o);
  /*!
   * @brief divides *this instance by other instance
   * @param o is the other instance to be divided by
   * @return *this / o
   */
  constexpr PowerOf10& operator/=(const PowerOf10& o);
  /*!
   * @brief calculates remainder of dividing *this instance by other instance
   * @param o is the other instance to be divided by
   * @return *this % o
   */
  constexpr PowerOf10& operator%=(const PowerOf10& o);
  /*!
   * @brief pre-increments *this instance
   * @return ++*this
   */
  constexpr PowerOf10& operator++();
  /*!
   * @brief post-increments *this instance
   * @return copy of *this
   */
  constexpr PowerOf10 operator++(int);
  /*!
   * @brief pre-decrements *this instance
   * @return --*this
   */
  constexpr PowerOf10& operator--();
  /*!
   * @brief post-decrements *this instance
   * @return copy of *this
   */
  constexpr PowerOf10 operator--(int);
  /*!
   * @brief applies bitwise NOT operation
   * @return copy of ~*this
   */
  constexpr PowerOf10 operator~() const;
  /*!
   * @brief applies bitwise AND operation
   * @param o is the other instance to be applied from right
   * @return *this & o
   */
  constexpr PowerOf10 operator&(const PowerOf10& o) const;
  /*!
   * @brief applies bitwise OR operation
   * @param o is the other instance to be applied from right
   * @return *this | o
   */
  constexpr PowerOf10 operator|(const PowerOf10& o) const;
  /*!
   * @brief applies bitwise XOR operation
   * @param o is the other instance to be applied from right
   * @return *this ^ o
   */
  constexpr PowerOf10 operator^(const PowerOf10& o) const;
  /*!
   * @brief applies bitwise left shift operation
   * @param bits is the number of bits to shift
   * @return *this << bits
   */
  constexpr PowerOf10 operator<<(const std::size_t& bits) const;
  /*!
   * @brief applies bitwise right shift operation
   * @param bits is the number of bits to shift
   * @return *this >> bits
   */
  constexpr PowerOf10 operator>>(const std::size_t& bits) const;
  /*!
   * @brief applies bitwise AND operation
   * @param o is the other instance to be applied from right
   * @return *this = *this & o
   */
  constexpr PowerOf10& operator&=(const PowerOf10& o);
  /*!
   * @brief applies bitwise OR operation
   * @param o is the other instance to be applied from right
   * @return *this = *this | o
   */
  constexpr PowerOf10& operator|=(const PowerOf10& o);
  /*!
   * @brief applies bitwise XOR operation
   * @param o is the other instance to be applied from right
   * @return *this = *this ^ o
   */
  constexpr PowerOf10& operator^=(const PowerOf10& o);
  /*!
   * @brief applies bitwise left shift operation
   * @param bits is the number of bits to shift
   * @return *this = *this << bits
   */
  constexpr PowerOf10& operator<<=(const std::size_t& bits);
  /*!
   * @brief applies bitwise right shift operation
   * @param bits is the number of bits to shift
   * @return *this = *this >> bits
   */
  constexpr PowerOf10& operator>>=(const std::size_t& bits);
  /*!
   * @brief casts *this instance to the type T only explicitly
   * @tparam T is the type to be casted to
   */
  template <class T> constexpr explicit operator T() const;
  /*!
   * @brief gets value of container field
   * @return constant reference to container value
   */
  constexpr const Container& container() const;
protected:
  //! inside representation
  Container container_{};
private:
};

} /// namespace su0

namespace su0 {

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>::PowerOf10(Container value)
  : container_(value) {}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>
PowerOf10<Exponent, Container>::operator+() const {
  return { +this->container_ };
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>
PowerOf10<Exponent, Container>::operator-() const {
  return { -this->container_ };
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>
PowerOf10<Exponent, Container>::operator+(
    const PowerOf10& o
) const {
  return { this->container_ + o.container_ };
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>
PowerOf10<Exponent, Container>::operator-(
    const PowerOf10& o
) const {
  return { this->container_ - o.container_ };
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>
PowerOf10<Exponent, Container>::operator*(
    const PowerOf10& o
) const {
  auto ret = *this;
  ret *= o;
  return ret;
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>
PowerOf10<Exponent, Container>::operator/(
    const PowerOf10& o
) const {
  auto ret = *this;
  ret /= o;
  return ret;
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>
PowerOf10<Exponent, Container>::operator%(
    const PowerOf10& o
) const {
  return { this->container_ % o.container_ };
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>&
PowerOf10<Exponent, Container>::operator+=(
    const PowerOf10& o
) {
  this->container_ += o.container_;
  return *this;
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>&
PowerOf10<Exponent, Container>::operator-=(
    const PowerOf10& o
) {
  this->container_ -= o.container_;
  return *this;
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>&
PowerOf10<Exponent, Container>::operator*=(
    const PowerOf10& o
) {
  this->container_ *= o.container_;
  if constexpr (Exponent < 0) {
    this->container_ /= std::pow(PowerOf10::BASE, -Exponent);
  } else {
    this->container_ *= std::pow(PowerOf10::BASE, +Exponent);
  }
  return *this;
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>&
PowerOf10<Exponent, Container>::operator/=(
    const PowerOf10& o
) {
  if constexpr (Exponent < 0) {
    this->container_ *= std::pow(PowerOf10::BASE, -Exponent);
  } else {
    this->container_ /= std::pow(PowerOf10::BASE, +Exponent);
  }
  this->container_ /= o.container_;
  return *this;
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>&
PowerOf10<Exponent, Container>::operator%=(
    const PowerOf10& o
) {
  this->container_ %= o.container_;
  return *this;
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>&
PowerOf10<Exponent, Container>::operator++() {
  this->container_++;
  return *this;
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>
PowerOf10<Exponent, Container>::operator++(int) {
  auto prev = *this;
  this->container_++;
  return prev;
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>&
PowerOf10<Exponent, Container>::operator--() {
  this->container_--;
  return *this;
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>
PowerOf10<Exponent, Container>::operator--(int) {
  auto prev = *this;
  this->container_--;
  return prev;
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>
PowerOf10<Exponent, Container>::operator~() const {
  return { ~this->container_ };
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>
PowerOf10<Exponent, Container>::operator&(
    const PowerOf10& o
) const {
  return { this->container_ & o.container_ };
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>
PowerOf10<Exponent, Container>::operator|(
    const PowerOf10& o
) const {
  return { this->container_ | o.container_ };
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>
PowerOf10<Exponent, Container>::operator^(
    const PowerOf10& o
) const {
  return { this->container_ ^ o.container_ };
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>
PowerOf10<Exponent, Container>::operator<<(
    const std::size_t& bits
) const {
  return { this->container_ << bits };
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>
  PowerOf10<Exponent, Container>::operator>>(
    const std::size_t& bits
) const {
  return { this->container_ >> bits };
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>&
PowerOf10<Exponent, Container>::operator&=(
    const PowerOf10& o
) {
  this->container_ &= o.container_;
  return *this;
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>&
PowerOf10<Exponent, Container>::operator|=(
    const PowerOf10& o
) {
  this->container_ |= o.container_;
  return *this;
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>&
PowerOf10<Exponent, Container>::operator^=(
    const PowerOf10& o
) {
  this->container_ ^= o.container_;
  return *this;
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>&
PowerOf10<Exponent, Container>::operator<<=(
    const std::size_t& bits
) {
  this->container_ <<= bits;
  return *this;
}

template <auto Exponent, class Container>
constexpr PowerOf10<Exponent, Container>&
PowerOf10<Exponent, Container>::operator>>=(
    const std::size_t& bits
) {
  this->container_ >>= bits;
  return *this;
}

template <auto Exponent, class Container>
template <class T>
constexpr PowerOf10<Exponent, Container>::operator T() const {
  if constexpr (Exponent < 0) {
    return this->container_ /
        static_cast<Container>(std::pow(PowerOf10::BASE, -Exponent));
  } else {
    return this->container_ *
        static_cast<Container>(std::pow(PowerOf10::BASE, +Exponent));
  }
}

template <auto Exponent, class Container>
constexpr const Container& PowerOf10<Exponent, Container>::container() const {
  return this->container_;
}

} /// namespace su0

#endif /// SU0_POWER_NUMBER_HH_
