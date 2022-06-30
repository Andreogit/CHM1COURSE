let a11 = 0.34;let a12 = 0.71;let a13 = 0.63;let x1 = 2.08;
let a21 = 0.71;let a22 = -0.65;let a23 = -0.18;let x2 = 0.17;
let a31 = 1.17;let a32 = -2.35;let a33 = 0.75;let x3 = 1.28;
let matA = [[a11,a12,a13],[a21,a22,a23],[a31,a32,a33]];
  let N = matA.length;
  console.log("Matrix:", matA);
  let matL = [
    [1, 0, 0],
    [0, 1, 0],
    [0, 0, 1] 
  ];
  let matU = [
    [0, 0, 0],
    [0, 0, 0],
    [0, 0, 0]
  ];
  for (let i = 0; i < N; i++) {
    let n = N - i - 1;
    matU[i][i] = matA[0][0];
    let u00 = matU[i][i];
    let u1T = []
    for (let j = 0; j < n; j++ ) {
      u1T[j] = matU[i][j + i + 1] = matA[0][j + 1];
    }
    let l1 = []
    for (let j = 0; j < n; j++ ) {
      l1[j] = matL[j + i + 1][i] = matA[j + 1][0] / u00;
    }
    let lu = new Array(n);
    for (let j = 0; j < n; j++) {
      lu[j] = new Array(n)
      for (let k = 0; k < n; k++) {
        lu[j][k] = matA[j + 1][k + 1] - l1[j] * u1T[k];
      }
    }
    matA = lu;
  }
   let original = [
    [0, 0, 0],
    [0, 0, 0],
    [0, 0, 0]
  ];
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      for (let k = 0; k < N; k++) {
        original[i][j] += matL[i][k] * matU[k][j];
      }
    }
  }
  console.log("L:", matL);
  console.log("U:", matU);
  console.log("LU:", original);
  
  let matB = [
    x1, x2, x3
  ];
let y = new Array(N);
for (let i = 0; i < N; i++) {
  let sum = 0;
  for (let j = 0; j < i; j++) {
    sum += matL[i][j] * y[j];
  }
  y[i] = (matB[i] - sum) / matL[i][i];
}
let x = new Array(N);
for (let i = N - 1; 0 <= i; i--) {
  let sum = 0;
  if (matU[i][i] === 0) {
    continue;
  }
  for (let j = N - 1; j > i; j--) {
    sum += matU[i][j] * x[j];
  }
  x[i] = (y[i] - sum) / matU[i][i];
}
console.log("Roots:");
console.log(x);
