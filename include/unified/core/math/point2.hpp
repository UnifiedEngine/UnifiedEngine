#ifndef _UNIFIED_CORE_MATH_POINT2_HPP
#define _UNIFIED_CORE_MATH_POINT2_HPP

# include <unified/core/math/point_fwd.hpp>
# include <fmt/format.h>

UNIFIED_BEGIN_NAMESPACE

template <class _type>
struct Point<_type, 2>
{
    _type x, y;

    UNIFIED_CONSTEXPR Point() : x(_type()), y(_type()) { }
    UNIFIED_CONSTEXPR Point(_type xy) : x(xy), y(xy) { }
    UNIFIED_CONSTEXPR Point(_type x, _type y) : x(x), y(y) { }

    UNIFIED_CONSTEXPR _type operator[](u32 i) const {
        UNIFIED_CONSTEXPR _type Point::*accessors[] = {
            &Point::x,
            &Point::y
        };
        return this->*accessors[i];
    }

    UNIFIED_CONSTEXPR _type &operator[](u32 i) {
        UNIFIED_CONSTEXPR _type Point::*accessors[] = {
            &Point::x,
            &Point::y
        };
        return this->*accessors[i];
    }

    UNIFIED_CONSTEXPR Point operator+(const _type &r) const {
        return Point(x + r, y + r);
    }

    UNIFIED_CONSTEXPR Point operator+(const Point &r) const {
        return Point(x + r.x, y + r.y);
    }

    UNIFIED_CONSTEXPR Point operator-(const _type &r) const {
        return Point(x - r, y - r);
    }

    UNIFIED_CONSTEXPR Point operator-(const Point &r) const {
        return Point(x - r.x, y - r.y);
    }

    UNIFIED_CONSTEXPR Point operator*(const _type &r) const {
        return Point(x * r, y * r);
    }

    UNIFIED_CONSTEXPR Point operator*(const Point &r) const {
        return Point(x * r.x, y * r.y);
    }

    UNIFIED_CONSTEXPR Point operator/(const _type &r) const {
        return Point(x / r, y / r);
    }

    UNIFIED_CONSTEXPR Point operator/(const Point &r) const {
        return Point(x / r.x, y / r.y);
    }

    UNIFIED_CONSTEXPR Point &operator+=(const _type &r) {
        x += r, y += r;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator+=(const Point &r) {
        x += r.x, y += r.y;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator-=(const _type &r) {
        x -= r, y -= r;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator-=(const Point &r) {
        x -= r.x, y -= r.y;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator*=(const _type &r) {
        x *= r, y *= r;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator*=(const Point &r) {
        x *= r.x, y *= r.y;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator/=(const _type &r) {
        x /= r, y /= r;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator/=(const Point &r) {
        x /= r.x, y /= r.y;
        return *this;
    }

    UNIFIED_FORCE_INLINE u32 size() const {
        return 2;
    }
};

typedef Point<unsigned, 2> Point2u;
typedef Point<int,      2> Point2i;
typedef Point<float,    2> Point2f;
typedef Point<double,   2> Point2d;

UNIFIED_END_NAMESPACE

namespace fmt
{
    template <class _type> struct formatter<UNIFIED_NAMESPACE::Point<_type, 2>> : formatter<std::string> {
        template <class FormatContext>
        auto format(const UNIFIED_NAMESPACE::Point<_type, 2> &point, FormatContext &ctx) {
            return formatter<std::string>::format(fmt::format("{{ {}, {} }}", point.x, point.y), ctx);
        }
    };
}

#endif
