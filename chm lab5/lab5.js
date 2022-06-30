let error = 0.001
let iterSeid = 0
let iterYak = 0
let a11 = 0.65;let a12 =-0.06;let a13 =-0.12;let a14 = 0.14;let x1 = 2.17;
let a21 = 0.04;let a22 =-0.82;let a23 = 0.08;let a24 = 0.11;let x2 =-1.4;
let a31 = 0.34;let a32 = 0.08;let a33 =-0.66;let a34 = 0.14;let x3 = 2.1;
let a41 = 0.11;let a42 = 0.12;let a43 = 0   ;let a44 =-0.53;let x4 =-0.8;
let matA = [[a11,a12,a13],[a21,a22,a23],[a31,a32,a33],[a41, a42, a43]];
let matB = [x1, x2, x3, x4];
function mod(a){
    return Math.abs(a);
}
if (mod(a11) > (mod(a12)+mod(a13)+mod(a14)) & mod(a22) > (mod(a21)+mod(a23)+mod(a24)) & mod(a33) > (mod(a31)+mod(a32)+mod(a34)) & mod(a44) > (mod(a41)+mod(a42)+mod(a43))){
    iterSeid++;
    let 
}
else{
    console.log("Error, wrong conditions")
}