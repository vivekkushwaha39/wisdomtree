TARGET := output/cpp_stl.exe

include ../../common.mk

$(TARGET): $(OBJS)
	ifndef module_list
		$(error module_list not defined)
	endif
	mkdir -p output/
	g++ -o $(TARGET) $(OBJS)
