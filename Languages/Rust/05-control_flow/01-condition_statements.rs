fn main() {
  let age = 29;

  if age < 16 {
    println!("You cannot vote");
  } else if age < 18 {
    println!("You can vote");
  } else {
    println!("You are required to vote");
  }
}