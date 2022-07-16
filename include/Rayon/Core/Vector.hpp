#pragma once

#include "raylib.h"
#include <cmath>
#include <ostream>

static inline bool operator==(const Vector3& v1, const Vector3& v2)
{
    return v1.x == v2.x
        && v1.y == v2.y
        && v1.z == v2.z;
}

static inline bool operator!=(const Vector3& v1, const Vector3& v2)
{
    return !(v1 == v2);
}

static inline Vector3 operator+(const Vector3& v1, const Vector3& v2)
{
    return { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
}

static inline Vector3 operator/(const Vector3& v1, int k)
{
    return { v1.x / k, v1.y / k, v1.z / k };
}

static inline Vector3 operator/(const Vector3& v1, float k)
{
    return { v1.x / k, v1.y / k, v1.z / k };
}

static inline Vector3 operator*(const Vector3& v1, int k)
{
    return { v1.x * k, v1.y * k, v1.z * k };
}

static inline Vector3& operator+=(Vector3& v1, const Vector3& v2)
{
    return v1 = v1 + v2;
}

static inline Vector3 operator-(const Vector3& v1, const Vector3& v2)
{
    return { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
}

static inline Vector3& operator-=(Vector3& v1, const Vector3& v2)
{
    return v1 = v1 - v2;
}

static inline std::ostream& operator<<(std::ostream& os, const Vector3& v)
{
    return os << "Vector3(x: " << v.x << ", y: " << v.y << ", z: " << v.z
              << ")";
}

static inline bool operator==(const Vector2& v1, const Vector2& v2)
{
    return v1.x == v2.x && v1.y == v2.y;
}

static inline bool operator!=(const Vector2& v1, const Vector2& v2)
{
    return !(v1 == v2);
}

static inline Vector2 operator+(const Vector2& v1, const Vector2& v2)
{
    return { v1.x + v2.x, v1.y + v2.y };
}

static inline Vector2 operator/(const Vector2& v1, int k)
{
    return { v1.x / k, v1.y / k };
}

static inline Vector2 operator/(const Vector2& v1, float k)
{
    return { v1.x / k, v1.y / k };
}

static inline Vector2 operator*(const Vector2& v1, int k)
{
    return { v1.x * k, v1.y * k };
}

static inline Vector2& operator+=(Vector2& v1, const Vector2& v2)
{
    return v1 = v1 + v2;
}

static inline Vector2 operator-(const Vector2& v1, const Vector2& v2)
{
    return { v1.x - v2.x, v1.y - v2.y };
}

static inline Vector2& operator-=(Vector2& v1, const Vector2& v2)
{
    return v1 = v1 - v2;
}

static inline std::ostream& operator<<(std::ostream& os, const Vector2& v)
{
    return os << "Vector2(x: " << v.x << ", y: " << v.y << ")";
}

static inline std::ostream& operator<<(std::ostream& os, const Vector4& v)
{
    return os << "Vector4(x: " << v.x << ", y: " << v.y << ", z: " << v.z << ", w: " << v.w << ")";
}

template <> struct std::hash<Vector2> {
    unsigned long long int operator()(const Vector2& v) const
    {
        const unsigned long long int a = 4135ULL;
        const unsigned long long int b = v.x * 2ULL;
        const unsigned long long int c = v.y;

        return (a * b + c) << 1ULL;
    }
};

template <> struct std::hash<Vector3> {
    unsigned long long int operator()(const Vector3& v) const
    {
        const unsigned long long int a = v.x * 135135ULL;
        const unsigned long long int b = v.y * 1000ULL;
        const unsigned long long int c = v.z;

        return (a * (b << 2) + c) >> 1ULL;
    }
};

template <> struct std::hash<Vector4> {
    unsigned long long int operator()(const Vector4& v) const
    {
        const unsigned long long int a = v.w * 106335ULL;
        const unsigned long long int b = v.z / 2ULL;
        const unsigned long long int c = v.y;
        const unsigned long long int d = v.x;

        return a - b + (c << 5ULL) * d;
    }
};

namespace rayon {
static inline double distance(const Vector2& v1, const Vector2& v2)
{
    return std::sqrt(std::pow(v1.x - v2.x, 2) + std::pow(v1.y - v2.y, 2));
}

static inline double distance(const Vector3& v1, const Vector3& v2)
{
    return std::sqrt(std::pow(v1.x - v2.x, 2) + std::pow(v1.y - v2.y, 2)
        + std::pow(v1.z - v2.z, 2));
}
}