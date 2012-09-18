#include <linux/module.h>

#define EXPORT(sym) \
extern void sym (void); \
EXPORT_SYMBOL(sym)

EXPORT(__cxa_allocate_exception);
EXPORT(__cxa_free_exception);
EXPORT(__cxa_bad_typeid);
EXPORT(__cxa_begin_catch);
EXPORT(__cxa_end_catch);
EXPORT(__cxa_pure_virtual);
EXPORT(__cxa_call_unexpected);
EXPORT(__cxa_throw);
EXPORT(__cxa_rethrow);
EXPORT(__dynamic_cast);
EXPORT(__gxx_personality_v0);
EXPORT(_ZTVN10__cxxabiv117__class_type_infoE);
EXPORT(_ZTVN10__cxxabiv120__si_class_type_infoE);
EXPORT(_ZTVN10__cxxabiv121__vmi_class_type_infoE);
EXPORT(_ZNKSt9type_infoeqERKS_);
EXPORT(_ZNSt9bad_allocD1Ev);
EXPORT(_ZTVSt9bad_alloc);
EXPORT(_ZTISt9bad_alloc);
EXPORT(_ZTISt10bad_typeid);
EXPORT(_ZTISt9exception);

EXPORT(_ZTIh);
EXPORT(_ZTIb);
EXPORT(_ZTIa);
EXPORT(_ZTIc);
EXPORT(_ZTIw);
EXPORT(_ZTIi);
EXPORT(_ZTIs);
EXPORT(_ZTIj);
EXPORT(_ZTIt);
EXPORT(_ZTIl);
EXPORT(_ZTIm);
EXPORT(_ZTIx);
EXPORT(_ZTIy);

EXPORT(_Znwj);
EXPORT(_Znaj);
EXPORT(_ZdlPv);
EXPORT(_ZdaPv);
