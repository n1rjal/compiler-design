// Sample item data
const items = [
  { id: 1, title: "Jeans", cost: 40 },
  { id: 2, title: "Hat", cost: 15 },
  { id: 3, title: "Sweater", cost: 50 },
];

const basketItems = [];

// Function to display items
function displayItems() {
  const itemList = document.getElementById("item-list");
  itemList.innerHTML = "";

  for (const item of items) {
    const li = document.createElement("li");
    li.innerHTML = `<strong>${item.title}</strong><br>Cost: $${item.cost}<br><button onclick="addToBasket(${item.id})">Add to Basket</button>`;
    itemList.appendChild(li);
  }
}

// Function to add an item to the basket
function addToBasket(itemId) {
  const item = items.find((i) => i.id === itemId);
  if (item) {
    basketItems.push(item);
    displayBasketContents();
  }
}

// Function to display basket contents
function displayBasketContents() {
  const basketList = document.getElementById("basket-contents");
  basketList.innerHTML = "";

  for (const item of basketItems) {
    const li = document.createElement("li");
    li.innerHTML = `${item.title} - $${item.cost}`;
    basketList.appendChild(li);
  }
}

// Function for payment (this is just a placeholder)
function proceedToPayment() {
  alert("Payment functionality not implemented in this example.");
}

// Initial display
displayItems();
