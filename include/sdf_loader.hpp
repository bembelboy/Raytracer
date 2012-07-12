#ifndef SDF_LOADER_CLASS_HPP
#define SDF_LOADER_CLASS_HPP
#include <string>
#include "material.hpp"
#include "scene.hpp"

class sdf_loader {
    public:
        //Constructors and Destrcutors
        sdf_loader(std::string file);
        ~sdf_loader();

        //Methods
        void load_sdf_file();
        void print_on(std::ostream& out) const;

    private:
        std::string sdf_;
        scene scene_;

};
std::ostream& operator<<(std::ostream& out, sdf_loader const& obj);
#endif //SDF_LOADER_CLASS_HPP
