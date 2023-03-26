#include "renderer.h"
 #include "..\nclgl\Light.h"
 #include "..\nclgl\HeightMap.h"
 #include "..\nclgl\Shader.h"
 #include "..\nclgl\Camera.h"
#include "..\nclgl\MeshMaterial.h"
#include "../nclgl/MeshAnimation.h"




Renderer::Renderer(Window& parent) : OGLRenderer(parent) {
	quad = Mesh::GenerateQuad();
	gem = Mesh::GeneratePyramid();
	tree = Mesh::LoadFromMeshFile("treeA.msh");
	camera = new Camera();

	// animation stuff
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);

	projMatrix = Matrix4::Perspective(1.0f, 10000.0f,
		(float)width / (float)height, 45.0f);
	camera = new Camera(-3, 0.0f, Vector3(0, 5.0f, 4.0f));

	/*Dshader = new Shader("SkinningVertex.glsl", "texturedFragment.glsl");

	if (!shader->LoadSuccess()) {
		return;

	}*/
	mesh = Mesh::LoadFromMeshFile("Role_T.msh");
	anim = new MeshAnimation("Role_T.anm");
	material = new MeshMaterial("Role_T.mat");

	for (int i = 0; i < mesh->GetSubMeshCount(); ++i) {
		const MeshMaterialEntry* matEntry =
			material->GetMaterialForLayer(i);

		const string* filename = nullptr;
		matEntry->GetEntry("Diffuse", &filename);
		string path = TEXTUREDIR + *filename;
		GLuint texID = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y);
		matTextures.emplace_back(texID);

	}
	currentFrame = 0;
	frameTime = 0.0f;
	init = true;
	//animation stuff


	shader = new Shader("SceneVertex.glsl", "SceneFragment.glsl");
	if (!shader->LoadSuccess()) {
    return;
		
	}
		 projMatrix = Matrix4::Perspective(1.0f, 10000.0f,
			 (float)width / (float)height, 45.0f);
		 camera->SetPosition(Vector3(0, 30, 175));

		 root = new	SceneNode();
		 root->AddChild(new Aztec(gem));
		 root->AddChild(new Forest(tree));

		 SceneNode* s = new SceneNode();
		 s->SetTexture(texture2);

		 glEnable(GL_DEPTH_TEST);
		  init = true;


	heightMap = new HeightMap(TEXTUREDIR"noise.png");
	//tree = Mesh::LoadFromMeshFile("treeA.msh");
	//treeMat = new MeshMaterial("treeA.mat");

	waterTex = SOIL_load_OGL_texture(
		TEXTUREDIR"water.TGA", SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

	earthTex = SOIL_load_OGL_texture(TEXTUREDIR"Barren Reds.JPG", SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

	// new texture
	grassTex = SOIL_load_OGL_texture(TEXTUREDIR"grasst.JPG", SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);


	// new texture 


	//3rd Texture
	snowTex = SOIL_load_OGL_texture(TEXTUREDIR"snowt.JPG", SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

	//3rd texture

	//4th texture

	//4th texture

	earthBump2 = SOIL_load_OGL_texture(
		TEXTUREDIR"grassbump.png", SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);


	// extra bump point
	earthBump = SOIL_load_OGL_texture(
		TEXTUREDIR"Barren RedsDOT3.jpg", SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	//extra bump point

	//new bump point 
	earthBump3 = SOIL_load_OGL_texture(
		TEXTUREDIR"snowbump.png", SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

	// new bump point 


	//cubeMap = SOIL_load_OGL_cubemap(
	//	TEXTUREDIR"rusted_west.jpg", TEXTUREDIR"rusted_east.jpg",
	//	TEXTUREDIR"rusted_up.jpg", TEXTUREDIR"rusted_down.jpg",
	//	TEXTUREDIR"rusted_south.jpg", TEXTUREDIR"rusted_north.jpg",
	//	SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, 0);
	cubeMap = SOIL_load_OGL_cubemap(
		TEXTUREDIR"rusted_west.JPG", TEXTUREDIR"rusted_east.JPG",
		TEXTUREDIR"rusted_up.JPG", TEXTUREDIR"rusted_down.JPG",
		TEXTUREDIR"rusted_south.JPG", TEXTUREDIR"rusted_north.JPG",
		SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, 0);

	if (!earthTex || !earthBump || !cubeMap || !waterTex) {
		return;

	}
	SetTextureRepeating(earthTex, true);
	SetTextureRepeating(grassTex, true);
	SetTextureRepeating(earthBump, true);
	SetTextureRepeating(earthBump2, true);
	SetTextureRepeating(waterTex, true);
	SetTextureRepeating(snowTex, true);



	Dshader = new Shader("SkinningVertex.glsl", "texturedFragment.glsl");
	reflectShader = new Shader(
		"reflectVertex.glsl", "reflectFragment.glsl");
	skyboxShader = new Shader(
		"skyboxVertex.glsl", "skyboxFragment.glsl");
	lightShader = new Shader(
		"PerPixelVertex.glsl", "PerPixelFragment.glsl");
	

	if (!reflectShader->LoadSuccess() ||
		!skyboxShader->LoadSuccess() ||
		!lightShader->LoadSuccess() || 
		!Dshader->LoadSuccess()){
		return;

	}




	Vector3 heightmapSize = heightMap->GetHeightmapSize();
	//camera start placement 
	camera = new Camera(-45.0f, 0.0f,heightmapSize * Vector3(0.5f, 1.0f, 0.5f));

	//light placment
	light = new Light(heightmapSize * Vector3(0.5f, 2.0f, 0.5f),
		//light intensity
		Vector4(1, 1, 1, 1), heightmapSize.x*1.7);

	projMatrix = Matrix4::Perspective(1.0f, 15000.0f,
		(float)width / (float)height, 45.0f);

	projMatrix = Matrix4::Perspective(1.0f, 10000.0f,
		(float)width / (float)height, 45.0f);

	//root = new	SceneNode();
	//root->AddChild(new Aztec(gem));
	//glEnable(GL_DEPTH_TEST);
	//init = true;
	////root = new SceneNode();
	
	


	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
	waterRotate = 0.0f;
	waterCycle = 0.0f;
	init = true;

}


		   Renderer ::~Renderer(void) {
			    delete camera;
			    delete heightMap;
			    delete quad;
			    delete reflectShader;
			    delete skyboxShader;
			    delete lightShader;
			    delete light;
				delete tree;
				//delete treeMat;
				delete root;
				delete gem;
				delete mesh;
				delete anim;
				delete material;
				glDeleteTextures(1, &earthTex);
				glDeleteTextures(1, &grassTex);
				glDeleteTextures(1, &snowTex);
			   
		   }



		   void Renderer::UpdateScene(float dt) {
			    camera->UpdateCamera(starttime,togcam,dt);
			    viewMatrix = camera->BuildViewMatrix();

				projMatrix = Matrix4::Perspective(1.0f, 10000.0f,
					(float)width / (float)height, 45.0f);

				root->Update(dt);
			    waterRotate += dt * 0.0f; //2 degrees a second
			    waterCycle += dt * 0.01f; //10 units a second
				frameTime -= dt;
				while (frameTime < 0.0f) {
					currentFrame = (currentFrame + 1) % anim->GetFrameCount();
					frameTime += 1.0f / anim->GetFrameRate();

				}

			   
		   }


		   void Renderer::DrawSkybox() {
			    glDepthMask(GL_FALSE);
			   
				    BindShader(skyboxShader);
			    UpdateShaderMatrices();
			   
				    quad->Draw();
			   
				    glDepthMask(GL_TRUE);
			   
		   }

		 

		   void Renderer::drawsoldier() {
			   //glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

			   BindShader(Dshader);
			   glUniform1i(glGetUniformLocation(Dshader->GetProgram(),
				   "diffuseTex"), 0);
			   //float a = longditude->heightmapCentre_x;

			   modelMatrix = Matrix4::Translation(Vector3{2000,150,2400}) * Matrix4::Scale(Vector3{ 50,50,50 }) * Matrix4::Rotation(-90, Vector3{ 0,1,0 });

			   UpdateShaderMatrices();

			   vector <Matrix4 > frameMatrices;

			   const Matrix4* invBindPose = mesh->GetInverseBindPose();
			   const Matrix4* frameData = anim->GetJointData(currentFrame);

			   for (unsigned int i = 0; i < mesh->GetJointCount(); ++i) {
				   frameMatrices.emplace_back(frameData[i] * invBindPose[i]);

			   }

			   int j = glGetUniformLocation(Dshader->GetProgram(), "joints");
			   glUniformMatrix4fv(j, frameMatrices.size(), false,
				   (float*)frameMatrices.data());

			   for (int i = 0; i < mesh->GetSubMeshCount(); ++i) {
				   glActiveTexture(GL_TEXTURE0);
				   glBindTexture(GL_TEXTURE_2D, matTextures[i]);
				   mesh->DrawSubMesh(i);

			   }
		   }


		   void Renderer::RenderScene() {
			    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
			    DrawSkybox();
			    DrawHeightmap();
			    DrawWater();
				BindShader(shader);
				UpdateShaderMatrices();
				DrawNode(root);
				//BindShader(shader);
				//UpdateShaderMatrices();
				drawsoldier();
		   }


		   void Renderer::DrawHeightmap() {
			    BindShader(lightShader);
			    SetShaderLight(*light);
			    glUniform3fv(glGetUniformLocation(lightShader->GetProgram(),
				    "cameraPos"), 1, (float*)&camera->GetPosition());
			   
				    glUniform1i(glGetUniformLocation(
					    lightShader->GetProgram(), "diffuseTex"), 0);
			    glActiveTexture(GL_TEXTURE0);
			    glBindTexture(GL_TEXTURE_2D, earthTex);
			   
				    glUniform1i(glGetUniformLocation(
					    lightShader->GetProgram(), "bumpTex"), 1);
			    glActiveTexture(GL_TEXTURE1);
			    glBindTexture(GL_TEXTURE_2D, earthBump);
			   
				glUniform1i(glGetUniformLocation(
					lightShader->GetProgram(), "diffuseTex2"), 2);
				glActiveTexture(GL_TEXTURE2);
				glBindTexture(GL_TEXTURE_2D, grassTex);


				glUniform1i(glGetUniformLocation(
					lightShader->GetProgram(), "bumpTex2"), 3);
				glActiveTexture(GL_TEXTURE3);
				glBindTexture(GL_TEXTURE_2D, earthBump2);

				glUniform1i(glGetUniformLocation(
					lightShader->GetProgram(), "diffuseTex3"), 4);
				glActiveTexture(GL_TEXTURE4);
				glBindTexture(GL_TEXTURE_2D, snowTex);

				    modelMatrix.ToIdentity(); //New!
			    textureMatrix.ToIdentity(); //New!
			   
				    UpdateShaderMatrices();
			   
				    heightMap->Draw();
		   }


		   void Renderer::DrawWater() {
			    BindShader(reflectShader);
			   
				    glUniform3fv(glGetUniformLocation(reflectShader->GetProgram(),
					    "cameraPos"), 1, (float*)&camera->GetPosition());
			   
				    glUniform1i(glGetUniformLocation(
					    reflectShader->GetProgram(), "diffuseTex"), 0);
			    glUniform1i(glGetUniformLocation(
				    reflectShader->GetProgram(), "cubeTex"), 2);
			   
				    glActiveTexture(GL_TEXTURE0);
			    glBindTexture(GL_TEXTURE_2D, waterTex);
			   
				    glActiveTexture(GL_TEXTURE2);
			    glBindTexture(GL_TEXTURE_CUBE_MAP, cubeMap);



				Vector3 hSize = heightMap->GetHeightmapSize();
				
					 modelMatrix =
					 Matrix4::Translation(hSize * 0.4f) *
					 Matrix4::Scale(hSize * 0.3f) *
					 Matrix4::Rotation(90, Vector3(1, 0, 0));
				
					 textureMatrix =
					 Matrix4::Translation(Vector3(waterCycle, 0.0f, waterCycle)) *
					 Matrix4::Scale(Vector3(10, 10, 10)) *
					 Matrix4::Rotation(waterRotate, Vector3(0, 0, 1));
				
					 UpdateShaderMatrices();
				 // SetShaderLight (* light); //No lighting in this shader!
					 quad->Draw();
				
		   }



		   void Renderer::DrawNode(SceneNode* n) {
			    if (n->GetMesh()) {
				    Matrix4 model = n->GetWorldTransform() *
					    Matrix4::Scale(n->GetModelScale());
				    glUniformMatrix4fv(
					    glGetUniformLocation(shader->GetProgram(),
						    "modelMatrix"), 1, false, model.values);
				   
					    glUniform4fv(glGetUniformLocation(shader->GetProgram(),
						    "nodeColour"), 1, (float*)&n->GetColour());
				   
					    glUniform1i(glGetUniformLocation(shader->GetProgram(),
						    "useTexture"), 1); //Next tutorial ;)
						    n->Draw(*this);
						   
			   }
			   
				    for (vector <SceneNode*>::const_iterator
					    i = n->GetChildIteratorStart();
					    i != n->GetChildIteratorEnd(); ++i) {
				    DrawNode(*i);
				   
			   }
			   
		   }