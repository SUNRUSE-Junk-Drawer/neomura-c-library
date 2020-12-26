# neomura > c library

single-header gnu89 c library for games for neomura virtual retro games console.

[mit licensed](./license.md).

## installation

add this repository as a git submodule, then include [neomura.h](./neomura.h).

## linker configuration

the following wasm-ld flags are recommended when using this library:

| flag             | reasoning                                          |
| ---------------- | -------------------------------------------------- |
| --no-entry       | neomura games should not have a main function      |
| --export-dynamic | this library will control the selection of exports |

## declarations

### types

the following types are declared to match those in the [neomura specification](https://github.com/neomura/specification/blob/main/api.md#types):

| neomura type | c type |
| ------------ | ------ |
| u8           | u8_t   |
| s8           | s8_t   |
| u16          | u16_t  |
| s16          | s16_t  |
| u32          | u32_t  |
| s32          | s32_t  |
| u64          | u64_t  |
| s64          | s64_t  |
| f32          | f32_t  |
| f64          | f64_t  |

### refresh rate

the REFRESH_RATE_DECLARATION macro, to be used in header (\*.h) files, declares
refresh_rate.

REFRESH_RATE (in hertz) should first be defined as an integer.

```c
#define REFRESH_RATE 60
REFRESH_RATE_DECLARATION
```

the REFRESH_RATE_IMPLEMENTATION macro, to be used in source (\*.c) files,
implements and exports refresh_rate.

```c
REFRESH_RATE_IMPLEMENTATION
```

### elapse event

the ELAPSE_DECLARATION macro, to be used in header (\*.h) files, declares
elapse.

```c
ELAPSE_DECLARATION
```

the ELAPSE_IMPLEMENTATION macro, to be used in source (\*.c) files, implements
and exports elapse.

```c
ELAPSE_IMPLEMENTATION {
  // the body of the elapse event.
}
```

### video

the VIDEO_DECLARATION macro, to be used in header (\*.h) files, declares:

- video_width.
- video_height.
- video_buffer.
- video_render.

VIDEO_WIDTH (in pixel columns) and VIDEO_HEIGHT (in pixel rows) should first be
defined as integers.

```c
#define VIDEO_WIDTH 270
#define VIDEO_HEIGHT 180
VIDEO_DECLARATION
```

the VIDEO_IMPLEMENTATION macro, to be used in source (\*.c) files, implements
and exports:

- video_width.
- video_height.
- video_buffer.
- video_render.

```c
VIDEO_IMPLEMENTATION {
  // the body of the video_render event.
  // video_buffer is available for writing here.
}
```

### audio

the AUDIO_DECLARATION macro, to be used in header (\*.h) files, declares:

- audio_length.
- audio_buffer.
- audio_render.

AUDIO_LENGTH (in samples per channel per refresh rate frame) should first be
defined as an integer.

```c
#define AUDIO_LENGTH 735
AUDIO_DECLARATION
```

the AUDIO_IMPLEMENTATION macro, to be used in source (\*.c) files, implements
and exports:

- audio_length.
- audio_buffer.
- audio_render.

```c
AUDIO_IMPLEMENTATION {
  // the body of the audio_render event.
  // audio_buffer is available for writing here.
}
```

### rumble

the RUMBLE_DECLARATION macro, to be used in header (\*.h) files, declares:

- rumble_buffer.
- rumble_render.

INPUTS (the number of gamepads) should first be defined as an integer.

```c
#define INPUTS 4
RUMBLE_DECLARATION
```

the RUMBLE_IMPLEMENTATION macro, to be used in source (\*.c) files, implements
and exports:

- rumble_buffer.
- rumble_render.

```c
RUMBLE_IMPLEMENTATION {
  // the body of the rumble_render event.
  // rumble_buffer is available for writing here.
}
```

### input

the following macros exist, where \* is "DECLARATION", for header (\*.h) files,
or "IMPLEMENTAITON", for source (\*.c) files:

| macro                  | export/c variable        |
| ---------------------- | ------------------------ |
| INPUTS_\*              | inputs                   |
| INPUT_DPAD_LEFT_\*     | input_dpad_left          |
| INPUT_DPAD_RIGHT_\*    | input_dpad_right         |
| INPUT_DPAD_UP_\*       | input_dpad_up            |
| INPUT_DPAD_DOWN_\*     | input_dpad_down          |
| INPUT_FACE_LEFT_\*     | input_face_left          |
| INPUT_FACE_RIGHT_\*    | input_face_right         |
| INPUT_FACE_UP_\*       | input_face_up            |
| INPUT_FACE_DOWN_\*     | input_face_down          |
| INPUT_TRIGGER_LEFT_\*  | input_face_trigger_left  |
| INPUT_TRIGGER_RIGHT_\* | input_face_trigger_right |
| INPUT_PAUSE_\*         | input_dpad_pause         |

INPUTS (the number of gamepads) should first be defined as an integer.

example header (\*.h) file:

```c
#define INPUTS 4
INPUTS_DECLARATION

// input_dpad_left, input_dpad_right and input_face_down are declared as
// u8_t[4].
INPUT_DPAD_LEFT_DECLARATION
INPUT_DPAD_RIGHT_DECLARATION
INPUT_FACE_DOWN_DECLARATION
```

example source (\*.c) file:

```c
INPUTS_IMPLEMENTATION

INPUT_DPAD_LEFT_IMPLEMENTATION
INPUT_DPAD_RIGHT_IMPLEMENTATION
INPUT_FACE_DOWN_IMPLEMENTATION
```

### state

the following macros exist, where \* is "DECLARATION", for header (\*.h) files,
or "IMPLEMENTAITON", for source (\*.c) files, and # is the name of a state
variable:

| macro            | exports/c variables |
| ---------------- | ------------------- |
| STATE_VERSION_\* | state_version       |
| STATE_\*         | state_#_buffer      |
|                  | state_#_size        |
| STATE_ARRAY_\*   | state_#_buffer      |
|                  | state_#_size        |


STATE_VERSION should first be defined as an integer.

example header (\*.h) file:

```c
#define STATE_VERSION 43.
STATE_VERSION_DECLARATION

// state_example_scalar_buffer is declared as s64_t.
STATE_DECLARATION(example_scalar, s64_t)

// state_example_vector_buffer is declared as s16_t[12].
STATE_ARRAY_DECLARATION(example_vector, s16_t, 12)
```

example source (\*.c) file:

```c
STATE_VERSION_IMPLEMENTATION
STATE_IMPLEMENTATION(example_scalar, s64_t)
STATE_ARRAY_IMPLEMENTATION(example_vector, s16_t, 12)
```
