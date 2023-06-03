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
KdTree<T>::KdTree(VecNB<T>* array, const int& N, const int& minDepthLvl, const int& maxDepthLvl)
{
	this->KdTree(N, minDepthLvl, maxDepthLvl);
	this->build(array);
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
TreeNode<T>* KdTree<T>::getNodes()
{
	return this->treeNodes;
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

template<class T>
void KdTree<T>::build(VecNB<T>* array)
{
	double lvl = log2(this->N);
	int startDim = lvl > int(lvl) ? int(lvl) + 1 : int(lvl);
	startDim = startDim % 3 == 0 ? dimZ : startDim % 2 == 0 ? dimY : dimX;
	this->mergeSort(array, startDim);
	for (int i = 0; i < this->N; i++)
		this->treeNodes[this->N + i].addParticle(array[i]);
	for (int i = this->N << 1; i != HEAD_INDEX; i <<= 1)
	{
		for (int index = i; index < (i >> 1); index++)
		{
			int offset = index >> 1;
			TreeNode<T> left = this->treeNodes[offset + 1];
			TreeNode<T> right = offset + 2 < this->getSizeTree() ? this->treeNodes[offset + 2] : 0.0;
			this->treeNodes[index] = left + right;
		}
	}
}

template<class T>
void KdTree<T>::mergeSort(VecNB<T>* array, const int& startDim)
{
	int dim = startDim;
	for (int curSize = 1; curSize <= this->N - 1; curSize <<= 1)
	{
		for (int leftStart = 0; leftStart < this->N - 1; leftStart += curSize << 1)
		{
			this->merge(array, leftStart, 
				min(leftStart + curSize - 1, this->N - 1),
				min(leftStart + (curSize << 1) - 1, this->N - 1),
				dim);
		}
		dim = --dim < dimX ? dimZ : dim;
	}
}

template<class T>
void KdTree<T>::merge(VecNB<T>* array, const int& l, const int& m, const int& r, const int& dim)
{
	int i = 0, j = 0, k = 1;
	int nL = m - l + 1;
	int nR = r - m;
	VecNB<T>* left = unique_ptr<VecNB<T>[]>(new VecNB<T>[nL]);
	VecNB<T>* right = unique_ptr<VecNB<T>[]>(new VecNB<T>[nR]);
	for (i = 0; i < nL; i++)
		left[i] = array[l + i];
	for (j = 0; j < nR; j++)
		right[j] = array[m + 1 + j];
	i = j = 0;
	while (i < nL && j < nR)
	{
		if (dim == dimX && left[i].lesserEqualRX(right[j]))
			array[k] = left[i++];
		else if (dim == dimY && left[i].lesserEqualRY(right[j]))
			array[k] = left[i++];
		else if (dim == dimZ && left[i].lesserEqualRZ(right[j]))
			array[k] = left[i++];
		else
			array[k] = right[j++];
		k++;
	}
	while (i < nL)
		array[k++] = left[i++];
	while (j < nR)
		array[k++] = right[j++];
}

#endif