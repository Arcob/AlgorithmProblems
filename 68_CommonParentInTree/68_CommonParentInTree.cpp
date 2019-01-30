// 68_CommonParentInTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 面试题68：树中两个结点的最低公共祖先
// 题目：输入两个树结点，求它们的最低公共祖先。

#include "pch.h"
#include <iostream>
#include <cstdio>
#include "Tree.h"
#include <list>

using namespace std;

bool GetNodePath(const TreeNode* pRoot, const TreeNode* pNode, list<const TreeNode*>& path)
{
	if (pRoot == pNode) {
		return true;
	}

	path.push_back(pRoot);

	bool found = false;

	for (int i = 0; i < pRoot->m_vChildren.size(); i++) {
		if (pRoot->m_vChildren[i] != nullptr) {
			found = found || GetNodePath(pRoot->m_vChildren[i], pNode, path);
		}
	}
	if (!found) {
		path.pop_back();
	}

	return found;
}

const TreeNode* GetLastCommonNode
(
	const list<const TreeNode*>& path1,
	const list<const TreeNode*>& path2
)
{
	if (path1.size() <= 0 || path2.size() <= 0) {
		return nullptr;
	}
	
	auto start1 = path1.begin();
	auto start2 = path2.begin();

	const TreeNode* lastEqual = nullptr;

	if (*start1 != *start2) {
		return false;
	}

	while (start1 != path1.end() && start2 != path2.end()) {
		//std::cout << (*start1)->m_nValue << " " << (*start2)->m_nValue << std::endl;
		if (*start1 == *start2) {
			lastEqual = *start1;
		}
		start1++;
		start2++;
	}
	return lastEqual;
}

const TreeNode* GetLastCommonParent(const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2)
{
	if (pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr)
		return nullptr;

	list<const TreeNode*> path1;
	GetNodePath(pRoot, pNode1, path1);

	list<const TreeNode*> path2;
	GetNodePath(pRoot, pNode2, path2);
	auto temp = path1.begin();

	return GetLastCommonNode(path1, path2);
}

// ====================测试代码====================
void Test(const char* testName, const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2, TreeNode* pExpected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	const TreeNode* pResult = GetLastCommonParent(pRoot, pNode1, pNode2);

	if ((pExpected == nullptr && pResult == nullptr) ||
		(pExpected != nullptr && pResult != nullptr && pResult->m_nValue == pExpected->m_nValue))
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 形状普通的树
//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10
void Test1()
{
	TreeNode* pNode1 = CreateTreeNode(1);
	TreeNode* pNode2 = CreateTreeNode(2);
	TreeNode* pNode3 = CreateTreeNode(3);
	TreeNode* pNode4 = CreateTreeNode(4);
	TreeNode* pNode5 = CreateTreeNode(5);
	TreeNode* pNode6 = CreateTreeNode(6);
	TreeNode* pNode7 = CreateTreeNode(7);
	TreeNode* pNode8 = CreateTreeNode(8);
	TreeNode* pNode9 = CreateTreeNode(9);
	TreeNode* pNode10 = CreateTreeNode(10);

	ConnectTreeNodes(pNode1, pNode2);
	ConnectTreeNodes(pNode1, pNode3);

	ConnectTreeNodes(pNode2, pNode4);
	ConnectTreeNodes(pNode2, pNode5);

	ConnectTreeNodes(pNode4, pNode6);
	ConnectTreeNodes(pNode4, pNode7);

	ConnectTreeNodes(pNode5, pNode8);
	ConnectTreeNodes(pNode5, pNode9);
	ConnectTreeNodes(pNode5, pNode10);

	Test("Test1", pNode1, pNode6, pNode8, pNode2);
}

// 树退化成一个链表
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test2()
{
	TreeNode* pNode1 = CreateTreeNode(1);
	TreeNode* pNode2 = CreateTreeNode(2);
	TreeNode* pNode3 = CreateTreeNode(3);
	TreeNode* pNode4 = CreateTreeNode(4);
	TreeNode* pNode5 = CreateTreeNode(5);

	ConnectTreeNodes(pNode1, pNode2);
	ConnectTreeNodes(pNode2, pNode3);
	ConnectTreeNodes(pNode3, pNode4);
	ConnectTreeNodes(pNode4, pNode5);

	Test("Test2", pNode1, pNode5, pNode4, pNode3);
}

// 树退化成一个链表，一个结点不在树中
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test3()
{
	TreeNode* pNode1 = CreateTreeNode(1);
	TreeNode* pNode2 = CreateTreeNode(2);
	TreeNode* pNode3 = CreateTreeNode(3);
	TreeNode* pNode4 = CreateTreeNode(4);
	TreeNode* pNode5 = CreateTreeNode(5);

	ConnectTreeNodes(pNode1, pNode2);
	ConnectTreeNodes(pNode2, pNode3);
	ConnectTreeNodes(pNode3, pNode4);
	ConnectTreeNodes(pNode4, pNode5);

	TreeNode* pNode6 = CreateTreeNode(6);

	Test("Test3", pNode1, pNode5, pNode6, nullptr);
}

// 输入nullptr
void Test4()
{
	Test("Test4", nullptr, nullptr, nullptr, nullptr);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}
