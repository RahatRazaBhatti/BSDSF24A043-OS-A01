# Top-level Makefile: delegates to src/, plus install/uninstall

SUBDIR  = src
PREFIX  = /usr/local
BINDEST = $(PREFIX)/bin
MANDEST = $(PREFIX)/share/man

all:
	$(MAKE) -C $(SUBDIR)

clean:
	$(MAKE) -C $(SUBDIR) clean

install:
	install -d $(BINDEST) $(MANDEST)/man1 $(MANDEST)/man3
	install -m 755 bin/client_static $(BINDEST)/client
	install -m 644 man/man1/client.1 $(MANDEST)/man1/
	install -m 644 man/man3/*.3 $(MANDEST)/man3/
	-mandb -q

uninstall:
	rm -f $(BINDEST)/client $(MANDEST)/man1/client.1
	rm -f $(MANDEST)/man3/mystrlen.3
	rm -f $(MANDEST)/man3/mystrcpy.3
	rm -f $(MANDEST)/man3/mystrncpy.3
	rm -f $(MANDEST)/man3/mystrcat.3
	rm -f $(MANDEST)/man3/wordCount.3
	rm -f $(MANDEST)/man3/mygrep.3
	-mandb -q

.PHONY: all clean install uninstall
