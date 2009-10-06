(define (sum-of-squeres n)
  (/ (* n (+ n 1) (+ ( * 2 n) 1)) 6))

(define (squere x) (* x x))

(define (squere-of-sum n)
  (squere (/ (* n (+ n 1)) 2)))

(define (task n)
  (- (squere-of-sum n) (sum-of-squeres n)))

(task 100)