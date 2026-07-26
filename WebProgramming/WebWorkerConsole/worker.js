
self.onmessage = async (event) => {
    if (event.data === "fetchUsers") {
        try {
            const response = await fetch("https://dummyjson.com/users");

            if (!response.ok) {
                throw new Error("Failed to fetch users");
            }

            const result = await response.json();

            if (!result.users || result.users.length === 0) {
                throw new Error("No users found");
            }

            self.postMessage(result.users);


        } 
        catch (error) {
            self.postMessage(`Error fetching users: ${error.message}`);
        }
    }
};
