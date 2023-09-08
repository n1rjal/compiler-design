// Sample item data
const items = [
  { id: 1, title: "Jeans", cost: 40 },
  { id: 2, title: "Hat", cost: 15 },
  { id: 3, title: "Sweater", cost: 50 },
];

const basketItems = [];
const orderRecords = [];

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
  if (basketItems.length === 0) {
    alert("Your basket is empty. Add items to the basket before proceeding.");
    return;
  }
  const orderTotal = basketItems.reduce((total, item) => total + item.cost, 0);
  const order = {
    items: [...basketItems],
    total: orderTotal,
  };
  orderRecords.push(order);
  basketItems.length = 0; // Clear the basket
  displayBasketContents();
  displayOrderRecords();
}

// Function to display order records
function displayOrderRecords() {
  const orderRecordsList = document.getElementById("recorded-orders");
  orderRecordsList.innerHTML = "";

  for (const order of orderRecords) {
    const li = document.createElement("li");
    li.classList.add("order-record");
    li.innerHTML = `<strong>Order Total: $${
      order.total
    }</strong><br>Items: ${order.items.map((item) => item.title).join(", ")}`;
    orderRecordsList.appendChild(li);
  }
}

// Initial display
displayItems();
displayOrderRecords();
