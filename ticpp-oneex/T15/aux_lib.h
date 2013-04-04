/******************************************************************************
* File Name          : auxlib.h
* Author             : tary
* Date               : 2:01 2012/4/4
* Version            : 0.5
* Description        : common used functions
******************************************************************************/

#ifndef __AUX_LIB_H__
#define __AUX_LIB_H__

#define countof(a)		(sizeof(a) / sizeof(a[0]))

#if defined(LBP_DBG)
#define DBG_LINE(nr, ...)		do {					\
	if (LOCAL_DBG) debug_line(__FUNCTION__, __LINE__, nr, __VA_ARGS__);	\
					}while(0)
#define DBG_BUF(name, buf, size)	do {					\
	if (LOCAL_DBG) debug_buf(name, buf, size);				\
					}while(0)
#define DBG_PRINT(fmt, ...)		do {						\
	if (LOCAL_DBG){								\
		printf("\r\nDBG:%s() L%d\t", __FUNCTION__, __LINE__);		\
		printf(fmt, __VA_ARGS__);						\
	}				}while(0)
#else
#define DBG_LINE(...)
#define DBG_BUF(...)
#define DBG_PRINT(...)
#endif	//LBP_DBG

int debug_buf(const char* head, unsigned char* buf, int len);
int debug_line(const char* file, int lin, int nr, ...);

#endif//__AUX_LIB_H__

/************************************END OF FILE******************************/
