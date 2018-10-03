/*\
 * Boot:
 * Just what is strictly necessary to do some testing.
 * The .org values are specified in the MicroBlaze data-sheet.
\*/
	.extern main
	.extern _stack_top
	.globl  __boot
	.ent    __boot

        .org 0x00
__boot:
        bri .Lgo

        .org 0x08
_exception_handler: /* Self-loop (nothing better to do) */
        bri _exception_handler

        .org 0x10
_interrupt_handler:
        bri __interrupt_handler

        .org 0x18
_break_handler: /* Self-loop (nothing better to do) */
        bri _break_handler

        .org 0x20
	.globl _hw_exception_handler
_hw_exception_handler:
	/* Uncomment the following line to get an invalid instruction */
	/* .byte 0x50, 0x0, 0x0, 0x0 */
        bri _hw_exception_handler

        .text
        .org 0x50
.Lgo:
	/* Set stack pointer (see ldscript) */
	addik   r1, r0, _stack_top
	/* Start main function */
	bri     main
_boot_end:
	bri 	_boot_end
