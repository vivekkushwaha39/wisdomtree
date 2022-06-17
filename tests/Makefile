TARGET:= output/test.exe

ALL_MODULE_DIR := $(shell find  ../source -maxdepth 1 -type d)

INC_DIRS := $(patsubst %, -I%/include, $(ALL_MODULE_DIR) )
INC_DIRS += -I./include

LIB_DIRS := $(patsubst %, -L%/output, $(ALL_MODULE_DIR) )
#LIB_DIRS += -L/mingw64/lib

SRCS := $(shell find ./ -name "*.cpp" -type f)
OBJS := $(patsubst %.cpp, objs/%.o, $(SRCS) )
OBJDIRS := $(shell echo $(OBJS)|xargs dirname |sort|uniq )

LIBS := -lds -lCppUTest


all: builddir $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p output/
	@echo "Linking--------------------------------"
	g++ -o $(TARGET) $(OBJS)  $(LIB_DIRS) $(LIBS)

builddir:
	echo "Creating directories"
	$(shell echo $(OBJDIRS) |xargs mkdir -p )

	
objs/%.o : %.cpp
	@echo "-------------------------------"
	@echo "compiling $^"
	@echo "-------------------------------"
	g++ -c $< -o $@ $(INC_DIR) $(INC_DIRS)  -fPIC 

clean:
	echo "cleaning"
	$(shell rm -f $(OBJS) )
	



