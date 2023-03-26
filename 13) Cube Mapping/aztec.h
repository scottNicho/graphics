#pragma once
#include "..\nclgl\scenenode.h"

class Aztec : public SceneNode {
public:
	Aztec(Mesh* gem);
	~Aztec(void) {};
	void Update(float dt) override;

protected:

	SceneNode* world_centre;
	SceneNode* centre_element;
	SceneNode* left_element;
	SceneNode* right_element;
	SceneNode* north_element;
	SceneNode* south_element;
	SceneNode* north_east_element;
	SceneNode* south_east_element;
	SceneNode* south_west_element;
	SceneNode* north_west_element;

};

