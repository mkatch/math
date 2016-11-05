#if !defined(KLETCH_MATH_FUZZY_VEC2_H) && \
    (defined(KLETCH_MATH_FUZZY_H_INSIDE) || defined(KLETCH_MATH_VEC2_H_INSIDE))
#define KLETCH_MATH_FUZZY_VEC2_H

namespace kletch {

template <class T1, class T2> inline
bool equal(vec2<T1> const& u, vec2<T2> const& v, common_t<T1, T2> eps)
{
    return equal(u.x, v.x, eps) && equal(u.y, v.y, eps);
}

} // namespace kletch

#endif // KLETCH_MATH_FUZZY_VEC2_H
