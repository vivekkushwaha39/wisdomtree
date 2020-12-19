TARGET = output/libds.a

include ../../common.mk

$(TARGET): $(OBJS)
	mkdir -p output/
	$(shell ar r $(TARGET) $(OBJS)  )

