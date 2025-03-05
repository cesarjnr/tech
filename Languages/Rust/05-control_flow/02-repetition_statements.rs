fn main() {
  println!("========== Loop ==========");

  let mut loop_counter = 0;

  loop {
    println!("Counter: {loop_counter}");

    if loop_counter == 10 {
      break;
    }

    loop_counter += 1;
  }

  let mut loop_counter_two = 0;

  println!("========== Loop (Continue) ==========");

  loop {
    loop_counter_two += 1;

    if loop_counter_two == 10 {
      break;
    }

    if loop_counter_two % 2 == 0 {
      println!("Counter {loop_counter_two} is divided by 2");

      continue;
    }

    println!("Counter: {loop_counter_two}");
  }

  println!("========== Loop (Returning) ==========");

  let mut loop_counter_three = 0;
  let result = loop {
    loop_counter_three += 1;

    if loop_counter_three == 10 {
      break loop_counter_three * 2;
    }
  };

  println!("The result is: {result}");

  println!("========== Loop (Labels) ==========");

  let mut loop_counter_four = 0;

  'counting_up: loop {
    println!("Counter: {loop_counter_four}");

    let mut remaining = 10;

    loop {
      println!("Remaining: {remaining}");

      if remaining == 9 {
        break;
      }

      if loop_counter_four == 2 {
        break 'counting_up;
      }

      remaining -= 1;
    }

    loop_counter_four += 1;
  }

  println!("End Counter: {loop_counter_four}");

  println!("========== While ==========");

  let mut while_counter = 3;

  while while_counter != 0 {
    println!("Counter: {while_counter}");

    while_counter -= 1;
  }

  println!("========== For ==========");

  let a = [10, 20, 30, 40, 50];

  for element in a {
    println!("The value is: {element}");
  }
}