#ifndef __TREE_NODE_HEADER__
#define __TREE_NODE_HEADER__

#include"VecNB.h"

template<class T>
class TreeNode
{
private:
	Vec3D<T> borderLeft;
	Vec3D<T> borderRight;
	VecNB<T>* pointer;
	T mass;
	Vec3D<T> massCentre;
public:
	TreeNode();
	TreeNode(const Vec3D<T>& borderLeft, const Vec3D<T>& borderRight, VecNB<T>* pointer = NULL);
	TreeNode(const T& leftX, const T& rightX, const T& leftY, const T& rightY, const T& leftZ, const T& rightZ, VecNB<T>* pointer = NULL);
	~TreeNode();

	T getMass();
	Vec3D<T> getMassCentre();

	TreeNode<T>& operator=(const TreeNode<T>& node);
	TreeNode<T>& operator=(const T& scalar);
	TreeNode<T> operator+(const TreeNode<T>& node);

	void addParticle(const VecNB<T>& particle);
	bool checkDistance(const VecNB<T>& particle);
};

#endif