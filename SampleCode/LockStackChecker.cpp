#include "LockStackChecker.h"

LockStackChecker::LockStackChecker(int threadId) : mThreadId(threadId)
{

}

void LockStackChecker::Push(Lock* lock)
{
	if (lock->GetLockHierarchy() == -1)
	{
		return;
	}

	if (mLockStakc.empty() == false)
	{

	}

	mLockStakc.push_back(lock);
}

void LockStackChecker::Pop(const Lock* lock)
{
	if (lock->GetLockHierarchy() == -1)
	{
		return;
	}

	// mLockStakc.back() != lock 이건 무슨의도일까 ? 꺼내려는 락이 아니다 흠. 
	if(mLockStakc.empty() || mLockStakc.back() != lock)
		//CRASH.

	mLockStakc.pop_back();
}
