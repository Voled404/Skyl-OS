#include <stdint.h>
#include <terminal_io.h>
#include <isrs.h>

typedef struct {
    // Pushed by pushad
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    // Pushed by CPU
    uint32_t eip, cs, eflags;
} registers_t;

void syscall_echo_isr(registers_t *regs) {
    printf("%c", regs->eax);
    return;
}






