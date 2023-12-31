#pragma once

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
		/// 右乘：Vector2 * float
		/// </summary>
		/// <param name="value">被乘数</param>
		/// <returns>结果</returns>
		const Vector2& operator*(float value)
		{
			return Vector2(this->x * value, this->y * value);
		}

		/// <summary>
		/// 左乘：float * Vector2
		/// </summary>
		/// <param name="value">乘数</param>
		/// <param name="other">被乘数</param>
		/// <returns>结果</returns>
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
	};
}