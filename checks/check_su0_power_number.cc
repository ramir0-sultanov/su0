#include <su0/power_number.hh>

template <class T>
constexpr bool as_bool(const T& o) {
  return static_cast<bool>(o);
}

template <class T>
constexpr char as_char(const T& o) {
  return static_cast<char>(o);
}

template <class T>
constexpr unsigned char as_uchar(const T& o) {
  return static_cast<unsigned char>(o);
}

template <class T>
constexpr short as_short(const T& o) {
  return static_cast<short>(o);
}

template <class T>
constexpr unsigned short as_ushort(const T& o) {
  return static_cast<unsigned short>(o);
}

template <class T>
constexpr int as_int(const T& o) {
  return static_cast<int>(o);
}

template <class T>
constexpr unsigned int as_uint(const T& o) {
  return static_cast<unsigned int>(o);
}

template <class T>
constexpr long as_long(const T& o) {
  return static_cast<long>(o);
}

template <class T>
constexpr unsigned long as_ulong(const T& o) {
  return static_cast<unsigned long>(o);
}

template <class T>
constexpr long long as_longlong(const T& o) {
  return static_cast<long long>(o);
}

template <class T>
constexpr unsigned long long as_ulonglong(const T& o) {
  return static_cast<unsigned long long>(o);
}

template <class T>
constexpr long double as_longdouble(const T& o) {
  return static_cast<long double>(o);
}

template <class T>
constexpr double as_double(const T& o) {
  return static_cast<double>(o);
}

template <class T>
constexpr float as_float(const T& o) {
  return static_cast<float>(o);
}

int main() {
  {
    using type = su0::PowerOf10<0>;
    {
      constexpr auto val = typename type::container_type{};
      constexpr type o{};
      static_assert(o == val == true);
      static_assert(o != val == false);
      static_assert(o < val == false);
      static_assert(o <= val == true);
      static_assert(o > val == false);
      static_assert(o >= val == true);
    }
    {
      constexpr auto val = typename type::container_type{1};
      constexpr type o{};
      static_assert(o == val == false);
      static_assert(o != val == true);
      static_assert(o < val == true);
      static_assert(o <= val == true);
      static_assert(o > val == false);
      static_assert(o >= val == false);
    }
    {
      constexpr auto val = typename type::container_type{-1};
      constexpr type o{};
      static_assert(o == val == false);
      static_assert(o != val == true);
      static_assert(o < val == false);
      static_assert(o <= val == false);
      static_assert(o > val == true);
      static_assert(o >= val == true);
    }
    {
      constexpr auto val = typename type::container_type{0};
      constexpr type o{-1};
      static_assert(o == val == false);
      static_assert(o != val == true);
      static_assert(o < val == true);
      static_assert(o <= val == true);
      static_assert(o > val == false);
      static_assert(o >= val == false);
    }
    {
      constexpr auto val = typename type::container_type{0};
      constexpr type o{1};
      static_assert(o == val == false);
      static_assert(o != val == true);
      static_assert(o < val == false);
      static_assert(o <= val == false);
      static_assert(o > val == true);
      static_assert(o >= val == true);
    }
    {
      static_assert(type{0} == type{0});
      static_assert(type{0} != type{1});
      static_assert(type{0} < type{1});
      static_assert(type{0} <= type{0});
      static_assert(type{1} > type{0});
      static_assert(type{0} >= type{0});
      static_assert(type{0} <=> type{0} == 0);
      static_assert(type{0} <=> type{1} < 0);
      static_assert(type{1} <=> type{0} > 0);
      static_assert(type{1} <=> type{1} == 0);
    }
    {
      constexpr auto val = 0;
      constexpr type o{val};
      static_assert(static_cast<bool>(o) == as_bool(val));
      static_assert(static_cast<char>(o) == as_char(val));
      static_assert(static_cast<unsigned char>(o) == as_uchar(val));
      static_assert(static_cast<short>(o) == as_short(val));
      static_assert(static_cast<unsigned short>(o) == as_ushort(val));
      static_assert(static_cast<int>(o) == as_int(val));
      static_assert(static_cast<unsigned int>(o) == as_uint(val));
      static_assert(static_cast<long>(o) == as_long(val));
      static_assert(static_cast<unsigned long>(o) == as_ulong(val));
      static_assert(static_cast<long long>(o) == as_longlong(val));
      static_assert(static_cast<unsigned long long>(o) == as_ulonglong(val));
      static_assert(static_cast<long double>(o) == as_longdouble(val));
      static_assert(static_cast<double>(o) == as_double(val));
      static_assert(static_cast<float>(o) == as_float(val));
    }
    {
      constexpr auto val = 1;
      constexpr type o{val};
      static_assert(static_cast<bool>(o) == as_bool(val));
      static_assert(static_cast<char>(o) == as_char(val));
      static_assert(static_cast<unsigned char>(o) == as_uchar(val));
      static_assert(static_cast<short>(o) == as_short(val));
      static_assert(static_cast<unsigned short>(o) == as_ushort(val));
      static_assert(static_cast<int>(o) == as_int(val));
      static_assert(static_cast<unsigned int>(o) == as_uint(val));
      static_assert(static_cast<long>(o) == as_long(val));
      static_assert(static_cast<unsigned long>(o) == as_ulong(val));
      static_assert(static_cast<long long>(o) == as_longlong(val));
      static_assert(static_cast<unsigned long long>(o) == as_ulonglong(val));
      static_assert(static_cast<long double>(o) == as_longdouble(val));
      static_assert(static_cast<double>(o) == as_double(val));
      static_assert(static_cast<float>(o) == as_float(val));
    }
    {
      constexpr auto val = -1;
      constexpr type o{val};
      static_assert(static_cast<bool>(o) == as_bool(val));
      static_assert(static_cast<char>(o) == as_char(val));
      static_assert(static_cast<unsigned char>(o) == as_uchar(val));
      static_assert(static_cast<short>(o) == as_short(val));
      static_assert(static_cast<unsigned short>(o) == as_ushort(val));
      static_assert(static_cast<int>(o) == as_int(val));
      static_assert(static_cast<unsigned int>(o) == as_uint(val));
      static_assert(static_cast<long>(o) == as_long(val));
      static_assert(static_cast<unsigned long>(o) == as_ulong(val));
      static_assert(static_cast<long long>(o) == as_longlong(val));
      static_assert(static_cast<unsigned long long>(o) == as_ulonglong(val));
      static_assert(static_cast<long double>(o) == as_longdouble(val));
      static_assert(static_cast<double>(o) == as_double(val));
      static_assert(static_cast<float>(o) == as_float(val));
    }
  }
  {
    using type = su0::PowerOf10<-3>;
    {
      constexpr auto val = typename type::container_type{};
      constexpr type o{};
      static_assert(o == val == true);
      static_assert(o != val == false);
      static_assert(o < val == false);
      static_assert(o <= val == true);
      static_assert(o > val == false);
      static_assert(o >= val == true);
    }
    {
      constexpr auto val = typename type::container_type{1};
      constexpr type o{};
      static_assert(o == val == false);
      static_assert(o != val == true);
      static_assert(o < val == true);
      static_assert(o <= val == true);
      static_assert(o > val == false);
      static_assert(o >= val == false);
    }
    {
      constexpr auto val = typename type::container_type{-1};
      constexpr type o{};
      static_assert(o == val == false);
      static_assert(o != val == true);
      static_assert(o < val == false);
      static_assert(o <= val == false);
      static_assert(o > val == true);
      static_assert(o >= val == true);
    }
    {
      constexpr auto val = typename type::container_type{0};
      constexpr type o{-1};
      static_assert(o == val == false);
      static_assert(o != val == true);
      static_assert(o < val == true);
      static_assert(o <= val == true);
      static_assert(o > val == false);
      static_assert(o >= val == false);
    }
    {
      constexpr auto val = typename type::container_type{0};
      constexpr type o{1};
      static_assert(o == val == false);
      static_assert(o != val == true);
      static_assert(o < val == false);
      static_assert(o <= val == false);
      static_assert(o > val == true);
      static_assert(o >= val == true);
    }
    {
      static_assert(type{0} == type{0});
      static_assert(type{0} != type{1});
      static_assert(type{0} < type{1});
      static_assert(type{0} <= type{0});
      static_assert(type{1} > type{0});
      static_assert(type{0} >= type{0});
      static_assert(type{0} <=> type{0} == 0);
      static_assert(type{0} <=> type{1} < 0);
      static_assert(type{1} <=> type{0} > 0);
      static_assert(type{1} <=> type{1} == 0);
    }
    {
      constexpr auto val = 0;
      constexpr type o{val * 1000};
      static_assert(static_cast<bool>(o) == as_bool(val));
      static_assert(static_cast<char>(o) == as_char(val));
      static_assert(static_cast<unsigned char>(o) == as_uchar(val));
      static_assert(static_cast<short>(o) == as_short(val));
      static_assert(static_cast<unsigned short>(o) == as_ushort(val));
      static_assert(static_cast<int>(o) == as_int(val));
      static_assert(static_cast<unsigned int>(o) == as_uint(val));
      static_assert(static_cast<long>(o) == as_long(val));
      static_assert(static_cast<unsigned long>(o) == as_ulong(val));
      static_assert(static_cast<long long>(o) == as_longlong(val));
      static_assert(static_cast<unsigned long long>(o) == as_ulonglong(val));
      static_assert(static_cast<long double>(o) == as_longdouble(val));
      static_assert(static_cast<double>(o) == as_double(val));
      static_assert(static_cast<float>(o) == as_float(val));
    }
    {
      constexpr auto val = 1;
      constexpr type o{val * 1000};
      static_assert(static_cast<bool>(o) == as_bool(val));
      static_assert(static_cast<char>(o) == as_char(val));
      static_assert(static_cast<unsigned char>(o) == as_uchar(val));
      static_assert(static_cast<short>(o) == as_short(val));
      static_assert(static_cast<unsigned short>(o) == as_ushort(val));
      static_assert(static_cast<int>(o) == as_int(val));
      static_assert(static_cast<unsigned int>(o) == as_uint(val));
      static_assert(static_cast<long>(o) == as_long(val));
      static_assert(static_cast<unsigned long>(o) == as_ulong(val));
      static_assert(static_cast<long long>(o) == as_longlong(val));
      static_assert(static_cast<unsigned long long>(o) == as_ulonglong(val));
      static_assert(static_cast<long double>(o) == as_longdouble(val));
      static_assert(static_cast<double>(o) == as_double(val));
      static_assert(static_cast<float>(o) == as_float(val));
    }
    {
      constexpr auto val = -1;
      constexpr type o{val * 1000};
      static_assert(static_cast<bool>(o) == as_bool(val));
      static_assert(static_cast<char>(o) == as_char(val));
      static_assert(static_cast<unsigned char>(o) == as_uchar(val));
      static_assert(static_cast<short>(o) == as_short(val));
      static_assert(static_cast<unsigned short>(o) == as_ushort(val));
      static_assert(static_cast<int>(o) == as_int(val));
      static_assert(static_cast<unsigned int>(o) == as_uint(val));
      static_assert(static_cast<long>(o) == as_long(val));
      static_assert(static_cast<unsigned long>(o) == as_ulong(val));
      static_assert(static_cast<long long>(o) == as_longlong(val));
      static_assert(static_cast<unsigned long long>(o) == as_ulonglong(val));
      static_assert(static_cast<long double>(o) == as_longdouble(val));
      static_assert(static_cast<double>(o) == as_double(val));
      static_assert(static_cast<float>(o) == as_float(val));
    }
    {
      static_assert(-type{0} == type{0});
      static_assert(-type{1} == type{-1});
    }
    {
      static_assert(+type{0} == type{0});
      static_assert(+type{1} == type{+1});
    }
    {
      static_assert(type{0} + type{0} == type{0});
      static_assert(type{0} + type{1} == type{1});
      static_assert(type{1} + type{1} == type{2});
    }
    {
      static_assert(type{0} - type{0} == type{0});
      static_assert(type{0} - type{1} == -type{1});
      static_assert(type{1} - type{1} == type{0});
    }
    {
      static_assert(type{0} * type{0} == type{0});
      static_assert(type{0} * type{1} == type{0});
      static_assert(type{1000} * type{1000} == type{1000});
      static_assert(type{-1000} * type{1000} == type{-1000});
      static_assert(type{2000} * type{2000} == type{4000});
    }
    {
      static_assert(type{0} / type{1} == type{0});
      static_assert(type{1000} / type{1000} == type{1000});
      static_assert(type{-1000} / type{1000} == type{-1000});
      static_assert(type{4000} / type{2000} == type{2000});
    }
    {
      static_assert(type{0} % type{1} == type{0});
      static_assert(type{1} % type{1} == type{0});
      static_assert(type{-1} % type{1} == type{0});
      static_assert(type{5} % type{2} == type{1});
    }
    {
      static_assert((type{0} += type{0}) == type{0});
      static_assert((type{0} += type{1}) == type{1});
      static_assert((type{1} += type{1}) == type{2});
    }
    {
      static_assert((type{0} -= type{0}) == type{0});
      static_assert((type{0} -= type{1}) == -type{1});
      static_assert((type{1} -= type{1}) == type{0});
    }
    {
      static_assert((type{0} *= type{0}) == type{0});
      static_assert((type{0} *= type{1}) == type{0});
      static_assert((type{1000} *= type{1000}) == type{1000});
      static_assert((type{-1000} *= type{1000}) == type{-1000});
      static_assert((type{2000} *= type{2000}) == type{4000});
    }
    {
      static_assert((type{0} /= type{1000}) == type{0});
      static_assert((type{1000} /= type{1000}) == type{1000});
      static_assert((type{-1000} /= type{1000}) == type{-1000});
      static_assert((type{5000} /= type{2000}) == type{2500});
    }
    {
      static_assert((type{0} %= type{1000}) == type{0});
      static_assert((type{1000} %= type{1000}) == type{0});
      static_assert((type{-1000} %= type{1000}) == type{0});
      static_assert((type{5000} %= type{2000}) == type{1000});
    }
    {
      static_assert(type{0}++ == type{0});
      static_assert(type{1}++ == type{1});
      static_assert(type{2}++ == type{2});
    }
    {
      static_assert(++type{0} == type{1});
      static_assert(++type{1} == type{2});
      static_assert(++type{2} == type{3});
    }
    {
      static_assert(type{3}-- == type{3});
      static_assert(type{2}-- == type{2});
      static_assert(type{1}-- == type{1});
    }
    {
      static_assert(--type{3} == type{2});
      static_assert(--type{2} == type{1});
      static_assert(--type{1} == type{0});
    }
    {
      static_assert(~type{0b1} == type{~1});
    }
    {
      static_assert((type{0} & type{0b0}) == type{0});
      static_assert((type{0} & type{0b1}) == type{0});
      static_assert((type{0} & type{0b10}) == type{0});
      static_assert((type{0} & type{0b11}) == type{0});
    }
    {
      static_assert((type{0b1} | type{0b0}) == type{0b1});
      static_assert((type{0b1} | type{0b1}) == type{0b1});
      static_assert((type{0b1} | type{0b10}) == type{0b11});
      static_assert((type{0b1} | type{0b11}) == type{0b11});
    }
    {
      static_assert((type{0b1} ^ type{0b0}) == type{0b1});
      static_assert((type{0b1} ^ type{0b1}) == type{0b0});
      static_assert((type{0b1} ^ type{0b10}) == type{0b11});
      static_assert((type{0b1} ^ type{0b11}) == type{0b10});
    }
    {
      static_assert((type{0b1} << 0) == type{0b1});
      static_assert((type{0b1} << 1) == type{0b10});
      static_assert((type{0b1} << 2) == type{0b100});
      static_assert((type{0b1} << 3) == type{0b1000});
    }
    {
      static_assert((type{0b1000} >> 0) == type{0b1000});
      static_assert((type{0b1000} >> 1) == type{0b100});
      static_assert((type{0b1000} >> 2) == type{0b10});
      static_assert((type{0b1000} >> 3) == type{0b1});
    }
    {
      {
        constexpr auto o = [](){
          type o{0b1};
          return o &= type{0b0};
        };
        static_assert(o() == type{0b0});
      }
      {
        constexpr auto o = [](){
          type o{0b1};
          return o &= type{0b1};
        };
        static_assert(o() == type{0b1});
      }
      {
        constexpr auto o = [](){
          type o{0b1};
          return o &= type{0b10};
        };
        static_assert(o() == type{0b0});
      }
      {
        constexpr auto o = [](){
          type o{0b1};
          return o &= type{0b11};
        };
        static_assert(o() == type{0b1});
      }
    }
    {
      {
        constexpr auto o = [](){
          type o{0b1};
          return o |= type{0b0};
        };
        static_assert(o() == type{0b1});
      }
      {
        constexpr auto o = [](){
          type o{0b1};
          return o |= type{0b1};
        };
        static_assert(o() == type{0b1});
      }
      {
        constexpr auto o = [](){
          type o{0b1};
          return o |= type{0b10};
        };
        static_assert(o() == type{0b11});
      }
      {
        constexpr auto o = [](){
          type o{0b1};
          return o |= type{0b11};
        };
        static_assert(o() == type{0b11});
      }
    }
    {
      {
        constexpr auto o = [](){
          type o{0b1};
          return o ^= type{0b0};
        };
        static_assert(o() == type{0b1});
      }
      {
        constexpr auto o = [](){
          type o{0b1};
          return o ^= type{0b1};
        };
        static_assert(o() == type{0b0});
      }
      {
        constexpr auto o = [](){
          type o{0b1};
          return o ^= type{0b10};
        };
        static_assert(o() == type{0b11});
      }
      {
        constexpr auto o = [](){
          type o{0b1};
          return o ^= type{0b11};
        };
        static_assert(o() == type{0b10});
      }
    }
    {
      {
        constexpr auto o = [](){
          type o{0b1};
          return o <<= 0;
        };
        static_assert(o() == type{0b1});
      }
      {
        constexpr auto o = [](){
          type o{0b1};
          return o <<= 1;
        };
        static_assert(o() == type{0b10});
      }
      {
        constexpr auto o = [](){
          type o{0b1};
          return o <<= 2;
        };
        static_assert(o() == type{0b100});
      }
      {
        constexpr auto o = [](){
          type o{0b1};
          return o <<= 3;
        };
        static_assert(o() == type{0b1000});
      }
      {
        constexpr auto o = [](type value){
          type ret{std::move(value)};
          return ret <<= 1;
        };
        static_assert(o(type{0b1}) == type{0b10});
        static_assert(o(type{0b10}) == type{0b100});
        static_assert(o(type{0b100}) == type{0b1000});
        static_assert(o(type{0b1000}) == type{0b10000});
      }
    }
    {
      {
        constexpr auto o = [](){
          type o{0b1000};
          return o >>= 0;
        };
        static_assert(o() == type{0b1000});
      }
      {
        constexpr auto o = [](){
          type o{0b1000};
          return o >>= 1;
        };
        static_assert(o() == type{0b100});
      }
      {
        constexpr auto o = [](){
          type o{0b1000};
          return o >>= 2;
        };
        static_assert(o() == type{0b10});
      }
      {
        constexpr auto o = [](){
          type o{0b1000};
          return o >>= 3;
        };
        static_assert(o() == type{0b1});
      }
      {
        constexpr auto o = [](type value){
          type ret{std::move(value)};
          return ret >>= 1;
        };
        static_assert(o(type{0b1000}) == type{0b100});
        static_assert(o(type{0b100}) == type{0b10});
        static_assert(o(type{0b10}) == type{0b1});
        static_assert(o(type{0b1}) == type{0b0});
      }
    }
  }
  {
    static_assert(static_cast<int>(su0::PowerOf10<2, long long>{3}) == 300);
  }

  return 0;
}
