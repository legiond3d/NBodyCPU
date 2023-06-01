#ifndef __VEC_3D_HEADER__
#define __VEC_3D_HEADER__

#include"Header.h"

template<class T>
class Vec3D
{
private:
	T x;
	T y;
	T z;
public:
	Vec3D();
	Vec3D(const Vec3D<T>& vec);
	Vec3D(const T& x, const T& y, const T& z);

	T getX();
	T getY();
	T getZ();

	void setX(const T& x);
	void setY(const T& y);
	void setZ(const T& z);

	T mod();
	T mod2();
	T mod(const int& order);

	Vec3D<T> getL(const Vec3D<T>& vec);

	Vec3D<T>& operator=(const Vec3D<T>& vec);
	Vec3D<T>& operator+=(const Vec3D<T>& vec);
	Vec3D<T>& operator-=(const Vec3D<T>& vec);
	Vec3D<T>& operator*=(const Vec3D<T>& vec);
	Vec3D<T>& operator/=(const Vec3D<T>& vec);
	Vec3D<T> operator+(const Vec3D<T>& vec);
	Vec3D<T> operator-(const Vec3D<T>& vec);
	Vec3D<T> operator/(const Vec3D<T>& vec);
	Vec3D<T> operator-();

	T operator*(const Vec3D<T>& vec);

	Vec3D<T>& operator+=(const T& scalar);
	Vec3D<T>& operator-=(const T& scalar);
	Vec3D<T>& operator*=(const T& scalar);
	Vec3D<T>& operator/=(const T& scalar);
	Vec3D<T> operator+(const T& scalar);
	Vec3D<T> operator-(const T& scalar);
	Vec3D<T> operator*(const T& scalar);
	Vec3D<T> operator/(const T& scalar);

	template<class V>
	friend ostream& operator<<(ostream& ofs, const Vec3D<V>& vec);
	template<class V>
	friend ofstream& operator<<(ofstream& ofs, const Vec3D<V>& vec);

	template<class V>
	friend Vec3D<V> operator+(const V& scalar, const Vec3D<V>& vec);
	template<class V, class U>
	friend Vec3D<V> operator+(const U& scalar, const Vec3D<V>& vec);
	template<class V>
	friend Vec3D<V> operator-(const V& scalar, const Vec3D<V>& vec);
	template<class V, class U>
	friend Vec3D<V> operator-(const U& scalar, const Vec3D<V>& vec);
	template<class V>
	friend Vec3D<V> operator*(const V& scalar, const Vec3D<V>& vec);
	template<class V, class U>
	friend Vec3D<V> operator*(const U& scalar, const Vec3D<V>& vec);
	template<class V>
	friend Vec3D<V> operator/(const V& scalar, const Vec3D<V>& vec);
	template<class V, class U>
	friend Vec3D<V> operator/(const U& scalar, const Vec3D<V>& vec);
};

#endif