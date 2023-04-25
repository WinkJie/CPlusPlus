#include "extcode.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct {
	int32_t dimSizes[2];
	double element[1];
} DoubleArrayBase;
typedef DoubleArrayBase **DoubleArray;
typedef uint16_t  Enum;
#define Enum_y_val1 0
#define Enum_y_val2 1
#define Enum_y_val3 2
typedef uint32_t  Enum1;
#define Enum1_SVD 0
#define Enum1_Givens 1
#define Enum1_Givens2 2
#define Enum1_Householder 3
#define Enum1_LUDecomposition 4
#define Enum1_Cholesky 5

/*!
 * array_init
 */
void __cdecl array_init(int32_t row, int32_t column, 
	DoubleArray *initializedArray);
/*!
 * polyfit
 */
int16_t __cdecl polyfit(double upper_range, DoubleArray *RawData, Enum y_val, 
	Enum1 algorithm, int32_t polynomialOrder, double weightingPower, 
	double lowerLimit[], int32_t lowerLimit_len, double upperLimit[], int32_t upperLimit_len, 
	DoubleArray *Coefficients, double *meanMse, int32_t *actual_num_levels);

MgErr __cdecl LVDLLStatus(char *errStr, int errStrLen, void *module);

/*
* Memory Allocation/Resize/Deallocation APIs for type 'DoubleArray'
*/
DoubleArray __cdecl AllocateDoubleArray (int32 *dimSizeArr);
MgErr __cdecl ResizeDoubleArray (DoubleArray *hdlPtr, int32 *dimSizeArr);
MgErr __cdecl DeAllocateDoubleArray (DoubleArray *hdlPtr);

#ifdef __cplusplus
} // extern "C"
#endif

