# Reduce firmware size
# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/#link-time-optimization-and-disabling-core-functionality
# EXTRAFLAGS += -flto

SPLIT_KEYBOARD = yes


EXTRAKEY_ENABLE = yes


RGB_MATRIX_ENABLE = no
# RGB_MATRIX_DRIVER = WS2812


# isaac's changes
SRC += features/custom_shift_keys.c
# CUSTOM_SHIFT_KEYS = no

# repeat key + magic key
REPEAT_KEY_ENABLE = yes

CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes



# Change keymaps without flashing
# https://caniusevia.com/
OLED_DRIVER_ENABLE = no
ENCODER_MAP_ENABLE = yes
ENCODER_ENABLE = yes
VIA_ENABLE = yes
