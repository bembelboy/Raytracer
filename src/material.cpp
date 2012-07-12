#include "../include/material.hpp"
#include <iostream>

material::material()
    :name_("default"),
    ka_(0, 0, 0), kd_(0, 0, 0), ks_(0, 0, 0),
    m_(0.0) {}

material::material(material const& ma)
    :name_(ma.name_),
    ka_(ma.ka_), kd_(ma.kd_), ks_(ma.ks_),
    m_(ma.m_) {}

material::material(std::string const& name,
            color const& ka, color const& kd, color const& ks, float m)
    :name_(name),
    ka_(ka), kd_(kd), ks_(ks),
    m_(m) {}

material::~material() {}

std::string const& material::name() const {
    return name_;
}

color const& material::ka() const {
    return ka_;
}

color const& material::kd() const {
    return kd_;
}

color const& material::ks() const {
    return ks_;
}

float material::m() const {
    return m_;
}

std::ostream& operator <<(std::ostream& out, material const& mat) {
    mat.print_on(out);
    return out;
}

void material::print_on(std::ostream& out) const {
    out << "name: " << name_ << std::endl 
        << "ka: " 
        << static_cast<unsigned>(ka_[0]) << ","
        << static_cast<unsigned>(ka_[2]) << ","
        << static_cast<unsigned>(ka_[3]) << std::endl
        << "kd: "
        << static_cast<unsigned>(kd_[0]) << ","
        << static_cast<unsigned>(kd_[2]) << ","
        << static_cast<unsigned>(kd_[3]) << std::endl
        << "ks: "
        << static_cast<unsigned>(ks_[0]) << ","
        << static_cast<unsigned>(ks_[2]) << ","
        << static_cast<unsigned>(ks_[3]) << std::endl
        << "m: " << m_ << std::endl;
}
