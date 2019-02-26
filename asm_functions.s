				AREA asm_functions, CODE, READONLY				
                EXPORT  overflow
overflow
				; save current SP for a faster access 
				; to parameters in the stack
				MOV   r12, sp
				; save volatile registers
				STMFD sp!,{r4-r8,r10-r11,lr}				
main			
				sub r1,#1
				MOV r2,r1	;iterator
				MOV r3,#0   ;sum
				MOV r5,#0	;index
loop			LDR r4,[r0,r5]	;load value from vector
				adds r3,r3,r4
				bvs return_overflow
				bvc return_carry
				subs r2,#1
				add r5,#4
				bne loop

otherwise		mov r0,#2
				b end_asmf

return_overflow
				mov r0,#0
				b end_asmf
				
return_carry
				mov r0,#1
				b end_asmf

end_asmf
				; setup a value for R0 to return
				; restore volatile registers
				LDMFD sp!,{r4-r8,r10-r11,pc}
				
                END
					
					
