include $(top_srcdir)/Makefile.am.inc

udevhomedir = $(udev_prefix)/lib/udev
udevhome_PROGRAMS = \
	create_floppy_devices

create_floppy_devices_SOURCES = \
	create_floppy_devices.c \
	../../udev/lib/libudev.h \
	../../udev/lib/libudev.c \
	../../udev/lib/libudev-list.c \
	../../udev/lib/libudev-util.c \
	../../udev/lib/libudev-device.c \
	../../udev/lib/libudev-enumerate.c \
	../../udev/udev-util.c

if USE_SELINUX
create_floppy_devices_SOURCES += \
	../../udev/udev-selinux.c
create_floppy_devices_LDADD = \
	$(SELINUX_LIBS)
endif

dist_man_MANS = \
	create_floppy_devices.8
