#pragma once
#include <Windows.h>

//SListEntry 라는 단어는 어디서 나왔을까?
// Singly-Linked List Entry(리스트 내의 단일 노드 또는 요소)
// 각 Entry는 데이터와, 다음 엔트리를 가리키는 참조(포인터)를 포함합니다.

//struct SListEntry
//{
//	SListEntry* next;
//};
//
//struct SListHeader
//{
//	SListEntry* next = nullptr;
//};
//
//void InitialzedHead(SListHeader* header);
//void PushEntrySList(SListHeader* header, SListEntry* entry);
//SListEntry* PopEntrySList(SListHeader* header);


//======= 3차 시도 ===============

// 메모리한테 우리 16byte정렬하겠다고 말하는 것
DECLSPEC_ALIGN(16) // DECLSPEC_ALIGN은 특정 플랫폼에 종속적이다, 코드의 이식성을 높이기 위해 c++11부터 도입된 표준 정렬 지정자인, alignas 선호
struct SListEntry
{
	SListEntry* next;
};

//struct alignas(16) AlignedStruct
//{
//	float data[4];
//};

//  DECLSPEC_ALIGN(16) -> 구조체의 시작이 16바이트의 배수가 되도록 보장한다.
// 이렇게하면 메모리 접근 성능을 향상시킨다는데 왜  ? 
// 
DECLSPEC_ALIGN(16)
struct SListHeader
{
	union
	{
		//union을 이용하여,
		// DUMMYSTRUCTNAME 와 HeaderX64 메모리 공간을 공유함 
		struct
		{
			UINT64 alignment;
			UINT64 region;
		} DUMMYSTRUCTNAME;

		struct
		{
			//16비트 크기의 depth.. 
			UINT64 depth : 16;
			UINT64 sequence : 48;
			UINT64 reserved : 4;
			UINT64 next : 60;
		} HeaderX64;

	};

	SListEntry* next = nullptr;
};

void InitialzedHead(SListHeader* header);
void PushEntrySList(SListHeader* header, SListEntry* entry);
SListEntry* PopEntrySList(SListHeader* header);