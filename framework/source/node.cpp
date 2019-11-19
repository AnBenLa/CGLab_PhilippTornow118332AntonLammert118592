#include "node.hpp"

Node::Node(std::string name) :
	name_(name),
	parent_(nullptr),
	path_("/"+name)
{};

Node::Node(std::string name, std::shared_ptr<Node> parent): 
	name_(name), 
	parent_(parent),
	path_("/" + name)
{};

Node::Node(std::string name, std::shared_ptr<Node> parent, glm::mat4x4 localTransform) : 
	name_(name), 
	parent_(parent), 
	localTransform_(localTransform),
	path_("/" + name)
{};

std::shared_ptr<Node>::getParent()
{
	return parent_;
}

void Node::setParent(std::shared_ptr<Node> parent)
{
	parent_ = parent;
	depth_ = parent_->getDepth() + 1;
	path_ = parent_->getPath() + "/" + name_;
}

std::shared_ptr<Node> Node::getChildren(std::string name)
{
	if (name_ == name) {
		return this;
	} else {
		for (auto child : children_) {
			return child.getChildren(name);
		}
	}
	return nullptr;
}

std::list<std::shared_ptr<Node>> Node::getChildren()
{
	return children_;
}

std::string Node::getName()
{
	return name_;
}

std::string Node::getPath()
{
	return path_;
}

int Node::getDepth()
{
	return depth_;
}

glm::mat4x4 Node::getLocalTransform()
{
	return localTransform_;
}

void Node::setLocalTransform(glm::mat4x4 localTransform)
{
	localTransform_ = localTransform;
}

glm::mat4x4 Node::getWorldTransform()
{
	return parent_->getWorldTransform()*localTransform_;
}

void Node::setWorldTransform(glm::mat4x4 worldTransform)
{
	worldTransform_ = worldTransform;
}

void Node::addChildren(std::shared_ptr<Node> child)
{
	children_.insert(child);
}

Node Node::removeChildren(std::string name)
{
	std::shared_ptr<Node> result = this->getChildren(name);
	if (result != nullptr) {
		std::shared_ptr<Node> parent = result->getParent();
		if (parent != nullptr) {
			parent->children_.erase(result);
		}
	}
	return result;
}
