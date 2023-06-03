#ifndef __VEC_NB_HEADER__
#define __VEC_NB_HEADER__

#include"Vec3D.h"

template<class T>
class VecNB
{
private:
	Vec3D<T> r;
	Vec3D<T> v;
	T m;
public:
	VecNB();
	VecNB(const Vec3D<T>& r, const Vec3D<T>& v, const T& m);
	VecNB(const T& x, const T& y, const T& z, const T& vx, const T& vy, const T& vz, const T& m);
	~VecNB();

	Vec3D<T> getR();
	Vec3D<T> getV();
	T getM();

	T getEp(const VecNB<T>& vec, const T& r);
	T getEk();
	Vec3D<T> getP();
	Vec3D<T> getL();

	void setR(const T& x, const T& y, const T& z);
	void setR(const Vec3D<T>& r);
	void setV(const T& x, const T& y, const T& z);
	void setV(const Vec3D<T>& v);
	void setM(const T& m);

	bool lesserEqualRX(const VecNB<T>& vec);
	bool lesserEqualRY(const VecNB<T>& vec);
	bool lesserEqualRZ(const VecNB<T>& vec);
};

#endif
