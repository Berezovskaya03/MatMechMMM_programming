#include <iostream> 
#include <cmath>
 using namespace std;
namespace d0{

 struct point0{
	const int p=0;
};

struct vector0{
	const int v=0;
};

    namespace d1
    {
	struct point1{
		double p;
	};
	struct vector1{
		double v;
	};

	double length_vect(vector1 vect){
		double k;
		k=abs(vect.v);
		return k;
	}

	double sum_vect(vector1 vect1, vector1 vect2 ){
		return (vect1.v+vect2.v);
	}

	double multi_numb(double k, vector1 vect){
		return (k*vect.v);
	}
		namespace d2
	    {
		struct point2{
			double x;
			double y;
		};
		struct vector2{
			double x;
			double y;
		};

		double length_vect(vector2 vect){
			double k;
			k=sqrt(vect.x*vect.x+vect.y*vect.y);
			return k;
		}

		vector2 sum_vect(vector2 vect1, vector2 vect2 ){
			vector2 k;
			k.x=vect1.x+vect2.x;
			k.y=vect1.y+vect2.y;
			return k;
		}

		vector2 multi_numb(double k, vector2 vect){
		vect.x*=k;
		vect.y*=k;	
		}

			namespace d3
	    {
		struct point3{
			double x;
			double y;
			double z;
		};
		struct vector3{
			double x;
			double y;
			double z;
		};

		double length_vect(vector3 vect){
			double k;
			k=sqrt(vect.x*vect.x+vect.y*vect.y+vect.z*vect.z);
			return k;
		}

		vector3 sum_vect(vector3 vect1, vector3 vect2 ){
			vector3 k;
			k.x=vect1.x+vect2.x;
			k.y=vect1.y+vect2.y;
			k.z=vect1.z+vect2.z;
			return k;
		}

		vector3 multi_numb(double k, vector3 vect){
		vect.x*=k;
		vect.y*=k;	
		vect.z*=k;
		}
		
		namespace d4
	    {
		struct point4{
			double x;
			double y;
			double z;
			double t;
		};
		struct vector4{
			double x;
			double y;
			double z;
			double t;
		};

		double length_vect(vector4 vect){
			double k;
			k=sqrt(vect.x*vect.x+vect.y*vect.y+vect.z*vect.z+vect.t*vect.t);
			return k;
		}

		vector4 sum_vect(vector4 vect1, vector4 vect2 ){
			vector4 k;
			k.x=vect1.x+vect2.x;
			k.y=vect1.y+vect2.y;
			k.z=vect1.z+vect2.z;
			k.t=vect1.t+vect2.t;
			return k;
		}

		vector4 multi_numb(double k, vector4 vect){
		vect.x*=k;
		vect.y*=k;	
		vect.z*=k;
		vect.t*=k;
		}
			
	    }
	    }
	    }
    }
}
int main() 
{ 
d0::d1::vector1 s;
s.v=9;
cout << multi_numb(9, s);

return 0;
}
