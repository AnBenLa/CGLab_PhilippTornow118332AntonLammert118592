#ifndef SCENE_GRAPH_HPP
#define SCENE_GRAPH_HPP
#include <string>
#include "node.hpp"

class SceneGraph {
	private: 
		std::string name_;
		Node root_;
		static bool instanceFlag;
		static SceneGraph* instance;
		SceneGraph();
		void setName(String);
		void setRoot(Node);

	public:
		static SceneGraph* getInstance();
		~SceneGraph();
		std::string getName();
		Node getRoot();
		std::string printGraph();
};

#endif