#include "../include/scene.hpp"

scene::scene() 
    :material_map() {}

scene::~scene() {}


void scene::print_on(std::ostream& out) const {
    for(auto i : material_map) {
        out << i.second;
    }
}

std::ostream& operator<<(std::ostream& out, scene const& scn) {
    scn.print_on(out);
    return out;
}
