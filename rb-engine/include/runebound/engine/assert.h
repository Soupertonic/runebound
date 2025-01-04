#pragma once

#include <stdio.h>
#include <stdlib.h>

#ifdef NDEBUG
#define rbAssert(format, expression) ((void) 0)
#define rbAssertExpression(expression) ((void) 0)
#define rbAssertNotNull(target) ((void) 0)
#endif

#ifndef NDEBUG
#define rbAssert(format, expression)                          \
    ((void) printf(format, __FILE__, __LINE__, expression), \
            abort())

#define rbAssertExpression(expression) \
    (void) ((expression) ||           \
            (rbAssert("%s:%d: failed expression assertion '%s'\n", #expression), 0))

#define rbAssertNotNull(target)    \
    (void) ((target != nullptr) || \
            (rbAssert("%s:%d: failed not null assertion for '%s'\n", #target), 0))
#endif

