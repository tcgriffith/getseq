
GCC = g++
SRCDIR = src
BUILDDIR = .build
BINDIR = bin
INCDIR = include

SRCPDB = $(SRCDIR)/PDB.cc \
         $(SRCDIR)/pdb_utils.cc
OBJ_PDB = $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SRCPDB:.cc=.o))

CFLAGS = -std=c++11 -fopenmp #-g 
LDFLAGS = 
LIB = -ldl
INC = -Iinclude


getseq: $(OBJ_PDB) src/getseq.cc
	@mkdir -p $(BINDIR)
	$(GCC) $^ $(CFLAGS)  $(INC) -static $(LIB) $(LDFLAGS)  -o bin/getseq

$(BUILDDIR)/%.o: $(SRCDIR)/%.cc $(INCDIR)/%.h
	@mkdir -p $(BUILDDIR)
	$(GCC) $(CFLAGS) $(INC) -c -o $@ $<

.PHONY: clean
clean:
	@echo " Cleaning..."
	rm -rf $(BUILDDIR) $(BINDIR)



