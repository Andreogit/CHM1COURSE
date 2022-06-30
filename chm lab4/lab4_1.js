let a11 = 0.34;let a12 = 0.71;let a13 = 0.63;let x1 = 2.08;
let a21 = 0.71;let a22 = -0.65;let a23 = -0.18;let x2 = 0.17;
let a31 = 1.17;let a32 = -2.35;let a33 = 0.75;let x3 = 1.28;
let mat = [[a11,a12,a13,x1],[a21,a22,a23,x2],[a31,a32,a33,x3]];

for(let i = 1; i < 3; i++){
    let mI = mat[i][0]/mat[0][0];
    for(let j = 0; j <= 3; j++){
        mat[i][j] = mat[i][j] - mat[0][j]*mI;
    }
}

mI = mat[2][1]/mat[1][1];

for(let i = 1; i <= 3; i++){
    mat[2][i] = mat[2][i] - mat[1][i]*mI;
}

console.log("Converted mat:");
console.log(mat);
let roots = [];
roots.push(mat[2][3]/mat[2][2]);
roots.push((mat[1][3]-mat[1][2]*roots[0])/mat[1][1]);
roots.push((mat[0][3]-mat[0][1]*roots[1]-mat[0][2]*roots[0])/mat[0][0]);
console.log("Mat roots:");
console.log(roots.reverse());
