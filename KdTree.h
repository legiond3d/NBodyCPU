#ifndef __KD_TREE_HEADER__
#define __KD_TREE_HEADER__

#include"TreeNode.h"

template<class T>
class KdTree
{
private:
	TreeNode<T>* treeNodes;
	int N;
	int minDepthLvl;
	int maxDepthLvl;
public:
	KdTree(const int& N, const int& minDepthLvl, const int& maxDepthLvl);
	KdTree(VecNB<T>* array, const int& N, const int& minDepthLvl, const int& maxDepthLvl);
	~KdTree();

	int getSizeTree();
	int getN();
	TreeNode<T>* getNodes();
	int getMinDepthLvl();
	int getMaxDepthLvl();

	void build(VecNB<T>* array);
	void mergeSort(VecNB<T>* array, const int& startDim);
	void merge(VecNB<T>* array, const int& l, const int& m, const int& r, const int& dim);
};

#endif
