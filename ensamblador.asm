.data

#varibles globlaes

	espacio : .ascii "\n"
	 
.text

main:





##deaclara paramtros $a1 ,$a2

addi $a1 ,$zero,5 
addi $a2, $zero,3

# declarra varible 

addi $s0,$zero,5
addi $s1,$zero,6

# imprime la suma de doa numeros

#add $s2,$s0,$s1 #suma 

#imprime la suma 
#li $v0, 1
#add $a0 ,$zero,$s2
#syscall 

#invocar una funcion 
	

	#segunda funcion invocar
	jal suma
	li $v0,1
	add $a0,$v1,0 #lo guarda para impimr 
	syscall 	
	
	jal espacios	## invocacion metodo enter
	li $v0,4
	syscall
	
	#segunda funcion invocar
	jal rest
	li $v0,1
	add $a0,$v1,0 #lo guarda para impimr 
	syscall 
	
	jal espacios		## invocacion metodo enter
	li $v0,4
	syscall
	
	#segunda funcion invocar
	jal multi
	li $v0,1
	add $a0,$v1,0 #lo guarda para impimr 
	syscall 
	
	jal espacios		## invocacion metodo enter
	li $v0,4
	syscall
	
	#segunda funcion invocar
	jal divi
	li $v0,1
	add $a0,$v1,0 #lo guarda para impimr 
	syscall 
	
	

# termina el programa 
li $v0,10
syscall

#fima de una funcion
#	nombreFuncion:
#	.... 	
#	jr $ra

	suma:
		add $v1,$a1 ,$a2
		jr $ra

	rest:
		sub $v1,$a1,$a2
		jr  $ra
	multi:
		mul $v1,$a1,$a2
		jr  $ra
	divi:
		div $v1,$a1,$a2
		jr  $ra
		
	espacios:
		li $v0 4
		la $a0,espacio
		jr $ra	
 
#crear una funcion q imprime la varible 
	 
	 
	 
	 
#APUNTES 
# lw $t0 , 32[$s2]    :  A[8 ]   caga varible en memoria que este declada en entre .data y  .text
# sw $s1 , 100($s2)  : arre[$s2+100] asigna 	 

#registros
# $s0 alamce un operador en regirstor de memoria


#imprimer 

	 
