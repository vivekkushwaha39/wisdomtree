TARGET = output/libds.a

include ../../common.mk

$(TARGET): $(OBJS)
	mkdir -p output/
	$(shell ar r $(TARGET) $(OBJS)  )

all: builddir $(TARGET) 
	$(MAKE) -C graph
clean:
	$(MAKE) -C graph clean
