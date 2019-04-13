	.data
m1: .asciiz "dummy_buffer"
m2:	.asciiz "hello_world\n"
m3:	.asciiz "The buffer message: "
m4: .asciiz "The source message: "
	
	.text
main:
	la			$a0, m1
	la			$a1, m2
	jal			strcpy
	li			$v0, 4
	la			$a0, m3
	syscall
	li			$v0, 4
	la			$a0, m1
	syscall
	li			$v0, 4
	la			$a0, m4
	syscall
	li			$v0, 4
	la			$a0, m2
	syscall
	li			$v0, 10
	syscall

strcpy:
	addi		$sp, $sp, -4
	sw			$s0, 0($sp)
	add			$s0, $zero, $zero
	j			L1
L1:
	add			$t1, $s0, $a1
	lb			$t2, 0($t1)
	add			$t3, $s0, $a0
	sb			$t2, 0($t3)
	beq			$t2, $zero, L2
	addi		$s0, $s0, 1
	j			L1
L2:
	lw			$s0, 0($sp)
	addi		$sp, $sp, 4
	jr			$ra


