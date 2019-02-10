#!/usr/bin/makefile -f

all: build

build: lv2_ttl_generator plugin generate_ttl

build32: lv2_ttl_generator32 plugin32 generate_ttl

lv2_ttl_generator32: lv2_ttl_generator.c
	$(CXX) lv2_ttl_generator.c -m32 -o lv2_ttl_generator -ldl

plugin: lv2_ttl_generator
	make config=release_x64 -C linux/gmake/

plugin32: lv2_ttl_generator.c
	make config=release_x32 -C linux/gmake/

generate_ttl: lv2_ttl_generator
	./lv2_ttl_generator linux/gmake/build/Misstortion.lv2/Misstortion.so
	mv Misstortion.ttl manifest.ttl linux/gmake/build/Misstortion.lv2/

clean:
	rm -f lv2_ttl_generator
	make -C linux/gmake/ clean
