use std::io;
use std::io::Write;

fn main() {
    println!("1. Encode");
    println!("2. Decode");
    print!("Enter Option: ");
    io::stdout().flush().unwrap();

    let mut input = String::new();

    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    if input.contains("1") {
        encode()
    } else if input.contains("2") {
        decode()
    } else {
        println!("Wrong input. Exiting")
    }
}

fn encode() {
    print!("Enter Number to Encode: ");
    io::stdout().flush().unwrap();

    let mut input = String::new();

    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    let int: u32 = input.trim().parse().expect("Parsing Error");
    if int <= 0 { println!("Wrong Input. Exiting"); return; }

    if int <= 127 {
        let binary = format!("{:b}", int);
        println!("1{}",pad(binary));
    } else {
        println!("Variable Byte Code: ");
        let mut binary = format!("{:b}", int);

        // Get first segment
        let modulo = &binary.len() % 7;
        let substring = String::from(&binary[..modulo]).clone();
        // Remove from input binary
        &binary.replace_range(..modulo,"");

        // Print with padding of zeroes to fill 7 bits
        println!("0{}",pad(substring));

        while binary.len() != 0 {

            // Get other segments
            let substring = String::from(&binary[..7]).clone();
            // Remove from input
            &binary.replace_range(..7, "");

            // Print segment
            if binary.len() == 0 { // if last segment
                println!("1{}", pad(substring));
            } else {
                println!("0{}", pad(substring));
            }
        }
    }
}

fn decode() {
    print!("Enter Number to Decode: ");
    io::stdout().flush().unwrap();

    let mut input = String::new();

    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    let mut binaryString = String::new();
    let mut hasNext = true;

    while hasNext {
        // Get Ending Bit from input string
        let endingBit = String::from(&input[..1]).clone();
        &input.replace_range(..1,"");
        hasNext = endingBit == "0";

        // Get binary value from input string
        let binaryStringSegment = String::from(&input[..7]).clone();
        &input.replace_range(..7,"");
        binaryString+= &*binaryStringSegment;

    }
    // Convert Binary String to Integer
    let int = isize::from_str_radix(&*binaryString, 2).unwrap();
    println!("Original Integer: {int}");
}

fn pad(string: String) -> String {
    let pad = "0".repeat(7-string.len());
    pad + &*string
}