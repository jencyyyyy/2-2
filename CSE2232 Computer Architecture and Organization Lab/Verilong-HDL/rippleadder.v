module rippleadder(s,c,a,b,cin);

input [3:0]a,b;
input cin;

output [3:0]s;
output c;

fulladder fa1(s[0],c1,a[0],b[0],cin);
fulladder fa2(s[1],c2,a[1],b[1],c1);
fulladder fa3(s[2],c3,a[2],b[2],c2);
fulladder fa4(s[3],c,a[3],b[3],c3);

endmodule