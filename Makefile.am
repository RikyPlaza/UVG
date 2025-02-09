bin_PROGRAMS = uvg
uvg_CFLAGS = "-I/usr/include/libxml2"
uvg_LDADD = -lxml2
uvg_SOURCES = UVG/uvg.c UVG/common/common.c UVG/common/xmlparser/xmlreader.c UVG/common/strings/uvgstrings.c

clean_local:
	@rm config.status configure config.log
	@rm Makefile
	@rm -r autom4te.cache/
	@rm aclocal.m4
	@rm compile install-sh missing Makefile.in
