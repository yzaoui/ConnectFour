#ifndef _RESOURCEMANAGER_H
#define _RESOURCEMANAGER_H

#include <string>
#include <unordered_map>

#include "CFRenderer.h"
#include "CFTexture.h"

class ResourceManager {
public:
	ResourceManager(CFRenderer&);
	~ResourceManager();
	CFTexture* load(std::string resName, std::string fileName);
private:
	const CFRenderer& renderer_;
	std::unordered_map<std::string, CFTexture*> resources_;
};

#endif
