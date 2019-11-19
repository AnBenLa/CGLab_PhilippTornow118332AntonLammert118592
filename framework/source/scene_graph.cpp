#include "scene_graph.hpp"

bool SceneGraph::instanceFlag = false;
SceneGraph* SceneGraph::instance = NULL;

SceneGraph::SceneGraph(){
	root_ = std::make_shared<Node>("root", nullptr);
}

SceneGraph* SceneGraph::getInstance() {
	if (!instanceFlag) {
		instance = new SceneGraph();
		instanceFlag = true;
		return instance;
	} else {
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

std::shared_ptr<Node> SceneGraph::getRoot() {
	return root_;
}

//TODO implement print out
std::string SceneGraph::printGraph() {
	return "TODO";
}

void SceneGraph::setName(std::string name) {
	name_ = name;
}

void SceneGraph::setRoot(std::shared_ptr<Node> root) {
	root_ = root;
}