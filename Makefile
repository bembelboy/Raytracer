# -*- Makefile -*-

# $Id: Makefile,v 1.1 2008-04-10 09:49:21 guni4317 Exp $

default: targets

UNAME := $(shell uname -s)

prefix =.

include $(prefix)/defines.mk

CXXINCLUDE	+=-I$(prefix)/include -I/opt/local/include
ifeq ($(UNAME), Darwin)
LIBS		+=-framework OpenGL -framework GLUT -lboost_thread-mt

else
LIBS		+=-lglut -lGL -lboost_thread
endif

EXTRA_LIBS	+=-L$(prefix)/ -Wl,-rpath,. -L/opt/local/lib
MOVE		=mv

HEADER =\
	include/glutwindow.hpp \
	include/pixel.hpp \
	include/ppmwriter.hpp \
	include/color.hpp \
	include/vector.hpp \
	include/point.hpp \
	include/light.hpp \
	include/camera.hpp \
	include/matrix.hpp \
	include/sdf_loader.hpp \
	include/shape.hpp \
	include/sphere.hpp \
	include/material.hpp \
	include/scene.hpp \
	include/box.hpp \
	include/hitpoint.hpp \
	include/ray.hpp \
	include/renderer.hpp \
        $(NULL)

SOURCE =\
	src/glutwindow.cpp \
	src/pixel.cpp \
	src/ppmwriter.cpp \
	src/color.cpp \
	src/point.cpp \
	src/light.cpp \
	src/camera.cpp \
	src/vector.cpp \
	src/matrix.cpp \
	src/sdf_loader.cpp \
	src/shape.cpp \
	src/sphere.cpp \
	src/material.cpp \
	src/scene.cpp \
	src/box.cpp \
	src/hitpoint.cpp \
	src/ray.cpp \
	src/renderer.cpp \
	$(NULL)

PROGRAMSOURCE =\
	src/main.cpp \
	$(NULL)

OBJECTS =$(SOURCE:.cpp=.o) 

PROGRAMOBJECT =$(PROGRAMSOURCE:.cpp=.o)

PROGRAMS = 	$(PROGRAMOBJECT:.o=)

targets:	$(PROGRAMS)

$(PROGRAMS):	$(OBJECTS) $(PROGRAMOBJECT)
	-$(RM) $@
	$(CXX) -o $(prefix)/$@ $(EXTRA_LIBS) $(LDXXFLAGS) $(OBJECTS) $(LIBS) $(PROGRAMOBJECT) 
	$(MOVE) $(prefix)/$@ .

realclean:: clean
	-$(RM) $(prefix)/$(OBJECTS)
	-$(RM) $(prefix)/$(PROGRAMOBJECT)
	-$(RM) ./main

include $(prefix)/rules.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),realclean)
#-include $(OBJECTS:.o=.d)
endif
endif

# $Id: Makefile,v 1.1 2008-04-10 09:49:21 guni4317 Exp $
