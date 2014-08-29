/*
Problem 23
A perfect number is a number for which the sum of its proper divisors is 
exactly equal to the number. For example, the sum of the proper divisors 
of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect 
number.

A number n is called deficient if the sum of its proper divisors is less 
than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, 
the smallest number that can be written as the sum of two abundant numbers
is 24. By mathematical analysis, it can be shown that all integers 
greater than 28123 can be written as the sum of two abundant numbers.
However, this upper limit cannot be reduced any further by analysis even 
though it is known that the greatest number that cannot be expressed as 
the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the 
sum of two abundant numbers.
*/

fn is_abundant(x:uint) -> bool {
    let mut result = 1u;
    let mut i = 2;
    while i * i <= x {
        if x % i == 0 {
            result += i;
            let j = x / i;
            if j != i {
                result += j;
            }
        } 
        i += 1;
    }
    result > x
}

fn main() {
    let max_n = 30000u;
    let abundant_numbers : Vec<uint> = 
        range(1, max_n).filter(|x| is_abundant(*x)).collect();
    
    let mut positives : Vec<bool> = Vec::from_elem(max_n, false);

    for i in range(0, abundant_numbers.len()) {
        for j in range(i, abundant_numbers.len()) {
            let sum = *abundant_numbers.get(i) + *abundant_numbers.get(j);
            if sum < positives.len() {
                *positives.get_mut(sum) = true;
            } else {
                break;
            }
        }
    }

    let mut result = 0u;
    for i in range(1, positives.len()) {
        if !positives.get(i) {
            result += i;
        }
    }

    println!("Result = {}", result);
}