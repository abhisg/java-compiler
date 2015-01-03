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

li $t0,302
neg $t0,$t0
sw $t0,-32($fp)
lw $t0,-32($fp)
sw $t0,0($t3)
move $t0,$s7
addu $t0,$t0,8
move $t4,$t0

li $t0,'a'
sw $t0,0($t4)
move $t0,$s7
addu $t0,$t0,12
move $t5,$t0

li $t0,0
sw $t0,0($t5)
move $t0,$s7
addu $t0,$t0,16
move $t6,$t0

li $t0,12345
sw $t0,0($t6)
move $t0,$s7
addu $t0,$t0,20
move $t7,$t0

li $t0,20
add $t0,$t0,1
mul $t0,$t0,4
move $a0,$t0
li $v0,9
syscall
sw $v0,-36($fp)
lw $t0,-36($fp)
sw $t0,0($t7)
.data
__print0:	.asciiz "created using default constructor"
.text
la $a0,__print0
li $v0,4
syscall

la $a0,newline
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
move $t0,$s7
addu $t0,$t0,8
move $t9,$t0

lw $t0,20($sp)
sw $t0,0($t9)
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

li $t0,20
addu $t0,$t0,1
mul $t0,$t0,4
move $a0,$t0
li $v0,9
syscall
sw $v0,-12($fp)
lw $t0,-12($fp)
sw $t0,-16($fp)
li $t0,0
sw $t0,-20($fp)
L2:
lw $t0,-20($fp)
li $t1,20
slt $t0,$t0,$t1
sw $t0,-28($fp)
lw $t0,-28($fp)
bnez $t0,L0
b L1
L3:
lw $t0,-20($fp)
sw $t0,-32($fp)
add $t0,$t0,1
sw $t0,-20($fp)
b L2
L0:
li $t0,4
lw $t1, -20($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, -16($fp)
add $t3, $t0, $t1

li $a0,24
li $v0,9
syscall
sw $s7,4($sp)
move $s7,$v0
sw $v0,-36($fp)
jal finaltest0
lw $s7,4($sp)
lw $t0,-36($fp)
sw $t0,0($t3)
li $t0,'a'
sb $t0,-40($fp)
li $t0,0
sw $t0,-24($fp)
L6:
lw $t0,-24($fp)
li $t1,20
slt $t0,$t0,$t1
sw $t0,-44($fp)
lw $t0,-44($fp)
bnez $t0,L4
b L5
L7:
lw $t0,-24($fp)
sw $t0,-48($fp)
add $t0,$t0,1
sw $t0,-24($fp)
b L6
L4:
li $t0,4
lw $t1, -20($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, -16($fp)
add $t4, $t0, $t1

lw $t0,0($t4)
addu $t0,$t0,20
move $t5,$t0

li $t0,4
lw $t1, -24($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, 0($t5)
add $t6, $t0, $t1

lb $t0,-40($fp)
sb $t0,-52($fp)
add $t0,$t0,1
sb $t0,-40($fp)
lw $t0,-52($fp)
sw $t0,0($t6)
li $t0,4
lw $t1, -20($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, -16($fp)
add $t7, $t0, $t1

lw $t0,0($t7)
addu $t0,$t0,20
move $t8,$t0

li $t0,4
lw $t1, -24($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, 0($t8)
add $t9, $t0, $t1

lb $a0,0($t9)
li $v0,11
syscall
la $a0,newline
li $v0,4
syscall
b L7
L5:
li $t0,4
lw $t1, -20($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, -16($fp)
add $t3, $t0, $t1

lw $t0,0($t3)
addu $t0,$t0,4
move $t4,$t0

lw $a0,0($t4)
li $v0,1
syscall
la $a0,newline
li $v0,4
syscall
li $t0,4
lw $t1, -20($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, -16($fp)
add $t5, $t0, $t1

lw $t0,0($t5)
addu $t0,$t0,8
move $t6,$t0

lb $a0,0($t6)
li $v0,11
syscall
la $a0,newline
li $v0,4
syscall
li $t0,4
lw $t1, -20($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, -16($fp)
add $t7, $t0, $t1

lw $t0,0($t7)
addu $t0,$t0,12
move $t8,$t0

lw $a0,0($t8)
li $v0,1
syscall
la $a0,newline
li $v0,4
syscall
li $t0,4
lw $t1, -20($fp)
addi $t1, $t1, 1
mul $t0,$t0, $t1
lw $t1, -16($fp)
add $t9, $t0, $t1

lw $t0,0($t9)
addu $t0,$t0,16
move $t3,$t0

lw $a0,0($t3)
li $v0,1
syscall
la $a0,newline
li $v0,4
syscall
b L3
L1:

mainend:
li $v0,10
syscall
