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

	// mLockStakc.back() != lock �̰� �����ǵ��ϱ� ? �������� ���� �ƴϴ� ��. 
	if(mLockStakc.empty() || mLockStakc.back() != lock)
		//CRASH.

	mLockStakc.pop_back();
}
