/* TEMP: frame time profile */
#ifndef PCSXR_PROF_H
#define PCSXR_PROF_H
#ifdef HW_WUP
#include <coreinit/time.h>
extern OSTime pcsxr_prof[8];
#define PROF_BEGIN(v) OSTime v = OSGetSystemTime()
#define PROF_END(i, v) (pcsxr_prof[i] += OSGetSystemTime() - (v))
#else
#define PROF_BEGIN(v)
#define PROF_END(i, v)
#endif
#endif
