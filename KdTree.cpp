#ifndef __KD_TREE__
#define __KD_TREE__

#include"KdTree.h"

template<class T>
KdTree<T>::KdTree(const int& N, const int& minDepthLvl, const int& maxDepthLvl)
{
	this->N = N;
	this->maxDepthLvl = maxDepthLvl;
	this->minDepthLvl = minDepthLvl;
	this->treeNodes = new TreeNode<T>[N << 1]();
}

template<class T>
KdTree<T>::KdTree(const VecNB<T>* array, const int& N, const int& minDepthLvl, const int& maxDepthLvl)
{
	this->KdTree(N, minDepthLvl, maxDepthLvl);

}

template<class T>
KdTree<T>::~KdTree()
{
	delete[] this->treeNodes;
	this->N = 0;
	this->maxDepthLvl = 0;
	this->minDepthLvl = 0;
}

template<class T>
int KdTree<T>::getSizeTree()
{
	return this->N << 1;
}

template<class T>
int KdTree<T>::getN()
{
	return this->N;
}

template<class T>
int KdTree<T>::getMinDepthLvl()
{
	return this->minDepthLvl;
}

template<class T>
int KdTree<T>::getMaxDepthLvl()
{
	return this->maxDepthLvl;
}

#endif