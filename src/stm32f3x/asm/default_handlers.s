.syntax unified
.thumb

//.global reset_handler
.global nmi_handler
.global hard_fault_handler
.global mem_manage_handler
.global bus_fault_handler
.global usage_fault_handler
.global svc_handler
.global debug_mon_handler
.global pendsv_handler
.global sys_tick_handler

.weak reset_handler
.weak nmi_handler
.weak hard_fault_handler
.weak mem_manage_handler
.weak bus_fault_handler
.weak usage_fault_handler
.weak svc_handler
.weak debug_mon_handler
.weak pendsv_handler
.weak sys_tick_handler

.text
.align

//reset_handler: b reset_handler
.thumb_func 
nmi_handler: b nmi_handler

.thumb_func 
hard_fault_handler: b hard_fault_handler

.thumb_func 
mem_manage_handler: b mem_manage_handler

.thumb_func 
bus_fault_handler: b bus_fault_handler

.thumb_func 
usage_fault_handler: b usage_fault_handler

.thumb_func 
svc_handler: b svc_handler

.thumb_func 
debug_mon_handler: b debug_mon_handler

.thumb_func 
pendsv_handler: b pendsv_handler

.thumb_func 
sys_tick_handler: b sys_tick_handler
