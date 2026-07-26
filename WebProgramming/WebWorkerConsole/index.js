
const worker = new Worker("worker.js");

worker.postMessage("fetchUsers");

worker.onmessage = (event) => {
    
    const data = event.data;

    if(data.error){
        console.log(data.error);
    }

    data.forEach((user) => {
        const status = (user.age >= 18) ? 'Active' : 'Inactive';
        console.log(`${user.firstName} - ${status}`);
    });
}

worker.onerror = (error) => {
    console.error(error.message);
};

