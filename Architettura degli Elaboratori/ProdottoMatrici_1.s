.data
; MATRICE A (2x2)
a:      .double 4.3, 2.1, 3.3, 5.2
; MATRICE B (2x2)
b:      .double 2.3, 1.1, 4.3, 6.2
; MATRICE C (2x2) (risultato)
c:      .double 0, 0, 0, 0
;COLONNE A 
n:      .word   2
;RIGHE A	
o:      .word   2
;COLONNE B
m:      .word   2
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
        DADDI   r2, r2, 16      ; scorri elemento B
        DADDI   r4, r4, -1      ; decrementa contatore colonne A
		BNEZ    r4, loop        ; ripeti se contatore colonne A diverso da 0
		S.D     f0, 0(r3)       ; salva il risultato 
        MUL.D   f0, f0, f3      ; resetta il risultato parziale

puntatori:	
		DADDI   r3, r3, 8		; scorri registro risultati di C
		DADDI   r2, r2, -24		; riporta puntatore B all inizio + 1
		DADDI   r1, r1, -16		; riporta puntatore A all inizio
		DADDI   r4, r4, 2		; resetta contatore colonne A
		DADDI   r6, r6, -1		; decrementa contatore colonne B
		BNEZ 	r6, loop		; ripeti se contatore colonne B diverso da 0
	
righe:	
		DADDI r1, r1, 16        ; riporta puntatore A alla seconda riga
		DADDI r2, r2, -16		; riporta puntatore B all inizio
		DADDI r6, r6, 2			; resetta numero di colonne B
		DADDI r5, r5, -1		; decrementa contatore righe A
		BNEZ  r5, loop			; ripeti se contatore righe di A diverso da 0
	
end:	HALT