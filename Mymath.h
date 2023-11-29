#pragma once
#include "Matrix4x4.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include <cmath>
#include <stdio.h>
#include <numbers>
#include <Novice.h>

Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle);

Vector3 Normalize(const Vector3& v);

float Dot(const Vector3& v1, const Vector3& v2);

Vector3 Cross(const Vector3& v1, const Vector3& v2);

float Length(const Vector3& v);

Matrix4x4 DirectionToDirection(const Vector3& from, const Vector3& to);