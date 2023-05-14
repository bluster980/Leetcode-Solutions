function curry(fn: Function): Function {
    return function curried(...args: any[]) {
        if (args.length >= fn.length) {
            return fn(...args)
        }
        
        return (...newArgs: any[]) => curried(...args, ...newArgs)
    };
};