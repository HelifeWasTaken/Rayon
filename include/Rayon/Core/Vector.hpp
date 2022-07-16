#pragma once

#include "raylib.h"
#include <cmath>
#include <ostream>

static inline bool operator==(const Vector3& v1, const Vector3& v2)
{
    return (long)v1.x == (long)v2.x && (long)v1.y == (long)v2.y
        && (long)v1.z == (long)v2.z;
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

static inline double distance(const Vector2& v1, const Vector2& v2)
{
    return std::sqrt(std::pow(v1.x - v2.x, 2) + std::pow(v1.y - v2.y, 2));
}

static inline double distance(const Vector3& v1, const Vector3& v2)
{
    return std::sqrt(std::pow(v1.x - v2.x, 2) + std::pow(v1.y - v2.y, 2)
        + std::pow(v1.z - v2.z, 2));
}

template <> struct std::hash<Vector2> {
    unsigned long long int operator()(const Vector2& v) const
    {
        return (unsigned long long int)(v.x * 1000000 + v.y);
    }
};

template <> struct std::hash<Vector3> {
    unsigned long long int operator()(const Vector3& v) const
    {
        return (unsigned long long int)(v.x * 1000000 + v.y * 1000 + v.z);
    }
};