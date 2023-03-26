#include "Forest.h"

Forest::Forest(Mesh* tree) {

	SceneNode* heart_tree = new SceneNode(tree, Vector4(0.2, 0.5, 0.6, 1)); 
	heart_tree->SetModelScale(Vector3(10, 10, 10));
	heart_tree->SetTransform(Matrix4::Translation(Vector3(-1000, 100, 500)));
	AddChild(heart_tree);

	SceneNode* tree1 = new SceneNode(tree, Vector4(0.2, 0.5, 0.6, 0.4)); 
	tree1->SetModelScale(Vector3(10, 10, 10));
	tree1->SetTransform(Matrix4::Translation(Vector3(100, 0, 10)));
	heart_tree -> AddChild(tree1);


	SceneNode* tree2 = new SceneNode(tree, Vector4(0.2, 0.2, 0.6, 0.3)); 
	tree2->SetModelScale(Vector3(10, 10, 10));
	tree2->SetTransform(Matrix4::Translation(Vector3(150, 0, 120)));
	heart_tree->AddChild(tree2);


	SceneNode* tree3 = new SceneNode(tree, Vector4(0.2, 0.5, 0.9, 0.2)); 
	tree3->SetModelScale(Vector3(10, 10, 10));
	tree3->SetTransform(Matrix4::Translation(Vector3(300, 0, 315)));
	heart_tree->AddChild(tree3);


	SceneNode* tree4 = new SceneNode(tree, Vector4(0.9, 0.5, 0.6, 0.6)); 
	tree4->SetModelScale(Vector3(10, 10, 10));
	tree4->SetTransform(Matrix4::Translation(Vector3(520, 0, -410)));
	heart_tree->AddChild(tree4);

	SceneNode* tree5 = new SceneNode(tree, Vector4(0.2, 0.1, 0.1, 0.5)); 
	tree5->SetModelScale(Vector3(10, 10, 10));
	tree5->SetTransform(Matrix4::Translation(Vector3(-810, 0, -210)));
	heart_tree->AddChild(tree5);

	SceneNode* tree6 = new SceneNode(tree, Vector4(0.2, 0.3, 0.6, 0.3)); 
	tree6->SetModelScale(Vector3(10, 10, 10));
	tree6->SetTransform(Matrix4::Translation(Vector3(730, 0, 910)));
	heart_tree->AddChild(tree6);


	SceneNode* tree7 = new SceneNode(tree, Vector4(0.2, 0.5, 0.5, 0.4)); 
	tree7->SetModelScale(Vector3(10, 10, 10));
	tree7->SetTransform(Matrix4::Translation(Vector3(340, 0, 700)));
	heart_tree->AddChild(tree7);


	SceneNode* tree8 = new SceneNode(tree, Vector4(0.2, 0.2, 0.6, 0.3)); 
	tree8->SetModelScale(Vector3(10, 10, 10));
	tree8->SetTransform(Matrix4::Translation(Vector3(1500, 0, 120)));
	heart_tree->AddChild(tree8);


	SceneNode* tree9 = new SceneNode(tree, Vector4(0.2, 0.9, 0.1, 0.4));
	tree9->SetModelScale(Vector3(10, 10, 10));
	tree9->SetTransform(Matrix4::Translation(Vector3(300, 0, 2000)));
	heart_tree->AddChild(tree9);


	SceneNode* tree10 = new SceneNode(tree, Vector4(0.1, 0.7, 0.6, 0.6)); 
	tree10->SetModelScale(Vector3(10, 10, 10));
	tree10->SetTransform(Matrix4::Translation(Vector3(1000, 0, 1500)));
	heart_tree->AddChild(tree10);

	SceneNode* tree11 = new SceneNode(tree, Vector4(0.4, 0.0, 0.6, 0.8)); 
	tree11->SetModelScale(Vector3(10, 10, 10));
	tree11->SetTransform(Matrix4::Translation(Vector3(-810, 0, 2100)));
	heart_tree->AddChild(tree11);

	SceneNode* tree12 = new SceneNode(tree, Vector4(0.2, 0.7, 0.6, 0.2)); 
	tree12->SetModelScale(Vector3(10, 10, 10));
	tree12->SetTransform(Matrix4::Translation(Vector3(720, 0, 1910)));
	heart_tree->AddChild(tree12);


}


void Forest::Update(float dt) {
	transform = transform *
		Matrix4::Rotation(0.0f * dt, Vector3(0, 1, 0));
	SceneNode::Update(dt);
	/*heart_tree->SetTransform(heart_tree->GetTransform() *
		Matrix4::Rotation(1.0f * dt, Vector3(0, 1, 0)));
	SceneNode::Update(dt);*/
}

