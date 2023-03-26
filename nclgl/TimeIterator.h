#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

class Itime {
public: 
	float clamp(float a) {
		while (a > 10) {
			a -= 10;
		}
		return a;
	}

	float timeiterator(float start_time){
		srand(start_time);
		float randreturn;
		float alc = time(0)%10;
		float r = rand();
		randreturn = clamp(r + alc);
		cout << randreturn << endl;
		return randreturn;
	}


protected:
	


};
