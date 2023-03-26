#include "Aztec.h"

Aztec::Aztec(Mesh* gem) {


	SceneNode* world_centre = new SceneNode(gem, Vector4(0.5, 0.7, 0.8, 1));
	world_centre->SetModelScale(Vector3(4, 4, 4));
	world_centre->SetTransform(Matrix4::Translation(Vector3(2000,300 , 2000)));
	AddChild(world_centre);

	centre_element = new SceneNode(gem, Vector4(0.5, 0.7, 0.8, 1));
	centre_element->SetModelScale(Vector3(4, 4, 4));
	centre_element->SetTransform(Matrix4::Translation(Vector3(0, 50, 200)));
	world_centre -> AddChild(centre_element);

	left_element = new SceneNode(gem, Vector4(0.9, 0.3, 0.6, 1));
	left_element->SetModelScale(Vector3(4, 4, 4));
	left_element->SetTransform(Matrix4::Translation(Vector3(10, 0, 0)));
	centre_element->AddChild(left_element);

	right_element = new SceneNode(gem, Vector4(1, 1, 0, 1));
	right_element->SetModelScale(Vector3(4, 4, 4));
	right_element->SetTransform(Matrix4::Translation(Vector3(-10, 0, 0)));
	centre_element->AddChild(right_element);

	north_element = new SceneNode(gem, Vector4(1, 1, 1, 1));
	north_element->SetModelScale(Vector3(4, 4, 4));
	north_element->SetTransform(Matrix4::Translation(Vector3(0, 0, -10)));
	centre_element->AddChild(north_element);


	south_element = new SceneNode(gem, Vector4(1, 0.5, 0.2, 1));
	south_element->SetModelScale(Vector3(4, 4, 4));
	south_element->SetTransform(Matrix4::Translation(Vector3(0, 0, 10)));
	centre_element->AddChild(south_element);

	north_east_element = new SceneNode(gem, Vector4(0.9, 0.2, 0.2, 1));
	north_east_element->SetModelScale(Vector3(4, 4, 4));
	north_east_element->SetTransform(Matrix4::Translation(Vector3(7, 0, -7)));
	centre_element->AddChild(north_east_element);

	south_east_element = new SceneNode(gem, Vector4(0.3, 0.3, 0.3, 1));
	south_east_element->SetModelScale(Vector3(4, 4, 4));
	south_east_element->SetTransform(Matrix4::Translation(Vector3(7, 0, 7)));
	centre_element->AddChild(south_east_element);

	south_west_element = new SceneNode(gem, Vector4(0.3, 0.6, 0.8, 1));
	south_west_element->SetModelScale(Vector3(4, 4, 4));
	south_west_element->SetTransform(Matrix4::Translation(Vector3(-7, 0, 7)));
	centre_element->AddChild(south_west_element);

	north_west_element = new SceneNode(gem, Vector4(0.6, 0, 0.4, 1));
	north_west_element->SetModelScale(Vector3(4, 4, 4));
	north_west_element->SetTransform(Matrix4::Translation(Vector3(-7, 0, 7)));
	centre_element->AddChild(north_west_element);


}


void Aztec::Update(float dt) {
	transform = transform *
		Matrix4::Rotation(0.0f * dt, Vector3(0, 1, 0));


	centre_element->SetTransform(centre_element->GetTransform() *
		 Matrix4::Rotation(30.0f * dt, Vector3(0, 1, 0.3)));

	//end function by updating everything

	SceneNode::Update(dt);
}
