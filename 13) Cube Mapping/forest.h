#pragma once
#include "..\nclgl\scenenode.h"

class Forest : public SceneNode {
public:
	Forest(Mesh* tree);
	~Forest(void) {};
	void Update(float dt) override;

protected:
	SceneNode* heart_tree;

};