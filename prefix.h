#ifndef KLETCH_MATH_PREFIX_H
#define KLETCH_MATH_PREFIX_H

#include "prefix.h"
#include <cmath>
#include <limits>
#include <type_traits>

namespace kletch {

using std::isnan;
using std::isinf;
using std::isnormal;

#ifdef KLETCH_WITH_DOUBLE
    typedef double real;
#else
    typedef float real;
#endif

template <class T> inline constexpr real rl(T x) { return static_cast<real>(x); }
template <class Tf, class Td> inline constexpr real rl(Tf xf, Td xd)
{
#   ifdef KLETCH_WITH_DOUBLE
        return rl(xd);
#   else
        return rl(xf);
#   endif
}

using std::swap;

typedef std::numeric_limits<float> float_limits;
typedef std::numeric_limits<double> double_limits;
typedef std::numeric_limits<real> real_limits;

constexpr float NaNf = float_limits::quiet_NaN();
constexpr double NaNd = double_limits::quiet_NaN();
constexpr real NaN = real_limits::quiet_NaN();

template <class... Ts>
using common_t = typename std::common_type<Ts...>::type;

} // namespace kletch

#endif // KLETCH_MATH_PREFIX_H
