#ifndef KLETCH_MATH_BOX_H
#define KLETCH_MATH_BOX_H

#include "prefix.h"
#include "vec2.h"

namespace kletch {

template <typename T>
struct box2
{
    static const box2 EMPTY;

    T x0;
    T y0;
    T x1;
    T y1;

    box2() = default;

    box2(T x0, T y0, T x1, T y1) : x0(x0), y0(y0), x1(x1), y1(y1) { }

    void expand(T x, T y)
    {
        expand(x0, x1, x);
        expand(y0, y1, y);
    }

    void expand(const vec2<T>& u) { expand(u.x, u.y); }

private:
    void expand(T& v0, T& v1, T v)
    {
        if (v0 <= v1)
        {
            if (v < v0)
                v0 = v;
            else if (v1 < v)
                v1 = v;
        }
        else
        {
            if (v < v1)
                v1 = v;
            else if (v0 < v)
                v0 = v;
        }
    }
};

typedef box2<float> box2f;
typedef box2<double> box2d;
typedef box2<real> box2r;

template <typename T>
const box2<T> box2<T>::EMPTY = box2<T>(
    std::numeric_limits<T>::infinity(), std::numeric_limits<T>::infinity(),
    -std::numeric_limits<T>::infinity(), -std::numeric_limits<T>::infinity()
);

} // namespace kletch

#endif // KLETCH_MATH_BOX_H
