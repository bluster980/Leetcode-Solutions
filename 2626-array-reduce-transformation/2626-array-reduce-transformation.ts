type Fn = (accum: number, curr: number) => number

function reduce(nums: number[], fn: Function, init: number): number {
  if (nums.length === 0) {
    return init;
  }
  let val: number = init;
  for (let i = 0; i < nums.length; i++) {
    val = fn(val, nums[i]);
  }
  return val;
};