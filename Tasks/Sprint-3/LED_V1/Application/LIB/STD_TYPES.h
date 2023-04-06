
#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_

typedef unsigned char 			uint8_t;
//typedef unsigned short int		uint16_t;
typedef unsigned long int		uint32_t;

typedef signed char 			s8 ;
typedef signed short int		s16;
typedef signed long int			s32;

typedef float                   f32;
typedef double                  f64;

typedef enum {OK, NOK, NULL_PTR, BUSY_FUNCTION}ErrorStatus;

typedef enum {ENABLE = 1, DISABLE}State;

#define 	NULL				0


#endif
