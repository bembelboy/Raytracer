#ifndef SDF_LOADER_CLASS_HPP
#define SDF_LOADER_CLASS_HPP

#include <string>
#include "scene.hpp"

class sdf_loader {
    public:
        //c'tors 
        sdf_loader(std::string file);
        ~sdf_loader();

        //Methods
        void load_sdf_file();
        scene const& get_scene() const;
        void print_on(std::ostream& os) const;

    private:
        std::string filename_;
        scene scene_;

};

std::ostream& operator<<(std::ostream& os, sdf_loader const& obj);

#endif //SDF_LOADER_CLASS_HPP
