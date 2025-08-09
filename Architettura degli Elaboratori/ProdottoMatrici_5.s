.data
; MATRICE A (2x2)
a:      .double 4.3, 2.1, 3.3, 5.2
; MATRICE B (2x2)
b:      .double 2.3, 1.1, 4.3, 6.2
; MATRICE C (2x2) (risultato)
c:      .double 0, 0, 0, 0
;RIGHE A	
o:      .word   2
;PARZIALE
p:      .double 0

.text  ;Instruction Reordering e Register Renaming
start:  
		DADDI   r1, r0, a       ; punta al primo elemento della matrice A
        DADDI   r2, r0, b       ; punta al primo elemento della matrice B
        DADDI   r3, r0, c       ; punta al primo elemento della matrice C
        LW      r5, o(r0)       ; carica il numero di righe di A
		L.D 	f0, p(r0)       ; inizializzazione parziale

loop:   
		L.D 	f1, 0(r1)       ; leggi a[i]
        L.D     f2, 0(r2)       ; leggi b[i]
		L.D 	f3, 8(r1)       ; leggi a[i]
        L.D     f4, 16(r2)      ; leggi b[i]
		L.D     f5, 8(r2)       ; leggi b[i] 
		L.D     f6, 24(r2)      ; leggi b[i]
        MUL.D   f7, f1, f2      ; a[i] * b[i]
		MUL.D   f8, f3, f4      ; a[i] * b[i]
        MUL.D   f9, f1, f5      ; a[i] * b[i]
		MUL.D   f10, f3, f6     ; a[i] * b[i]
		ADD.D   f11, f7, f8     ; p = p + a[i] * b[i] (risultato parziale)
		ADD.D   f12, f9, f10    ; p = p + a[i] * b[i] (risultato parziale)
		DADDI r3, r3, 16		; scorri registro risultati di C
		DADDI r1, r1, 16        ; riporta puntatore A alla seconda riga
		DADDI r5, r5, -1		; decrementa contatore righe A
		S.D   f11, 0(r3)        ; salva il risultato 
		S.D	  f12, 8(r3)        ; salva il risultato 
		BNEZ  r5, loop			; ripeti se contatore righe di A diverso da 0

end:	HALT