#ifndef MATERIAL_CLASS_HPP
#define MATERIAL_CLASS_HPP

#include <string>
#include "color.hpp"

class material {
    public:
        //c'tors
        material();
        material(material const& ma);
        material(std::string const& name,
                color const& ka, color const& kd, color const& ks, float m);
        ~material();

        //Getter & Methods
        std::string const& name() const;
        color const& ka() const;
        color const& kd() const;
        color const& ks() const;
        float m() const;
        void print_on(std::ostream& out) const;

    private:
        std::string name_;
        color ka_;
        color kd_;
        color ks_;
        float m_;
}; 

std::ostream& operator <<(std::ostream& out, material const& mat);

#endif //MATERIAL_CLASS_HPP
