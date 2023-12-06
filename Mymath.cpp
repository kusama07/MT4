#include "Mymath.h"

Vector3 Multiply(const float& v1, const Vector3& v2)
{
	Vector3 result{};
	result.x = v1 * v2.x;
	result.y = v1 * v2.y;
	result.z = v1 * v2.z;
	return result;
}

Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle)
{
	Matrix4x4 result;

	result.m[0][0] = axis.x * axis.x * (1 - std::cos(angle)) + std::cos(angle);
	result.m[0][1] = axis.x * axis.y * (1 - std::cos(angle)) + axis.z * std::sin(angle);
	result.m[0][2] = axis.x * axis.z * (1 - std::cos(angle)) - axis.y * std::sin(angle);
	result.m[0][3] = 0.0f;

	result.m[1][0] = axis.x * axis.y * (1 - std::cos(angle)) - axis.z * std::sin(angle);
	result.m[1][1] = axis.y * axis.y * (1 - std::cos(angle)) + std::cos(angle);
	result.m[1][2] = axis.y * axis.z * (1 - std::cos(angle)) + axis.x * std::sin(angle);
	result.m[1][3] = 0.0f;

	result.m[2][0] = axis.x * axis.z * (1 - std::cos(angle)) + axis.y * std::sin(angle);
	result.m[2][1] = axis.y * axis.z * (1 - std::cos(angle)) - axis.x * std::sin(angle);
	result.m[2][2] = axis.z * axis.z * (1 - std::cos(angle)) +  std::cos(angle);
	result.m[2][3] = 0.0f;

	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;
}


Vector3 Normalize(const Vector3& v)
{
	Vector3 result{};

	float date = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	if (date != 0) {
		result.x = v.x / date;
		result.y = v.y / date;
		result.z = v.z / date;
	}
	return result;
}

float Dot(const Vector3& v1, const Vector3& v2)
{

	float result;

	result = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);

	return result;

}

Vector3 Cross(const Vector3& v1, const Vector3& v2)
{

	Vector3 result;

	result.x = (v1.y * v2.z) - (v1.z * v2.y);
	result.y = (v1.z * v2.x) - (v1.x * v2.z);
	result.z = (v1.x * v2.y) - (v1.y * v2.x);

	return result;

}

float Length(const Vector3& v)
{
	float result;
	result = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);

	return result;
}


Matrix4x4 DirectionToDirection(const Vector3& from, const Vector3& to)
{
	Matrix4x4 result;

	Vector3 n;

	n = Normalize(Cross(from,to));

	if (from.x == -to.x || from.y == -to.y || from.z == -to.z) 
	{
		if (from.x != 0 || from.y != 0) {
			n = { from.y,-from.x,0 };
		}
		else if (from.x != 0 || from.z != 0) {
			n = { from.z , 0,-from.x };
		}

	}

	float cosTheta = Dot(from, to);

	float sinTheta = Length(Cross(from, to));
	
	result.m[0][0] = n.x * n.x * (1 - cosTheta) + cosTheta;
	result.m[0][1] = n.x * n.y * (1 - cosTheta) + n.z * sinTheta;
	result.m[0][2] = n.x * n.z * (1 - cosTheta) - n.y * sinTheta;
	result.m[0][3] = 0.0f;

	result.m[1][0] = n.x * n.y * (1 - cosTheta) - n.z * sinTheta;
	result.m[1][1] = n.y * n.y * (1 - cosTheta) + cosTheta;
	result.m[1][2] = n.y * n.z * (1 - cosTheta) + n.x * sinTheta;
	result.m[1][3] = 0.0f;

	result.m[2][0] = n.x * n.z * (1 - cosTheta) + n.y * sinTheta;
	result.m[2][1] = n.y * n.z * (1 - cosTheta) - n.x * sinTheta;
	result.m[2][2] = n.z * n.z * (1 - cosTheta) + cosTheta;
	result.m[2][3] = 0.0f;

	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;
}

Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs)
{
	Quaternion result;

	Vector3 qV = { lhs.x,lhs.y,lhs.z };

	Vector3 rV = { rhs.x,rhs.y,rhs.z };

	float dot = Dot(qV, rV);

	Vector3 cross = Cross(qV, rV);

	result.x = cross.x + lhs.w * rhs.x + lhs.x * rhs.w;
	result.y = cross.y + lhs.w * rhs.y + lhs.y * rhs.w;
	result.z = cross.z + lhs.w * rhs.z + lhs.z * rhs.w;

	result.w = (lhs.w * rhs.w) - dot;

	return result;
}

Quaternion IdentityQuaternion()
{
	Quaternion result;

	result = { 0.0f,0.0f,0.0f,1.0f };

	return result;
}

Quaternion Conjugate(const Quaternion& quaternion)
{
	Quaternion result;

	result.x = quaternion.x * -1;
	result.y = quaternion.y * -1;
	result.z = quaternion.z * -1;
	result.w = quaternion.w;

	return result;
}

float Norm(const Quaternion& quaternion)
{
	float result;

	result =
		sqrt((quaternion.w * quaternion.w) +
			(quaternion.x * quaternion.x) +
			(quaternion.y * quaternion.y) +
			(quaternion.z * quaternion.z));

	return result;
}

Quaternion Normalize(const Quaternion& quaternion)
{
	Quaternion result{};

	float date = sqrtf(quaternion.x * quaternion.x + quaternion.y * quaternion.y + quaternion.z * quaternion.z + quaternion.w * quaternion.w);
	if (date != 0) {
		result.x = quaternion.x / date;
		result.y = quaternion.y / date;
		result.z = quaternion.z / date;
		result.w = quaternion.w / date;
	}
	return result;
}

Quaternion Inverse(const Quaternion& quaternion)
{
	Quaternion result;

	float norm = Norm(quaternion);

	Quaternion conjugate = Conjugate(quaternion);

	float normSquad = norm * norm;

	result.x = conjugate.x / normSquad;
	result.y = conjugate.y / normSquad;
	result.z = conjugate.z / normSquad;
	result.w = conjugate.w / normSquad;


	return result;
}

