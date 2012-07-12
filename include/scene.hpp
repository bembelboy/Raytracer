#ifndef SCENE_STRUCT_HPP
#define SCENE_STRUCT_HPP
#include <map>
#include "material.hpp"

struct scene {
    //constructors & destructors
    scene();
    ~scene();

    //member
    std::map<std::string,material> material_map;

    //methods
    void print_on(std::ostream& out) const;

};
std::ostream& operator<< (std::ostream& out, scene const& scn);
#endif //SCENE_STRUCT_HPP
