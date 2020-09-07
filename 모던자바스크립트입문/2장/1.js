function factorial(n) {
    if (n < 1) return 1;

    return factorial(n - 1) * n;
}

for (i = 0; i < 10; i++) {
    console.log(i + "! = " + factorial(i));
}
