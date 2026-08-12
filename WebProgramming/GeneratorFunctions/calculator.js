
function* calculator(initialValue) {

    let result = initialValue;
    let output = result;

    while (true) {

        let input = yield output;

        if (!input || typeof input.operation !== "string") {
            output = "Invalid input";
            continue;
        }

        let { operation, value } = input;

        switch (operation.toLowerCase()) {

            case "add":
                if (typeof value !== "number") {
                    output = "Invalid input";
                    continue;
                }

                result = result + value;
                output = result;
                break;

            case "subtract":
                if (typeof value !== "number") {
                    output = "Invalid input";
                    continue;
                }

                result = result - value;
                output = result;
                break;

            case "multiply":
                value = Number(value);

                if (Number.isNaN(value)) {
                    output = "Invalid input";
                    continue;
                }

                result = result * value;
                output = result;
                break;

            case "divide":
                value = Number(value);

                if (Number.isNaN(value) || value === 0) {
                    output = "Invalid input";
                    continue;
                }

                result = result / value;
                output = result;
                break;

            default:
                output = "Invalid operation";
                continue;
        }
    }
}


const calc = calculator(50);

calc.next();

console.log(calc.next({ operation: "add", value: 30 }).value);
console.log(calc.next({ operation: "multiply", value: "2" }).value);
console.log(calc.next({ operation: "add", value: "30" }).value);
console.log(calc.next({ operation: "multiply", value: 0 }).value); 