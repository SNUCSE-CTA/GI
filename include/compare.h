#ifndef __COMPARE_H__
#define __COMPARE_H__

extern "C" {
int compare(const char *fname1, const char *fname2, bool *isomorphic, double *processedTime, const char* outfname = nullptr);

}

#endif /* compare.h */
