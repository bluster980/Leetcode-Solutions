declare global { 
    interface Function {
      callPolyfill(context: Record<any, any>, ...args: any[]): any;
	}
}

Object.defineProperty(Function.prototype, 'callPolyfill', {
  value: function(obj, ...args) {
    Object.defineProperty(obj, '__temp__', {
      value: this,
      enumerable: false
    });

    const result = obj.__temp__(...args);

    delete obj.__temp__;

    return result;
  },
  enumerable: false
});
/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */