#include "../include/shape.hpp"
#include "../include/color.hpp"
#include <string>
#include <iostream>

shape::shape()
    : name_("default")
{}

shape::shape(std::string const& name, material* mat_ptr)
    :name_(name), 
    material_ptr_(mat_ptr) 
{}

shape::~shape() 
{
    //std::cout << "shape Destructor" << std::endl;
}

std::ostream& 
operator<<(std::ostream& os, shape const& s) 
{
    s.print_on(os);
    return os;
}

void shape::print_on(std::ostream& os) const 
{
    os << "Name: " <<  name_ << std::endl
        << "Material: " <<  *(material_ptr_) ;
}

