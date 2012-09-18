/*
 *
 * Automatically generated file; DO NOT EDIT.
 * Linux/i386 3.2.28 Kernel Configuration
 *
 */
/*
 * Helper macros to use CONFIG_ options in C expressions. Note that
 * these only work with boolean and tristate options.
 */
/*
 * IS_ENABLED(CONFIG_FOO) evaluates to 1 if CONFIG_FOO is set to 'y' or 'm',
 * 0 otherwise.
 *
 */



/*
 * IS_BUILTIN(CONFIG_FOO) evaluates to 1 if CONFIG_FOO is set to 'y', 0
 * otherwise. For boolean options, this is equivalent to
 * IS_ENABLED(CONFIG_FOO).
 */


/*
 * IS_MODULE(CONFIG_FOO) evaluates to 1 if CONFIG_FOO is set to 'm', 0
 * otherwise.
 */
/*
 * wakeup.ld
 *
 * Linker script for the real-mode wakeup code
 */
/*
 * Definitions for the wakeup data structure at the head of the
 * wakeup code.
 */






/* Wakeup behavior bits */
OUTPUT_FORMAT("elf32-i386", "elf32-i386", "elf32-i386")
OUTPUT_ARCH(i386)
ENTRY(_start)
SECTIONS
{
 . = 0;
 .jump : {
  *(.jump)
 } = 0x90909090
 . = 8;
 .header : {
  *(.header)
 }
 . = ALIGN(16);
 .text : {
   *(.text*)
 } = 0x90909090
 . = ALIGN(16);
 .rodata : {
  *(.rodata*)
 }
 .videocards : {
  video_cards = .;
  *(.videocards)
  video_cards_end = .;
 }
 . = ALIGN(16);
 .data : {
   *(.data*)
 }
 . = ALIGN(16);
 .bss : {
  __bss_start = .;
  *(.bss)
  __bss_end = .;
 }
 .signature : {
  *(.signature)
 }
 _end = .;
 /DISCARD/ : {
  *(.note*)
 }
}
