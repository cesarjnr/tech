fn main() {
  let age = calculate_age(1996);

  println!("Your age is: {age}");
}

fn calculate_age(year_of_birth: u16) -> u16 {
  let current_year = 2025;

  current_year - year_of_birth
}