#pragma once

namespace Engine
{
	struct Vector3
	{
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

		Vector3()
		{
			this->x = 0.0f;
			this->y = 0.0f;
			this->z = 0.0f;
		}

		Vector3(float value)
		{
			this->x = value;
			this->y = value;
			this->z = value;
		}

		Vector3(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		void Set(float value)
		{
			this->x = value;
			this->y = value;
			this->z = value;
		}

		void Set(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		const Vector3& operator+(const Vector3& other)
		{
			return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
		}

		const Vector3& operator-(const Vector3& other)
		{
			return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
		}

		/// <summary>
		/// �ҳˣ�Vector3 * float
		/// </summary>
		/// <param name="value">������</param>
		/// <returns>���</returns>
		const Vector3& operator*(float value)
		{
			return Vector3(this->x * value, this->y * value, this->z * value);
		}

		/// <summary>
		/// ��ˣ�float * Vector3
		/// </summary>
		/// <param name="value">����</param>
		/// <param name="other">������</param>
		/// <returns>���</returns>
		friend const Vector3& operator*(float value, const Vector3& other)
		{
			return Vector3(value * other.x, value * other.y, value * other.z);
		}

		const Vector3& operator/(float value)
		{
			return Vector3(this->x / value, this->y / value, this->z / value);
		}

		void operator+=(const Vector3& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
		}

		void operator-=(const Vector3& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
		}
	};
}