#ifndef SCENE_STRUCT_HPP
#define SCENE_STRUCT_HPP

#include <map>
#include <string>

class material;
class Light;
class camera;
class shape;

struct scene {
    //c'tors
    scene();
    ~scene();

    //member
    std::map<std::string,material*> material_map;
    std::map<std::string,shape*> shape_map;
    std::map<std::string,Light*> light_map;
    
    camera* cam_ptr;
    std::string filename_;
    std::size_t xRes_;
    std::size_t yRes_;
    
    //methods
    void print_on(std::ostream& out) const;
};

std::ostream& operator<< (std::ostream& out, scene const& scn);

#endif //SCENE_STRUCT_HPP
