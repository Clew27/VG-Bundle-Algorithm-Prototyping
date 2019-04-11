#include "Tree.hpp"

bool Tree::addChild(int childId, int parentId) {
	if (vertices.size() == 0) {
		addVertex(childId);
		return true;
	} 

	if (getIndex(parentId) == -1) {
		return false;
	}

	addVertex(childId);
	addDirectedEdge(parentId, childId);

	return true;
}

std::vector<Node*> getAncestors(int id) {
	Node* node = getNode(id);

	if (node == nullptr) {
		return {};
	}

	std::vector<Node*> ancestors;
	
	std::vector<Node*> parent = node.getIncomingNodes();
	while (parent.size() != 0) {
		node = parent.at(0);
		ancestors.push_back(node);
		parent = node.getIncomingNodes();
	}

	return ancestors;
}

std::vector<Node*> getSiblings(int id) {
	Node* node = getNode(id);

	if (node == nullptr) {
		return {};
	}

	std::vector<Node*> parent = node.getIncomingNodes()
	if (parent.size() == 0) {
		return std::vector<Node*>();
	}

	std::vector<Node*> siblings = parent.at(0).getOutgoingNodes();

	Node comp = Node(id);

	std::vector<Node*>::iterator itr = std::find(verts.begin(), vertices.end(), comp);
	int index = std::distance(vertices.begin(), itr);
	siblings.erase(siblings.begin() + index);

	return siblings;
}