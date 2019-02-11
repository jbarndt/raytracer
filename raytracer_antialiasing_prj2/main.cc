#include <iostream>
#include <cmath>
#include "ray.h"
#include "camera.h"
#include "float.h"

vec3 color(const ray& r){
	vec3 unit_direction = 20*unit_vector(r.direction());
	float sin_xy_squared = sin((unit_direction.x()*unit_direction.x()*unit_direction.y()*unit_direction.y()));
	float t = 0.5*(1+ sin_xy_squared);
	return t*vec3(1.0,1.0,1.0);
}

int main() {
    int nx = 512;
    int ny = 512;
	int ns = 100;
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	camera cam;

    for (int j = ny-1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
			vec3 col(0,0,0);
			for (int s = 0; s < ns; s++) {
				float random1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				float random2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				float u = float(i + random1)/float(nx);
				float v = float(j + random2)/float(ny);
				ray r = cam.get_ray(u,v);
				col += color(r);
			}
			col /= float(ns);

            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}
