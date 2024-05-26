// Function to call the C++ method to clear the selected temp folders
function clearTempFolders() {
    const checkboxes = document.querySelectorAll('input[type="checkbox"]');
    const selectedFolders = [];

    checkboxes.forEach((checkbox, index) => {
        if (checkbox.checked) {
            selectedFolders.push(index); // The index corresponds to the TempFolder enum value
        }
    });

    // Call the C++ method
    if (window.ultralight) {
        window.ultralight.clearTempFolders(selectedFolders);
    } else {
        console.error("Ultralight API is not available");
    }
}

// Wait for the DOM to be fully loaded
document.addEventListener("DOMContentLoaded", () => {
    // Attach event listener to the button
    const clearButton = document.querySelector("button");
    if (clearButton) {
        clearButton.addEventListener("click", clearTempFolders);
        if (clearTempFolders) {
            alert("clearTempFolders is not empty!");
        }
        
    }
});
