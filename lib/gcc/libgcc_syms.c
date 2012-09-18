#include <linux/module.h>

#define EXPORT(sym) \
extern void sym (void); \
EXPORT_SYMBOL(sym)

EXPORT(_Unwind_GetDataRelBase);
EXPORT(_Unwind_SetGR);
EXPORT(_Unwind_GetLanguageSpecificData);
EXPORT(_Unwind_GetTextRelBase);
EXPORT(_Unwind_SetIP);
EXPORT(_Unwind_RaiseException);
EXPORT(_Unwind_DeleteException);
EXPORT(_Unwind_Resume);
EXPORT(_Unwind_GetRegionStart);
EXPORT(_Unwind_Resume_or_Rethrow);
EXPORT(_Unwind_GetIP);
EXPORT(__register_frame_info);
EXPORT(__register_frame_info_bases);
EXPORT(__deregister_frame_info);
EXPORT(__deregister_frame_info_bases);
EXPORT(__dso_handle);
