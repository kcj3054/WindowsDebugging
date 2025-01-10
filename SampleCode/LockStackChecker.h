#pragma once

#include "Lock.h"
#include <vector>

/*
* 락 hierarchy 체커 
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
	//락 개체를 스택에 추가 
	void Push(Lock* lock);

	void Pop(const Lock* lock);

public:
	//각 스렏의 락 스택체커의 덤프 수행 Exception.cpp같은 곳에서 등록된다. 
	// void Dum(wofstream& outFile) const.. 
};


// 스레드별 락 계층 체커 매니저 
// 용도는 Exception 같은 곳에서 Dump 시 사용한다.

class LockStackManager
{
public:
	// MAX_THREAD_COUNT
	// 변수 선언과 동시에 nullptr
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

	//각 스레드의 lockStackChecker 덤프 
	// void Dump(std::stream outFile)..
};
inline LockStackManager* GLockStackManager = nullptr;