LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

# the executables that should be installed on the final system have to be added
# to PRODUCT_PACKAGES in
#   build/target/product/core.mk
# possible executables are
#   starter - allows to control and configure the daemons from the command line
#   charon - the IKEv2 daemon
#   pluto - the IKEv1 daemon

# if you enable starter and/or pluto (see above) uncomment the proper lines here
# strongswan_BUILD_STARTER := true
# strongswan_BUILD_PLUTO := true

# this is the list of plugins that are built into libstrongswan and charon
# also these plugins are loaded by default (if not changed in strongswan.conf)
strongswan_CHARON_PLUGINS := openssl fips-prf random pubkey pkcs1 \
	pem xcbc hmac kernel-netlink socket-default android \
	stroke eap-identity eap-mschapv2 eap-md5

ifneq ($(strongswan_BUILD_PLUTO),)
# if both daemons are enabled we use raw sockets in charon
strongswan_CHARON_PLUGINS := $(subst socket-default,socket-raw, \
				$(strongswan_CHARON_PLUGINS))
# plugins loaded by pluto
strongswan_PLUTO_PLUGINS := openssl fips-prf random pubkey pkcs1 \
	pem xcbc hmac kernel-netlink xauth
endif

strongswan_STARTER_PLUGINS := kernel-netlink

# list of all plugins - used to enable them with the function below
strongswan_PLUGINS := $(sort $(strongswan_CHARON_PLUGINS) \
			     $(strongswan_PLUTO_PLUGINS) \
			     $(strongswan_STARTER_PLUGINS))

# helper macros to only add source files for plugins included in the list above
# source files are relative to the android.mk that called the macro
plugin_enabled = $(findstring $(1), $(strongswan_PLUGINS))
add_plugin = $(if $(call plugin_enabled,$(1)), \
               $(patsubst $(LOCAL_PATH)/%,%, \
                 $(wildcard \
                   $(subst %,$(subst -,_,$(strip $(1))), \
                     $(LOCAL_PATH)/plugins/%/%*.c \
                    ) \
                  ) \
                ) \
              )

# includes
strongswan_PATH := $(LOCAL_PATH)
libvstr_PATH := external/strongswan-support/vstr/include
libgmp_PATH := external/strongswan-support/gmp

# some definitions
strongswan_VERSION := "4.6.4"
strongswan_DIR := "/system/bin"
strongswan_SBINDIR := "/system/bin"
strongswan_PIDDIR := "/data/misc/vpn"
strongswan_PLUGINDIR := "$(strongswan_IPSEC_DIR)/ipsec"
strongswan_CONFDIR := "/system/etc"
strongswan_STRONGSWAN_CONF := "$(strongswan_CONFDIR)/strongswan.conf"

# CFLAGS (partially from a configure run using droid-gcc)
strongswan_CFLAGS := \
	-Wno-format \
	-Wno-pointer-sign \
	-Wno-pointer-arith \
	-Wno-sign-compare \
	-Wno-strict-aliasing \
	-DHAVE___BOOL \
	-DHAVE_STDBOOL_H \
	-DHAVE_ALLOCA_H \
	-DHAVE_ALLOCA \
	-DHAVE_CLOCK_GETTIME \
	-DHAVE_PTHREAD_COND_TIMEDWAIT_MONOTONIC \
	-DHAVE_PRCTL \
	-DHAVE_LINUX_UDP_H \
	-DHAVE_STRUCT_SADB_X_POLICY_SADB_X_POLICY_PRIORITY \
	-DHAVE_IPSEC_MODE_BEET \
	-DHAVE_IPSEC_DIR_FWD \
	-DOPENSSL_NO_EC \
	-DOPENSSL_NO_ECDSA \
	-DOPENSSL_NO_ECDH \
	-DOPENSSL_NO_ENGINE \
	-DCAPABILITIES \
	-DCAPABILITIES_NATIVE \
	-DMONOLITHIC \
	-DUSE_VSTR \
	-DDEBUG \
	-DROUTING_TABLE=0 \
	-DROUTING_TABLE_PRIO=220 \
	-DVERSION=\"$(strongswan_VERSION)\" \
	-DPLUGINDIR=\"$(strongswan_PLUGINDIR)\" \
	-DIPSEC_DIR=\"$(strongswan_DIR)\" \
	-DIPSEC_PIDDIR=\"$(strongswan_PIDDIR)\" \
	-DIPSEC_CONFDIR=\"$(strongswan_CONFDIR)\" \
	-DSTRONGSWAN_CONF=\"$(strongswan_STRONGSWAN_CONF)\" \
	-DDEV_RANDOM=\"/dev/random\" \
	-DDEV_URANDOM=\"/dev/urandom\"

# only for Android 2.0+
strongswan_CFLAGS += \
	-DHAVE_IN6ADDR_ANY

strongswan_BUILD := \
	charon \
	libcharon \
	libhydra \
	libstrongswan \
	libtncif \
	libtnccs

ifneq ($(strongswan_BUILD_STARTER),)
strongswan_BUILD += \
	libfreeswan \
	starter \
	stroke \
	ipsec
endif

ifneq ($(strongswan_BUILD_PLUTO),)
strongswan_BUILD += \
	libfreeswan \
	pluto \
	whack
endif

include $(addprefix $(LOCAL_PATH)/src/,$(addsuffix /Android.mk, \
		$(sort $(strongswan_BUILD))))
