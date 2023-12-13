#pragma once
#include "Matrix4x4.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Quaternion.h"
#include <cmath>
#include <stdio.h>
#include <numbers>
#include <Novice.h>

Vector3 Multiply(const float& v1, const Vector3& v2);

Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle);

Vector3 Normalize(const Vector3& v);

float Dot(const Vector3& v1, const Vector3& v2);

Vector3 Cross(const Vector3& v1, const Vector3& v2);

float Length(const Vector3& v);

Matrix4x4 DirectionToDirection(const Vector3& from, const Vector3& to);

// Quaternionの積
Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs);
// 単位Quaterinonを返す
Quaternion IdentityQuaternion();
// 共役Quaternionを返す
Quaternion Conjugate(const Quaternion& quaternion);
// Quaternionのnormを返す
float Norm(const Quaternion& quaternion);
// 正規化したQuaternionを返す
Quaternion Normalize(const Quaternion& quaternion);
// 逆Quaternionを返す
Quaternion Inverse(const Quaternion& quaternion);
// 任意軸回転を表すQuaternionの生成
Quaternion MakeRotateAxisAngleQuaternion(const Vector3& axis, float angle);
// ベクトルをQuaternionで回転させた結果のベクトルを求める
Vector3 RotateVector(const Vector3& vector, const Quaternion& quaternion);
// Quaternionから回転行列を求める
Matrix4x4 MakeRotateMatrix(const Quaternion& quaternion);

Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);
