# Makefile.am -- Process this file with automake to produce Makefile.in
ACLOCAL_AMFLAGS = -I m4

common_CPPFLAGS = -I$(top_srcdir)/src/common
excmd_CPPFLAGS = -I${top_srcdir}/libraries/excmd/src
fmt_CPPFLAGS = -I${top_srcdir}/libraries/fmt/include

excmd_files = libraries/excmd/src/excmd_exception.h  \
	libraries/excmd/src/excmd.h  \
	libraries/excmd/src/excmd_meta.h  \
	libraries/excmd/src/excmd_str.h  \
	libraries/excmd/src/excmd_value_parser.h


bin_PROGRAMS = elf2rpl readrpl rplexportgen rplimportgen udplogserver bundlebuilder

noinst_LTLIBRARIES      = libfmt.la

libfmt_la_SOURCES = libraries/fmt/include/fmt/core.h  \
	libraries/fmt/include/fmt/format.h  \
	libraries/fmt/include/fmt/format-inl.h  \
	libraries/fmt/include/fmt/ostream.h \
	libraries/fmt/include/fmt/posix.h  \
	libraries/fmt/include/fmt/printf.h  \
	libraries/fmt/include/fmt/ranges.h  \
	libraries/fmt/include/fmt/time.h \
	libraries/fmt/src/format.cc \
	libraries/fmt/src/posix.cc

libfmt_la_CPPFLAGS	= $(fmt_CPPFLAGS)

elf2rpl_SOURCES	= $(excmd_files) src/elf2rpl/main.cpp

elf2rpl_CPPFLAGS = @ZLIB_CFLAGS@ $(common_CPPFLAGS) ${excmd_CPPFLAGS} ${fmt_CPPFLAGS}
elf2rpl_LDADD = libfmt.la @ZLIB_LIBS@

readrpl_SOURCES = src/readrpl/generate_exports_def.cpp  \
	src/readrpl/generate_exports_def.h  \
	src/readrpl/main.cpp  src/readrpl/print.cpp  \
	src/readrpl/print.h  src/readrpl/readrpl.h  \
	src/readrpl/verify.cpp src/readrpl/verify.h

readrpl_CPPFLAGS = @ZLIB_CFLAGS@ $(common_CPPFLAGS) ${excmd_CPPFLAGS} ${fmt_CPPFLAGS}
readrpl_LDADD = libfmt.la @ZLIB_LIBS@

bundlebuilder_SOURCES = $(excmd_files) src/bundlebuilder/main.cpp \
	src/bundlebuilder/main.h \
	src/bundlebuilder/entities/BufferFileEntry.cpp \
	src/bundlebuilder/entities/BufferFileEntry.h \
	src/bundlebuilder/entities/DirectoryEntry.cpp \
	src/bundlebuilder/entities/DirectoryEntry.h \
	src/bundlebuilder/entities/FileEntry.cpp \
	src/bundlebuilder/entities/FileEntry.h \
	src/bundlebuilder/entities/NodeEntry.cpp \
	src/bundlebuilder/entities/NodeEntry.h \
	src/bundlebuilder/entities/OSFileEntry.cpp \
	src/bundlebuilder/entities/OSFileEntry.h \
	src/bundlebuilder/entities/RootEntry.cpp \
	src/bundlebuilder/entities/RootEntry.h \
	src/bundlebuilder/services/RomFSService.cpp \
	src/bundlebuilder/services/RomFSService.h \
	src/bundlebuilder/services/RomFSStructs.h \
	src/bundlebuilder/services/stb/stb_image.h \
	src/bundlebuilder/services/stb/stb_image_resize.h \
	src/bundlebuilder/services/stb/stb_image_write.h \
	src/bundlebuilder/services/stb/strict_fstream.hpp \
	src/bundlebuilder/utils/filepath.cpp \
	src/bundlebuilder/utils/filepath.h \
	src/bundlebuilder/utils/types.h \
	src/bundlebuilder/utils/utils.cpp \
	src/bundlebuilder/utils/utils.h \
	src/bundlebuilder/zstr/zstr.hpp \
	src/bundlebuilder/zstr/zstr_make_unique_polyfill.h
        
bundlebuilder_CPPFLAGS = @ZLIB_CFLAGS@ $(common_CPPFLAGS) ${excmd_CPPFLAGS}
bundlebuilder_LDADD = @ZLIB_LIBS@

rplexportgen_SOURCES = src/rplexportgen/rplexportgen.cpp

rplexportgen_CPPFLAGS = @ZLIB_CFLAGS@ $(common_CPPFLAGS) ${excmd_CPPFLAGS} ${fmt_CPPFLAGS}
rplexportgen_LDADD = @ZLIB_LIBS@

rplimportgen_SOURCES = src/rplimportgen/rplimportgen.cpp

rplimportgen_CPPFLAGS = @ZLIB_CFLAGS@ $(common_CPPFLAGS) ${excmd_CPPFLAGS} ${fmt_CPPFLAGS}
rplimportgen_LDADD = @ZLIB_LIBS@

udplogserver_SOURCES = src/udplogserver/main.cpp
udplogserver_LDADD = @NET_LIBS@

EXTRA_DIST = autogen.sh src/common/be_val.h  src/common/elf.h  src/common/rplwrap.h src/common/type_traits.h  src/common/utils.h LICENSE.md
