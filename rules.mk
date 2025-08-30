# Default is current pinout
LEGACY_PINOUT ?= 0

ifeq ($(LEGACY_PINOUT),1)
    EXTRAFLAGS += -DLEGACY_PINOUT
    RGBLIGHT_ENABLE = no       # Disable WS2812 RGB underlight on Legacy as it uses GP16
else
    RGBLIGHT_ENABLE = yes      # Enable RGB underlight, to control the LED on the RP2040-Zero
endif
