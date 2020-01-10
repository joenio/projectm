GTK_CXXFLAGS = `pkg-config gtkmm-3.0 gl --cflags --libs`

AM_CPPFLAGS = \
	-include $(top_builddir)/config.h \
	-DSYSCONFDIR=\""$(sysconfdir)"\" \
	-I${top_srcdir}/src/libprojectM \
	-I${top_srcdir}/src/libprojectM/Renderer \
	${GTK_CXXFLAGS} \
	-fPIC

AM_CFLAGS = ${my_CFLAGS} \
	-fvisibility=hidden \
	-ffunction-sections \
	-fdata-sections

bin_PROGRAMS = projectM-gtk
projectM_gtk_SOURCES = projectM-gtk.cpp
projectM_gtk_LDADD = ${top_srcdir}/src/libprojectM/libprojectM.la
projectM_gtk_LDFLAGS = -static `pkg-config gtkmm-3.0 --cflags --libs`
projectM_gtk_PROGRAM = projectM-gtk
