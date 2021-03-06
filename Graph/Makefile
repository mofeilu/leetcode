# vim:comments=
#
# I don't like the Cuda SDK makefiles. Here's my own! This makefile should
# allow you to build Cuda programs independent of the NVidia Cuda SDK. Its
# simplicity makes it easy for you to put objects, binaries, etc where you want
# them. There is even some boiler-plate Makefile magic that you can copy
# into other Makefiles.
#
# Mark Murphy 2008

# Fill in the name of the output binary here
target    := test
#test
#matrix
#solver 
#gmres

# shared lib
shared_lib := graph
# you should have testCG.cu or testCG.cpp file
main := testGraph

# List of sources, with .c, .cu, and .cc extensions
#sources	  := Utils.cpp DotPvec.cpp  HostVecPageLocked.cpp  LinOpPvec.cpp  OpPvec.cpp Partition2D.cpp  Partition3D.cpp \
#Pvec.cpp  Stencil2D.cpp Stencil3D.cpp  Poisson3D.cpp Poisson3DNug.cpp SparseSolver.cpp MemOp.cpp\
#MatStruct.cpp MeshStruct.cpp KernelWrapper.cu KernelPoisson.cu  KernelPoissonNug.cu#testCG.cu #testMat.cu #testPoisson.cu #testCG.cu #testPoisson.cu

topdir := .
#topdir := /workspace/yanglu/tmpprac/tmp1
sources := $(shell find $(topdir) -name "*.cpp" ! -path "$(topdir)/$(main).cpp")


all: $(target)

extradeps := 

LIB_TOP := #/user/libsync/RHEL7/polaris/POP/libs


# Flags common to all compilers. You can set these on the comamnd line, e.g:
# $ make opt="" dbg="-g" warn="-Wno-deptrcated-declarations -Wall -Werror"

opt  ?= -O3
dbg  ?= 
warn ?= -Wall #-Werror


# This is where the cuda runtime libraries and SDK resides
# Nuo: checked
cudaroot  := /usr/local/cuda-8.0
#cudaSDKroot := /home/eeres/kzhai/NVIDIA_GPU_Computing_SDK/C
cudaSDKroot := /usr/local/cuda-8.0/samples

#----- C compilation options ------
# Nuo: checked
gcc        := /user/libsync/RHEL6/compiler/gcc-4.9.4/bin/gcc
cflags     += $(opt) $(dbg) $(warn) -std=c++11 -fPIC
clib_paths :=
cinc_paths := 
clibraries := 

#----- C++ compilation options ------
# Nuo: checked
#gpp         := /appl/open_tools/gcc/4.8.1/bin/g++
gpp         := /user/libsync/RHEL6/compiler/gcc-4.9.4/bin/g++
ccflags     += $(opt) $(dbg) $(warn) -std=c++11 -fPIC
cclib_paths := 
ccinc_paths := 
#-I$(cudaroot)/include  -I$(cudaSDKroot)/common/inc
cclibraries := #-Wl,-rpath,$(LIB_TOP)/json/lib64 -L$(LIB_TOP)/json/lib64 -ljsoncpp


lib_paths   := $(cclib_paths) $(clib_paths)
libraries   := $(cclibraries) $(clibraries)


#----- Generate source file and object file lists
# This code separates the source files by filename extension into C, C++,
# and Cuda files.
csources  := $(filter %.c,  $(sources))
ccsources := $(filter %.cc, $(sources)) \
	     $(filter %.cpp,$(sources))

# This code generates a list of object files by replacing filename extensions
objects := $(patsubst %.c,  %.o,$(csources))  \
	   $(patsubst %.cpp,%.o,$(filter %.cpp,$(ccsources))) \
	   $(patsubst %.cc, %.o,$(filter %.cc, $(ccsources)))


#----- Build rules ------

#$(target): $(extradeps) 


# this is static linking
#$(target): $(objects)
#	$(gpp) $(objects) $(lib_paths) $(libraries) -o $@ 

$(target): lib$(shared_lib).so  $(main).o
	@echo "generating binary...$(target)"
	$(gpp) $(main).o -o $(target) -Bdynamic $(lib_paths) $(libraries) -Wl,-rpath,. -L. -l$(shared_lib)

#$(target): testCG.o
#	$(gpp) testCG.o -o test -Bdynamic -L. -l$(shared_lib)


# we first build the lib
lib$(shared_lib).so : $(objects)
	@echo "showing all objs: " $(objects)
	@echo "linking shared lib $(shared_lib)..."
	$(gpp) -shared $(objects) $(lib_paths) $(libraries) -o $@
	@echo "shared lib generated." 	

#%.o: %.cc %.cpp
#	$(gpp) -c $^ $(ccflags) $(ccinc_paths) -o $@

#%.o: %.c
#	$(gcc) -c $^ $(cflags) $(cinc_paths) -o $@

%.o: %.cpp
	$(gpp) -c $^ $(ccflags) $(ccinc_paths) -o $@	


clean:
	rm -f *.o *.so $(target) makefile.*dep 


#----- Dependency Generation -----
#
# If a particular set of sources is non-empty, then have rules for
# generating the necessary dep files.
#

ccdep := ccdep.mk
cdep  := cdep.mk


depfiles =

ifneq ($(ccsources),)

depfiles += $(ccdep)
$(ccdep): $(ccsources)
	$(gpp) -MM $(ccsources) > $(ccdep)

else

$(ccdep):

endif


ifneq ($(csources),)

depfiles += $(cdep)
$(cdep): $(csources)
	$(gcc) -MM -x c $(csources) > $(cdep)

else

$(cdep):

endif

.PHONY: dep
dep: $(depfiles)


