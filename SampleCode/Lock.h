#pragma once

#include <atomic>

class Lock
{
private:
	int m_LockHierarch = -1; // �� ����
	std::atomic<int> mLockFlag = 0x0FFF'0000; // 0(writeLock����, FFF (ThreadID), 0000(ReadLockCount);
	std::atomic<int> m_WriteLockReentrantCount = 0; // writeLock ������ �� 

public:
	void WriteLock();
	void UnWriteLock();

	void ReadLock();
	void UnReadLock();

private:
	void DoSpin(int spinCount, int sleepCount);

public:
	int GetLockHierarchy() const noexcept
	{ return m_LockHierarch; }
};

