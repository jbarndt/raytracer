#include <iostream>
#include <cmath>
#include "ray.h"

vec3 color(const ray& r){
	vec3 unit_direction = 10.83*unit_vector(r.direction());
	float sin_xy_squared = sin((unit_direction.x()*unit_direction.x()*unit_direction.y()*unit_direction.y()));
	float t = 0.5*(1+ sin_xy_squared);
	return t*vec3(1.0,1.0,1.0);
}

int main() {
    int nx = 512;
    int ny = 512;
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	vec3 lower_left_corner(-2.0,-1.0,-1.0);
	vec3 horizontal(4.0,0.0,0.0);
	vec3 vertical(0.0,2.0,0.0);
	vec3 origin(0.0,0.0,0.0);

    for (int j = ny-1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
			float u = float(i)/float(nx);
			float v = float(j)/float(ny);
			ray r(origin, lower_left_corner + u*horizontal + v*vertical);
            vec3 col = color(r);

            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}
