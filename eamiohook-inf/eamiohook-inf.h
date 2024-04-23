// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the EAMIOHOOKINF_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// EAMIOHOOKINF_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef EAMIOHOOKINF_EXPORTS
#define EAMIOHOOKINF_API __declspec(dllexport)
#else
#define EAMIOHOOKINF_API __declspec(dllimport)
#endif

// This class is exported from the dll
class EAMIOHOOKINF_API Ceamiohookinf {
public:
	Ceamiohookinf(void);
	void send_input();
};

extern EAMIOHOOKINF_API int neamiohookinf;

EAMIOHOOKINF_API int fneamiohookinf(void);
