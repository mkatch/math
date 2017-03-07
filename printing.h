#ifndef JOGURT_MATH_PRINTING_H
#define JOGURT_MATH_PRINTING_H

#include "prefix.h"
#include "../printing.h"

#include "math.h"

namespace jogurt {

template <class T>
std::ostream& operator << (std::ostream& out, vec2<T> const& v)
{
    return out << '(' << v.x << ' ' << v.y << ')';
}

template <class T>
std::ostream& operator << (std::ostream& out, mat2<T> const& m)
{
    return out
        << '('
        << m.a11 << ' ' << m.a12 << "; "
        << m.a21 << ' ' << m.a22
        << ')';
}

template <class T>
std::ostream& operator << (std::ostream& out, mat3<T> const& m)
{
    return out
        << '('
        << m.a11 << ' ' << m.a12 << ' ' << m.a13 << "; "
        << m.a21 << ' ' << m.a22 << ' ' << m.a23 << "; "
        << m.a31 << ' ' << m.a32 << ' ' << m.a33
        << ')';
}

template <class T>
std::ostream& operator << (std::ostream& out, box2<T> const& box)
{
    return out << '(' << box.x0 << ", " << box.y0 << ")-(" << box.x1 << ", " << box.y1 << ')';
}

} // namespace jogurt

#endif // JOGURT_MATH_PRINT_H
