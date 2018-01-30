// Always include the original .hpp that corresponds to the .cpp
#include "point_in_polygon.hpp"

// Here is the original C version from Stack Overflow.
// 
// Adapt it to use Person objects and a Person array
// instead of just pure x/y coordinates.
//
// Make the function match the types in the function
// declaration in "point_in_polygon.hpp"
//
// Remember -- the algorithm already essentially works!
//
// You just need to have it use our C++ object type now!
//
bool pnpoly(
       /* int nvert, = num_points
        float *vertx, = points[i]get_location().get_x()
        float *verty, 
        float testx, = testget_location().get_x
        float testy) */
		std::size_t num_points,
		Person* points,
		Person test)

		{
    int i, j, c = 0;
    for (i = 0, j = num_points-1; i < num_points; j = i++) {
        if (((points[i].get_location().get_y()>test.get_location().get_y()) != 
			(points[j].get_location().get_y()>test.get_location().get_y())) && 
				(test.get_location().get_x() < (points[j].get_location().get_x()-points[i].get_location().get_x()) * 
					(test.get_location().get_y()-points[i].get_location().get_y()) / 
						(points[j].get_location().get_y()-points[i].get_location().get_y()) + 
							points[i].get_location().get_x())) {
            c = !c;
        }
    }
    return c;
}
