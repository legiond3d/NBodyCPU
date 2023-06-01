#ifndef __VEC_3D__
#define __VEC_3D__

#include"Vec3D.h"

template<class T>
Vec3D<T>::Vec3D()
{
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

template<class T>
Vec3D<T>::Vec3D(const Vec3D<T>& vec)
{
	this->x = vec.x;
	this->y = vec.y;
	this->z = vec.z;
}

template<class T>
Vec3D<T>::Vec3D(const T& x, const T& y, const T& z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template<class T>
T Vec3D<T>::getX()
{
	return this->x;
}

template<class T>
T Vec3D<T>::getY()
{
	return this->y;
}

template<class T>
T Vec3D<T>::getZ()
{
	return this->z;
}

template<class T>
void Vec3D<T>::setX(const T& x)
{
	this->x = x;
}

template<class T>
void Vec3D<T>::setY(const T& y)
{
	this->y = y;
}

template<class T>
void Vec3D<T>::setZ(const T& z)
{
	this->z = z;
}

template<class T>
T Vec3D<T>::mod()
{
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

template<class T>
T Vec3D<T>::mod2()
{
	return this->x * this->x + this->y * this->y + this->z * this->z;
}

template<class T>
T Vec3D<T>::mod(const int& order)
{
	T res = 1.0;
	if (order == 1)
		res = this->mod()
	else if (order >= 2)
	{
		res = this->mod2();
		for (int i = 0; i < order; i += 2)
		{
			if (order % 2 == 1)
			{
				res *= this->mod();
				order--;
			}
			res *= res;
		}
	}
	return res;
}

template<class T>
Vec3D<T> Vec3D<T>::getL(const Vec3D<T>& vec)
{
	Vec3D<T> l;
	l.x = this->y * vec.z - this->z * vec.y;
	l.y = this->z * vec.x - this->x * vec.z;
	l.z = this->x * vec.y - this->y * vec.x;
	return l;
}

template<class T>
Vec3D<T>& Vec3D<T>::operator=(const Vec3D<T>& vec)
{
	if (this != &vec)
	{
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;
	}
	return *this;
}

template<class T>
Vec3D<T>& Vec3D<T>::operator+=(const Vec3D<T>& vec)
{
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.z;
	return *this;
}

template<class T>
Vec3D<T>& Vec3D<T>::operator-=(const Vec3D<T>& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	this->z -= vec.z;
	return *this;
}

template<class T>
Vec3D<T>& Vec3D<T>::operator*=(const Vec3D<T>& vec)
{
	this->x *= vec.x;
	this->y *= vec.y;
	this->z *= vec.z;
	return *this;
}

template<class T>
Vec3D<T>& Vec3D<T>::operator/=(const Vec3D<T>& vec)
{
	this->x /= vec.x;
	this->y /= vec.y;
	this->z /= vec.z;
	return *this;
}

template<class T>
Vec3D<T> Vec3D<T>::operator+(const Vec3D<T>& vec)
{
	Vec3D<T> res;
	res.x = this->x + vec.x;
	res.y = this->y + vec.y;
	res.z = this->z + vec.z;
	return res;
}

template<class T>
Vec3D<T> Vec3D<T>::operator-(const Vec3D<T>& vec)
{
	Vec3D<T> res;
	res.x = this->x - vec.x;
	res.y = this->y - vec.y;
	res.z = this->z - vec.z;
	return res;
}

template<class T>
Vec3D<T> Vec3D<T>::operator/(const Vec3D<T>& vec)
{
	Vec3D<T> res;
	res.x = this->x / vec.x;
	res.y = this->y / vec.y;
	res.z = this->z / vec.z;
	return res;
}

template<class T>
Vec3D<T> Vec3D<T>::operator-()
{
	Vec3D<T> res;
	res.x = -this->x;
	res.y = -this->y;
	res.z = -this->z;
	return res;
}

template<class T>
T Vec3D<T>::operator*(const Vec3D<T>& vec)
{
	return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}

template<class T>
Vec3D<T>& Vec3D<T>::operator+=(const T& scalar)
{
	this->x += scalar;
	this->y += scalar;
	this->z += scalar;
	return *this;
}

template<class T>
Vec3D<T>& Vec3D<T>::operator-=(const T& scalar)
{
	this->x -= scalar;
	this->y -= scalar;
	this->z -= scalar;
	return *this;
}

template<class T>
Vec3D<T>& Vec3D<T>::operator*=(const T& scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	return *this;
}

template<class T>
Vec3D<T>& Vec3D<T>::operator/=(const T& scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
	return *this;
}

template<class T>
Vec3D<T> Vec3D<T>::operator+(const T& scalar)
{
	Vec3D<T> res;
	res.x = this->x + scalar;
	res.y = this->y + scalar;
	res.z = this->z + scalar;
	return res;
}

template<class T>
Vec3D<T> Vec3D<T>::operator-(const T& scalar)
{
	Vec3D<T> res;
	res.x = this->x - scalar;
	res.y = this->y - scalar;
	res.z = this->z - scalar;
	return res;
}

template<class T>
Vec3D<T> Vec3D<T>::operator*(const T& scalar)
{
	Vec3D<T> res;
	res.x = this->x * scalar;
	res.y = this->y * scalar;
	res.z = this->z * scalar;
	return res;
}

template<class T>
Vec3D<T> Vec3D<T>::operator/(const T& scalar)
{
	Vec3D<T> res;
	res.x = this->x / scalar;
	res.y = this->y / scalar;
	res.z = this->z / scalar;
	return res;
}

template<class V>
ostream& operator<<(ostream& ofs, const Vec3D<V>& tmp)//перегрузка потокового вывода
{
	return ofs << tmp.x << ";" << tmp.y << ";" << tmp.z;
}

template<class V>
ofstream& operator<<(ofstream& ofs, const Vec3D<V>& tmp)//перегрузка потокового вывода в файл
{
	return ofs << tmp.x << ";" << tmp.y << ";" << tmp.z;
}

template<class V>
Vec3D<V> operator+(const V& scalar, const Vec3D<V>& vec)
{
	Vec3D<V> res;
	res.x = scalar + vec.x;
	res.y = scalar + vec.y;
	res.z = scalar + vec.z;
	return res;
}

template<class V, class U>
Vec3D<V> operator+(const U& scalar, const Vec3D<V>& vec)
{
	Vec3D<V> res;
	res.x = scalar + vec.x;
	res.y = scalar + vec.y;
	res.z = scalar + vec.z;
	return res;
}

template<class V>
Vec3D<V> operator-(const V& scalar, const Vec3D<V>& vec)
{
	Vec3D<V> res;
	res.x = scalar - vec.x;
	res.y = scalar - vec.y;
	res.z = scalar - vec.z;
	return res;
}

template<class V, class U>
Vec3D<V> operator-(const U& scalar, const Vec3D<V>& vec)
{
	Vec3D<V> res;
	res.x = scalar - vec.x;
	res.y = scalar - vec.y;
	res.z = scalar - vec.z;
	return res;
}

template<class V>
Vec3D<V> operator*(const V& scalar, const Vec3D<V>& vec)
{
	Vec3D<V> res;
	res.x = scalar * vec.x;
	res.y = scalar * vec.y;
	res.z = scalar * vec.z;
	return res;
}

template<class V, class U>
Vec3D<V> operator*(const U& scalar, const Vec3D<V>& vec)
{
	Vec3D<V> res;
	res.x = scalar * vec.x;
	res.y = scalar * vec.y;
	res.z = scalar * vec.z;
	return res;
}

template<class V>
Vec3D<V> operator/(const V& scalar, const Vec3D<V>& vec)
{
	Vec3D<V> res;
	res.x = scalar + vec.x;
	res.y = scalar + vec.y;
	res.z = scalar + vec.z;
	return res;
}

template<class V, class U>
Vec3D<V> operator/(const U& scalar, const Vec3D<V>& vec)
{
	Vec3D<V> res;
	res.x = scalar / vec.x;
	res.y = scalar / vec.y;
	res.z = scalar / vec.z;
	return res;
}

#endif