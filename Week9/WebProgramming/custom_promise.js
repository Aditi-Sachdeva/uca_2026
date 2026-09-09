
function NewPromise(executorFunction) {
    this.state = "pending";
    this.value = undefined;
    this.successCallbacks = [];
    this.errorCallbacks = [];

    const resolve = (val) => {
        if (this.state !== "pending") return;
        this.state = "fulfilled";
        this.value = val;
        this.successCallbacks.forEach(cb => cb(val));
    };

    const reject = (err) => {
        if (this.state !== "pending") return;
        this.state = "rejected";
        this.value = err;
        this.errorCallbacks.forEach(cb => cb(err));
    };

    try {
        executorFunction(resolve, reject);
    } catch (err) {
        reject(err);
    }

    this.then = (successCallback) => {
        return new NewPromise((resolveNext, rejectNext) => {
            const handle = (val) => {
                try {
                    const result = successCallback(val);
                    resolveNext(result);
                } catch (err) {
                    rejectNext(err);
                }
            };

            if (this.state === "fulfilled") {
                handle(this.value);
            } else if (this.state === "pending") {
                this.successCallbacks.push(handle);
            }
        });
    };

    this.catch = (errorCallback) => {
        return new NewPromise((resolveNext, rejectNext) => {
            const handle = (err) => {
                try {
                    const result = errorCallback(err);
                    resolveNext(result);
                } catch (e) {
                    rejectNext(e);
                }
            };

            if (this.state === "rejected") {
                handle(this.value);
            } else if (this.state === "pending") {
                this.errorCallbacks.push(handle);
            }
        });
    };
}

new NewPromise(resolve => {
    resolve(5);
})
    .then(value => {
        return value * 2;
    })
    .then(value => {
        return value * 5;
    })
    .then(value => {
        console.log(value);
    });