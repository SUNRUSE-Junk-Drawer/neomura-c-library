# neomura > c game library

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

the REFRESH_RATE macro exports the specified number of hertz as the u16_t
refresh_rate.

```c
// specify a refresh rate of 60hz.
REFRESH_RATE(60)
```

### elapse event

the ELAPSE macro exports the following function body as the elapse event
handler.

```c
ELAPSE() {
  // the body of the elapse event.
}
```

### video

the VIDEO macro exports its arguments as video_width and video_height, and the
following function body as the video_render event handler (in which the
video_buffer export will be available for writing).

```c
VIDEO(270, 180) {
  // the body of the video_render event.
  // video_buffer is available for writing here.
}
```

### audio

the AUDIO macro exports its argument as audio_length, and the following function
body as the audio_render event handler (in which the audio_buffer export will be
available for writing).

```c
AUDIO(735) {
  // the body of the audio_render event.
  // audio_buffer is available for writing here.
}
```

### rumble

the RUMBLE macro exports the following function body as the rumble_render event
handler (in which the rumble_buffer export will be available for writing).

```c
RUMBLE() {
  // the body of the rumble_render event.
  // rumble_buffer is available for writing here.
}
```

### input

the INPUTS macro exports the specified number of gamepads as the u16_t inputs.

then, the INPUT_* macros export the associated input_* u8_t buffers, which can
also be read from in your game:

| macro               | export/c variable        |
| ------------------- | ------------------------ |
| INPUT_DPAD_LEFT     | input_dpad_left          |
| INPUT_DPAD_RIGHT    | input_dpad_right         |
| INPUT_DPAD_UP       | input_dpad_up            |
| INPUT_DPAD_DOWN     | input_dpad_down          |
| INPUT_FACE_LEFT     | input_face_left          |
| INPUT_FACE_RIGHT    | input_face_right         |
| INPUT_FACE_UP       | input_face_up            |
| INPUT_FACE_DOWN     | input_face_down          |
| INPUT_TRIGGER_LEFT  | input_face_trigger_left  |
| INPUT_TRIGGER_RIGHT | input_face_trigger_right |
| INPUT_PAUSE         | input_dpad_pause         |

```c
// specify that four gamepads exist.
INPUTS(4)

// input_dpad_left, input_dpad_right and input_face_down are declared as
// u8_t[4].
INPUT_DPAD_LEFT()
INPUT_DPAD_RIGHT()
INPUT_FACE_DOWN()
```
