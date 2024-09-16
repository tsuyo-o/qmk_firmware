//#define NO_CHARYBDIS_KEYCODES

// https://docs.qmk.fm/features/pointing_device
// Enable auto mouse
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE

// Amount of mouse movement(unit) required to switch layers
#define AUTO_MOUSE_THRESHOLD 20

// Time(ms) layer remains active after activation
#define AUTO_MOUSE_TIME	650

// https://github.com/qmk/qmk_firmware/blob/master/docs/getting_started_introduction.md
#undef MASTER_RIGHT
#define MASTER_LEFT
//#define EE_HANDS

// default is 200
#define TAPPING_TERM 300
// keep Hold state if the time of next key-typing < TAPPING_TERM.
#define PERMISSIVE_HOLD
