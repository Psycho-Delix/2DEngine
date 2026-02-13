#pragma once

struct Vec2
{
    float x = 0;
    float y = 0;
};

inline Vec2 operator+(const Vec2& a, const Vec2& b) {
    return { a.x + b.x, a.y + b.y };
}

inline Vec2 operator-(const Vec2& a, const Vec2& b) {
    return { a.x - b.x, a.y - b.y };
}

inline Vec2 operator*(const Vec2& v, float scalar) {
    return { v.x * scalar, v.y * scalar };
}

inline Vec2& operator+=(Vec2& a, const Vec2& b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

inline Vec2& operator*=(Vec2& v, float scalar) {
    v.x *= scalar;
    v.y *= scalar;
    return v;
}
