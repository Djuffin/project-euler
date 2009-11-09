(define (get-digit x n)
  (remainder (quotient x (expt 10 n)) 10))

(define (polindrom? a)
  (and (= (get-digit a 0) (get-digit a 5))
       (= (get-digit a 1) (get-digit a 4))
       (= (get-digit a 2) (get-digit a 3))))

(define (has-3-digits? x)
  (and (>= x 100) (<= x 999)))


(define (mult2x3? x)
  (define (iter guess)
     (if (has-3-digits? guess)
      (if (and
           (= (remainder x guess) 0)
           (has-3-digits? (quotient x guess)))
          #t
          (iter (- guess 1)))
      #f))
  (iter 999)) 
    
  
(define (task n)
  (if (and (polindrom? n) (mult2x3? n)) 
      n
      (task (- n 1))))
      
(task 999999)
