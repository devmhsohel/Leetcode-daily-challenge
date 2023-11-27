let MOD = 1000000007;
let results = new Uint32Array(5001);
let pre = new Uint32Array(10);
let cur = new Uint32Array(10).fill(1);
cur[5] = 0;

results[1] = 10;
for (let i = 2; i <= 5000; i++) {
  let tem = pre;
  pre = cur;
  cur = tem;

  cur[0] = (pre[4] + pre[6]) % MOD;
  cur[1] = (pre[6] + pre[8]) % MOD;
  cur[2] = (pre[7] + pre[9]) % MOD;
  cur[3] = (pre[4] + pre[8]) % MOD;
  cur[4] = (pre[0] + pre[3] + pre[9]) % MOD;
  cur[6] = (pre[0] + pre[1] + pre[7]) % MOD;
  cur[7] = (pre[2] + pre[6]) % MOD;
  cur[8] = (pre[1] + pre[3]) % MOD;
  cur[9] = (pre[2] + pre[4]) % MOD;

  tem = 0;
  for (let d = 0; d < 10; d++) tem = (tem + cur[d]) % MOD;
  results[i] = tem;
}

/**
 * @param {number} n
 * @return {number}
 */
var knightDialer = function(n) {
  return results[n]; 
};