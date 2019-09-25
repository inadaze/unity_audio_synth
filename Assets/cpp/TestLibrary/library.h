#include "Talker.h"

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#  ifdef MODULE_API_EXPORTS
#    define MODULE_API __declspec(dllexport)
#  else
#    define MODULE_API __declspec(dllimport)
#  endif
#else
#  define MODULE_API
#endif
MODULE_API void hello();
MODULE_API Talker* create_talker();
MODULE_API void talker_talk(Talker* talker);
MODULE_API void makeSineWave();
MODULE_API void makeRtSineWave();

#ifdef __cplusplus
}
#endif