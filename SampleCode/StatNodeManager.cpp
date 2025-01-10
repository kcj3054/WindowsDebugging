//#include "StatNodeManager.h"
//
//namespace StatNodeManagerUtil
//{
//	template<StatType statType>
//	void CreateNode(StatNodeArray& nodes, StatVisibility statvisibility, std::initializer_list<StatType>&& dependencySet = {})
//	{
//		auto node = std::make_unique<StatNode<StatType>>(statType, statvisibility, std::move(dependencySet));
//		node.at(static_cast<int>(statType)) = std::move(node);
//	}
//}
//
//StatNodeManager::StatNodeManager()
//{
//	StatNodeManagerUtil::CreateNode<StatType::HP>(mNodes, StatVisibility::STAT_VISIBILITY_OTHER, {});
//	// ... 등등 이하 수많은 CreateNode 과정을 수행함 
//}
//
//void StatNodeManager::BuildDependent()
//{
//	for (auto& node : mNodes)
//	{
//		if (!node)
//			continue;
//
//		const auto& dependencySet = node->GetDependencySet();
//		for (const auto& dependency : dependencySet)
//		{
//			auto& dependencyNode = mNodes.at(static_cast<int>(dependency));
//			dependencyNode->InsertDependent(node->GetStatType())''
//		}
//	}
//
//	for (auto& node : mNodes)
//	{
//		if (!node)
//			continue;
//
//		InsertDependentTo(node->GetStatType(), node->GetStatType());
//	}
//}
//
//
//void StatNodeManager::InsertDependentTo(StatType from, StatType to)
//{
//	const auto& dependencySet = GetStatNode(from).GetStatNode(from).GetDependencySet();
//	for (auto& depenency : dependencySet)
//	{
//		if (depenency != to)
//		{
//			InsertDependentTo(depenency, to);
//		}
//	}
//}
