//#define NO_CHARYBDIS_KEYCODES
//#define CHARYBDIS_MINIMUM_DEFAULT_DPI 800

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

// https://github.com/qmk/qmk_firmware/blob/3ac9259742bfd428f71c31dbf2bfedace2a7f91b/keyboards/lets_split/readme.md#setting-ee_hands-to-use-either-hands-as-master
#define EE_HANDS

// default is 200
#define TAPPING_TERM 400
// keep Hold state if the time of next key-typing < TAPPING_TERM.
#define PERMISSIVE_HOLD
