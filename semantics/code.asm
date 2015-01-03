.data
newline:	.asciiz "\n"

.text
finaltest0:
subu $sp,$sp,352
sw $ra,40($sp)
sw $fp,36($sp)
addu $fp,$sp,300
s.s $f12,32($sp)
s.s $f13,28($sp)
s.s $f14,24($sp)
sw $a0,20($sp)
sw $a1,16($sp)
sw $a2,12($sp)
sw $a3,8($sp)

move $t0,$s7
addu $t0,$t0,4
move $t3,$t0

li $t0,20
add $t0,$t0,1
mul $t0,$t0,4
move $a0,$t0
li $v0,9
syscall
sw $v0,-20($fp)
lw $t0,-20($fp)
sw $t0,0($t3)
move $t0,$s7
addu $t0,$t0,0
move $t4,$t0

li $t0,'a'
sw $t0,0($t4)
.data
__print0:	.asciiz "created using default constructor"
.text
la $a0,__print0
li $v0,4
syscall

la $a0,newline
li $v0,4
syscall
move $t0,$s7
addu $t0,$t0,0
move $t5,$t0

lb $a0,0($t5)
li $v0,11
syscall
la $a0,newline
li $v0,4
syscall
finaltest0end:
lw $ra,40($sp)
lw $fp,36($sp)
l.s $f12,32($sp)
l.s $f13,28($sp)
l.s $f14,24($sp)
lw $a0,20($sp)
lw $a1,16($sp)
lw $a2,12($sp)
lw $a3,8($sp)
addu $sp,$sp,352
jr $ra

finaltest1:
subu $sp,$sp,352
sw $ra,40($sp)
sw $fp,36($sp)
addu $fp,$sp,300
s.s $f12,32($sp)
s.s $f13,28($sp)
s.s $f14,24($sp)
sw $a0,20($sp)
sw $a1,16($sp)
sw $a2,12($sp)
sw $a3,8($sp)

jal finaltest0
.data
__print1:	.asciiz "created using parameterised constructor"
.text
la $a0,__print1
li $v0,4
syscall

la $a0,newline
li $v0,4
syscall
move $t0,$s7
addu $t0,$t0,0
move $t6,$t0

lw $t0,20($sp)
sw $t0,0($t6)
finaltest1end:
lw $ra,40($sp)
lw $fp,36($sp)
l.s $f12,32($sp)
l.s $f13,28($sp)
l.s $f14,24($sp)
lw $a0,20($sp)
lw $a1,16($sp)
lw $a2,12($sp)
lw $a3,8($sp)
addu $sp,$sp,352
jr $ra

init2:
subu $sp,$sp,352
sw $ra,40($sp)
sw $fp,36($sp)
addu $fp,$sp,300
s.s $f12,32($sp)
s.s $f13,28($sp)
s.s $f14,24($sp)
sw $a0,20($sp)
sw $a1,16($sp)
sw $a2,12($sp)
sw $a3,8($sp)

li $a0,12
li $v0,9
syscall
sw $s7,4($sp)
move $s7,$v0
sw $v0,-16($fp)
jal finaltest0
lw $s7,4($sp)
lw $t0,-16($fp)
sw $t0,-20($fp)
addu $t0,$t0,0
move $t7,$t0

lw $t0,0($t7)
sb $t0,-24($fp)
li $t0,0
sw $t0,-12($fp)
L2:
lw $t0,-12($fp)
move $t1,$s0
slt $t0,$t0,$t1
sw $t0,-28($fp)
bnez $t0,L0
b L1
L3:
b L2
L0:
li $t0,4
lw $t1, -12($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, 20($sp)
add $t8, $t0, $t1

lw $t0,-24($fp)
sw $t0,0($t8)
lb $t0,-24($fp)
sb $t0,-32($fp)
add $t0,$t0,1
sb $t0,-24($fp)
lw $t0,-12($fp)
add $t0,$t0,1
sw $t0,-12($fp)
b L3
L1:
li $t0,0
sw $t0,-12($fp)
L6:
b L4
L7:
b L6
L4:
lw $t0,-12($fp)
move $t1,$s0
sge $t0,$t0,$t1
sw $t0,-36($fp)
beqz $t0,L8
b L5

L8:
li $t0,4
lw $t1, -12($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, 20($sp)
add $t9, $t0, $t1

lb $a0,0($t9)
li $v0,11
syscall
.data
__print2:	.asciiz " "
.text
la $a0,__print2
li $v0,4
syscall

lw $t0,-12($fp)
sw $t0,-40($fp)
add $t0,$t0,1
sw $t0,-12($fp)
b L7
L5:
la $a0,newline
li $v0,4
syscall
li $a0,12
li $v0,9
syscall
move $s7,$v0
li $a0,'e'
sw $v0,-44($fp)

jal finaltest1
lw $t0,-44($fp)
sw $t0,-48($fp)
addu $t0,$t0,0
move $t3,$t0

lw $t0,0($t3)
sw $t0,-24($fp)
li $t0,0
sw $t0,-12($fp)
L11:
lw $t0,-12($fp)
move $t1,$s0
slt $t0,$t0,$t1
sw $t0,-52($fp)
bnez $t0,L9
b L10
L12:
b L11
L9:
li $t0,4
lw $t1, -12($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, 20($sp)
add $t4, $t0, $t1

lw $t0,-24($fp)
sw $t0,0($t4)
lb $t0,-24($fp)
sb $t0,-56($fp)
add $t0,$t0,1
sb $t0,-24($fp)
lw $t0,-12($fp)
add $t0,$t0,1
sw $t0,-12($fp)
b L12
L10:
li $t0,0
sw $t0,-12($fp)
L15:
b L13
L16:
b L15
L13:
lw $t0,-12($fp)
move $t1,$s0
sge $t0,$t0,$t1
sw $t0,-60($fp)
beqz $t0,L17
b L14

L17:
li $t0,4
lw $t1, -12($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, 20($sp)
add $t5, $t0, $t1

lb $a0,0($t5)
li $v0,11
syscall
.data
__print3:	.asciiz " "
.text
la $a0,__print3
li $v0,4
syscall

lw $t0,-12($fp)
sw $t0,-64($fp)
add $t0,$t0,1
sw $t0,-12($fp)
b L16
L14:
la $a0,newline
li $v0,4
syscall
init2end:
lw $ra,40($sp)
lw $fp,36($sp)
l.s $f12,32($sp)
l.s $f13,28($sp)
l.s $f14,24($sp)
lw $a0,20($sp)
lw $a1,16($sp)
lw $a2,12($sp)
lw $a3,8($sp)
addu $sp,$sp,352
jr $ra

main:
subu $sp,$sp,352
sw $ra,40($sp)
sw $fp,36($sp)
addu $fp,$sp,300
s.s $f12,32($sp)
s.s $f13,28($sp)
s.s $f14,24($sp)
sw $a0,20($sp)
sw $a1,16($sp)
sw $a2,12($sp)
sw $a3,8($sp)

li $t0,12
move $s0,$t0
move $t0,$s0
add $t0,$t0,1
mul $t0,$t0,4
move $a0,$t0
li $v0,9
syscall
sw $v0,-12($fp)
lw $t0,-12($fp)
sw $t0,-16($fp)
lw $a0,-16($fp)

jal init2
li $t0,20
addu $t0,$t0,1
mul $t0,$t0,4
move $a0,$t0
li $v0,9
syscall
sw $v0,-24($fp)
lw $t0,-24($fp)
sw $t0,-28($fp)
li $t0,0
sw $t0,-32($fp)
L20:
lw $t0,-32($fp)
li $t1,20
slt $t0,$t0,$t1
sw $t0,-40($fp)
bnez $t0,L18
b L19
L21:
lw $t0,-32($fp)
sw $t0,-44($fp)
add $t0,$t0,1
sw $t0,-32($fp)
b L20
L18:
li $t0,4
lw $t1, -32($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, -28($fp)
add $t6, $t0, $t1

li $a0,12
li $v0,9
syscall
sw $s7,4($sp)
move $s7,$v0
sw $v0,-48($fp)
jal finaltest0
lw $s7,4($sp)
lw $t0,-48($fp)
sw $t0,0($t6)
li $t0,'a'
sb $t0,-52($fp)
li $t0,0
sw $t0,-36($fp)
L24:
lw $t0,-36($fp)
li $t1,20
slt $t0,$t0,$t1
sw $t0,-56($fp)
bnez $t0,L22
b L23
L25:
lw $t0,-36($fp)
sw $t0,-60($fp)
add $t0,$t0,1
sw $t0,-36($fp)
b L24
L22:
li $t0,4
lw $t1, -32($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, -28($fp)
add $t7, $t0, $t1

lw $t0,0($t7)
addu $t0,$t0,4
move $t8,$t0

li $t0,4
lw $t1, -36($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, 0($t8)
add $t9, $t0, $t1

lb $t0,-52($fp)
sb $t0,-64($fp)
add $t0,$t0,1
sb $t0,-52($fp)
lw $t0,-64($fp)
sw $t0,0($t9)
li $t0,4
lw $t1, -32($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, -28($fp)
add $t3, $t0, $t1

lw $t0,0($t3)
addu $t0,$t0,4
move $t4,$t0

li $t0,4
lw $t1, -36($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, 0($t4)
add $t5, $t0, $t1

lb $a0,0($t5)
li $v0,11
syscall
.data
__print4:	.asciiz " "
.text
la $a0,__print4
li $v0,4
syscall

b L25
L23:
la $a0,newline
li $v0,4
syscall
b L21
L19:

mainend:
li $v0,10
syscall
