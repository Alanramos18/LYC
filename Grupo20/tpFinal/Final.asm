include macros2.asm
include number.asm

.MODEL LARGE
.386
.STACK200h

.DATA

nombre     dd         ?         
num        dd         ?         
num2       dd         9         
may        dd         18        
men        dd         1         
alan       dd         alan      
enero      dd         18        
mayo       dd         12        
julio      dd         18        
oct        dd         18        
slo        dd         18        
sla        dd         18        

.CODE

mov AX, @DATA
mov DS, AX
mov es,ax

FILD 9
FISTP num2
FILD 18
FISTP may
FILD 1
FISTP men
FILD 1
FISTP men
FLD men
FCOMP 20
FSTSW AX
SAHF
JNE end_if
FLD men
FCOMP 30
FSTSW AX
SAHF
JNE end_if
FILD 18
FISTP enero
end_if:
FLD num
FCOMP 8
FSTSW AX
SAHF
JNA end_if
FLD num
FCOMP 10
FSTSW AX
SAHF
JG else_part
then_part:
FILD 12
FISTP mayo
else_part:
FILD 18
FISTP julio
end_if:
begin_while:
FLD num
FCOMP 0
FSTSW AX
SAHF
JNE end_while
FILD 18
FISTP oct
JMP begin_while
end_while:
FILD 1
FISTP temp
begin_while:
FLD temp
FCOMP 6
FSTSW AX
SAHF
JG end_while
FILD 18
FISTP slo
FLD temp
FLD 2
FADD
FSTP temp
FFREE
JMP begin_while
end_while:
FLD 1
FLD 1
FADD
FSTP @num
FFREE
FILD 1
FISTP @max
FILD 2
FISTP @aux
FLD @aux
FCOMP @max
FSTSW AX
SAHF
JNA end_if
FILD @aux
FISTP @max
end_if:
FILD temp
FISTP @aux
FLD @aux
FCOMP @max
FSTSW AX
SAHF
JNA end_if
FILD @aux
FISTP @max
end_if:
FLD @num
FCOMP @max
FSTSW AX
SAHF
JNE else_part
then_part:
FILD 1
FISTP @true
else_part:
FILD 0
FISTP @true
end_if:
FLD @true
FCOMP 0
FSTSW AX
SAHF
JNE end_if
FILD 18
FISTP sla
end_if:

mov ax, 4c00h
int 21h
END