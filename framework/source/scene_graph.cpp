#include "scene_graph.hpp"

SceneGraph::getInstance() {
	if (!instanceFlag) {
		instance = new SceneGraph();
		instanceFlag = true;
		return instance;
	}
}

//TODO delete nodes?
SceneGraph::~SceneGraph() {
	instanceFlag = false;
}

std::string SceneGraph::getName() {
	return name_;
}

Node SceneGraph::getRoot() {
	return root_;
}

//TODO implement print out
std::string SceneGraph::printGraph() {
	return "TODO";
}

void SceneGraph::setName(std::string name) {
	this.name_ = name;
}

void SceneGraph::setRoot(Node root) {
	this.getRoot = root;
}