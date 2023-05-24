function objDiff(obj1: any, obj2: any): any {
    const key1 = Object.keys(obj1);
    const key2 = Object.keys(obj2);

    if(!key1.length || !key2.length){
        return {};
    }

    let result = {};
    for(let key in obj1){
        if(obj2[key] !== undefined){
            if(typeof obj1[key] !== 'object' || obj1[key] === null ){
                if(obj1[key] !== obj2[key]){
                    result[key] = [obj1[key], obj2[key]]
                }
            }else if(Array.isArray(obj1[key]) !== Array.isArray(obj2[key])){
                result[key] = [obj1[key], obj2[key]]
            }
            else { 
                const temp = objDiff(obj1[key], obj2[key])
                if(Object.keys(temp).length){
                    result = {...result, [key] : {...temp}}
                }
                
            }
        }
    }
    return result;


};