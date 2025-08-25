#pragma once
/// <summary>
/// 2차원에서 사각형 영역을 표시하는 클래스
/// </summary>
class Bounds
{
public:
	explicit Bounds() = default;
	explicit Bounds(float x, float y, float width = 1.0f, float height = 1.0f)
		: x(x), y(y), width(width), height(height)
	{
	}

public:
	// 겹침 판정 함수
	bool Intersects(const Bounds& other) const;

public: // Getter & Setter
	__forceinline float GetX() const { return x; }
	__forceinline float GetY() const { return y; }
	__forceinline float GetWidth() const { return width; }
	__forceinline float GetHeight() const { return height; }

	__forceinline float MaxX() const { return x + width; }
	__forceinline float MaxY() const { return y + height; }

private:
	// 위치 기준은 왼쪽 상단
	float x = 0.0f;
	float y = 0.0f;
	float width = 1.0f;
	float height = 1.0f;
};