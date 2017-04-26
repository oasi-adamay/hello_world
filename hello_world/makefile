#
# Makefile
#
BINDIR := ./bin
LIBDIR := ./lib
OBJDIR := ./obj
INCDIR := ./include


CXX := clang
LINK := llvm-link
ifeq ($(OS),Windows_NT)
AR := llvm-ar
endif
ARFLAGS := rv

SRCS = $(wildcard *.cpp)
OBJS += $(patsubst %.cpp, %.o ,$(filter %.cpp,$(notdir $(SRCS))))
OBJS += $(patsubst %.c, %.o ,$(filter %.c,$(notdir $(SRCS))))
DEPENDS = $(OBJS:.o=.d)

CXXFLAGS = --std=c++14
CXXFLAGS += -D"_CRT_SECURE_NO_WARNINGS"
CXXFLAGS += -I$(INCDIR)
#CXXFLAGS += -g -O0 
CXXFLAGS += -O3 
#CXXFLAGS += -Wall
#CXXFLAGS = -v


ifeq ($(OS),Windows_NT)
LINKFLAGS =
TARGET = $(BINDIR)/hello.exe
LIBEXT := lib
else
LINKFLAGS = -lstdc++
LINKFLAGS += -lpthread
TARGET = $(BINDIR)/hello
LIBEXT := a
endif



all: build 

.PHONY: build
build:	check $(TARGET)


.PHONY: run
run:	build
	$(TARGET)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(LIBS) $(DEPENDS)

.PHONY: check 
check:
ifeq ($(OS),Windows_NT)
#	@[ -d $(LIBDIR) ] || mkdir $(subst /,\,$(LIBDIR))
	@[ -d $(BINDIR) ] || mkdir $(subst /,\,$(BINDIR))
#	@[ -d $(OBJDIR) ] || mkdir $(subst /,\,$(OBJDIR))
else
#	@[ -d $(LIBDIR) ] || mkdir -p $(LIBDIR)
	@[ -d $(BINDIR) ] || mkdir -p $(BINDIR)
#	@[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
endif


$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $< 

$(LIBS): $(OBJS) 
	$(AR) $(ARFLAGS) $@ $(OBJS)

%.bc: %.cpp
	$(CXX) $(CXXFLAGS) -emit-llvm -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS)  $< -MQ $@ -MM > $(@:.o=.d)	
	$(CXX) $(CXXFLAGS) -c $< -o $@


-include $(DEPENDS)


