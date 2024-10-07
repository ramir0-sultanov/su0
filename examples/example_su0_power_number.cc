#include <su0/power_number.hh>
#include <iostream>
#include <iomanip>

template <auto Exponent, class Container>
std::ostream& operator<<(
    std::ostream& os,
    const su0::PowerOf10<Exponent, Container>& object
) {
  auto string = std::string{};
  auto value = object.container();
  auto e = Exponent;
  while (value <= -10 || value >= +10) {
    string = std::to_string(value % 10) + string;
    value /= 10;
    e++;
  }
  os << value << "." << string << "e";
  if (e >= 0) {
    os << "+";
  }
  os << e;
  return os;
}

int main() {
  std::cout << std::setprecision(25) << std::scientific;
  std::cout << "1111111111111111111e-256 [long double]:\t" <<
      1111111111111111111e-256l << '\n';
  constexpr auto verySmallNumber =
      su0::PowerOf10<-256ll>{1111111111111111111ll};
  std::cout << "1111111111111111111e-256 [PowerOf10]:\t" <<
      verySmallNumber << '\n';
  std::cout << "1111111111111111111e+256 [long double]:\t" <<
      1111111111111111111e+256l << '\n';
  constexpr auto veryLargeNumber =
      su0::PowerOf10<+256ll>{1111111111111111111ll};
  std::cout << "1111111111111111111e+256 [PowerOf10]:\t" <<
      veryLargeNumber << '\n';
}
