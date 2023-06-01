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
	KdTree(const VecNB<T>* array, const int& N, const int& minDepthLvl, const int& maxDepthLvl);
	~KdTree();

	int getSizeTree();
	int getN();
	int getMinDepthLvl();
	int getMaxDepthLvl();
};

#endif
