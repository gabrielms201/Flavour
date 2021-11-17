#ifdef _WIN32 || _WIN64
# ifdef FLAVOUR_WIN_EXPORT
#   define EXPORTED __declspec(dllexport)
# else
#   define EXPORTED __declspec(dllimport)
# endif
#else
# define EXPORTED
#endif