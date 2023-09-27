#ifndef DLL_H
#define DLL_H

#include <stdbool.h> // for `bool`
#include <stddef.h>  // for `size_t`

typedef char *string;

typedef struct DLL *dll;

dll    DLLcreate       (void);
void   DLLdestroy      (dll);
void   DLLshow         (dll);
dll    DLLappend       (dll, string);
dll    DLLprepend      (dll, string);
string DLLshrink       (dll);
string DLLshift        (dll);

bool   DLLisEmpty      (dll);
size_t DLLlength       (dll);
dll    DLLcopy         (dll);
dll    DLLreverse      (dll);
bool   DLLisCyclic     (dll);
bool   DLLisConsistent (dll);
bool   DLLisOrdered    (dll);
dll    DLLsort         (dll);

void   DLLinsertBefore (dll, string, string);
void   DLLreplace      (dll, string, string);
void   DLLinsertAfter  (dll, string, string);
void   DLLremoveBefore (dll, string);
void   DLLremove       (dll, string);
void   DLLremoveAfter  (dll, string);

#endif // DLL_H

#ifndef EXTRAS_H
#define EXTRAS_H

void DLLcreateCycle                  (dll, size_t, size_t);
void DLLcreateForwardInconsistency   (dll, size_t, size_t);
void DLLcreateBackwardsInconsistency (dll, size_t, size_t);

#endif // EXTRAS_H