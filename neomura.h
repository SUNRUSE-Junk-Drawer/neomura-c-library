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

#define REFRESH_RATE_DECLARATION \
  EXPORT extern const u8_t refresh_rate;

#define REFRESH_RATE_IMPLEMENTATION \
  EXPORT const u8_t refresh_rate = (REFRESH_RATE);

#define ELAPSE_DECLARATION \
  EXPORT void elapse();

#define ELAPSE_IMPLEMENTATION \
  EXPORT void elapse()

#define VIDEO_DECLARATION                                            \
  EXPORT extern const u16_t video_width;                             \
  EXPORT extern const u16_t video_height;                            \
  EXPORT extern u8_t video_buffer[(VIDEO_WIDTH) * (VIDEO_HEIGHT)*4]; \
  EXPORT void video_render();

#define VIDEO_IMPLEMENTATION                                  \
  EXPORT const u16_t video_width = (VIDEO_WIDTH);             \
  EXPORT const u16_t video_height = (VIDEO_HEIGHT);           \
  EXPORT u8_t video_buffer[(VIDEO_WIDTH) * (VIDEO_HEIGHT)*4]; \
  EXPORT void video_render()

#define AUDIO_DECLARATION                             \
  EXPORT extern const u16_t audio_length;             \
  EXPORT extern f32_t audio_buffer[(AUDIO_LENGTH)*2]; \
  EXPORT void audio_render();

#define AUDIO_IMPLEMENTASTION                       \
  EXPORT const u16_t audio_length = (AUDIO_LENGTH); \
  EXPORT f32_t audio_buffer[(AUDIO_LENGTH)*2];      \
  EXPORT void audio_render()

#define RUMBLE_DECLARATION                  \
  EXPORT extern u8_t rumble_buffer[inputs]; \
  EXPORT void rumble_render();

#define RUMBLE_IMPLEMENTATION        \
  EXPORT u8_t rumble_buffer[inputs]; \
  EXPORT void rumble_render()

#define INPUTS_DECLARATION \
  EXPORT extern const u8_t inputs;

#define INPUTS_IMPLEMENTATION \
  EXPORT const u8_t inputs = (quantity);

#define INPUT_DPAD_LEFT_DECLARATION \
  EXPORT extern const u8_t input_dpad_left[inputs];

#define INPUT_DPAD_LEFT_IMPLEMENTATION \
  EXPORT const u8_t input_dpad_left[inputs];

#define INPUT_DPAD_RIGHT_DECLARATION \
  EXPORT extern const u8_t input_dpad_right[inputs];

#define INPUT_DPAD_RIGHT_IMPLEMENTATION \
  EXPORT const u8_t input_dpad_right[inputs];

#define INPUT_DPAD_UP_DECLARATION \
  EXPORT extern const u8_t input_dpad_up[inputs];

#define INPUT_DPAD_UP_IMPLEMENTATION \
  EXPORT const u8_t input_dpad_up[inputs];

#define INPUT_DPAD_DOWN_DECLARATION \
  EXPORT extern const u8_t input_dpad_down[inputs];

#define INPUT_DPAD_DOWN_IMPLEMENTATION \
  EXPORT const u8_t input_dpad_down[inputs];

#define INPUT_FACE_LEFT_DECLARATION \
  EXPORT extern const u8_t input_face_left[inputs];

#define INPUT_FACE_LEFT_IMPLEMENTATION \
  EXPORT const u8_t input_face_left[inputs];

#define INPUT_FACE_RIGHT_DECLARATION \
  EXPORT extern const u8_t input_face_right[inputs];

#define INPUT_FACE_RIGHT_IMPLEMENTATION \
  EXPORT const u8_t input_face_right[inputs];

#define INPUT_FACE_UP_DECLARATION \
  EXPORT extern const u8_t input_face_up[inputs];

#define INPUT_FACE_UP_IMPLEMENTATION \
  EXPORT const u8_t input_face_up[inputs];

#define INPUT_FACE_DOWN_DECLARATION \
  EXPORT extern const u8_t input_face_down[inputs];

#define INPUT_FACE_DOWN_IMPLEMENTATION \
  EXPORT const u8_t input_face_down[inputs];

#define INPUT_TRIGGER_LEFT_DECLARATION \
  EXPORT extern const u8_t input_trigger_left[inputs];

#define INPUT_TRIGGER_LEFT_IMPLEMENTATION \
  EXPORT const u8_t input_trigger_left[inputs];

#define INPUT_TRIGGER_RIGHT_DECLARATION \
  EXPORT extern const u8_t input_trigger_right[inputs];

#define INPUT_TRIGGER_RIGHT_IMPLEMENTATION \
  EXPORT const u8_t input_trigger_right[inputs];

#define INPUT_PAUSE_DECLARATION \
  EXPORT extern const u8_t input_pause_right[inputs];

#define INPUT_PAUSE_IMPLEMENTATION \
  EXPORT const u8_t input_pause_right[inputs];

#define STATE_VERSION_DECLARATION \
  EXPORT extern const u16_t state_version;

#define STATE_VERSION_IMPLEMENTATION \
  EXPORT const u16_t state_version = (version);

#define STATE_DECLARATION(name, type)       \
  EXPORT extern type state_##name##_buffer; \
  EXPORT extern const u32_t state_##name##_size;

#define STATE_IMPLEMENTATION(name, type) \
  EXPORT type state_##name##_buffer;     \
  EXPORT const u32_t state_##name##_size = sizeof(type);

#define STATE_ARRAY_DECLARATION(name, type, quantity) \
  EXPORT extern type state_##name##_buffer[quantity]; \
  EXPORT extern const u32_t state_##name##_size;

#define STATE_ARRAY_IMPLEMENTATION(name, type, quantity) \
  EXPORT type state_##name##_buffer[quantity];           \
  EXPORT const u32_t state_##name##_size = sizeof(type) * quantity;
