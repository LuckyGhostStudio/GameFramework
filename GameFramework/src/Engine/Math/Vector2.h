#pragma once

#include <ostream>
#include <cmath>

namespace Engine
{
	struct Vector2
	{
		float x = 0.0f;
		float y = 0.0f;

		Vector2()
		{
			this->x = 0.0f;
			this->y = 0.0f;
		}

		Vector2(float value)
		{
			this->x = value;
			this->y = value;
		}

		Vector2(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		void Set(float value)
		{
			this->x = value;
			this->y = value;
		}

		void Set(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
		}

		const Vector2& operator+(const Vector2& other)
		{
			return Vector2(this->x + other.x, this->y + other.y);
		}

		const Vector2& operator-(const Vector2& other)
		{
			return Vector2(this->x - other.x, this->y - other.y);
		}

		/// <summary>
		/// �ҳˣ�Vector2 * float
		/// </summary>
		/// <param name="value">������</param>
		/// <returns>���</returns>
		const Vector2& operator*(float value)
		{
			return Vector2(this->x * value, this->y * value);
		}

		/// <summary>
		/// ��ˣ�float * Vector2
		/// </summary>
		/// <param name="value">����</param>
		/// <param name="other">������</param>
		/// <returns>���</returns>
		friend const Vector2& operator*(float value, const Vector2& other)
		{
			return Vector2(value * other.x, value * other.y);
		}

		const Vector2& operator/(float value)
		{
			return Vector2(this->x / value, this->y / value);
		}

		void operator+=(const Vector2& other)
		{
			this->x += other.x;
			this->y += other.y;
		}

		void operator-=(const Vector2& other)
		{
			this->x -= other.x;
			this->y -= other.y;
		}

		friend std::ostream& operator<<(std::ostream& output, const Vector2& vector)
		{
			output << "(" << vector.x << ", " << vector.y << ")";
			return output;
		}

		static Vector2 Clamp(const Vector2& value, const Vector2& min, const Vector2& max)
		{
			Vector2 result = value;

			if (value.x < min.x || value.x > max.x) {
				result.x = abs(value.x - min.x) <= abs(value.x - max.x) ? min.x : max.x;	// Mathf.Clamp(value, min, max)
			}
			// ���� y ��Χ [0, screenSize.y]
			if (value.y < min.y || value.y > max.y) {
				result.y = abs(value.y - min.x) <= abs(value.y - max.y) ? min.y : max.y;	// Mathf.Clamp(value, min, max)
			}

			return result;
		}
	};
}