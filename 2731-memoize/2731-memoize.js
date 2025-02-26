/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
  let mp = new Map();
  let c = 0;

  return function (...args) {
    if (args.length === 0) return c;
    let key = JSON.stringify(args);
    if (mp.has(key)) {
      return mp.get(key);
    }
    c++;
    let x = fn(...args);
    mp.set(key, x);
    return x;
  };
}

/**
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1
 */
