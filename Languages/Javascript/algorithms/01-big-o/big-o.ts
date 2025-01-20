// O(n)

function sum(n: string): number {
  let sum = 0;

  for (let i = 0; i < n.length; i++) {
    sum += 1;
  }

  return sum;
}

console.log(`O(n): ${sum('ABC')}`);

// O(n²)

function sum_two(n: string): number {
  let sum = 0;

  for (let i = 0; i < n.length; i++) {
    for (let j = 0; j < n.length; j++) {
      sum += 1;
    }
  }

  return sum;
}

console.log(`O(n²): ${sum_two('ABC')}`);