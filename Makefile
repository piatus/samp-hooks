GPP = g++
GCC = gcc 
CMDS_OUTFILE = "./build/samp-hooks.so"

COMPILE_FLAGS = -m32 -fPIC -c -lrt -w -DLINUX -O3 -D_GNU_SOURCE -fpermissive  -I ../ -I ../amx  -D PROJECT_NAME=\"samp-hooks\"

samp-hooks = -D samp-hooks $(COMPILE_FLAGS)

all: samp-hooks

clean:
	-rm -f *~ *.o *.so

samp-hooks: clean
	$(GPP) $(samp-hooks) *.cpp
	$(GPP) -m32 -fshort-wchar -static-libstdc++ -lrt  -shared -o $(CMDS_OUTFILE) *.o
	rm -f *~ *.o

