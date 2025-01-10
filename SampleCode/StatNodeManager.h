#pragma once

#include <array>
#include <memory>
#include <unordered_set>

#include "StatType.h"

using StatNodeArray = std::array<std::unique_ptr<class StatNodeBase>, static_cast<int>(StatType::MAX)>;

class StatNodeManager
{
private:
	StatNodeArray mNodes; // ���� ��� ��� ��� 

public:
	StatNodeManager();

private:
	void BuildDependent();
	void InsertDependentTo(StatType from, StatType to);
public:
	StatNodeBase& GetStatNode(StatType statType) { return *mNodes.at(static_cast<int>(statType)); }
};

inline StatNodeManager* GStatNodeManager = nullptr;

