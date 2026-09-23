# Top-level Makefile: delegates work to the Makefile inside src/

SUBDIR = src

all:
	$(MAKE) -C $(SUBDIR)

clean:
	$(MAKE) -C $(SUBDIR) clean

.PHONY: all clean
