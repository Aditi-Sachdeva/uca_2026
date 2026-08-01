
const fields = [ 
  "First Name", 
  "Last Name", 
  "Email"
]; 

function generateForm(){

    return `
    <form>
    ${fields.map((field) => {
        return `
        <label> ${field} </label>
        <input type="text">
        `;
    }).join("")}
    </form>
    `;
}

console.log(generateForm());