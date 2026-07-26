
const worker = new Worker("worker.js");

const users = document.getElementById("users");

worker.postMessage("fetchUsers");

worker.onmessage = (event) => {
    
    const data = event.data;

    if(data.error){
        console.log(data.error);
    }

    data.forEach((user) => {
        const status = (user.age >= 18) ? 'Active' : 'Inactive';
        users.innerHTML += `${user.firstName} - ${status} <br>`;
    });
}

worker.onerror = (error) => {
    console.error(error.message);
};

