SRCS := $(shell find src/ -name "*.cpp" )
OBJS := $(patsubst %.cpp, objs/%.o, $(SRCS) )
OBJDIRS := $(shell echo $(OBJS)|xargs dirname |sort|uniq )

INC_DIR=-I./include


all: builddir $(TARGET)
	@echo "-----------------------------------"
	@echo "Building $(TARGET)"
	@echo "-----------------------------------"

builddir: 
	@echo "----------------------------------"
	@echo "Creating directories in $(CURDIR)"
	$(shell echo $(OBJDIRS) |xargs mkdir -p )

	
objs/%.o : %.cpp
	echo "compiling $^"
	g++ -c $< -o $@ $(INC_DIR)

clean:
	echo "cleaning $(CURDIR)"
	$(shell rm -rf $(OBJS) $(TARGET) )
	