#ifndef DISTRHO_PLUGIN_INFO_H_INCLUDED
#define DISTRHO_PLUGIN_INFO_H_INCLUDED

#define DISTRHO_PLUGIN_NAME    "Misstortion DPF"
#define DISTRHO_PLUGIN_BRAND   "Nimble Tools"
#define DISTRHO_PLUGIN_URI     "https://github.com/pdesaulniers/misstortion-dpf"
#define DISTRHO_PLUGIN_CLAP_ID "com.github.pdesaulniers.misstortion-dpf"

#define DISTRHO_PLUGIN_HAS_UI          1
#define DISTRHO_UI_USE_NANOVG          1
#define DISTRHO_UI_USER_RESIZABLE      1

#define DISTRHO_PLUGIN_NUM_INPUTS      2
#define DISTRHO_PLUGIN_NUM_OUTPUTS     2
#define DISTRHO_PLUGIN_WANT_PROGRAMS   0
#define DISTRHO_PLUGIN_USES_MODGUI     0
#define DISTRHO_PLUGIN_WANT_STATE      0
#define DISTRHO_PLUGIN_WANT_FULL_STATE 0

#define DISTRHO_UI_DEFAULT_WIDTH 611
#define DISTRHO_UI_DEFAULT_HEIGHT 662

#ifdef __MOD_DEVICES__
#undef DISTRHO_PLUGIN_USES_MODGUI
#undef DISTRHO_UI_DEFAULT_HEIGHT
#define DISTRHO_PLUGIN_USES_MODGUI 1
#define DISTRHO_UI_DEFAULT_HEIGHT 550
#endif

#define DISTRHO_PLUGIN_LV2_CATEGORY "lv2:DistortionPlugin"
#define DISTRHO_PLUGIN_VST3_CATEGORIES "Fx|Distortion|Stereo"
#define DISTRHO_PLUGIN_CLAP_FEATURES "audio-effect", "distortion", "stereo"

#define DISTRHO_PLUGIN_IS_RT_SAFE 1

#endif
