#ifndef __KD_TREE_HEADER__
#define __KD_TREE_HEADER__

#include"Header.h"
#include"TreeNode.h"

template<class T>
class KdTree
{
private:
	TreeNode<T>* treeNodes;
	size_t N;
public:
	void KdTree();
	void KdTree(T* array, size_t N);
	void ~KdTree();
};

#endif
