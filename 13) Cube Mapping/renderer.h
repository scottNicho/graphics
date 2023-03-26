#include "../nclgl/OGLRenderer.h"
#include "../nclgl/SceneNode.h"
#include "aztec.h"
#include "forest.h"

 class Camera;
 class Shader;
 class HeightMap;
 class MeshMaterial;
 class Mesh;
 class MeshAnimation;

 class Renderer : public OGLRenderer {
 public:
	 Renderer(Window & parent);
	 ~Renderer(void);
	 void RenderScene() override;
	 void UpdateScene(float dt) override;
	 int togcam;
	 int starttime;
 protected:
	 void DrawNode(SceneNode* n);
	 void DrawHeightmap();
	 void DrawWater();
	 void DrawSkybox();
	 void drawsoldier();
	
	Shader * lightShader;
	 Shader * reflectShader;
	 Shader * skyboxShader;
	
	HeightMap * heightMap;
	HeightMap* longditude;
	 Mesh* quad;

	 Mesh* tree;
	 MeshMaterial* treeMat;
	 vector <GLuint> treeTextures;

	 SceneNode* root;
	Light * light;
	 Camera * camera;
	 Mesh* gem;
	 Shader* shader;
	 Shader* Dshader;
	 Mesh* mesh;
	 MeshAnimation* anim;
	 MeshMaterial* material;
	 

	 vector<GLuint> matTextures;
	 GLuint cubeMap;
	 GLuint waterTex;
	 GLuint earthTex;
	 GLuint earthBump;
	 GLuint earthBump2;
	 GLuint earthBump3;
	 GLuint grassTex;
	 GLuint snowTex;
	 GLuint texture2;
	
		 float waterRotate;
	 float waterCycle;
	 int currentFrame;
	 float frameTime;

};
