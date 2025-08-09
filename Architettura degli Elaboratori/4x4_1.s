.data
; MATRICE A (4x4)
a:      .double 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8
; MATRICE B (4x4)
b:      .double 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8
; MATRICE C (4x4) (risultato)
c:      .double 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
;COLONNE A 
n:      .word   4
;RIGHE A	
o:      .word   4
;COLONNE B
m:      .word   4
;PARZIALE
p:      .double 0

.text
start:  
		DADDI   r1, r0, a       ; punta al primo elemento della matrice A
        DADDI   r2, r0, b       ; punta al primo elemento della matrice B
        DADDI   r3, r0, c       ; punta al primo elemento della matrice C
        LW      r4, n(r0)       ; carica il numero di colonne di A
        LW      r5, o(r0)       ; carica il numero di righe di A
		LW      r6, m(r0)       ; carica il numero di colonne di B
		L.D 	f0, p(r0)       ; inizializzazione parziale

loop:   
		L.D 	f1, 0(r1)       ; leggi a[i]
        L.D     f2, 0(r2)       ; leggi b[i]
        MUL.D   f1, f1, f2      ; a[i] * b[i]
        ADD.D   f0, f0, f1      ; p = p + a[i] * b[i] (risultato parziale)
		DADDI   r1, r1, 8       ; scorri elemento A
        DADDI   r2, r2, 32      ; scorri elemento B
        DADDI   r4, r4, -1      ; decrementa contatore colonne A
		BNEZ    r4, loop        ; ripeti se contatore colonne A diverso da 0
		S.D     f0, 0(r3)       ; salva il risultato 
        MUL.D   f0, f0, f3      ; resetta il risultato parziale

puntatori:	
		DADDI   r3, r3, 8		; scorri registro risultati di C
		DADDI   r2, r2, -120		; riporta puntatore B all inizio + 1
		DADDI   r1, r1, -32		; riporta puntatore A all inizio
		DADDI   r4, r4, 4		; resetta contatore colonne A
		DADDI   r6, r6, -1		; decrementa contatore colonne B
		BNEZ 	r6, loop		; ripeti se contatore colonne B diverso da 0
	
righe:	
	DADDI r1, r1, 32        	; riporta puntatore A alla seconda riga
	DADDI r2, r2, -32			; riporta puntatore B all inizio
	DADDI r6, r6, 4				; resetta numero di colonne B
	DADDI r5, r5, -1			; decrementa contatore righe A
	BNEZ  r5, loop				; ripeti se contatore righe di A diverso da 0
	
end:	HALT