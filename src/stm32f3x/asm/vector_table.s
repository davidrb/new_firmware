.syntax unified 
.section vectors
.globl __vector_table
__vector_table:
.long 0x20008000     // initial stack pointer
.long reset_handler
.long nmi_handler
.long hard_fault_handler
.long mem_manage_handler
.long bus_fault_handler
.long usage_fault_handler
.long 0
.long 0
.long 0
.long 0
.long svc_handler
//.long debug_mon_handler
.long 0
.long 0
.long pendsv_handler
.long sys_tick_handler
