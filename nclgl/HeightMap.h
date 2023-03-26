#pragma once
 #include <string>
 #include "Mesh.h"

 class HeightMap : public Mesh {
 public:
	 float heightmapCentre_x;
	 float heightmapCentre_y;
	 float heightmapCentre_z;
	 HeightMap(const std::string & name);
	 ~HeightMap(void) {};
	
		 Vector3 GetHeightmapSize() const { return heightmapSize; }
 protected:
	 Vector3 heightmapSize;
};

