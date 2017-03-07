#if !defined(JOGURT_MATH_FUZZY_VEC2_H) && \
    (defined(JOGURT_MATH_FUZZY_H_INSIDE) || defined(JOGURT_MATH_VEC2_H_INSIDE))
#define JOGURT_MATH_FUZZY_VEC2_H

namespace jogurt {

template <class T1, class T2> inline
bool equal(vec2<T1> const& u, vec2<T2> const& v, common_t<T1, T2> eps)
{
    return equal<T1, T2>(u.x, v.x, eps) && equal<T1, T2>(u.y, v.y, eps);
}

} // namespace jogurt

#endif // JOGURT_MATH_FUZZY_VEC2_H
