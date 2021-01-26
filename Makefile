# module handling
export module_list := 

define REGMODULE
	$(eval tmp_module_name := $1:$2:$3)
	$(eval 
		ifndef module_list \ 
			$(error module_list  NOT DEFINED ) \
		endif
	) 
	$(eval module_list += $(tmp_module_name))
endef

.PHONY:  add_modules

add_modules:
	$(call REGMODULE,Ds ,$(CURDIR))

maketest:
	echo "$(module_list)"

all:
	make -C source all
	make -C tests all
clean:
	make -C source clean
	make -C tests clean
	
test:
	./tests/output/test.exe

