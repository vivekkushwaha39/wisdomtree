TARGET = output/libds.a
SRCS := $(shell find src/ -name "*.cpp" )
OBJS := $(patsubst %.cpp, objs/%.o, $(SRCS) )
OBJDIRS := $(shell echo $(OBJS)|xargs dirname |sort|uniq )

INC_DIR=-I./include

all: builddir $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p output/
	$(shell ar r $(TARGET) $(OBJS)  )

builddir: 
	echo "Creating directories"
	$(shell echo $(OBJDIRS) |xargs mkdir -p )

	
objs/%.o : %.cpp
	echo "compiling $^"
	g++ -c $< -o $@ $(INC_DIR)

clean:
	echo "cleaning"
	$(shell rm -f $(OBJS) )
	
