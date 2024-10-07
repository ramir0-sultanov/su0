# su0

su0 is a header-only library for simulation of universe.

## Testing

Tests are performed during compilation (via "static_assert"s). 
If a compilation of tests didn't return errors then it means tests passed.

```console
cmake -S <path-to-local-repository> -B <path-to-build-directory>
make -C <path-to-build-directory>
```

## Features

### su0::PowerOf10<Exponent, Container>

#### Avoid floating-point errors

`examples/example_su0_power_number.cc`
```c++
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
  //! will print
  //! 1111111111111111111e-256 [long double]: 1.1111111111111111109673800e-238
  //! 1111111111111111111e-256 [PowerOf10]:   1.111111111111111111e-238
  std::cout << "1111111111111111111e+256 [long double]:\t" <<
      1111111111111111111e+256l << '\n';
  constexpr auto veryLargeNumber =
      su0::PowerOf10<+256ll>{1111111111111111111ll};
  std::cout << "1111111111111111111e+256 [PowerOf10]:\t" <<
      veryLargeNumber << '\n';
  //! will print
  //! 1111111111111111111e+256 [long double]: 1.1111111111111111110181092e+274
  //! 1111111111111111111e+256 [PowerOf10]:   1.111111111111111111e+274
}
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

Distributed under the `MIT-0` license. See license.txt for more information.
