//#pragma once
//
//#include "StatType.h"
//#include <set>
//
//class StatOwner;
//class StatComponent; 
//
//// : public StatNodeBase.. 
//// 
//class StatckNodeBase
//{
//private:
//	StatType mStatType = StatType::MAX;
//	StatVisibility mStatvisibility = StatVisibility::MAX;
//
//	std::set<StatType>  mDependencySet;
//	std::set<StatType>  mDependentSet;
//
//public:
//	explicit StatckNodeBase(StatType statType, StatVisibility statVisibility, std::initializer_list<StatType>&& dependencySet);
//	virtual ~StatckNodeBase() = default;
//
//public:
//	virtual StatValue UpdateStatValue([[maybe_unused]] StatOwner& statOnwer, [[may_unused]] StatComponent* statComponent = nullptr) const
//	{
//		return StatValue();
//	}
//
//public:
//	void InsertDependency(StatType statType) { mDependencySet.insert(statType); }
//	void InsertDependent(StatType statType)
//	{
//		mDependentSet.insert(statType);
//	}
//	bool HasDependency(StatType statType) const { return (mDependencySet.find(statType) != mDependencySet.end()); }
//
//public:
//	const std::set<StatType>& GetDependencySet() const { return mDependencySet; }
//	const std::set<StatType>& GetDependentSet() const { return mDependentSet; }
//	StatValue GetStatValue(StatOwner& statOwner, StatType statType) const;
//	StatType GetStatType() const { return mStatType; }
//	StatVisibility GetStatVisibility() const { return mStatVisibility; }
//};
//
