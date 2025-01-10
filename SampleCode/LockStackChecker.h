#pragma once

#include "Lock.h"
#include <vector>

/*
* �� hierarchy üĿ 
*/
class LockStackChecker
{
public:
	LockStackChecker() = default;
	explicit LockStackChecker(int threadId);

private:

	using LockStack = std::vector<Lock*>;

	LockStack	mLockStakc;
	int			mThreadId;

public:
	//�� ��ü�� ���ÿ� �߰� 
	void Push(Lock* lock);

	void Pop(const Lock* lock);

public:
	//�� ������ �� ����üĿ�� ���� ���� Exception.cpp���� ������ ��ϵȴ�. 
	// void Dum(wofstream& outFile) const.. 
};


// �����庰 �� ���� üĿ �Ŵ��� 
// �뵵�� Exception ���� ������ Dump �� ����Ѵ�.

class LockStackManager
{
public:
	// MAX_THREAD_COUNT
	// ���� ����� ���ÿ� nullptr
	LockStackManager* mLockStackManager[2000]; 

public:
	LockStackManager() noexcept
	{
		for (int i = 0; i < 2000; ++i)
		{
			//nullptr
		}
	}

public:

	//�� �������� lockStackChecker ���� 
	// void Dump(std::stream outFile)..
};
inline LockStackManager* GLockStackManager = nullptr;