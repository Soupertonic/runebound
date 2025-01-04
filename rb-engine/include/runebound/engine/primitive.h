#pragma once

static_assert(sizeof(void*) == 8, "expected 64-bit platform");

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

static_assert(sizeof(u8) == 1, "expected \"unsigned char\" to be 8 bits in size");
static_assert(sizeof(u16) == 2, "expected \"unsigned short\" to be 16 bits in size");
static_assert(sizeof(u32) == 4, "expected \"unsigned int\" to be 32 bits in size");
static_assert(sizeof(u64) == 8, "expected \"unsigned long long\" to be 64 bits in size");

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

static_assert(sizeof(s8) == 1, "expected \"signed char\" to be 8 bits in size");
static_assert(sizeof(s16) == 2, "expected \"signed short\" to be 16 bits in size");
static_assert(sizeof(s32) == 4, "expected \"signed int\" to be 32 bits in size");
static_assert(sizeof(s64) == 8, "expected \"signed long long\" to be 64 bits in size");

typedef float f32;
typedef double f64;

static_assert(sizeof(f32) == 4, "expected \"float\" to be 32 bits in size");
static_assert(sizeof(f64) == 8, "expected \"double\" to be 64 bits in size");

typedef bool b8;

static_assert(sizeof(b8) == 1, "expected \"bool\" to be 8 bits in size");
static_assert(false == 0, "expected \"false\" to match \"0\"");
static_assert(true == 1, "expected \"true\" to match \"1\"");

typedef char* cstr;
