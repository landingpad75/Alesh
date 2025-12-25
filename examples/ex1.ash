fn main() {
    res = add(50, 50);
    print(res);
    return 0;
}

fn add(num1, num2) : (int) {
    result = &num1 + &num2;
    print(typeof(result));
    return &result;
}

!_startp = main;