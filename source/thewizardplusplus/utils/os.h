#ifndef OS_H
#define OS_H

#if defined(__linux__) || defined(__linux)
#define OS_LINUX
#elif (!defined(SAG_COM) && (defined(WIN64) || defined(_WIN64) || defined( \
	__WIN64__) || (!defined(WINCE) && !defined(_WIN32_WCE) && (defined(WIN32) \
	|| defined(_WIN32) || defined(__WIN32__) || defined(__NT__))))) || \
	(defined(__MWERKS__) && defined(__INTEL__))
#define OS_WINDOWS
#else
#error This OS is not supported by the TheWizardUtils.
#endif
#endif
