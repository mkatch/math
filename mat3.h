#ifndef KLETCH_MATH_MAT3_H
#define KLETCH_MATH_MAT3_H

namespace kletch {

template <typename T>
struct mat3
{
    static const mat3 EYE;

    T a11; T a21; T a31;
    T a12; T a22; T a32;
    T a13; T a23; T a33;

    mat3() = default;

    vec3(
        T a11, T a12, T a13,
        T a21, T a22, T a23,
        T a31, T a32, T a33
    ) :
        a11(a11), a21(a21), a31(a31),
        a12(a12), a22(a22), a23(a23),
        a31(a31), a32(a32), a33(a33)
    { }

    mat3& scale(T sx, T sy)
    {
        a11 *= sx; a12 *= sx; a13 *= sx;
        a21 *= sy; a22 *= sy; a23 *= sy;
        return *this;
    }

    mat3& scale(const vec2& s) { return scale(s.x, s.y); }

    mat3& translate(T tx, T ty)
    {
        a11 += a31 * tx; a12 += a32 * tx; a13 += a33 * tx;
        a21 += a31 * ty; a22 += a32 * ty; a23 += a33 * ty;
        return *this;
    }

    mat3& rotate(T angle)
    {
        T c = cos(angle); T s = sin(angle);

        T x = a11, y = a21;
        a11 = c * x - s * y;
        a21 = s * x + c * y;

        x = a12; y = a22;
        a12 = c * x - s * y;
        a22 = s * x + c * y;

        x = a13; y = a23;
        a13 = c * x - s * y;
        a23 = s * x + c * y;
    }

    vec2<T> translation() const { return vec2<T>(a13 / a33, a23 / a33); }
};

template <typename T>
const mat3<T> mat3<T>::EYE = mat3<T>(
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
);

} // namespace kletch

#endif // KLETCH_MATH_MAT3_H
