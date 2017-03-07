#ifndef KLETCH_MATH_FLINE2_H
#define KLETCH_MATH_FLINE2_H

namespace kletch {

// Represents a 2D line in Cartesian coordinate system defined as the plot of a function
// `y = f(x) = a * x + b`.
template <class T>
struct fline2
{
    T a, b;

    constexpr fline2() = default;
    constexpr fline2(T a, T b) : a(a), b(b) { }

    T eval_y(T x) { return a * x + b; }
    vec2<T> eval(T x) { return vec2<T>(x, eval_y(x)); }
};

typedef fline2<float> fline2f;
typedef fline2<double> fline2d;
typedef fline2<real> fline2r;

} // namespace kletch

#endif // KLETCH_MATH_FLINE2_H
