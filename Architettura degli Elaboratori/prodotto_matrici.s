.data
; MATRICE A (2x2)
a:      .double 4.3, 2.1, 3.3, 5.2
; MATRICE B (2x2)
b:      .double 2.3, 1.1, 4.3, 6.2
; MATRICE C (2x2) (risultato)
c:      .double 0, 0, 0, 0
;PARZIALE
p:      .double 0

.text  
start:  
		    DADDI   r1, r0, a       ; punta al primo elemento della matrice A
        DADDI   r2, r0, b       ; punta al primo elemento della matrice B
        DADDI   r3, r0, c       ; punta al primo elemento della matrice C
        L.D 	f0, p(r0)       ; inizializzazione parziale

		    ; Caricamento prima riga di A e B
		    L.D 	f1, 0(r1)       ; leggi a[0][0]
        L.D   f2, 0(r2)       ; leggi b[0][0]
		    L.D 	f3, 8(r1)       ; leggi a[0][1]
        L.D   f4, 8(r2)       ; leggi b[0][1]
		    ; Caricamento seconda riga di A e B
		    L.D 	f5, 16(r1)      ; leggi a[1][0]
        L.D   f6, 16(r2)      ; leggi b[1][0]
		    L.D 	f7, 24(r1)      ; leggi a[1][1]
		    L.D   f8, 24(r2)      ; leggi b[1][1]
		
        ; Moltiplicazioni per la prima riga di C
        MUL.D   f9, f1, f2      ; a[0][0] * b[0][0]
        MUL.D   f10, f3, f4     ; a[0][1] * b[0][1]
        MUL.D   f11, f1, f6     ; a[0][0] * b[1][0]
        MUL.D   f12, f3, f8     ; a[0][1] * b[1][1]
        ; Moltiplicazioni per la seconda riga di C
        MUL.D   f15, f5, f2     ; a[1][0] * b[0][0]
        MUL.D   f16, f7, f4     ; a[1][1] * b[0][1]
        MUL.D   f17, f5, f6     ; a[1][0] * b[1][0]
        MUL.D   f18, f7, f8     ; a[1][1] * b[1][1]
		
        ; Somme per la prima riga di C
        ADD.D   f13, f9, f10    ; p = p + a[0][0] * b[0][0] + a[0][1] * b[0][1]
        ADD.D   f14, f11, f12   ; p = p + a[0][0] * b[1][0] + a[0][1] * b[1][1]
        ; Somme per la seconda riga di C
        ADD.D   f19, f15, f16   ; p = p + a[1][0] * b[0][0] + a[1][1] * b[0][1]
        ADD.D   f20, f17, f18   ; p = p + a[1][0] * b[1][0] + a[1][1] * b[1][1]		
		
        ; Salvataggio della prima riga di C
        S.D     f13, 0(r3)      ; salva il risultato in c[0][0]
        S.D     f14, 8(r3)      ; salva il risultato in c[0][1]
        ; Salvataggio della seconda riga di C
        S.D     f19, 16(r3)     ; salva il risultato in c[1][0]
        S.D     f20, 24(r3)     ; salva il risultato in c[1][1]

end:	HALT
