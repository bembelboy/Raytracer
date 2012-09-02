#ifndef RENDERER_CLASS_HPP
#define RENDERER_CLASS_HPP

#include "scene.hpp"
#include "ppmwriter.hpp"

class glutwindow;

class renderer {
    public:
        // c'tors
        renderer(scene const& sc);
        ~renderer();
        
        void render_scene();

    private:
        scene sc_;
        glutwindow& window_;
        ppmwriter image_;
};

#endif // RENDERER_CLASS_HPP

