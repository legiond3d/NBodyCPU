#ifndef __TREE_NODE__
#define __TREE_NODE__

#include"TreeNode.h"

template<class T>
TreeNode<T>::TreeNode()
{
	this->borderLeft = new Vec3D<T>();
	this->borderRight = new Vec3D<T>();
	this->pointer = NULL;
	this->mass = 0.0;
	this->massCentre = new Vec3D<T>();
}

template<class T>
TreeNode<T>::TreeNode(const Vec3D<T>& borderLeft, const Vec3D<T>& borderRight, VecNB<T>* pointer)
{
	this->borderLeft = new Vec3D<T>(borderLeft);
	this->borderRight = new Vec3D<T>(borderRight);
	this->pointer = pointer;
	if (pointer != NULL)
	{
		this->mass = pointer->getM();
		this->massCentre = new Vec3D<T>(pointer->getR())
	}
	else
	{
		this->mass = 0.0;
		this->massCentre = new Vec3D<T>()
	}
}

template<class T>
TreeNode<T>::TreeNode(const T& leftX, const T& rightX, const T& leftY, const T& rightY, const T& leftZ, const T& rightZ, VecNB<T>* pointer)
{
	this->borderLeft = new Vec3D<T>(leftX, leftY, leftZ);
	this->borderRight = new Vec3D<T>(rightX, rightY, rightZ);
	this->pointer = pointer;
	if (pointer != NULL)
	{
		this->mass = pointer->getM();
		this->massCentre = new Vec3D<T>(pointer->getR());
	}
	else
	{
		this->mass = 0.0;
		this->massCentre = new Vec3D<T>()
	}
}

template<class T>
TreeNode<T>::~TreeNode()
{
	delete this->borderLeft;
	delete this->borderRight;
	delete this->massCentre;
	this->mass = 0.0;
	this->pointer = NULL;
}

template<class T>
T TreeNode<T>::getMass()
{
	return this->mass;
}

template<class T>
Vec3D<T> TreeNode<T>::getMassCentre()
{
	return this->massCentre / this->mass;
}

template<class T>
TreeNode<T>& TreeNode<T>::operator=(const TreeNode<T>& node)
{
	if (this != &node)
	{
		this->mass = node.mass;
		this->massCentre = node.massCentre;
	}
	return *this;
}

template<class T>
TreeNode<T>& TreeNode<T>::operator=(const T& scalar)
{
	this->mass = scalar;
	this->massCentre = scalar;
	return *this;
}

template<class T>
TreeNode<T> TreeNode<T>::operator+(const TreeNode<T>& node)
{
	TreeNode<T> res;
	res.mass = this->mass + node.mass;
	res.massCentre = this->massCentre + node.massCentre;
	return res;
}

template<class T>
void TreeNode<T>::addParticle(const VecNB<T>& particle)
{
	this->mass = particle.getM();
	this->massCentre = particle.getR() * particle.getM();
}

template<class T>
bool TreeNode<T>::checkDistance(const VecNB<T>& particle)
{
	T dr = (this->pointer->getR() - particle.getR()).mod();
	return dr > 0.0 && (1.0 / THETA) > dr;
}

#endif