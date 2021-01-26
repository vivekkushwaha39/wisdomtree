build_dirs := problems Ds

all:
	$(foreach dr,$(build_dirs), $(MAKE) -C $(dr) all ; )
clean:
	$(foreach dr,$(build_dirs), $(MAKE) -C $(dr) clean ; )
