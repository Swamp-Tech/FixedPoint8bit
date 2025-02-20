void taylor_cos (void) {
    SQUARE (value_16bit, u_c); 
    term_1 = u_c; // X^2
    SQUARE (term_1, u_c); // X^4
    term_2 = u_c; // X^4

    MUL_UFIX (term_2, value_16bit, u_c); // X^5
    MUL_UFIX (u_c, value_16bit, u_c); // X^6
    term_3 = u_c; // X^6

    term_1 /= 2; // (X^2) / 2!;
    term_2 /= 24; // (X^4) / 4!;
    term_3 /= 720; //  (X^6) / 6!;

    c = term_2; // ((X^4) / 4!) - ((X^2) / 2!);
    c -= term_1;
    c -= term_3;

    c += 256; // ((X^4) / 4!) - ((X^2) / 2!) - ((X^6) / 6!) + 1
}