# -*- Mode:Makefile -*-

CXX		=g++-4.7

# on MACOS 64 Bit
#CXXFLAGS	=-g -O1 -fPIC -W -Wall -m64
CXXFLAGS	=-g -O1 -fPIC -W -Wall -std=c++11 -m64

CXXINCLUDE	=-I.
CXXDEFINES	=
LDXXFLAGS	=$(CXXFLAGS) -L. -fPIC -Wl,-rpath,.
RM		=rm -f
