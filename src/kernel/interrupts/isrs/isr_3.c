#include <stdint.h>
#include <terminal_io.h>
#include <isrs.h>

typedef struct {
    // Pushed by pushad (order must match your assembly frame)
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    // Pushed by CPU
    uint32_t eip, cs, eflags;
} registers_t;

void isr_3(registers_t *regs)
{
    printf("\n=== DEBUG BREAKPOINT ===\n");
    kprint("EAX: "); printf("%x\n", regs->eax);
    kprint("EBX: "); printf("%x\n", regs->ebx);
    kprint("EIP: "); printf("%x\n", regs->eip);

    // Neo EAX
    regs->eax = 0xFE1DA5;

    kprint("New EAX set to: "); printf("%x\n", regs->eax);
    kprint("System Halted for inspection.\n");
    printf("=== DEBUG BREAKPOINT END ===\n");
}
