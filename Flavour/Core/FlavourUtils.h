#if defined _WIN32 || _WIN64
# ifdef FLAVOUR_WIN_EXPORT
#   define API_EXPORTED __declspec(dllexport)
# else
#   define API_EXPORTED __declspec(dllimport)
# endif
#else
# define API_EXPORTED
#endif