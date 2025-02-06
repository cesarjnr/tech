fn main() {
  // Scalar Types

  let positive: u32 = 1;
  let negative: i32 = -1;
  let default_int = -100; // Default is i32
  let float: f32 = 1.5;
  let default_float = 3.2; // Default is f64
  let boolean: bool = true;
  let boolean_two = false;
  let character: char = 'C';
  let character_two = 'J';


  println!("{}", positive);
  println!("{negative}");
  println!("{}", default_int);
  println!("{float}");
  println!("{}", default_float);
  println!("{boolean}");
  println!("{}", boolean_two);
  println!("{character}");
  println!("{}", character_two);

  // Compound Types
  let tup: (i32, f64, u8) = (500, 6.4, 1);
  let (five_hundred, _six_point_four, _one) = tup;
  let six_point_four = tup.1;
  let arr_one = [1, 2, 3, 4, 5];
  let arr_two: [i32; 5] = [1, 2, 3, 4, 5];
  let arr_three = [3; 5];
  let one = arr_one[0];
  let two = arr_two[1];
  let three = arr_three[2];

  println!("{five_hundred}");
  println!("{}", six_point_four);
  println!("{one}");
  println!("{}", two);
  println!("{three}");
}
