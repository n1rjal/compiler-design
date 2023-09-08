// Sample basket data
const basketContents = [
  { id: 1, title: "Item 1", cost: 40 },
  { id: 2, title: "Item 2", cost: 50 },
  { id: 3, title: "Item 3", cost: 60 },
];

// Function to display basket contents
function displayBasketContents() {
  const basketList = document.getElementById("basket-list");
  basketList.innerHTML = "";

  for (const item of basketContents) {
    const li = document.createElement("li");
    li.innerHTML = `<strong>${item.title}</strong> - $${item.cost}`;
    basketList.appendChild(li);
  }
}

// Function to clear the basket
function clearBasket() {
  basketContents.length = 0; // Clear the basketContents array
  displayBasketContents(); // Update the basket display
}

// Initial display
displayBasketContents();
