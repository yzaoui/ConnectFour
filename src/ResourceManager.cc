#include "ResourceManager.h"

ResourceManager::ResourceManager(CFRenderer& renderer) : renderer_(renderer) {}

ResourceManager::~ResourceManager() {
	for (auto res = resources_.begin(); res != resources_.end(); res++) {
		delete res->second;
	}

	resources_.clear();
}

CFTexture* ResourceManager::load(std::string fileName) {
	//If the resource is already loaded, return it.
	//Otherwise, load the resource and return it.
	if (resources_.find(fileName) != resources_.end()) {
		return resources_.at(fileName);
	} else {
		CFTexture* texture = new CFTexture(renderer_);
		texture->loadFromFile(fileName);

		resources_.insert({fileName, texture});

		return texture;
	}
}
