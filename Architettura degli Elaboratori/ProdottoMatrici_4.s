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

.text  ;Loop Unrolling, Rimozione colonne B
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
        MUL.D   f5, f1, f2      ; a[i] * b[i]
		MUL.D   f6, f3, f4      ; a[i] * b[i]
        ADD.D   f0, f5, f6      ; p = p + a[i] * b[i] (risultato parziale)
		S.D     f0, 0(r3)       ; salva il risultato 
        MUL.D   f0, f0, f7      ; resetta il risultato parziale
		L.D     f2, 8(r2)       ; leggi b[i]
		L.D     f4, 24(r2)      ; leggi b[i]
        MUL.D   f5, f1, f2      ; a[i] * b[i]
		MUL.D   f6, f3, f4      ; a[i] * b[i]
        ADD.D   f0, f5, f6      ; p = p + a[i] * b[i] (risultato parziale)
		S.D     f0, 8(r3)       ; salva il risultato 
        MUL.D   f0, f0, f7      ; resetta il risultato parziale
		DADDI   r3, r3, 16		; scorri registro risultati di C
	
righe:	
		DADDI r1, r1, 16        ; riporta puntatore A alla seconda riga
		DADDI r5, r5, -1		; decrementa contatore righe A
		BNEZ  r5, loop			; ripeti se contatore righe di A diverso da 0
	
end:	HALT