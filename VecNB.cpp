#ifndef __VEC_NB__
#define __VEC_NB__

#include"VecNB.h"

template<class T>
VecNB<T>::VecNB()
{
	this->r = new Vec3D<T>();
	this->v = new Vec3D<T>();
	this->m = 0.0;
}

template<class T>
VecNB<T>::VecNB(const Vec3D<T>& r, const Vec3D<T>& v, const T& m)
{
	this->r = new Vec3D<T>(r);
	this->v = new Vec3D<T>(v);
	this->m = m;
}

template<class T>
VecNB<T>::VecNB(const T& x, const T& y, const T& z, const T& vx, const T& vy, const T& vz, const T& m)
{
	this->r = new Vec3D<T>(x, y, z);
	this->v = new Vec3D<T>(vx, vy, vz);
	this->m = m;
}

template<class T>
VecNB<T>::~VecNB()
{
	delete this->r;
	delete this->v;
	this->m = 0.0;
}

template<class T>
Vec3D<T> VecNB<T>::getR()
{
	return this->r;
}

template<class T>
Vec3D<T> VecNB<T>::getV()
{
	return this->v;
}

template<class T>
T VecNB<T>::getM()
{
	return this->m;
}

template<class T>
T VecNB<T>::getEp(const VecNB<T>& vec, const T& r)
{
	return (G * this->m * vec.m) / r;
}

template<class T>
T VecNB<T>::getEk()
{
	return this->m * this->v.mod2();
}

template<class T>
Vec3D<T> VecNB<T>::getP()
{
	return this->m * this->v;
}

template<class T>
Vec3D<T> VecNB<T>::getL()
{
	return this->m * this->r.getL(this->v);
}

template<class T>
void VecNB<T>::setR(const T& x, const T& y, const T& z)
{
	this->r.setX(x);
	this->r.setY(y);
	this->r.setZ(z);
}

template<class T>
void VecNB<T>::setR(const Vec3D<T>& r)
{
	this->r = r;
}

template<class T>
void VecNB<T>::setV(const T& x, const T& y, const T& z)
{
	this->v.setX(x);
	this->v.setY(y);
	this->v.setZ(z);
}

template<class T>
void VecNB<T>::setV(const Vec3D<T>& v)
{
	this->v = v;
}

template<class T>
void VecNB<T>::setM(const T& m)
{
	this->m = m;
}

template<class T>
bool VecNB<T>::lesserEqualRX(const VecNB<T>& vec)
{
	return this->r.getX() <= vec.getR().getX();
}

template<class T>
bool VecNB<T>::lesserEqualRY(const VecNB<T>& vec)
{
	return this->r.getY() <= vec.getR().getY();
}

template<class T>
bool VecNB<T>::lesserEqualRZ(const VecNB<T>& vec)
{
	return this->r.getZ() <= vec.getR().getZ();
}

#endif