#include "Camera.h"
 #include "Window.h"
 #include <algorithm >
#include "Light.h"
#include<iostream>
using namespace std;




//
//void fixedCameraTrack(int& a) {
//	while (true) {
//		if (Window::GetKeyboard()->KeyDown(KEYBOARD_7)) {
//			a = 1;
//			return;
//		}
//
//		return;
//	}
//	return;
//}




void Camera::UpdateCamera(int&stime,int &togglecamera,float dt) {
	if (togglecamera != 1) {
		Matrix4 rotation = Matrix4::Rotation(yaw, Vector3(0, 1, 0));

		Vector3 forward = rotation * Vector3(0, 0, -1);
		Vector3 right = rotation * Vector3(1, 0, 0);

		float speed = 300.0f * dt;
			if (Window::GetKeyboard()->KeyDown(KEYBOARD_7)) {
				togglecamera = 1;
				return;
				

			}
			if (stime != 2) {
				timekeeper = 0;
				stime = 2;
			}

			timekeeper += dt;

			//pitch and yawwwwww
			/*yaw += 0.0f;
			pitch += 0.0f;*/

			pitch = std::min(pitch, 90.0f);
			pitch = std::max(pitch, -90.0f);

			if (yaw < 0) {
				yaw += 360.0f;

			}
			if (yaw > 360.0f) {
				yaw -= 360.0f;

			}

			//linear movement
			if (timekeeper < 20.0f) {
				position += (forward * 0.5);
				yaw += 0.3;
				return;
			}
            if (timekeeper >= 20.0f && timekeeper < 25.0f) {
				position += (forward * 0.2);
				pitch += 0.1f;
				return;
			}
			if (timekeeper >= 25.0f && timekeeper < 30.0f) {
				position += (forward * 0.3);
				return;
			}
			if (timekeeper >= 30.0f && timekeeper < 35.0f) {
				position += (right * 0.2);
				yaw += 0.2f;
				return;
			}
			if (timekeeper >= 35.0f && timekeeper < 40.0f) {
				position += (forward * 0.2);
				return;
			}
			if (timekeeper >= 35.0f && timekeeper < 40.0f) {
				position += (forward * 0.2);
				return;
			}
			if (timekeeper >= 40.0f && timekeeper < 50.0f) {
				position.y += 0.1f;
				yaw += 0.07f;
				pitch -= 0.04f;
				return;
			}
			if (timekeeper >= 50.0f && timekeeper < 55.0f) {
				
				yaw += 0.1f;
				
				return;
			}
			if (timekeeper >= 55.0f && timekeeper < 60.0f) {
				pitch += 0.1f;
				yaw -= 0.5f;

				return;
			}
			if (timekeeper >= 60.0f && timekeeper < 70.0f) {
				position.y -= 0.1f;
				yaw += 0.07f;
				pitch += 0.04f;

				return;
			}

			if (timekeeper >= 70.0f && timekeeper < 80.0f) {
				position -= (forward * 0.3);

				return;

				if (timekeeper >= 80.0f) {
					timekeeper = 0;
					return;
			     }
			}

	
		return;
	}
	 pitch -= (Window::GetMouse()->GetRelativePosition().y);
	 yaw -= (Window::GetMouse()->GetRelativePosition().x);
	
		 pitch = std::min(pitch, 90.0f);
	 pitch = std::max(pitch, -90.0f);
	
		 if (yaw < 0) {
		 yaw += 360.0f;
		
	}
	 if (yaw > 360.0f) {
		 yaw -= 360.0f;
		
	}

	 Matrix4 rotation = Matrix4::Rotation(yaw, Vector3(0, 1, 0));
	 
		  Vector3 forward = rotation * Vector3(0, 0, -1);
	  Vector3 right = rotation * Vector3(1, 0, 0);
	 
		  float speed = 300.0f * dt;



		  if (Window::GetKeyboard()->KeyDown(KEYBOARD_W)) {
			   position += forward * speed;
			  
		  }
		   if (Window::GetKeyboard()->KeyDown(KEYBOARD_S)) {
			   position -= forward * speed;
			  
		  }
		   if (Window::GetKeyboard()->KeyDown(KEYBOARD_A)) {
			   position -= right * speed;
			  
		  }
		   if (Window::GetKeyboard()->KeyDown(KEYBOARD_D)) {
			   position += right * speed;
			  
		  }



		   if (Window::GetKeyboard()->KeyDown(KEYBOARD_SHIFT)) {
			    position.y += speed;
			   
		   }
		    if (Window::GetKeyboard()->KeyDown(KEYBOARD_SPACE)) {
			    position.y -= speed;
			   
		   }
		   
     }



Matrix4 Camera::BuildViewMatrix() {
	 return Matrix4::Rotation(-pitch, Vector3(1, 0, 0)) *
		 Matrix4::Rotation(-yaw, Vector3(0, 1, 0)) *
		 Matrix4::Translation(-position);
	
};



void OGLRenderer::SetShaderLight(const Light& l) {
	 glUniform3fv(glGetUniformLocation(currentShader->GetProgram(),
		 "lightPos"), 1, (float*)&l.GetPosition());
	
		 glUniform4fv(glGetUniformLocation(currentShader->GetProgram(),
			 "lightColour"), 1, (float*)&l.GetColour());
	
		 glUniform1f(glGetUniformLocation(currentShader->GetProgram(),
			 "lightRadius"), l.GetRadius());
	
}



