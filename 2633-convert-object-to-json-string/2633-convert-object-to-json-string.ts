function jsonStringify(object: any): string {
    if (typeof object === 'string') return `"${object}"`;
    if (typeof object === 'boolean') return object ? "true" : "false";
    if (typeof object === 'number') return String(object);
    if (object === null) return "null";
    
    if (Array.isArray(object)) {
        let string = "[";
        for (let i = 0; i < object.length; i++) {
            if (i === object.length - 1) {
                string += jsonStringify(object[i]);
                break;
            }
            string += `${jsonStringify(object[i])},`;
        }
        string += "]";
        return string;
    }

    if (typeof object === "object") {
        let string = "{"
        const filteredEntries = Object.entries(object).filter(v => v[1] !== undefined)
        for (let i = 0; i < filteredEntries.length; i++) {
            if (i === filteredEntries.length - 1) {
                string += `"${filteredEntries[i][0]}":${jsonStringify(filteredEntries[i][1])}`
                break;
            }
            string += `"${filteredEntries[i][0]}":${jsonStringify(filteredEntries[i][1])},`
        }
        string += "}";
        return string;
    }

};