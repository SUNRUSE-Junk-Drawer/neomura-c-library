#pragma once

typedef unsigned char u8_t;
typedef signed char s8_t;
typedef unsigned short u16_t;
typedef signed short s16_t;
typedef unsigned int u32_t;
typedef signed int s32_t;
typedef unsigned long u64_t;
typedef signed long s64_t;
typedef float f32_t;
typedef double f64_t;

#define EXPORT __attribute__((visibility("default")))

#define REFRESH_RATE(hertz) \
  EXPORT const u8_t refresh_rate = (hertz);

#define ELAPSE() \
  EXPORT void elapse()

#define VIDEO(width, height) \
  EXPORT const u16_t video_width = (width); \
  EXPORT const u16_t video_height = (height); \
  EXPORT u8_t video_buffer[(width) * (height) * 3]; \
  EXPORT void video_render()

#define AUDIO(length) \
  EXPORT const u16_t audio_length = (length); \
  EXPORT f32_t audio_buffer[(length) * 2]; \
  EXPORT void audio_render()

#define RUMBLE() \
  EXPORT u8_t rumble_buffer[inputs]; \
  EXPORT void rumble_render()

#define INPUTS(quantity) \
  EXPORT const u8_t inputs = (quantity);

#define INPUT_DPAD_LEFT() \
  EXPORT const u8_t input_dpad_left[inputs];

#define INPUT_DPAD_RIGHT() \
  EXPORT const u8_t input_dpad_right[inputs];

#define INPUT_DPAD_UP() \
  EXPORT const u8_t input_dpad_up[inputs];

#define INPUT_DPAD_DOWN() \
  EXPORT const u8_t input_dpad_down[inputs];

#define INPUT_FACE_LEFT() \
  EXPORT const u8_t input_dpad_left[inputs];

#define INPUT_FACE_RIGHT() \
  EXPORT const u8_t input_dpad_right[inputs];

#define INPUT_FACE_UP() \
  EXPORT const u8_t input_dpad_up[inputs];

#define INPUT_FACE_DOWN() \
  EXPORT const u8_t input_dpad_down[inputs];

#define INPUT_TRIGGER_LEFT() \
  EXPORT const u8_t input_trigger_left[inputs];

#define INPUT_TRIGGER_RIGHT() \
  EXPORT const u8_t input_trigger_right[inputs];

#define INPUT_PAUSE() \
  EXPORT const u8_t input_pause[inputs];

#define STATE_VERSION(version) \
  EXPORT const u16_t state_version = (version);

#define STATE(name, type) \
  EXPORT type state_ ## name ## _buffer; \
  EXPORT const u32_t state_ ## name ## _size = sizeof(type);

#define STATE_ARRAY(name, type, quantity) \
  EXPORT type state_ ## name ## _buffer[quantity]; \
  EXPORT const u32_t state_ ## name ## _size = sizeof(type) * quantity;
