module fulladder(s,c,a,b,cin);

input a,b,cin;
output s,c;

halfadder ha1(s1,c1,a,b);
halfadder ha2(s,c2,s1,cin);

or or1(c, c2,c1);

endmodule