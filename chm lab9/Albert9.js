let xI = [2.03,2.08,2.16,2.23,2.26,2.33];
let yI = [4.01,3.78,3.52,3.42,3.19,2.95];

let a = [];
let b = [];
let m = 2;

function findA() {
    for (let k = 0; k != m; ++k) {
        let Sum = 0;
        let stringA = [];
        for (let j = 0; j != m; ++j) {
            for (let i = 0; i != xI.length; ++i) {
              Sum += Math.pow(xI[i],k+j)
            }
            stringA.push(Sum);
            Sum = 0;
        }
        a.push(stringA)
     }

     for (let i = 0; i != m; ++i) {
        let sum = 0
        for (let j = 0; j != xI.length; ++j) {
            sum += yI[j] * Math.pow(xI[j], i);
        }
        b.push(sum)
        sum = 0;
    }
}

// Lower Upper Solver
function lusolve(A, b, update) {
	var lu = ludcmp(A, update)
	if (lu === undefined) return // Singular Matrix!
	return lubksb(lu, b, update) 	
}
 
// Lower Upper Decomposition
function ludcmp(A, update) {
	// A is a matrix that we want to decompose into Lower and Upper matrices.
	var d = true
	var n = A.length
	var idx = new Array(n) // Output vector with row permutations from partial pivoting
	var vv = new Array(n)  // Scaling information
 
	for (var i=0; i<n; i++) {
		var max = 0
		for (var j=0; j<n; j++) {
			var temp = Math.abs(A[i][j])
			if (temp > max) max = temp
		}
		if (max == 0) return // Singular Matrix!
		vv[i] = 1 / max // Scaling
	}
 
	if (!update) { // make a copy of A 
		var Acpy = new Array(n)
		for (var i=0; i<n; i++) {		
			var Ai = A[i] 
			Acpyi = new Array(Ai.length)
			for (j=0; j<Ai.length; j+=1) Acpyi[j] = Ai[j]
			Acpy[i] = Acpyi
		}
		A = Acpy
	}
 
	var tiny = 1e-20 // in case pivot element is zero
	for (var i=0; ; i++) {
		for (var j=0; j<i; j++) {
			var sum = A[j][i]
			for (var k=0; k<j; k++) sum -= A[j][k] * A[k][i];
			A[j][i] = sum
		}
		var jmax = 0
		var max = 0;
		for (var j=i; j<n; j++) {
			var sum = A[j][i]
			for (var k=0; k<i; k++) sum -= A[j][k] * A[k][i];
			A[j][i] = sum
			var temp = vv[j] * Math.abs(sum)
			if (temp >= max) {
				max = temp
				jmax = j
			}
		}
		if (i <= jmax) {
			for (var j=0; j<n; j++) {
				var temp = A[jmax][j]
				A[jmax][j] = A[i][j]
				A[i][j] = temp
			}
			d = !d;
			vv[jmax] = vv[i]
		}
		idx[i] = jmax;
		if (i == n-1) break;
		var temp = A[i][i]
		if (temp == 0) A[i][i] = temp = tiny
		temp = 1 / temp
		for (var j=i+1; j<n; j++) A[j][i] *= temp
	}
	return {A:A, idx:idx, d:d}
}
 
// Lower Upper Back Substitution
function lubksb(lu, b, update) {
	// solves the set of n linear equations A*x = b.
	// lu is the object containing A, idx and d as determined by the routine ludcmp.
	var A = lu.A
	var idx = lu.idx
	var n = idx.length
 
	if (!update) { // make a copy of b
		var bcpy = new Array(n) 
		for (var i=0; i<b.length; i+=1) bcpy[i] = b[i]
		b = bcpy
	}
 
	for (var ii=-1, i=0; i<n; i++) {
		var ix = idx[i]
		var sum = b[ix]
		b[ix] = b[i]
		if (ii > -1)
			for (var j=ii; j<i; j++) sum -= A[i][j] * b[j]
		else if (sum)
			ii = i
		b[i] = sum
	}
	for (var i=n-1; i>=0; i--) {
		var sum = b[i]
		for (var j=i+1; j<n; j++) sum -= A[i][j] * b[j]
		b[i] = sum / A[i][i]
	}
	return b // solution vector x
}
 
//1
findA(m);
console.log(a,b);
let x = lusolve(a,b);
console.log(`${x[1].toFixed(3)}x + ${x[0].toFixed(3)} = y`)
a = [];
b=[];
//2
m++
findA(m);
console.log(a,b);
x = lusolve(a,b);
console.log(`${x[2].toFixed(3)}x^2+ ${x[1].toFixed(3)}x + ${x[0].toFixed(3)} = y`)
a = [];
b=[];
//3
m++
findA(m);
console.log(a,b);
x = lusolve(a,b);
console.log(`${x[3].toFixed(3)}x^3+ ${x[2].toFixed(3)}x^2+ ${x[1].toFixed(3)}x + ${x[0].toFixed(3)} = y`)
a = [];
b=[];

