/*
 * srpc_utils.h
 *
 *  Created on: 21-Jul-2017
 *  Author: bharath
 */

#include <stdio.h>

#ifndef SRPC_UTILS_H_
#define SRPC_UTILS_H_

#ifdef SRPC_INFO
#define TRACING_ACTIVE
#define TRACE_INFO TRACE
#endif

#ifdef SRPC_DEBUG
#define TRACE_INFO TRACE
#define TRACE_DEBUG TRACE
#define TRACING_ACTIVE
#endif

#ifdef TRACING_ACTIVE
#define TRACE(fmt, ...) printf("%s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#ifndef TRACE_DEBUG
#define TRACE_DEBUG
#endif
#ifndef TRACE_INFO
#define TRACE_INFO
#endif

#endif /* SRPC_UTILS_H_ */
