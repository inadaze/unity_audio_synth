
#ifndef STK_EXPORT_H
#define STK_EXPORT_H

#ifdef STK_STATIC_DEFINE
#  define STK_EXPORT
#  define STK_NO_EXPORT
#else
#  ifndef STK_EXPORT
#    ifdef STK_EXPORTS
        /* We are building this library */
#      define STK_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define STK_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef STK_NO_EXPORT
#    define STK_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef STK_DEPRECATED
#  define STK_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef STK_DEPRECATED_EXPORT
#  define STK_DEPRECATED_EXPORT STK_EXPORT STK_DEPRECATED
#endif

#ifndef STK_DEPRECATED_NO_EXPORT
#  define STK_DEPRECATED_NO_EXPORT STK_NO_EXPORT STK_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef STK_NO_DEPRECATED
#    define STK_NO_DEPRECATED
#  endif
#endif

#endif /* STK_EXPORT_H */
