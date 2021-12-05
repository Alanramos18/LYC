include macros2.asm
include number.asm

.MODEL LARGE
.386
.STACK200h

.DATA

nombre     dd         ?         
num        dd         ?         
alan       dd         "alan"    
valor      dd         18        

.CODE

mov AX, @DATA
mov DS, AX
mov es,ax

FILD "alan"
FISTP alan
FILD 18
FISTP valor
FILD 88
FISTP num
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
displayString "El numero es mayor"
else_part:
displayString "El numero es menor"
end_if:
FLD valor
FCOMP 20
FSTSW AX
SAHF
JNE end_if
FLD valor
FCOMP 30
FSTSW AX
SAHF
JNE end_if
FILD "holis"
FISTP nombre
end_if:
begin_while:
FLD num
FCOMP 0
FSTSW AX
SAHF
JNE end_while
FILD 18
FISTP num
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
FISTP num
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
FILD valor
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
GetInteger num
end_if:

mov ax, 4c00h
int 21h
END