#include "../include/sdf_loader.hpp"
#include "../include/material.hpp"
#include "../include/scene.hpp"

#include <sstream>
#include <fstream>
#include <iostream>
#include <list>


sdf_loader::sdf_loader(std::string file)
    :sdf_(file) {}

sdf_loader::~sdf_loader() {}

void sdf_loader::load_sdf_file() {
    std::ifstream sdf_file(sdf_.c_str(), std::ios::in);

    if(sdf_file.is_open()) {

        while(!sdf_file.eof()) {
            std::string sdf_line;
            std::getline(sdf_file, sdf_line);   //get string line from sdf_file
            std::stringstream ss;
            ss << sdf_line;     //stream sdf_line in stringstream for reading evry word of line

            std::string keyword;
            ss >> keyword;
            if(keyword == "define") {
                std::string mode;
                ss >> mode;
                material m1;
                if(mode == "material") {
                    std::string name;
                    float r;
                    float g;
                    float b;
                    ss >> name >> r >> g >> b;
                    color ka(r, g, b);

                    float r1;
                    float g1;
                    float b1;
                    ss >> r1 >> g1 >> b1;
                    color kd(r1, g1, b1);

                    float r2;
                    float g2;
                    float b2;
                    float m;
                    ss >> r2 >> g2 >> b2 >> m;
                    color ks(r2, g2, b2);
                    material m1(name, ka, kd, ks, m);
                    scene_.material_map.insert(std::pair<std::string, material>(name, m1));
                    //scene_:material_mape["material1"] = material(name, ka, kd, ks, m);
                }
            }

        }
        sdf_file.close();
    }
}

void sdf_loader::print_on(std::ostream& out) const {
    out << scene_;
}

std::ostream& operator<<(std::ostream& out, sdf_loader const& obj) {
    obj.print_on(out);
    return out;
}
