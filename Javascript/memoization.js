//Memoization is a form of caching where the return value of a function is cached based on its parameters.
//If the parameter of that function is not changed, the cached version of the function is returned.

function addTo256(num) {
  return num + 256;
}
addTo256(20); // Returns 276
addTo256(40); // Returns 296
addTo256(20); // Returns 276

//In the code above, we have written a function that adds the parameter to 256 and returns it.
//When we are calling the function addTo256 again with the same parameter (“20” in the case above), we are computing the result again for the same parameter.

//Computing the result with the same parameter, again and again, is not a big deal in the above case,
// but if the function does some heavy-duty work, then, computing the result again and again with the same parameter will lead to wastage of time.

function memoizedAddTo256() {
  var cache = {};

  return function (num) {
    if (num in cache) {
      console.log("cached value");
      return cache[num];
    } else {
      cache[num] = num + 256;
      return cache[num];
    }
  };
}
var memoizedFunc = memoizedAddTo256();

memoizedFunc(20); // Normal return
memoizedFunc(20); // Cached return

// In the code above, if we run the memoizedFunc function with the same parameter, instead of computing the result again, it returns the cached result.

// Note- Although using memoization saves time, it results in larger consumption of memory since we are storing all the computed results.
