// 35_CopyComplexList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 面试题35：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
// 结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。

#include "pch.h"
#include <iostream>
#include <cstdio>
#include "ComplexList.h"

void CloneNodes(ComplexListNode* pHead);
void ConnectSiblingNodes(ComplexListNode* pHead);
ComplexListNode* ReconnectNodes(ComplexListNode* pHead);

ComplexListNode* Clone(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}

void CloneNodes(ComplexListNode* pHead)
{
	if (pHead == nullptr) {
		return;
	}
	ComplexListNode* tempNode = pHead;
	while (tempNode != nullptr) {
		ComplexListNode* pCloned = new ComplexListNode();
		pCloned->m_nValue = tempNode->m_nValue;
		pCloned->m_pNext = tempNode->m_pNext;
		pCloned->m_pSibling = nullptr;

		tempNode->m_pNext = pCloned;
		tempNode = pCloned->m_pNext;
	}
}

void ConnectSiblingNodes(ComplexListNode* pHead)
{
	if (pHead == nullptr) {
		return;
	}
	ComplexListNode* tempNode = pHead;
	while (tempNode != nullptr) {
		ComplexListNode* clonedNode = tempNode->m_pNext;
		if (tempNode->m_pSibling == nullptr) {
			clonedNode->m_pSibling = nullptr;
		}
		else {
			clonedNode->m_pSibling = tempNode->m_pSibling->m_pNext;
		}
		tempNode = clonedNode->m_pNext;
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	if (pHead == nullptr) {
		return nullptr;
	}
	
	ComplexListNode* tempNode = pHead;
	ComplexListNode* clonedNode = tempNode->m_pNext;
	ComplexListNode* result = pHead->m_pNext;
	while (tempNode != nullptr && clonedNode != nullptr) {
		pHead->m_pNext = clonedNode->m_pNext;
		if (clonedNode->m_pNext == nullptr) {
			break;
		}
		clonedNode->m_pNext = clonedNode->m_pNext->m_pNext;

		pHead = clonedNode->m_pNext;
		clonedNode = clonedNode->m_pNext->m_pNext;
	}
	return result;
}

// ====================测试代码====================
void Test(const char* testName, ComplexListNode* pHead)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("The original list is:\n");
	PrintList(pHead);

	ComplexListNode* pClonedHead = Clone(pHead);

	printf("The cloned list is:\n");
	PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
	ComplexListNode* pNode1 = CreateNode(1);
	ComplexListNode* pNode2 = CreateNode(2);
	ComplexListNode* pNode3 = CreateNode(3);
	ComplexListNode* pNode4 = CreateNode(4);
	ComplexListNode* pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, pNode3);
	BuildNodes(pNode2, pNode3, pNode5);
	BuildNodes(pNode3, pNode4, nullptr);
	BuildNodes(pNode4, pNode5, pNode2);

	Test("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
	ComplexListNode* pNode1 = CreateNode(1);
	ComplexListNode* pNode2 = CreateNode(2);
	ComplexListNode* pNode3 = CreateNode(3);
	ComplexListNode* pNode4 = CreateNode(4);
	ComplexListNode* pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, nullptr);
	BuildNodes(pNode2, pNode3, pNode5);
	BuildNodes(pNode3, pNode4, pNode3);
	BuildNodes(pNode4, pNode5, pNode2);

	Test("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3()
{
	ComplexListNode* pNode1 = CreateNode(1);
	ComplexListNode* pNode2 = CreateNode(2);
	ComplexListNode* pNode3 = CreateNode(3);
	ComplexListNode* pNode4 = CreateNode(4);
	ComplexListNode* pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, nullptr);
	BuildNodes(pNode2, pNode3, pNode4);
	BuildNodes(pNode3, pNode4, nullptr);
	BuildNodes(pNode4, pNode5, pNode2);

	Test("Test3", pNode1);
}

// 只有一个结点
void Test4()
{
	ComplexListNode* pNode1 = CreateNode(1);
	BuildNodes(pNode1, nullptr, pNode1);

	Test("Test4", pNode1);
}

// 鲁棒性测试
void Test5()
{
	Test("Test5", nullptr);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}
