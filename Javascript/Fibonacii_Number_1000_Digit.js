let fab = '';
let f1 = '0';
let f2 = '1';
let i = 1;
while (fab.length !== 1000) {
  if (fab.length < 2) {
    fab = (Number(f1) + Number(f2)).toString();
  } else {
    let remain = 0;
    let sum = '';
    let totalSumInString = '';
    for (let i = 1; i <= f2.length; i++) {
      if (i <= f1.length) {
        sum = Number(f2[f2.length - i]) + Number(f1[f1.length - i]) + remain;
        if (sum > 9) {
          totalSumInString = (sum % 10) + totalSumInString;
          remain = 1;
        } else {
          remain = 0;
          totalSumInString = sum + totalSumInString;
        }
      } else {
        sum = remain + Number(f2[f2.length - i]);
        if (sum > 9) {
          totalSumInString = (sum % 10) + totalSumInString;
          remain = 1;
        } else {
          remain = 0;
          totalSumInString = sum + totalSumInString;
        }
      }
    }
    if (remain !== 0) {
      fab = remain + totalSumInString;
    } else {
      fab = totalSumInString;
    }
  }
  f1 = f2; f2 = fab; i++;
}

console.log(i, '===>', fab);
