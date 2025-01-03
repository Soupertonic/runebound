.PHONY: setup tidy
.SUFFXES:

MAKEFLAGS += -rR
 
toolchain.assembler = clang
toolchain.compiler = clang
toolchain.linker = clang

build.distribution.directory = dist
build.distribution.binary = libRuneboundEngine.dylib

build.include.directory = include
build.include.files = $(shell find $(build.include.directory) -name '*.h')

build.source.directory = source
build.source.files = $(shell find $(build.source.directory) -name '*.c')

build.object.directory = build
build.object.files = $(patsubst $(build.source.directory)/%.c,$(build.object.directory)/%.c.o,$(build.source.files))

flags.default.compiler = -c -std=c23 -I $(build.include.directory) -Wno-unused-variable
flags.default.linker = -Wl,-undefined -Wl,dynamic_lookup -I $(build.include.directory) -o $(build.distribution.directory)/$(build.distribution.binary)

flags.debug.compiler = $(flags.default.compiler) -g
flags.debug.linker = $(flags.default.linker)

flags.release.compiler = $(flags.default.compiler) -g -O3 -static -fdata-sections -ffunction-sections
flags.release.linker = $(flags.default.linker) -O3 -Wl,-dead_strip

default: debug

debug: build.type = debug
debug: setup $(build.object.files)
	$(toolchain.linker) $(flags.debug.linker) $(build.object.files)

release: build.type = release
release: setup $(build.object.files)
	$(toolchain.linker) $(flags.release.linker) $(build.object.files)

$(build.object.files): $(build.object.directory)/%.c.o: $(build.source.directory)/%.c
	$(toolchain.compiler) $(flags.$(build.type).compiler) -o $@ $<

setup:
	mkdir -p $(build.distribution.directory)
	mkdir -p $(build.object.directory)

tidy:
	rm -f .gdb_history
	rm -rf $(build.distribution.directory)
	rm -rf $(build.object.directory)
