type F = () => Promise<any>

const promisePool = (fn: F[], n: number): Promise<any> => {
    let next = () => fn[n++]?.().then(next)
    return Promise.all(fn.slice(0, n).map(f => f().then(next)))
}