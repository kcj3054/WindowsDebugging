#pragma once
#include <Windows.h>

//SListEntry ��� �ܾ�� ��� ��������?
// Singly-Linked List Entry(����Ʈ ���� ���� ��� �Ǵ� ���)
// �� Entry�� �����Ϳ�, ���� ��Ʈ���� ����Ű�� ����(������)�� �����մϴ�.

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


//======= 3�� �õ� ===============

// �޸����� �츮 16byte�����ϰڴٰ� ���ϴ� ��
DECLSPEC_ALIGN(16) // DECLSPEC_ALIGN�� Ư�� �÷����� �������̴�, �ڵ��� �̽ļ��� ���̱� ���� c++11���� ���Ե� ǥ�� ���� ��������, alignas ��ȣ
struct SListEntry
{
	SListEntry* next;
};

//struct alignas(16) AlignedStruct
//{
//	float data[4];
//};

//  DECLSPEC_ALIGN(16) -> ����ü�� ������ 16����Ʈ�� ����� �ǵ��� �����Ѵ�.
// �̷����ϸ� �޸� ���� ������ ����Ų�ٴµ� ��  ? 
// 
DECLSPEC_ALIGN(16)
struct SListHeader
{
	union
	{
		//union�� �̿��Ͽ�,
		// DUMMYSTRUCTNAME �� HeaderX64 �޸� ������ ������ 
		struct
		{
			UINT64 alignment;
			UINT64 region;
		} DUMMYSTRUCTNAME;

		struct
		{
			//16��Ʈ ũ���� depth.. 
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