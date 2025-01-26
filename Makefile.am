bin_PROGRAMS = uvg
uvg_CFLAGS = "-I/usr/include/libxml2"
uvg_LDADD = libxml2.so
uvg_SOURCES = UVG/uvg.c

clean_local:
	@rm config.status configure config.log
	@rm Makefile
	@rm -r autom4te.cache/
	@rm aclocal.m4
	@rm compile install-sh missing Makefile.in
