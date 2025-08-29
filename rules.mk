# Default is current pinout
LEGACY_PINOUT ?= 0

ifeq ($(LEGACY_PINOUT),1)
    EXTRAFLAGS += -DLEGACY_PINOUT
endif
