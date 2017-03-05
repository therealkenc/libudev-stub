#define STR_EXPAND(tok) #tok
#define STR(tok) STR_EXPAND(tok)
#define _public_ __attribute__ ((visibility("default")))
