#include "LockFreeStack.h"

//void InitialzedHead(SListHeader* header)
//{
//	header->next = nullptr;
//}

//============== 1�� �ڵ� ===================
//void PushEntrySList(SListHeader* header, SListEntry* entry)
//{
//	entry->next = header->next;
//	/*
//	* multiThread ȯ�濡�� ���� �������� ������ �߻��� �� ����
//	*/
//	header->next = entry;
//}
//
//SListEntry* PopEntrySList(SListHeader* header)
//{
//	SListEntry* first = header->next;
//
//	if (first != nullptr)
//		header->next = first->next;
//
//	return first;
//}


//===========2�� �ڵ�===================
//void PushEntrySList(SListHeader* header, SListEntry* entry)
//{
//	entry->next = header->next;
//	/*
//	* multiThread ȯ�濡�� ���� �������� ������ �߻��� �� ����
//	*/
//	// header->next = entry;
//
//	// whlie(::InterlockedComparedExchange64..)
//}
//
//SListEntry* PopEntrySList(SListHeader* header)
//{
//	SListEntry* first = header->next;
//
//	// ABA Problem
//	// 
//
//
//	// ���� Header�� 5000�̶��, Header���� 6000�� �־��� 
//	// [5000] - > [6000] - > [7000]
//	// [Header]
//
//	if (first != nullptr)
//		header->next = first->next;
//
//	return first;
//}


//=============3���ڵ� (ABA �ذ�� �κ�) ===================
// 16����Ʈ ���Ľ� ������ 4bit�� �׻� 0�̴�.. ������ .. 
// 
void InitialzedHead(SListHeader* header)
{
	header->alignment = 0;
	header->HeaderX64.depth = 0; //.. 
}

void PushEntrySList(SListHeader* header, SListEntry* entry)
{
	SListHeader expected = {};
	SListHeader desired = {};

	// 16����Ʈ ���Ŀ��� ���� 4����Ʈ�� ������ 0�̴�.
	desired.HeaderX64.next = (((UINT64)entry) >> 4);

	while (true)
	{
		expected = *header;
	}
}

SListEntry* PopEntrySList(SListHeader* header)
{
	return nullptr;
}

/*
* MemoryPool�� ����� �� queue�� ����ϸ�, �����ͻӸ��ƴ϶� �����͸� ���� ������ �Ҵ��Ѵ� �׷��� ��ȿ���̴� �� ?
* �׷��� SListEntry�� ����Ѵٰ��Ѵ�.
*/