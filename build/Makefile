GPP = g++
GCC = gcc
CMDS_OUTFILE = "samp-hooks.so"

COMPILE_FLAGS = -std=c++0x -m32 -fPIC -c -lrt -w -DLINUX -D_GNU_SOURCE -fpermissive -I ../ -D PROJECT_NAME=\"samp-hooks\"

samp-hooks = -D samp-hooks $(COMPILE_FLAGS)

all: samp-hooks

clean:
	-rm -f *~ *.o *.so

samp-hooks: clean
	$(GPP) $(samp-hooks) ../*.cpp
	$(GPP) -m32 -fshort-wchar -static-libstdc++ -lrt  -shared -o $(CMDS_OUTFILE) *.o

