#include "../include/hitpoint.hpp"

hitpoint::hitpoint()
    :hitpoint_(),
    normal_(),
    view_(),
    t_(),
    material_ptr_(NULL)
{}

hitpoint::hitpoint(hitpoint const& hp)
    :hitpoint_(hp.hitpoint_),
    normal_(hp.normal_),
    view_(hp.view_),
    t_(hp.t_),
    material_ptr_(hp.material_ptr_)
{}

hitpoint::~hitpoint()
{}

bool
hitpoint::operator<(hitpoint const& hp) {
    return t_ < hp.t_;
}
