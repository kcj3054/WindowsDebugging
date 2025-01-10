#include "LockFreeStack.h"

//void InitialzedHead(SListHeader* header)
//{
//	header->next = nullptr;
//}

//============== 1차 코드 ===================
//void PushEntrySList(SListHeader* header, SListEntry* entry)
//{
//	entry->next = header->next;
//	/*
//	* multiThread 환경에서 사이 공간에서 문제가 발생할 수 있음
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


//===========2차 코드===================
//void PushEntrySList(SListHeader* header, SListEntry* entry)
//{
//	entry->next = header->next;
//	/*
//	* multiThread 환경에서 사이 공간에서 문제가 발생할 수 있음
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
//	// 만약 Header가 5000이라면, Header에다 6000을 넣어줘 
//	// [5000] - > [6000] - > [7000]
//	// [Header]
//
//	if (first != nullptr)
//		header->next = first->next;
//
//	return first;
//}


//=============3차코드 (ABA 해결된 부분) ===================
// 16바이트 정렬시 최하위 4bit는 항상 0이다.. 몰랐음 .. 
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

	// 16바이트 정렬에서 하위 4바이트는 어차피 0이다.
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
* MemoryPool을 사용할 때 queue를 사용하면, 데이터뿐만아니라 데이터를 담을 공간도 할당한다 그래서 비효율이다 왜 ?
* 그래서 SListEntry를 사용한다고한다.
*/