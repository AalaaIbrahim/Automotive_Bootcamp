#ifndef SERVICES_STD_TYPES_H_
#define SERVICES_STD_TYPES_H_

typedef unsigned char 			uint8_t;
typedef unsigned short int		u_int_16;
typedef unsigned long int		uint32_t;

typedef enum
{
	uSeconds,
	mSeconds,
	Seconds
}en_timeUnits_t;

typedef enum {OK, NOK}ErrorStatus;

#define 	NULL				0


#endif
